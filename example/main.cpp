#include <IOKit/hid/IOHIDDevice.h>
#include <csignal>
#include <pqrs/osx/iokit_service_monitor.hpp>

namespace {
auto global_wait = pqrs::make_thread_wait();
}

int main(void) {
  std::signal(SIGINT, [](int) {
    global_wait->notify();
  });

  auto time_source = std::make_shared<pqrs::dispatcher::hardware_time_source>();
  auto dispatcher = std::make_shared<pqrs::dispatcher::dispatcher>(time_source);
  auto run_loop_thread = std::make_shared<pqrs::cf::run_loop_thread>();

  if (auto matching_dictionary = IOServiceMatching(kIOHIDDeviceKey)) {
    auto service_monitor = std::make_unique<pqrs::osx::iokit_service_monitor>(dispatcher,
                                                                              run_loop_thread,
                                                                              matching_dictionary);

    service_monitor->service_matched.connect([](auto&& registry_entry_id, auto&& service_ptr) {
      std::cout << "service_matched registry_entry_id:" << registry_entry_id << std::endl;

      io_name_t name;
      pqrs::osx::kern_return r = IORegistryEntryGetName(*service_ptr, name);
      if (r) {
        std::cout << "IORegistryEntryGetName: " << name << std::endl;
      } else {
        std::cout << "IORegistryEntryGetName Error: " << r << std::endl;
      }

      std::cout << std::endl;
    });

    service_monitor->service_terminated.connect([](auto&& registry_entry_id) {
      std::cout << "service_terminated registry_entry_id:" << registry_entry_id << std::endl;
      std::cout << std::endl;
    });

    service_monitor->error_occurred.connect([](auto&& message, auto&& kern_return) {
      std::cerr << "error_occurred " << message << " " << kern_return << std::endl;
    });

    service_monitor->async_start();

    global_wait->wait_notice();

    CFRelease(matching_dictionary);
  }

  run_loop_thread->terminate();
  run_loop_thread = nullptr;

  dispatcher->terminate();
  dispatcher = nullptr;

  std::cout << "finished" << std::endl;

  return 0;
}
