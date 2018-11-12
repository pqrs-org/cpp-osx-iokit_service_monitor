[![Build Status](https://travis-ci.org/pqrs-org/cpp-osx-iokit_service_monitor.svg?branch=master)](https://travis-ci.org/pqrs-org/cpp-osx-iokit_service_monitor)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_service_monitor/blob/master/LICENSE.md)

# cpp-osx-iokit_service_monitor

A wrapper class of IOService notifications.

- `IOServiceAddMatchingNotification(kIOFirstMatchNotification)`
- `IOServiceAddMatchingNotification(kIOTerminatedNotification)`

## Requirements

cpp-osx-iokit_service_monitor depends the following classes.

- [Nod](https://github.com/fr00b0/nod)
- [pqrs::cf_ptr](https://github.com/pqrs-org/cpp-cf_ptr)
- [pqrs::cf_run_loop_thread](https://github.com/pqrs-org/cpp-cf_run_loop_thread)
- [pqrs::dispatcher](https://github.com/pqrs-org/cpp-dispatcher)
- [pqrs::osx::iokit_object_ptr](https://github.com/pqrs-org/cpp-osx-iokit_object_ptr)
- [pqrs::osx::iokit_return](https://github.com/pqrs-org/cpp-osx-iokit_return)
- [pqrs::osx::iokit_types](https://github.com/pqrs-org/cpp-osx-iokit_types)
- [pqrs::thread_wait](https://github.com/pqrs-org/cpp-thread_wait)
- [type_safe](https://github.com/foonathan/type_safe)

## Install

### Manual install

Copy `include/pqrs` directory into your include directory.

### Using package manager

You can also install `include/pqrs` by using [cget](https://github.com/pfultz2/cget).

```shell
cget install foonathan/type_safe@v0.2 --cmake header
cget install fr00b0/nod@v0.5.0 --cmake header
cget install pqrs-org/cpp-cf_ptr@v1.3.0 --cmake header
cget install pqrs-org/cpp-cf_run_loop_thread@v1.3.0 --cmake header
cget install pqrs-org/cpp-dispatcher@v2.1.0 --cmake header
cget install pqrs-org/cpp-osx-iokit_object_ptr@v2.1.0 --cmake header
cget install pqrs-org/cpp-osx-iokit_return@v1.1.0 --cmake header
cget install pqrs-org/cpp-osx-iokit_service_monitor@v2.1.0 --cmake header
cget install pqrs-org/cpp-osx-iokit_types@v2.0.0 --cmake header
cget install pqrs-org/cpp-thread_wait@v1.2.0 --cmake header
```
