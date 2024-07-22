#include "helper_funcs.h"

#include "stdbool.h"

int get_bit(uint32_t input_uint, size_t position) {
  return (input_uint >> position) & 1;
}
