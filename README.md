<img src="logo/astron.libwasm.png" align="right" width="50%"/>

astron.libwasm
==============

![](https://img.shields.io/discord/1066973060357443644?color=blue&label=Discord&logo=discord&logoColor=white) ![](https://img.shields.io/github/last-commit/Max-Rodriguez/astron.libwasm) ![](https://img.shields.io/github/license/Max-Rodriguez/astron.libwasm)

An open-source implementation of the Astron client  protocol for C++ applications targeting Web Assembly.

This implementation will only be targeting Web Assembly,
as it is portable to any operating system and any
architecture that is supported by a Javascript engine. (Chrome v8, NodeJS)

For the internal (server-side) implementation of Astron, check out [astron.libts](https://github.com/Max-Rodriguez/astron.libts).

# Building from Source

Before compiling the source code, you first need to generate the Makefile using CMake.
**NOTE:** You need to run `emcmake` to run cmake so that it sets the various
environment variables that are needed for CMake to generate for the em++ compiler.

**It is required** that you have the Emscripten SDK installed in your system
and added to your PATH in order to use the tools from the emsdk.

**On Linux:** To configure & build for release, run the following commands:

```bash
$ emcmake cmake . -Bbuild-release -DCMAKE_BUILD_TYPE=Release
$ cd build-release && make
```

astron.libwasm is always compiled as a static library, not Web Assembly. It is compiled with Emscripten
so that your own application can be linked with this static library and target Web Assembly.

# Troubleshooting

When using astron.libwasm, all output is flushed to the JavaScript console. In most browsers, pressing the F12 key should open this console.

**For astron.libwasm developers**, it is recommended that you compile with `-DCMAKE_BUILD_TYPE=Debug` as this disables
all compiler / linker optimizations and compiles with Clang's undefined behavior & address sanitizers (UBSan & ASan) for catching bugs faster.
There is a considerable performance and size penalty to doing this; expect a larger static library!

# Contributing

Before writing your first contribution, please make sure to read the [contributing guidelines](CONTRIBUTING.md).

**For astron.libwasm developers:** To regenerate the parser / lexer in `src/dcfile`,
please use the following commands inside the `src/dcfile` directory:

```bash
$ bison dcParser.yxx -o dcParser.cxx --header
$ flex --outfile dcLexer.cxx dcLexer.lxx
```

# Reporting Vulnerabilities

Please read the [security policy](SECURITY.md) document for more information on reporting software vulnerabilities.
