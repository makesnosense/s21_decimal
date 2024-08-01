#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

void print_binary(uint32_t input_uint);
void print_binary_without_spaces(uint32_t input_uint);
void debug_printf(const char* format, ...);
void debug_print_decimal_as_binary(s21_decimal input_decimal);
void debug_print_decimal_as_binary_in_one_line(s21_decimal input_decimal);
void debug_print_mantissa_as_binary(uint32_t* mantissa_parts,
                                    int mantissa_size);
