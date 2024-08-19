#include "debug_funcs.h"

void print_binary(uint32_t input_num) {
  uint32_t mask = 0x80000000;
  for (size_t i = 0; i < 32; i++) {
    if ((i != 0) && (i % 4 == 0)) {
      putchar(' ');
    }
    (input_num & mask) ? putchar('1') : putchar('0');
    mask >>= 1;
  }
}

void print_binary_without_spaces(uint32_t input_num) {
  uint32_t mask = 0x80000000;
  for (size_t i = 0; i < 32; i++) {
    (input_num & mask) ? putchar('1') : putchar('0');
    mask >>= 1;
  }
}

void debug_printf(const char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

void debug_print_decimal_as_binary(s21_decimal input_decimal) {
  for (int i = 3; i >= 0; i--) {
    print_binary(input_decimal.bits[i]);
    putchar('\n');
  }
}

void debug_print_decimal_as_binary_in_one_line(s21_decimal input_decimal) {
  for (int i = 3; i >= 0; i--) {
    print_binary_without_spaces(input_decimal.bits[i]);
    if (i == 3) {
      putchar(' ');
    }
  }
  putchar('\n');
}

void debug_print_mantissa_as_binary(uint32_t* mantissa_parts,
                                    int mantissa_size) {
  for (int i = mantissa_size - 1; i >= 0; i--) {
    print_binary_without_spaces(mantissa_parts[i]);
  }
  putchar('\n');
}

void debug_print_mantissa_as_hex(uint32_t* mantissa_parts, int mantissa_size) {
  for (int i = mantissa_size - 1; i >= 0; i--) {
    printf("%08X", mantissa_parts[i]);
  }
  putchar('\n');
}
