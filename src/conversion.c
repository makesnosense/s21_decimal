#include "conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  ConversionResult result = OK;
  if (dst == NULL) {
    result = CONVERSION_ERROR;
  } else {
    reset_decimal(dst);
    if (src < 0) {
      set_sign(dst, MINUS);
      dst->bits[0] = -src;
    } else {
      dst->bits[0] = src;
    }
  }

  return result;
}
