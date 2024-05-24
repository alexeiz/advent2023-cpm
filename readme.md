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
      "cacheVariables": {
        "CMAKE_EXPORT_COMPILE_COMMANDS": "TRUE",
        "CMAKE_C_COMPILER": "gcc-14",
        "CMAKE_CXX_COMPILER": "g++-14"
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
