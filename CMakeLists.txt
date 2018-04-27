cmake_minimum_required(VERSION 3.6)
project(libsdp VERSION 1.0.0 DESCRIPTION "SDP implementation conforming to the
RFC 4566")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
