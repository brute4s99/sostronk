# SoStronk - matchmaking solution

## Problem Statement

<p> <a href="problem.pdf">Please open the PDF to view the problem statement</a>.</p>

## Build Instructions

The solution is set up as a CMake project.

### On Linux

1. To configure use: -
```
cd solution
mkdir
cd build
cmake ..
```
(please do note the two dots in the end of the last command ^)

2. To build use: -
```
make -j8
```

## How to test

1. To configure & build use: -
```
cmake ..
make
```

2. To run tests use: -
```
make tests
```

## How to use

- You can find the binary for my solution with the file name `matchmake` in `build/src/` after performing the build instructions.

## License

none