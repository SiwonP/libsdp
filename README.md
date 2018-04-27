# libsdp

This library, entirely in C and using only the C standard libraries, implements
the Session Description Protocol - SDP - as described by the RCF 4566 of the
IETF.

## Getting Started

### Prequisites

The project is meant to be build via `CMake` and `Make`. You should also have a C
compiler (whether it be GCC or CLANG).

### Building 

Follow the instructions below to build the library.

```
git clone 
cd 
mkdir build
cd build
cmake -DBUILD_TYPE=RELEASE ..
make
```

## Running the tests

## Building the doc

The doc is generated by doxygen, so you should have it installed.

```
doxygen Doxyfile
``` 

It creates a `doc` folder containing both `html` and `latex` version of the
documentation.
