[![Build Status](https://github.com/pqrs-org/cpp-osx-iokit_service_monitor/workflows/CI/badge.svg)](https://github.com/pqrs-org/cpp-osx-iokit_service_monitor/actions)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_service_monitor/blob/main/LICENSE.md)

# cpp-osx-iokit_service_monitor

A wrapper class of IOService notifications.

- `IOServiceAddMatchingNotification(kIOFirstMatchNotification)`
- `IOServiceAddMatchingNotification(kIOTerminatedNotification)`

## Requirements

cpp-osx-iokit_service_monitor depends the following classes.

- [Nod](https://github.com/fr00b0/nod)
- [pqrs::cf::run_loop_thread](https://github.com/pqrs-org/cpp-cf-run_loop_thread)
- [pqrs::dispatcher](https://github.com/pqrs-org/cpp-dispatcher)
- [pqrs::osx::iokit_iterator](https://github.com/pqrs-org/cpp-osx-iokit_iterator)
- [pqrs::osx::iokit_object_ptr](https://github.com/pqrs-org/cpp-osx-iokit_object_ptr)
- [pqrs::osx::iokit_registry_entry](https://github.com/pqrs-org/cpp-osx-iokit_registry_entry)
- [pqrs::osx::iokit_types](https://github.com/pqrs-org/cpp-osx-iokit_types)
- [pqrs::osx::kern_return](https://github.com/pqrs-org/cpp-osx-kern_return)
- [type_safe](https://github.com/foonathan/type_safe)

## Install

Copy `include/pqrs` and `vendor/vendor/include` directories into your include directory.
