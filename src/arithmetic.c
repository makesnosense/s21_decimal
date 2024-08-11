#include "arithmetic.h"

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);
  ArithmeticResult result_add = OK;

  uint32_t term_1_long_mantissa[6] = {0};
  uint32_t term_2_long_mantissa[6] = {0};
  uint32_t result_long_mantissa[6] = {0};

  int bigger_scale = cast_decimals_to_normalized_mantissas(
      value_1, term_1_long_mantissa, value_2, term_2_long_mantissa);

  int result_sign = PLUS;

  // (a) + (b) = a + b
  if (get_sign(value_1) == PLUS && get_sign(value_2) == PLUS) {
    add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                       result_long_mantissa);
  }
  // (-a) + (b) =  b - a
  else if (get_sign(value_1) == MINUS && get_sign(value_2) == PLUS) {
    result_sign = subtract_long_mantissas(
        term_2_long_mantissa, term_1_long_mantissa, result_long_mantissa);
  }
  // (a) + (- b) = a - b
  else if (get_sign(value_1) == PLUS && get_sign(value_2) == MINUS) {
    result_sign = subtract_long_mantissas(
        term_1_long_mantissa, term_2_long_mantissa, result_long_mantissa);
  }
  // (-a) + (-b) = - (a + b)
  else {
    add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                       result_long_mantissa);
    result_sign = MINUS;
  }

  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};

  bool is_overflow =
      downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa);

  write_in_mantissa_to_decimal(result_mantissa, result);

  set_scale(&result->bits[3], bigger_scale);

  set_sign(result, (Sign)result_sign);

  if (is_overflow) {
    if (result_sign == PLUS) {
      result_add = TOO_BIG;
    } else {
      result_add = TOO_SMALL;
    }
  }
  return result_add;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  ArithmeticResult result_sub = OK;

  uint32_t minuend_normalized_long_mantissa[6] = {0};
  uint32_t subtrahend_normalized_long_mantissa[6] = {0};
  uint32_t result_long_mantissa[6] = {0};

  int bigger_scale = cast_decimals_to_normalized_mantissas(
      value_1, minuend_normalized_long_mantissa, value_2,
      subtrahend_normalized_long_mantissa);
  int result_sign = PLUS;

  // (a) - (b) = a - b
  if (get_sign(value_1) == PLUS && get_sign(value_2) == PLUS) {
    result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                          subtrahend_normalized_long_mantissa,
                                          result_long_mantissa);
    // (-a) - (b) =  - (a+b)
  } else if (get_sign(value_1) == MINUS && get_sign(value_2) == PLUS) {
    add_long_mantissas(minuend_normalized_long_mantissa,
                       subtrahend_normalized_long_mantissa,
                       result_long_mantissa);
    result_sign = MINUS;
    // (a) - (- b) = a + b
  } else if (get_sign(value_1) == PLUS && get_sign(value_2) == MINUS) {
    add_long_mantissas(minuend_normalized_long_mantissa,
                       subtrahend_normalized_long_mantissa,
                       result_long_mantissa);
    result_sign = PLUS;
    // (-a) - (-b) = b - a
  } else {
    result_sign = subtract_long_mantissas(subtrahend_normalized_long_mantissa,
                                          minuend_normalized_long_mantissa,
                                          result_long_mantissa);
  }

  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};

  bool is_overflow =
      downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa);

  write_in_mantissa_to_decimal(result_mantissa, result);

  set_scale(&result->bits[3], bigger_scale);

  set_sign(result, (Sign)result_sign);

  if (is_overflow) {
    if (result_sign == PLUS) {
      result_sub = TOO_BIG;
    } else {
      result_sub = TOO_SMALL;
    }
  }
  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  ArithmeticResult result_mul = OK;
  Sign result_sign = PLUS;
  bool is_overflow = false;

  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  if ((get_sign(value_1) == PLUS && get_sign(value_2) == MINUS) ||
      (get_sign(value_1) == MINUS && get_sign(value_2) == PLUS)) {
    result_sign = MINUS;
  }

  if (is_zero_decimal(value_1) || is_zero_decimal(value_2)) {
    reset_decimal(result);
  } else if (is_one_decimal(value_1) || is_one_decimal(value_2)) {
    if (is_one_decimal(value_1)) {
      copy_decimal(&value_2, result);
    } else {
      copy_decimal(&value_1, result);
    }
    set_sign(result, result_sign);
  } else {
    uint32_t mantissa_value_1[3] = {0};
    uint32_t mantissa_value_2[3] = {0};
    uint32_t long_mantissa_result[6] = {0};
    uint32_t mantissa_result[3] = {0};
    get_mantissa_from_decimal(mantissa_value_1, &value_1);
    get_mantissa_from_decimal(mantissa_value_2, &value_2);
    multiply_mantissas(mantissa_value_1, mantissa_value_2,
                       long_mantissa_result);

    int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);

    is_overflow =
        downsize_mantissa(long_mantissa_result, &scale_result, mantissa_result);

    set_scale(&result->bits[3], scale_result);
    set_sign(result, result_sign);
    write_in_mantissa_to_decimal(mantissa_result, result);
  }

  if (is_overflow) {
    if (result_sign == PLUS) {
      result_mul = TOO_BIG;
    } else {
      result_mul = TOO_SMALL;
    }
  }

  return result_mul;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (1 == 0) {
    printf("%d", value_1.bits[0]);
    printf("%d", value_2.bits[0]);
    printf("%d", result->bits[0]);
  }
  return 0;
}
