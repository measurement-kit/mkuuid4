# Measurement Kit UUID4 library

[![GitHub license](https://img.shields.io/github/license/measurement-kit/mkuuid4.svg)](https://raw.githubusercontent.com/measurement-kit/mkuuid4/master/LICENSE) [![Github Releases](https://img.shields.io/github/release/measurement-kit/mkuuid4.svg)](https://github.com/measurement-kit/mkuuid4/releases) [![Build Status](https://img.shields.io/travis/measurement-kit/mkuuid4/master.svg?label=travis)](https://travis-ci.org/measurement-kit/mkuuid4) [![codecov](https://codecov.io/gh/measurement-kit/mkuuid4/branch/master/graph/badge.svg)](https://codecov.io/gh/measurement-kit/mkuuid4) [![Build status](https://img.shields.io/appveyor/ci/bassosimone/mkuuid4/master.svg?label=appveyor)](https://ci.appveyor.com/project/bassosimone/mkuuid4/branch/master)

This header-only library contains Measurement Kit UUID4 code. Its main
use case is vendoring of a specific tag inside Measurement Kit. Because this
is just a basic building block, we do not provide any stable API guarantee
for this library. For this reason, we'll never release `v1.0.0`.

## Regenerating build files

Possibly edit `MKBuild.yaml`, then run:

```
go get -v github.com/measurement-kit/mkbuild
mkbuild
```

## Building

```
mkdir build
cd build
cmake -GNinja ..
cmake --build .
ctest -a -j8 --output-on-failure
```

## Testing with docker

```
./docker.sh <build-type>
```
