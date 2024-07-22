#include "conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  reset_decimal(dst);
  if (src < 0) {
    set_sign(dst, MINUS);
    src = -src;
  }
  dst->bits[0] = src;
  return OK;
}
