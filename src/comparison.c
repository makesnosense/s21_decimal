#include "comparison.h"

#include "arithmetic.h"
#include "tests/debug_funcs.h"
#include "utility.h"

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimals_are_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  if (get_sign(decimal_1) != get_sign(decimal_2)) {
    bool decimals_are_equal = false;
  } else {
    if (get_scale(decimal_1.bits[3]) == get_scale(decimal_2.bits[3])) {
      mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);
      mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
    } else {
      s21_two_decimals two_decimals_sorted_ascending_by_scale =
          sort_decimals_ascending_by_scale(decimal_1, decimal_2);

      s21_decimal smaller_scale_decimal =
          two_decimals_sorted_ascending_by_scale.decimals[0];

      s21_decimal bigger_scale_decimal =
          two_decimals_sorted_ascending_by_scale.decimals[1];

      int smaller_scale = get_scale(smaller_scale_decimal.bits[3]);
      int bigger_scale = get_scale(bigger_scale_decimal.bits[3]);

      debug_printf("\n%d %d \n", smaller_scale, bigger_scale);

      int scale_difference = 0;

      scale_difference = bigger_scale - smaller_scale;
      multiply_mantissas(smaller_scale_decimal.bits,
                         get_mantissa_with_power_of_ten(scale_difference),
                         normalized_mantissa_1);

      mantissa3_to_mantissa6(bigger_scale_decimal.bits, normalized_mantissa_2);
    }

    debug_print_mantissa_as_binary(normalized_mantissa_1, 6);
    debug_print_mantissa_as_binary(normalized_mantissa_2, 6);

    for (int i = 0; i < 6 && decimals_are_equal == true; i++) {
      if (normalized_mantissa_1[i] != normalized_mantissa_2[i]) {
        decimals_are_equal = false;
      }
    }
  }
  return (ComparisonResult)decimals_are_equal;
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