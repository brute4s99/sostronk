# SoStronk - matchmaking solution

## Problem Statement

<p> <a href="problem.pdf">Please open the PDF to view the problem statement</a>.</p>

## Build Instructions

The solution is set up as a CMake project.

### On Linux

1. To configure use: -
```
cd solution
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=~/brute4s99 ..
```
(please do note the two dots in the end of the last command ^)

2. To build use: -
```
make -j8 install
```

## How to test

1. To build the project use: -
```
cmake -DCMAKE_INSTALL_PREFIX=~/brute4s99 ..
 
make
```
2. To run the tests use: -
```
make tests
```

## How to use

- You can find the binary for my solution installed in `matchmake` in `~/brute4s99/bin/` after performing the build instructions.


## License

none