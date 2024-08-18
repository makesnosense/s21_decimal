#include "arithmetic.h"

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (result == NULL || decimal_service_part_is_correct(value_1) == false ||
      decimal_service_part_is_correct(value_2) == false) {
    return INPUT_ERROR;
  }
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
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  write_in_mantissa_to_decimal(result_mantissa, result);
  set_scale(&result->bits[3], bigger_scale);
  set_sign(result, (Sign)result_sign);
  result_add = catch_overflow(is_overflow, result_sign);

  return result_add;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (result == NULL || decimal_service_part_is_correct(value_1) == false ||
      decimal_service_part_is_correct(value_2) == false) {
    return INPUT_ERROR;
  }
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
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  write_in_mantissa_to_decimal(result_mantissa, result);
  set_scale(&result->bits[3], bigger_scale);
  set_sign(result, (Sign)result_sign);
  result_sub = catch_overflow(is_overflow, result_sign);

  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (result == NULL || decimal_service_part_is_correct(value_1) == false ||
      decimal_service_part_is_correct(value_2) == false) {
    return INPUT_ERROR;
  }

  ArithmeticResult result_mul = OK;
  Sign result_sign = PLUS;
  bool is_overflow = false;

  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  if (get_sign(value_1) != get_sign(value_2)) {
    result_sign = MINUS;
  }

  if (is_zero_decimal(value_1) == false && is_zero_decimal(value_2) == false) {
    if (is_one_decimal(value_1) || is_one_decimal(value_2)) {
      if (is_one_decimal(value_1)) {
        copy_decimal(&value_2, result);
      } else {
        copy_decimal(&value_1, result);
      }
    } else {
      result_mul = actually_multiply(value_1, value_2, &is_overflow,
                                     result_sign, result);
    }
  }

  set_sign(result, result_sign);

  return result_mul;
}

ArithmeticResult actually_multiply(s21_decimal value_1, s21_decimal value_2,
                                   bool* is_overflow, Sign result_sign,
                                   s21_decimal* result) {
  ArithmeticResult result_mul = OK;
  uint32_t mantissa_value_1[3] = {0};
  uint32_t mantissa_value_2[3] = {0};
  uint32_t long_mantissa_result[6] = {0};
  uint32_t mantissa_result[3] = {0};

  get_mantissa_from_decimal(mantissa_value_1, &value_1);
  get_mantissa_from_decimal(mantissa_value_2, &value_2);

  multiply_mantissas(mantissa_value_1, mantissa_value_2, long_mantissa_result);

  uint32_t initital_long_result[6] = {0};

  copy_long_mantissa(initital_long_result, long_mantissa_result);

  int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);
  int removed_digits = downsize_mantissa(long_mantissa_result, &scale_result,
                                         mantissa_result, is_overflow);

  if (scale_result > 28) {
    int digits_to_remove = (scale_result - 28) + removed_digits;
    scale_result = 28;
    remove_digits_rounding_to_even(initital_long_result, digits_to_remove);
    copy_mantissa(mantissa_result, initital_long_result);
  }

  set_scale(&result->bits[3], scale_result);
  write_in_mantissa_to_decimal(mantissa_result, result);

  result_mul = catch_overflow(*is_overflow, result_sign);
  return result_mul;
}

ArithmeticResult catch_overflow(bool is_overflow, Sign result_sign) {
  ArithmeticResult arithmetic_result = OK;
  if (is_overflow) {
    if (result_sign == PLUS) {
      arithmetic_result = TOO_BIG;
    } else {
      arithmetic_result = TOO_SMALL;
    }
  }
  return arithmetic_result;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (1 == 0) {
    printf("%d", value_1.bits[0]);
    printf("%d", value_2.bits[0]);
    printf("%d", result->bits[0]);
  }
  return 0;
}
