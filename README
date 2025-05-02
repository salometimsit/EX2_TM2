# Matrix Operators Assigment

## Overview 
The Squaremat library provides a powerful and flexible implementation of square matrices in C++. It enables mathematical operations on square matrices of arbitrary size with an intuitive operator-based interface.

## Features
- Dynamic allocation of square matrices of any size
- Comprehensive set of mathematical operations:
  - Addition and subtraction (`+`, `-`, `+=`, `-=`)
  - Matrix multiplication (`*`, `*=`)
  - Scalar multiplication and division (`*`, `/`, `*=`)
  - Matrix division (multiplication by inverse)
  - Element-wise increment and decrement (`++`, `--`)
  - Matrix transposition (`~`)
  - Modulo operations (`%`, `%=`)
  - Matrix exponentiation (`^`)
  - Matrix inversion
  - Determinant calculation (`!`)
- Comparison operators based on sum of elements (`==`, `!=`, `<`, `<=`, `>`, `>=`)
- Memory-safe implementation with proper constructors, destructors, and assignment operators

## Requirements
- C++ compiler with C++11 support or later
- Standard C++ libraries (iostream, cmath)

## Installation
This is a header-only library. To use the Squaremat library in your project:

1. Copy `Squaremat.hpp` and `Squaremat.cpp` to your project directory
2. Include the header file in your source code:
```cpp
#include "Squaremat.hpp"
```
3. Compile your project with the implementation file:
```
make 
./main
./test
```


## API Reference

### Constructors and Destructors
- `Squaremat(int s)` - Create a square matrix of size s×s filled with zeros
- `Squaremat(const Squaremat& other)` - Copy constructor
- `~Squaremat()` - Destructor that properly frees all allocated memory

### Getters
- `int getsize() const` - Returns the size of the matrix
- `double** getmat() const` - Returns the internal 2D array

### Matrix Operations
- `Squaremat& operator=(const Squaremat& other)` - Assignment operator
- `Squaremat operator+(const Squaremat& other) const` - Matrix addition
- `Squaremat& operator+=(const Squaremat& other)` - Matrix addition assignment
- `Squaremat operator-(const Squaremat& other) const` - Matrix subtraction
- `Squaremat& operator-=(const Squaremat& other)` - Matrix subtraction assignment
- `Squaremat operator*(const Squaremat& other) const` - Matrix multiplication
- `Squaremat& operator*=(const Squaremat& other)` - Matrix multiplication assignment
- `Squaremat operator/(const Squaremat& other) const` - Matrix division (by inverse)
- `Squaremat& operator/=(const Squaremat& other)` - Matrix division assignment
- `Squaremat operator~() const` - Matrix transpose
- `Squaremat operator-() const` - Negate all elements
- `Squaremat operator^(int n) const` - Matrix exponentiation
- `Squaremat inversematrix() const` - Calculate matrix inverse
- `double operator!() const` - Calculate determinant

### Scalar Operations
- `Squaremat operator*(double n) const` - Scalar multiplication
- `Squaremat& operator*=(double n)` - Scalar multiplication assignment
- `Squaremat operator/(double n) const` - Scalar division
- `Squaremat operator%(int n) const` - Modulo with scalar
- `Squaremat& operator%=(int n)` - Modulo assignment with scalar

### Element-wise Operations
- `Squaremat& operator++()` - Pre-increment (add 1 to all elements)
- `Squaremat operator++(int)` - Post-increment
- `Squaremat& operator--()` - Pre-decrement (subtract 1 from all elements)
- `Squaremat operator--(int)` - Post-decrement
- `Squaremat operator%(const Squaremat& other) const` - Element-wise modulo
- `Squaremat& operator%=(const Squaremat& other)` - Element-wise modulo assignment

### Comparison Operators (based on sum of elements)
- `bool operator==(const Squaremat& other) const`
- `bool operator!=(const Squaremat& other) const`
- `bool operator<(const Squaremat& other) const`
- `bool operator<=(const Squaremat& other) const`
- `bool operator>(const Squaremat& other) const`
- `bool operator>=(const Squaremat& other) const`

### Element Access
- `double* operator[](int x)` - Access row (for writing)
- `const double* operator[](int x) const` - Access row (for reading)

### Helper Methods
- `Squaremat deletee(const Squaremat& m, int row, int col) const` - Helper for creating submatrices

### Global Operators
- `std::ostream& operator<<(std::ostream& os, const Squaremat& mat)` - Stream output for printing

## Implementation Details
- All matrices are dynamically allocated using a double pointer approach
- Matrix properties are validated at runtime (e.g., matching sizes for operations)
- Exception handling for invalid operations
- The determinant calculation uses the cofactor expansion method
- Matrix inversion uses the adjugate method
- Matrix exponentiation uses binary exponentiation for efficiency

## Notes on Comparison Operators
The comparison operators (`==`, `!=`, `<`, `<=`, `>`, `>=`) compare matrices based on the sum of all elements rather than the traditional element-by-element comparison. This provides an ordering for matrices that might be useful in some contexts but is not the standard mathematical definition of matrix equality.
## WEBSITES I USED FOR HELP:
- matrix devision- https://www.wikihow.com/Divide-Matrices#:~:text=Understand%20matrix%20%22division.%22%20Technically,matrix%20is%20an%20undefined%20function.&text=The%20closest%20equivalent%20is%20multiplying,*%20%5BB%5D%2D1.
- Claude- helped me document and write the readme file only- here is the prompt: 
https://claude.ai/share/8c42f6f8-9f58-4c86-8cbe-903cfd48cb58
- The rest of my knowledge came from the course Linear Algebra 1, Ariel's University


## Author
Contact: timsitmelosa@gmail.com
