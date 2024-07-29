#include "comparison.h"

#include "arithmetic.h"
#include "debug_funcs.h"
#include "utility.h"

int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimals_are_less = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  bool decimal_1_is_negative = (bool)get_sign(decimal_1);
  bool decimal_2_is_negative = (bool)get_sign(decimal_2);
  bool both_decimals_are_negative =
      decimal_1_is_negative && decimal_2_is_negative;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimals_are_less = false;
  } else if (decimal_1_is_negative == false && decimal_2_is_negative == true) {
    decimals_are_less = false;
  } else if (decimal_1_is_negative == true && decimal_2_is_negative == false) {
    decimals_are_less = true;
  } else {
    casting_decimals_to_normalized_mantissa(decimal_1, normalized_mantissa_1,
                                            decimal_2, normalized_mantissa_2);

    bool check = true;
    for (int i = 5; i >= 0 && check == true; i--) {
      if (normalized_mantissa_1[i] < normalized_mantissa_2[i]) {
        decimals_are_less = true;
        check = false;
      } else if (normalized_mantissa_1[i] > normalized_mantissa_2[i]) {
        decimals_are_less = false;
        check = false;
      }
    }
    invert_result_due_decimal_signs(both_decimals_are_negative,
                                    &decimals_are_less);
  }

  return (ComparisonResult)decimals_are_less;
}

int s21_is_less_or_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_less_or_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  // int sine_decimal_1 = get_sign(decimal_1);
  // int sine_decimal_2 = get_sign(decimal_2);
  // int is_negative = sine_decimal_1 + sine_decimal_2;
  bool decimal_1_is_negative = (bool)get_sign(decimal_1);
  bool decimal_2_is_negative = (bool)get_sign(decimal_2);
  bool both_decimals_are_negative =
      decimal_1_is_negative && decimal_2_is_negative;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_less_or_equal = true;
  } else if (decimal_1_is_negative == false && decimal_2_is_negative == true) {
    decimal_is_less_or_equal = false;
  } else if (decimal_1_is_negative == true && decimal_2_is_negative == false) {
    decimal_is_less_or_equal = true;
  } else {
    casting_decimals_to_normalized_mantissa(decimal_1, normalized_mantissa_1,
                                            decimal_2, normalized_mantissa_2);

    bool check = true;
    for (int i = 5; i >= 0 && check == true; i--) {
      if (normalized_mantissa_1[i] < normalized_mantissa_2[i]) {
        decimal_is_less_or_equal = true;
        check = false;
      } else if (normalized_mantissa_1[i] > normalized_mantissa_2[i]) {
        decimal_is_less_or_equal = false;
        check = false;
      }
    }
    invert_result_due_decimal_signs(both_decimals_are_negative,
                                    &decimal_is_less_or_equal);
  }

  return (ComparisonResult)decimal_is_less_or_equal;
}

int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_greater = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  int sine_decimal_1 = get_sign(decimal_1);
  int sine_decimal_2 = get_sign(decimal_2);
  int is_negative = sine_decimal_1 + sine_decimal_2;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_greater = false;
  } else if (sine_decimal_1 == 0 && sine_decimal_2 == 1) {
    decimal_is_greater = true;
  } else if (sine_decimal_1 == 1 && sine_decimal_2 == 0) {
    decimal_is_greater = false;
  } else {
    casting_decimals_to_normalized_mantissa(decimal_1, normalized_mantissa_1,
                                            decimal_2, normalized_mantissa_2);

    bool check = true;
    for (int i = 5; i >= 0 && check == true; i--) {
      if (normalized_mantissa_1[i] > normalized_mantissa_2[i]) {
        decimal_is_greater = true;
        check = false;
      } else if (normalized_mantissa_1[i] < normalized_mantissa_2[i]) {
        decimal_is_greater = false;
        check = false;
      }
    }
    invert_result_due_to_sign(is_negative, &decimal_is_greater);
  }

  return (ComparisonResult)decimal_is_greater;
}

int s21_is_greater_or_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_greater_or_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  int sine_decimal_1 = get_sign(decimal_1);
  int sine_decimal_2 = get_sign(decimal_2);
  int is_negative = sine_decimal_1 + sine_decimal_2;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_greater_or_equal = true;
  } else if (sine_decimal_1 == 0 && sine_decimal_2 == 1) {
    decimal_is_greater_or_equal = true;
  } else if (sine_decimal_1 == 1 && sine_decimal_2 == 0) {
    decimal_is_greater_or_equal = false;
  } else {
    casting_decimals_to_normalized_mantissa(decimal_1, normalized_mantissa_1,
                                            decimal_2, normalized_mantissa_2);

    bool check = true;
    for (int i = 5; i >= 0 && check == true; i--) {
      if (normalized_mantissa_1[i] > normalized_mantissa_2[i]) {
        decimal_is_greater_or_equal = true;
        check = false;
      } else if (normalized_mantissa_1[i] < normalized_mantissa_2[i]) {
        decimal_is_greater_or_equal = false;
        check = false;
      }
    }
    invert_result_due_to_sign(is_negative, &decimal_is_greater_or_equal);
  }

  return (ComparisonResult)decimal_is_greater_or_equal;
}

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

int s21_is_not_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
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

    for (int i = 5; i >= 0 && decimals_are_equal == true; i--) {
      if (normalized_mantissa_1[i] != normalized_mantissa_2[i]) {
        decimals_are_equal = false;
      }
    }
  }
  return (ComparisonResult)!decimals_are_equal;
}

void casting_decimals_to_normalized_mantissa(s21_decimal decimal_1,
                                             uint32_t* normalized_mantissa_1,
                                             s21_decimal decimal_2,
                                             uint32_t* normalized_mantissa_2) {
  int scale_difference =
      get_scale_difference_from_decimals(decimal_1, decimal_2);

  if (scale_difference == 0) {
    mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);
    mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
  } else if (get_scale(decimal_1.bits[3]) > get_scale(decimal_2.bits[3])) {
    multiply_mantissas(decimal_2.bits,
                       get_mantissa_with_power_of_ten(scale_difference),
                       normalized_mantissa_2);

    mantissa3_to_mantissa6(decimal_1.bits, normalized_mantissa_1);

  } else if (get_scale(decimal_1.bits[3]) < get_scale(decimal_2.bits[3])) {
    multiply_mantissas(decimal_1.bits,
                       get_mantissa_with_power_of_ten(scale_difference),
                       normalized_mantissa_1);

    mantissa3_to_mantissa6(decimal_2.bits, normalized_mantissa_2);
  }
}

void invert_result_due_decimal_signs(bool both_are_negative, bool* result) {
  if (both_are_negative && *result == true) {
    *result = false;
  } else if (both_are_negative && *result == false) {
    *result = true;
  }
}

void invert_result_due_to_sign(int is_negative, bool* result) {
  if (is_negative == 2 && *result == true) {
    *result = false;
  } else if (is_negative == 2 && *result == false) {
    *result = true;
  }
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