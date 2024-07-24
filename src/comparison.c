#include "comparison.h"

#include "arithmetic.h"
#include "s21_decimal.h"
#include "tests/debug_funcs.h"
#include "utility.h"

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimals_are_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  if (get_sign(decimal_1) != get_sign(decimal_2)) {
    bool decimals_are_equal = false;
  } else {
    int decimal_1_scale = get_scale(decimal_1.bits[3]);
    int decimal_2_scale = get_scale(decimal_2.bits[3]);

    debug_printf("\n%d %d хххууу\n", decimal_1_scale, decimal_2_scale);

    int scale_difference = 0;

    if (decimal_1_scale > decimal_2_scale) {
      scale_difference = decimal_1_scale - decimal_2_scale;
      multiply_mantissas(decimal_2.bits,
                         get_mantissa_with_power_of_ten(scale_difference),
                         normalized_mantissa_2);

      mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);

    } else if (decimal_1_scale < decimal_2_scale) {
      scale_difference = decimal_2_scale - decimal_1_scale;
      multiply_mantissas(decimal_1.bits,
                         get_mantissa_with_power_of_ten(scale_difference),
                         normalized_mantissa_1);

      mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);

    } else {
      mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);
      mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
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