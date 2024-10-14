# s21_decimal

A C library for high-precision decimal arithmetic, supporting numbers up to ±79228162514264337593543950335 (equivalent to three 0xFFFFFFFFs). 

**Library is developed as a practice project at School 21 (formerly 42.fr)**.

## Features

- Custom decimal data type (`s21_decimal`) for precise arithmetic
- Arithmetic operations: addition, subtraction, multiplication, division
- Comparison functions
- Type conversion utilities
- Rounding and truncation operations

## Installation

To use the s21_decimal library in your project:

1. Clone the repo and build the library:
```bash
git clone https://github.com/makesnosense/s21_decimal.git
cd s21_decimal/src
make
```
2. Include the header file in your C project:
```c
#include "s21_decimal.h"
```
3. Link against the built library when compiling your project. Replace `/path/to/library/directory` with the actual path where `s21_decimal.a` is located:
```bash
gcc your_program.c -L/path/to/library/directory -ls21_decimal -o your_program
```

## Testing
```bash
git clone https://github.com/makesnosense/s21_decimal.git
cd s21_decimal/src
```

To run test suites ([Check](https://github.com/libcheck/check) library required):
```bash
make test
```

To generate a code coverage report (requires [GCOVR](https://github.com/gcovr/gcovr) library):
```bash
make gcov_report
```

## Test Generator
The project includes a test generator (s21_decimal/tests_generator/decimal.ipynb) implemented as a Jupyter Notebook. To use it:
- Open decimal.ipynb in Jupyter Notebook or JupyterLab
- Run the cells to generate test cases 
- Copy the generated test cases from tests_body.txt and addition.txt into your test files

## API Reference

### Arithmetic
```c
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result)
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result)
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result)
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result)
```
### Comparison
```c
int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2)
int s21_is_less_or_equal(s21_decimal decimal_1, s21_decimal decimal_2)
int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2)
int s21_is_greater_or_equal(s21_decimal decimal_1, s21_decimal decimal_2)
int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2)
int s21_is_not_equal(s21_decimal decimal_1, s21_decimal decimal_2)
```
### Conversion
```c
int s21_from_int_to_decimal(int src, s21_decimal* dst)
int s21_from_float_to_decimal(float src, s21_decimal* dst)
int s21_from_decimal_to_int(s21_decimal src, int* dst)
int s21_from_decimal_to_float(s21_decimal src, float* dst)
```
### Other operations
```c
int s21_floor(s21_decimal value, s21_decimal* result)
int s21_round(s21_decimal value, s21_decimal* result)
int s21_truncate(s21_decimal value, s21_decimal* result)
int s21_negate(s21_decimal value, s21_decimal* result)
```