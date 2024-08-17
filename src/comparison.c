#include "comparison.h"

#include "arithmetic.h"
#include "debug_funcs.h"
#include "utility.h"

int s21_is_less(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_less = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  bool decimal_1_is_negative = (bool)get_sign(decimal_1);
  bool decimal_2_is_negative = (bool)get_sign(decimal_2);
  bool both_decimals_are_negative =
      decimal_1_is_negative && decimal_2_is_negative;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_less = false;
  } else if (decimal_1_is_negative == false && decimal_2_is_negative == true) {
    decimal_is_less = false;
  } else if (decimal_1_is_negative == true && decimal_2_is_negative == false) {
    decimal_is_less = true;
  } else {
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
                                          decimal_2, normalized_mantissa_2);

    bool check = true;
    for (int i = 5; i >= 0 && check == true; i--) {
      if (normalized_mantissa_1[i] < normalized_mantissa_2[i]) {
        decimal_is_less = true;
        check = false;
      } else if (normalized_mantissa_1[i] > normalized_mantissa_2[i]) {
        decimal_is_less = false;
        check = false;
      }
    }
    invert_result_due_to_decimal_signs(both_decimals_are_negative,
                                       &decimal_is_less);
  }

  return (ComparisonResult)decimal_is_less;
}

int s21_is_less_or_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_less_or_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

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
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
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
    invert_result_due_to_decimal_signs(both_decimals_are_negative,
                                       &decimal_is_less_or_equal);
  }

  return (ComparisonResult)decimal_is_less_or_equal;
}

int s21_is_greater(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_greater = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  bool decimal_1_is_negative = (bool)get_sign(decimal_1);
  bool decimal_2_is_negative = (bool)get_sign(decimal_2);
  bool both_decimals_are_negative =
      decimal_1_is_negative && decimal_2_is_negative;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_greater = false;
  } else if (decimal_1_is_negative == false && decimal_2_is_negative == true) {
    decimal_is_greater = true;
  } else if (decimal_1_is_negative == true && decimal_2_is_negative == false) {
    decimal_is_greater = false;
  } else {
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
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
    invert_result_due_to_decimal_signs(both_decimals_are_negative,
                                       &decimal_is_greater);
  }

  return (ComparisonResult)decimal_is_greater;
}

int s21_is_greater_or_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  bool decimal_is_greater_or_equal = true;
  uint32_t normalized_mantissa_1[6] = {0};
  uint32_t normalized_mantissa_2[6] = {0};

  bool decimal_1_is_negative = (bool)get_sign(decimal_1);
  bool decimal_2_is_negative = (bool)get_sign(decimal_2);
  bool both_decimals_are_negative =
      decimal_1_is_negative && decimal_2_is_negative;

  if (s21_is_equal(decimal_1, decimal_2)) {
    decimal_is_greater_or_equal = true;
  } else if (decimal_1_is_negative == false && decimal_2_is_negative == true) {
    decimal_is_greater_or_equal = true;
  } else if (decimal_1_is_negative == true && decimal_2_is_negative == false) {
    decimal_is_greater_or_equal = false;
  } else {
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
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
    invert_result_due_to_decimal_signs(both_decimals_are_negative,
                                       &decimal_is_greater_or_equal);
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
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
                                          decimal_2, normalized_mantissa_2);
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
    cast_decimals_to_normalized_mantissas(decimal_1, normalized_mantissa_1,
                                          decimal_2, normalized_mantissa_2);

    for (int i = 5; i >= 0 && decimals_are_equal == true; i--) {
      if (normalized_mantissa_1[i] != normalized_mantissa_2[i]) {
        decimals_are_equal = false;
      }
    }
  }
  return (ComparisonResult)!decimals_are_equal;
}

void invert_result_due_to_decimal_signs(bool both_are_negative, bool* result) {
  if (both_are_negative && *result == true) {
    *result = false;
  } else if (both_are_negative && *result == false) {
    *result = true;
  }
}
