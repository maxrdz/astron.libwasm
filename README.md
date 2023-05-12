<img src="logo/astron.libwasm.png" align="right" width="50%"/>

astron.libwasm
==============

![](https://img.shields.io/discord/1066973060357443644?color=blue&label=Discord&logo=discord&logoColor=white) ![](https://img.shields.io/github/last-commit/Max-Rodriguez/astron.libwasm) ![](https://img.shields.io/github/license/Max-Rodriguez/astron.libwasm)

An open-source implementation of the Astron client  protocol for C++ applications targeting Web Assembly.

This implementation will only be targeting Web Assembly,
as it is portable to any operating system and any
architecture that is supported by a Javascript engine. (Chrome v8, NodeJS)

# Building from Source

Before compiling the source code, you first need to generate the Makefile using CMake.
NOTE: You need to run `emcmake` to run cmake so that it sets the various
environment variables that are needed for CMake to generate for the em++ compiler.

To configure & build for release, run the following commands:

```bash
$ emcmake cmake . -Bbuild-release -DCMAKE_BUILD_TYPE=Release
$ cd build-release && make
```

It is required that you have the Emscripten SDK installed in your system
and added to your PATH in order to use the tools from the emsdk.

# Contributing

Before writing your first contribution, please make sure to read the [contributing guidelines](CONTRIBUTING.md).

Note for contributors: To regenerate the parser / lexer in `src/dcparser`,
please use the following commands inside the `src/dcparser` directory:

```bash
$ bison dcParser.yxx -o dcParser.cxx --header
$ flex --outfile dcLexer.cxx dcLexer.lxx
```

# Reporting Vulnerabilities

Please read the [security policy](SECURITY.md) document for more information on reporting software vulnerabilities.
