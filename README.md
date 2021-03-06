# libsdp ![travis](https://travis-ci.org/SiwonP/libsdp.svg?branch=master)

This library, entirely in C and using only the C standard libraries, implements
the Session Description Protocol - SDP - as described by the RCF 4566 of the
IETF.

- [Getting Started](#getting-started)
    * [Prerequisites](#prerequisites)
    * [Documentation Prerequisites](#documentation-prerequisites)
    * [Tests Prerequisites](#tests-prerequisites)
- [Installing](#installing)
    * [Building from source](#building-form-source)
    * [Binaries](#binaries)
    * [Packages](#packages)
- [Running the tests](#running-the-tests)
- [Building the doc](#building-the-doc)
- [Authors](#authors)
- [License](#license)

## Getting Started

### Prerequisites

The project is meant to be build via `CMake` and `Make`. You should also have a C
compiler (whether it be GCC or CLANG).

### Documentation Prerequisites

The documentation is made thanks to `doxygen`, so you must have it installed on
your machine.

See [here](http://www.stack.nl/~dimitri/doxygen/download.html) to install
`doxygen`.

### Tests prerequisites

The test are conducted with the `criterion` framework. To be able to run the
tests, make you this framework is installed and available. See the
[criterion](https://www.github.com/Snaipe/Criterion) github project.

## Installing

### Building from source

Follow the instructions below to build the library.

```
git clone https://github.com/SiwonP/libsdp.git
cd libsdp
mkdir build
cd build
cmake -DBUILD_TYPE=RELEASE ..
make
```

### Binaries

There are no binaries released currently.

### Packages

There are no packages available so far.

## Running the tests

After building the library from source just run `make test` in your `build`
folder.

## Building the doc

The doc is generated by doxygen, so you should have it installed.

```
doxygen Doxyfile
``` 

It creates a `doc` folder containing both `html` and `latex` version of the
documentation.

- To open the documentation in the browser, open the `doc/html/index.html` file.

- To open the pdf version :

```
cd doc/latex
make
```

The pdf is called `refman.pdf`.

## Authors

- Simon Petit - Initial contributer and only author so far.

## License

This library is under the GNU General Public License, see
[LICENSE](https://github.com/SiwonP/libsdp/blob/master/LICENSE) for details.
