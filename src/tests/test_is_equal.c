#include "run_tests.h"

START_TEST(comparison_eq_test) {
  s21_decimal input_decimal_1 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000001010000000000000000};

  s21_decimal input_decimal_2 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_1, input_decimal_2), 0);

  s21_decimal input_decimal_3 = {0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000};

  s21_decimal input_decimal_4 = {0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_3, input_decimal_4), 0);

  // 999999999999 scale 0
  s21_decimal input_decimal_5 = {0xD4A50FFF, 0xE8, 0x0,
                                 0b00000000000000000000000000000000};
  // 999999999999000 scale 3
  s21_decimal input_decimal_6 = {0xA4C67C18, 0x38D7E, 0x0,
                                 0b00000000000000110000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_5, input_decimal_6), 1);

  // 2*(10**28) scale 28
  s21_decimal input_decimal_7 = {0x20000000, 0x7C4A04C2, 0x409F9CBC,
                                 0b00000000000111000000000000000000};

  // 2 scale 0
  s21_decimal input_decimal_8 = {0x2, 0x0, 0x0,
                                 0b00000000000000000000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_7, input_decimal_8), 1);

  s21_decimal input_decimal_9 = {0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000};

  s21_decimal input_decimal_10 = {0x124U, 0x123U, 0x123U,
                                  0b00000000000000101000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_9, input_decimal_10), 1);

  // 0
  s21_decimal input_decimal_11 = {0x0U, 0x0U, 0x0U,
                                  0b00000000000000101000000000000000};
  // -0
  s21_decimal input_decimal_12 = {0x0U, 0x0U, 0x0U,
                                  0b10000000000110110000000000000000};

  ck_assert_int_eq(s21_is_equal(input_decimal_11, input_decimal_12), 1);
}
END_TEST

Suite* make_is_equal_suite() {
  Suite* is_equal_suite = suite_create("is_equal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, comparison_eq_test);

  suite_add_tcase(is_equal_suite, tc_core);
  return is_equal_suite;
}