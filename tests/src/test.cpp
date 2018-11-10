#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit/ioservice_monitor.hpp>

TEST_CASE("ioservice_monitor stress testing") {
  auto time_source = std::make_shared<pqrs::dispatcher::hardware_time_source>();
  auto dispatcher = std::make_shared<pqrs::dispatcher::dispatcher>(time_source);

  auto object_id = pqrs::dispatcher::make_new_object_id();
  dispatcher->attach(object_id);

  for (int i = 0; i < 10000; ++i) {
    if (i % 100 == 0) {
      std::cout << "." << std::flush;
    }

    auto matching_dictionary = IOServiceNameMatching("IOHIDEventDriver");
    REQUIRE(matching_dictionary);

    auto monitor = std::make_shared<pqrs::osx::iokit::ioservice_monitor>(dispatcher,
                                                                         matching_dictionary);

    monitor->ioservice_detected.connect([](auto&& registry_entry_id, auto&& service) {
    });

    monitor->ioservice_removed.connect([](auto&& registry_entry_id) {
    });

    monitor->async_start();

    // wait until ioservice_monitor is started.
    {
      auto wait = pqrs::make_thread_wait();

      dispatcher->enqueue(
          object_id,
          [wait] {
            wait->notify();
          });

      wait->wait_notice();
    }

    monitor->async_stop();

    // wait until ioservice_monitor is stopped.
    {
      auto wait = pqrs::make_thread_wait();

      dispatcher->enqueue(
          object_id,
          [wait] {
            wait->notify();
          });

      wait->wait_notice();
    }
  }

  std::cout << std::endl;

  dispatcher->detach(object_id);

  dispatcher->terminate();
  dispatcher = nullptr;
}
