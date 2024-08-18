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
    // (a) + (b) = a + b
    if (get_sign(value_2) == PLUS) {
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
    }
    // (a) + (- b) = a - b
    else {
      result_sign = subtract_long_mantissas(
          term_1_long_mantissa, term_2_long_mantissa, result_long_mantissa);
    }
  } else {
    // (-a) + (b) =  b - a
    if (get_sign(value_2) == PLUS) {
      result_sign = subtract_long_mantissas(
          term_2_long_mantissa, term_1_long_mantissa, result_long_mantissa);
    }
    // (-a) + (-b) = - (a + b)
    else {
      add_long_mantissas(term_1_long_mantissa, term_2_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    }
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
    // // (a) - (b) = a - b
    if (get_sign(value_2) == PLUS) {
      result_sign = subtract_long_mantissas(minuend_normalized_long_mantissa,
                                            subtrahend_normalized_long_mantissa,
                                            result_long_mantissa);
    }
    // (a) - (- b) = a + b
    else {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
    }
  } else {
    // (-a) - (b) =  - (a+b)
    if (get_sign(value_2) == PLUS) {
      add_long_mantissas(minuend_normalized_long_mantissa,
                         subtrahend_normalized_long_mantissa,
                         result_long_mantissa);
      result_sign = MINUS;
    }  // (-a) - (-b) = b - a
    else {
      result_sign = subtract_long_mantissas(subtrahend_normalized_long_mantissa,
                                            minuend_normalized_long_mantissa,
                                            result_long_mantissa);
    }
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

  get_mantissa_from_decimal(mantissa_value_1, value_1);
  get_mantissa_from_decimal(mantissa_value_2, value_2);

  multiply_mantissas(mantissa_value_1, mantissa_value_2, long_mantissa_result);

  uint32_t initital_long_result[6] = {0};

  copy_long_mantissa(initital_long_result, long_mantissa_result);

  int scale_result = get_scale(value_1.bits[3]) + get_scale(value_2.bits[3]);
  int removed_digits = downsize_mantissa(long_mantissa_result, &scale_result,
                                         mantissa_result, is_overflow);

  if (scale_result > 28) {
    int digits_to_remove = (scale_result - 28) + removed_digits;
    scale_result = 28;
    remove_digits_rounding_to_even(initital_long_result, digits_to_remove,
                                   mantissa_result);
  }

  set_scale(&result->bits[3], scale_result);
  write_in_mantissa_to_decimal(mantissa_result, result);

  result_mul = catch_overflow(*is_overflow, result_sign);
  return result_mul;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  if (input_is_correct(value_1, value_2, result) == false) {
    return INPUT_ERROR;
  }

  ArithmeticResult result_code = OK;

  memset(result, 0, sizeof(s21_decimal));

  if (is_zero_decimal(value_2)) {
    result_code = DIVISION_BY_ZERO;
    return result_code;
  }

  uint32_t* upscale_multiplier;

  int result_scale = get_scale(value_1.bits[3]) - get_scale(value_2.bits[3]);
  int temp_scale = 28;
  int exponent;
  bool overflow = 0;

  if (result_scale <= 0) {
    exponent = -result_scale;
    upscale_multiplier = get_mantissa_with_power_of_ten(28);
  } else {
    exponent = 0;
    upscale_multiplier = get_mantissa_with_power_of_ten(28 - result_scale);
  }

  uint32_t divident[6] = {0};
  uint32_t divider[6] = {0};
  uint32_t result_mantissa[6] = {0};
  uint32_t rounded_result_mantissa[6] = {0};
  uint32_t remainder[6] = {0};

  multiply_mantissas(value_1.bits, upscale_multiplier, divident);
  copy_mantissa(divider, value_2.bits);

  divide_long_mantissas(divident, divider, result_mantissa, remainder);

  /*   debug_print_mantissa_as_hex(result_mantissa, 6);
    puts("\n"); */

  uint32_t* max_mantissa = get_max_mantissa();
  // max_mantissa * 10^28
  uint32_t max_upscaled_mantissa[6] = {0xF0000000, 0xC1DAFD9E, 0xDFB031A1,
                                       0xFFFFFFF,  0x3E250261, 0x204FCE5E};

  uint32_t multiplied_result[6] = {0};
  if (exponent > 0) {
    overflow = multiply_long_mantissas(result_mantissa,
                                       get_mantissa_with_power_of_ten(exponent),
                                       multiplied_result);
    uint32_t multiplied_remainder[6] = {0};
    uint32_t additional_digits[6] = {0};
    multiply_long_mantissas(remainder, get_mantissa_with_power_of_ten(exponent),
                            multiplied_remainder);
    divide_long_mantissas(multiplied_remainder, divider, additional_digits,
                          remainder);
    add_long_mantissas(multiplied_result, additional_digits, result_mantissa);

    if (compare_long_mantissas(result_mantissa, max_upscaled_mantissa) > 0) {
      overflow = true;
    };
    // debug_print_mantissa_as_hex(result_mantissa, 6);
  }

  int digits = count_long_mantissa_digits(result_mantissa);
  int digits_to_remove = digits - 29;
  // puts("print:");
  // debug_print_mantissa_as_hex(result_mantissa, 6);
  // printf("\nremove: %d\n", digits_to_remove);
  // debug_print_mantissa_as_hex(remainder, 6);

  if (digits_to_remove <= 0 && !long_mantissa_is_zero(remainder)) {
    uint32_t scaled_remainder[6] = {0};
    multiply_long_mantissas(remainder, get_mantissa_with_power_of_ten(1),
                            scaled_remainder);
    // debug_print_mantissa_as_hex(scaled_remainder, 6);
    uint32_t first_leftout_digit[6] = {0};
    uint32_t leftout_remainder[6] = {0};
    divide_long_mantissas(scaled_remainder, divider, first_leftout_digit,
                          leftout_remainder);
    uint32_t* one = get_mantissa_with_power_of_ten(0);
    if (first_leftout_digit[0] == 5) {
      if (!long_mantissa_is_zero(leftout_remainder)) {
        add_long_mantissas(result_mantissa, one, rounded_result_mantissa);
      } else {
        if (result_mantissa[0] & 1) {
          add_long_mantissas(result_mantissa, one, rounded_result_mantissa);
        } else {
          copy_long_mantissa(rounded_result_mantissa, result_mantissa);
        }
      }
    } else if (first_leftout_digit[0] > 5) {
      add_long_mantissas(result_mantissa, one, rounded_result_mantissa);
    } else {
      copy_long_mantissa(rounded_result_mantissa, result_mantissa);
    }
    // debug_print_mantissa_as_hex(rounded_result_mantissa, 6);
  } else if (digits_to_remove > 0) {
    temp_scale -= digits_to_remove;
    if (long_mantissa_is_zero(remainder)) {
      remove_digits_rounding_to_even(result_mantissa, digits_to_remove,
                                     rounded_result_mantissa);
    } else {
      remove_digits_rounding_half_up(result_mantissa, digits_to_remove,
                                     rounded_result_mantissa);
    }
  } else {
    digits_to_remove = 0;
    copy_long_mantissa(rounded_result_mantissa, result_mantissa);
  }

  if (compare_long_mantissas(rounded_result_mantissa, max_mantissa) > 0) {
    digits_to_remove += 1;
    temp_scale -= 1;
    if (long_mantissa_is_zero(remainder)) {
      remove_digits_rounding_to_even(result_mantissa, digits_to_remove,
                                     rounded_result_mantissa);
    } else {
      remove_digits_rounding_half_up(result_mantissa, digits_to_remove,
                                     rounded_result_mantissa);
    }
  }
  // debug_print_mantissa_as_hex(rounded_result_mantissa, 6);
  // printf("\nexp: %d\n", exponent);

  copy_mantissa(result->bits, rounded_result_mantissa);

  Sign result_sign;
  if (get_sign(value_1) == get_sign(value_2)) {
    result_sign = PLUS;
  } else {
    result_sign = MINUS;
  }
  set_sign(result, result_sign);
  set_scale(&result->bits[3], temp_scale);
  result_code = catch_overflow(overflow, result_sign);

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
