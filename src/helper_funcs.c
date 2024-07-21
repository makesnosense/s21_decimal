#include "helper_funcs.h"

void print_binary(u_int32_t input_num) {
  u_int32_t mask = 0x80000000;
  putchar('\n');
  for (size_t i = 0; i < 32; i++) {
    if ((i != 0) && (i % 4 == 0)) {
      putchar(' ');
    }

    (input_num & mask) ? putchar('1') : putchar('0');

    mask >>= 1;
  }
  putchar('\n');
}