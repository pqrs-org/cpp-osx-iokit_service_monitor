[![Build Status](https://travis-ci.org/pqrs-org/cpp-osx-iokit_service_monitor.svg?branch=master)](https://travis-ci.org/pqrs-org/cpp-osx-iokit_service_monitor)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_service_monitor/blob/master/LICENSE.md)

# cpp-osx-iokit_service_monitor

A wrapper class of IOService notifications.

- `IOServiceAddMatchingNotification(kIOFirstMatchNotification)`
- `IOServiceAddMatchingNotification(kIOTerminatedNotification)`

## Requirements

cpp-osx-iokit_service_monitor depends the following classes.

- [Nod](https://github.com/fr00b0/nod)
- [pqrs::cf_run_loop_thread](https://github.com/pqrs-org/cpp-cf_run_loop_thread)
- [pqrs::dispatcher](https://github.com/pqrs-org/cpp-dispatcher)
- [pqrs::osx::iokit_object_ptr](https://github.com/pqrs-org/cpp-osx-iokit_object_ptr)
- [pqrs::osx::iokit_return](https://github.com/pqrs-org/cpp-osx-iokit_return)
- [pqrs::osx::iokit_types](https://github.com/pqrs-org/cpp-osx-iokit_types)
- [type_safe](https://github.com/foonathan/type_safe)

## Install

### Using package manager

You can install `include/pqrs` by using [cget](https://github.com/pfultz2/cget).

```shell
cget install pqrs-org/cpp-cget-recipes
cget install pqrs-org/cpp-osx-iokit_service_monitor
```

### Manual install

Copy `include/pqrs` directory into your include directory.
