# Advent of Code 2023

## Configure and build the project

Assuming the following **CMakeUserPresets.json**:

``` json
{
  "version": 4,
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "toolchainFile": "${sourceDir}/cmake/toolchain-gcc.cmake",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "TRUE"
      }
    }
  ],
  "buildPresets": [
    {
      "name": "default",
      "configurePreset": "default"
    }
  ],
  "testPresets": [
    {
      "name": "default",
      "configurePreset": "default"
    }
  ]
}
```

Configure with:

``` shell
cmake --preset default .
```

Then build:

``` shell
cmake --build build --config Debug --target all
```

## Run puzzle solvers

``` shell
# day 1 puzzle 2
build/advent23 1.2
```
