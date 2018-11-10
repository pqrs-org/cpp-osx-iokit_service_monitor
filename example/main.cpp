#include <csignal>
#include <iostream>
#include <pqrs/osx/iokit/ioservice_monitor.hpp>

namespace {
auto global_wait = pqrs::make_thread_wait();
}

int main(void) {
  pqrs::dispatcher::extra::initialize_shared_dispatcher();

  std::signal(SIGINT, [](int) {
    global_wait->notify();
  });

  if (auto matching_dictionary = IOServiceNameMatching("IOHIDEventDriver")) {
    auto ioservice_monitor = std::make_unique<pqrs::osx::iokit::ioservice_monitor>(
        pqrs::dispatcher::extra::get_shared_dispatcher(),
        matching_dictionary);

    ioservice_monitor->ioservice_detected.connect([](auto&& registry_entry_id, auto&& service) {
      std::cout << "ioservice_detected registry_entry_id:" << registry_entry_id << std::endl;
    });

    ioservice_monitor->ioservice_removed.connect([](auto&& registry_entry_id) {
      std::cout << "ioservice_removed registry_entry_id:" << registry_entry_id << std::endl;
    });

    ioservice_monitor->async_start();

    global_wait->wait_notice();

    CFRelease(matching_dictionary);
  }

  pqrs::dispatcher::extra::terminate_shared_dispatcher();

  std::cout << "finished" << std::endl;

  return 0;
}
