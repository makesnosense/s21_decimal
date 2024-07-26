#include "comparison.h"

#include "arithmetic.h"
#include "debug_funcs.h"
#include "utility.h"

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimals_are_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};
  if (is_zero_decimal(decimal_1) && is_zero_decimal(decimal_2)) {
    decimals_are_equal = true;
  } else if (get_sign(decimal_1) != get_sign(decimal_2)) {
    decimals_are_equal = false;
  } else {
    int scale_difference =
        get_scale_difference_from_decimals(decimal_1, decimal_2);

    if (scale_difference == 0) {
      mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);
      mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
    } else {
      s21_two_decimals two_decimals_sorted_ascending_by_scale =
          sort_decimals_ascending_by_scale(decimal_1, decimal_2);

      s21_decimal smaller_scale_decimal =
          two_decimals_sorted_ascending_by_scale.decimals[0];

      s21_decimal bigger_scale_decimal =
          two_decimals_sorted_ascending_by_scale.decimals[1];

      multiply_mantissas(smaller_scale_decimal.bits,
                         get_mantissa_with_power_of_ten(scale_difference),
                         normalized_mantissa_1);

      mantissa3_to_mantissa6(bigger_scale_decimal.bits, normalized_mantissa_2);

      // debug_printf("\n%d %d \n", get_scale(smaller_scale_decimal.bits[3]),
      //              get_scale(bigger_scale_decimal.bits[3]));
    }

    // debug_print_mantissa_as_binary(normalized_mantissa_1, 6);
    // debug_print_mantissa_as_binary(normalized_mantissa_2, 6);

    for (int i = 0; i < 6 && decimals_are_equal == true; i++) {
      if (normalized_mantissa_1[i] != normalized_mantissa_2[i]) {
        decimals_are_equal = false;
      }
    }
  }
  return (ComparisonResult)decimals_are_equal;
}

int get_scale_difference_from_decimals(s21_decimal decimal_1,
                                       s21_decimal decimal_2) {
  int decimal_1_scale = get_scale(decimal_1.bits[3]);
  int decimal_2_scale = get_scale(decimal_2.bits[3]);
  int result = 0;
  if (decimal_1_scale > decimal_2_scale) {
    result = decimal_1_scale - decimal_2_scale;
  } else if (decimal_1_scale < decimal_2_scale) {
    result = decimal_2_scale - decimal_1_scale;
  }
  return result;
}

s21_two_decimals sort_decimals_ascending_by_scale(s21_decimal decimal_1,
                                                  s21_decimal decimal_2) {
  s21_two_decimals result;
  {
    int decimal_1_scale = get_scale(decimal_1.bits[3]);
    int decimal_2_scale = get_scale(decimal_2.bits[3]);

    if (decimal_1_scale <= decimal_2_scale) {
      result.decimals[0] = decimal_1;
      result.decimals[1] = decimal_2;
    } else {
      result.decimals[0] = decimal_2;
      result.decimals[1] = decimal_1;
    }
  }

  return result;
}