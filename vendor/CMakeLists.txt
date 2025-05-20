cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
project(vendor NONE)

include("${CMAKE_CURRENT_LIST_DIR}/cpm-cmake-package-lock/vendor/CPM.cmake")

CPMUsePackageLock("${CMAKE_CURRENT_LIST_DIR}/cpm-cmake-package-lock/cmake/package-lock.cmake")

set(VENDOR_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor")
file(MAKE_DIRECTORY "${VENDOR_INCLUDE_DIR}")

include("${CMAKE_CURRENT_LIST_DIR}/cpm-cmake-package-lock/cmake/common.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cpm-cmake-package-lock/cmake/dependency.cmake")

copy_vendor_package(nod)
copy_vendor_package(pqrs_cf_run_loop_thread)
copy_vendor_package(pqrs_dispatcher)
copy_vendor_package(pqrs_osx_iokit_iterator)
copy_vendor_package(pqrs_osx_iokit_object_ptr)
copy_vendor_package(pqrs_osx_iokit_registry_entry)
copy_vendor_package(pqrs_osx_iokit_types)
copy_vendor_package(pqrs_osx_kern_return)
copy_vendor_package(type_safe)
copy_vendor_package(ut)
