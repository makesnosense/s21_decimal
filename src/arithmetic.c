#include "arithmetic.h"

#include "debug_funcs.h"
#include "s21_decimal.h"
#include "utility.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (input_is_correct(value_1, value_2, result) == false) {
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

  if (get_sign(value_1) == PLUS) {
    if (get_sign(value_2) == PLUS) {
      // (a) + (b) = a + b
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
    } else /* (a) + (- b) = a - b*/ {
      result_sign = subtract_long_mantissas(
          term_1_long_mantissa, term_2_long_mantissa, result_long_mantissa);
    }
  } else /* (-a) + (b) =  b - a */ {
    if (get_sign(value_2) == PLUS) {
      result_sign = subtract_long_mantissas(
          term_2_long_mantissa, term_1_long_mantissa, result_long_mantissa);
    } else /* (-a) + (-b) = - (a + b) */ {
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    }
  }
  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  compose_decimal(result_mantissa, bigger_scale, result_sign, result);
  result_add = catch_overflow(is_overflow, result_sign);
  return result_add;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (input_is_correct(value_1, value_2, result) == false) {
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
  if (get_sign(value_1) == PLUS) {
    if (get_sign(value_2) == PLUS) /* (a) - (b) = a - b */ {
      result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                            subtrahend_normalized_long_mantissa,
                                            result_long_mantissa);
    } else /* (a) - (- b) = a + b */ {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
    }
  } else /* (-a) - (b) =  - (a+b) */ {
    if (get_sign(value_2) == PLUS) {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    } else /* (-a) - (-b) = b - a */ {
      result_sign = subtract_long_mantissas(subtrahend_normalized_long_mantissa,
                                            minuend_normalized_long_mantissa,
                                            result_long_mantissa);
    }
  }
  uint32_t result_mantissa[3] = {0x0, 0x0, 0x0};
  bool is_overflow;
  downsize_mantissa(result_long_mantissa, &bigger_scale, result_mantissa,
                    &is_overflow);
  compose_decimal(result_mantissa, bigger_scale, result_sign, result);
  result_sub = catch_overflow(is_overflow, result_sign);
  return result_sub;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (input_is_correct(value_1, value_2, result) == false) {
    return INPUT_ERROR;
  }
  ArithmeticResult result_mul = OK;
  Sign result_sign = PLUS;
  bool is_overflow = false;

  s21_memset(result->bits, 0, sizeof(uint32_t) * 4);

  if (get_sign(value_1) != get_sign(value_2)) {
    result_sign = MINUS;
  }

  uint32_t mantissa_value_1[3] = {0};
  uint32_t mantissa_value_2[3] = {0};
  uint32_t long_mantissa_result[6] = {0};
  uint32_t mantissa_result[3] = {0};

  get_mantissa_from_decimal(mantissa_value_1, value_1);
  get_mantissa_from_decimal(mantissa_value_2, value_2);

  multiply_mantissas(mantissa_value_1, mantissa_value_2, long_mantissa_result);

  uint32_t initital_long_result[6] = {0};

  copy_long_mantissa(initital_long_result, long_mantissa_result);

  int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);
  int removed_digits = downsize_mantissa(long_mantissa_result, &scale_result,
                                         mantissa_result, &is_overflow);

  if (scale_result > 28) {
    int digits_to_remove = (scale_result - 28) + removed_digits;
    scale_result = 28;
    remove_digits_rounding_to_even(initital_long_result, digits_to_remove,
                                   mantissa_result);
  }
  compose_decimal(mantissa_result, scale_result, result_sign, result);
  result_mul = catch_overflow(is_overflow, result_sign);
  return result_mul;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (is_zero_decimal(value_2)) {
    if (result != NULL) {
      reset_decimal(result);
    }
    return DIVISION_BY_ZERO;
  }
  bool overflow = false;
  int value_1_scale = get_scale(value_1.bits[3]);
  int value_2_scale = get_scale(value_2.bits[3]);
  int scale_difference = value_1_scale - value_2_scale;
  int multiplier_scale;
  uint32_t* upscale_factor;

  if (scale_difference <= 0) {
    multiplier_scale = -scale_difference;
    upscale_factor = get_mantissa_with_power_of_ten(28);
  } else {
    multiplier_scale = 0;
    upscale_factor = get_mantissa_with_power_of_ten(28 - scale_difference);
  }
  uint32_t dividend[6] = {0};
  uint32_t divisor[6] = {0};
  multiply_mantissas(value_1.bits, upscale_factor, dividend);
  copy_mantissa(divisor, value_2.bits);

  uint32_t result_mantissa[6] = {0};
  uint32_t remainder[6] = {0};
  divide_long_mantissas(dividend, divisor, result_mantissa, remainder);

  if (multiplier_scale > 0) {
    overflow = multiply_division_result(result_mantissa, remainder, divisor,
                                        multiplier_scale);
  }
  uint32_t downsized_result_mantissa[3] = {0};
  int result_scale = downsize_division_result(
      result_mantissa, remainder, divisor, downsized_result_mantissa);
  normalize_division_result(downsized_result_mantissa, &result_scale,
                            value_1_scale);
  Sign result_sign = PLUS;
  if (get_sign(value_1) != get_sign(value_2)) {
    result_sign = MINUS;
  }
  ArithmeticResult result_code = catch_overflow(overflow, result_sign);
  if (result_code == OK) {
    compose_decimal(downsized_result_mantissa, result_scale, result_sign,
                    result);
  }
  return result_code;
}

bool input_is_correct(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal* result) {
  return (result != NULL && decimal_service_part_is_correct(value_1) &&
          decimal_service_part_is_correct(value_2));
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

void compose_decimal(uint32_t* mantissa, int scale, Sign sign,
                     s21_decimal* decimal) {
  memset(decimal, 0, sizeof(s21_decimal));
  copy_mantissa(decimal->bits, mantissa);
  set_sign(decimal, sign);
  set_scale(&decimal->bits[3], scale);
}

bool multiply_division_result(uint32_t* result, uint32_t* remainder,
                              uint32_t* divisor, int multiplier_scale) {
  bool overflow = false;
  uint32_t* multiplier = get_mantissa_with_power_of_ten(multiplier_scale);
  overflow = multiply_long_mantissas(result, multiplier, result);
  uint32_t additional_digits[6] = {0};
  multiply_long_mantissas(remainder, multiplier, remainder);
  divide_long_mantissas(remainder, divisor, additional_digits, remainder);
  add_long_mantissas(result, additional_digits, result);

  // max_mantissa * 10^28
  uint32_t* max_upscaled_mantissa = get_max_upscaled_mantissa();
  if (compare_long_mantissas(result, max_upscaled_mantissa) > 0) {
    overflow = true;
  }
  return overflow;
}

int downsize_division_result(uint32_t* long_mantissa, uint32_t* remainder,
                             uint32_t* divisor, uint32_t* mantissa) {
  int result_scale = 28;
  uint32_t rounded_long_mantissa[6];
  int digits = count_long_mantissa_digits(long_mantissa);
  int digits_to_remove = digits - 29;
  if (digits_to_remove <= 0) {
    if (!long_mantissa_is_zero(remainder)) {
      round_division_result_to_even(long_mantissa, remainder, divisor,
                                    rounded_long_mantissa);
    } else {
      copy_long_mantissa(rounded_long_mantissa, long_mantissa);
    }
  } else {
    result_scale -= digits_to_remove;
    if (long_mantissa_is_zero(remainder)) {
      remove_digits_rounding_to_even(long_mantissa, digits_to_remove,
                                     rounded_long_mantissa);
    } else {
      remove_digits_rounding_half_up(long_mantissa, digits_to_remove,
                                     rounded_long_mantissa);
    }
  }
  uint32_t* max_mantissa = get_max_mantissa();
  if (compare_long_mantissas(rounded_long_mantissa, max_mantissa) > 0) {
    digits_to_remove += 1;
    result_scale -= 1;
    if (long_mantissa_is_zero(remainder)) {
      remove_digits_rounding_to_even(long_mantissa, digits_to_remove,
                                     rounded_long_mantissa);
    } else {
      remove_digits_rounding_half_up(long_mantissa, digits_to_remove,
                                     rounded_long_mantissa);
    }
  }
  copy_mantissa(mantissa, rounded_long_mantissa);
  return result_scale;
}

void round_division_result_to_even(uint32_t* result, uint32_t* remainder,
                                   uint32_t* divisor,
                                   uint32_t* rounded_result) {
  uint32_t first_fraction_digit[6] = {0};
  uint32_t temp_remainder[6] = {0};
  uint32_t* ten = get_mantissa_with_power_of_ten(1);
  multiply_long_mantissas(remainder, ten, temp_remainder);
  divide_long_mantissas(temp_remainder, divisor, first_fraction_digit,
                        temp_remainder);
  uint32_t* one = get_mantissa_with_power_of_ten(0);
  if (first_fraction_digit[0] == 5) {
    if (!long_mantissa_is_zero(temp_remainder)) {
      add_long_mantissas(result, one, rounded_result);
    } else {
      if (result[0] & 1) {
        add_long_mantissas(result, one, rounded_result);
      } else {
        copy_long_mantissa(rounded_result, result);
      }
    }
  } else if (first_fraction_digit[0] > 5) {
    add_long_mantissas(result, one, rounded_result);
  } else {
    copy_long_mantissa(rounded_result, result);
  }
}

void normalize_division_result(uint32_t* result, int* scale,
                               int dividend_scale) {
  uint32_t last_digit[3] = {0};
  uint32_t temp_result[3] = {0};
  uint32_t* ten = get_mantissa_with_power_of_ten(1);

  divide_mantissas(result, ten, temp_result, last_digit);
  while (last_digit[0] == 0 && (*scale > dividend_scale)) {
    *scale -= 1;
    copy_mantissa(result, temp_result);
    divide_mantissas(result, ten, temp_result, last_digit);
  }
}
