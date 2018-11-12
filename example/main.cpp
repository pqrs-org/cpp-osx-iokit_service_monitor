#include <csignal>
#include <pqrs/osx/iokit_service_monitor.hpp>

namespace {
auto global_wait = pqrs::make_thread_wait();
}

int main(void) {
  pqrs::dispatcher::extra::initialize_shared_dispatcher();

  std::signal(SIGINT, [](int) {
    global_wait->notify();
  });

  if (auto matching_dictionary = IOServiceNameMatching("IOHIDEventDriver")) {
    auto service_monitor = std::make_unique<pqrs::osx::iokit_service_monitor>(
        pqrs::dispatcher::extra::get_shared_dispatcher(),
        matching_dictionary);

    service_monitor->service_detected.connect([](auto&& registry_entry_id, auto&& service_ptr) {
      std::cout << "service_detected registry_entry_id:" << registry_entry_id << std::endl;

      io_name_t name;
      pqrs::osx::iokit_return r = IORegistryEntryGetName(*service_ptr, name);
      if (r) {
        std::cout << "IORegistryEntryGetName: " << name << std::endl;
      } else {
        std::cout << "IORegistryEntryGetName Error: " << r << std::endl;
      }

      std::cout << std::endl;
    });

    service_monitor->service_removed.connect([](auto&& registry_entry_id) {
      std::cout << "service_removed registry_entry_id:" << registry_entry_id << std::endl;
      std::cout << std::endl;
    });

    service_monitor->async_start();

    global_wait->wait_notice();

    CFRelease(matching_dictionary);
  }

  pqrs::dispatcher::extra::terminate_shared_dispatcher();

  std::cout << "finished" << std::endl;

  return 0;
}
