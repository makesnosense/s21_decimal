#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_int_to_decimal_input_equal_NULL) {
  int input_int = -2147483640;

  ConversionResult s21_return_code = s21_from_int_to_decimal(input_int, NULL);

  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_0) {
  int input_int = -2147483640;
  // -2147483640
  s21_decimal expected_result = {
      {0x7FFFFFF8, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_1) {
  int input_int = 5;
  // 5
  s21_decimal expected_result = {
      {0x00000005, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_2) {
  int input_int = -42353455;
  // -42353455
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_3) {
  int input_int = 4;
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_4) {
  int input_int = 0;
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_5) {
  int input_int = -0;
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_6) {
  int input_int = 333;
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_7) {
  int input_int = 12345;
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_8) {
  int input_int = -300000000;
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_9) {
  int input_int = 2147483647;
  // 2147483647
  s21_decimal expected_result = {
      {0x7FFFFFFF, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_int_to_decimal_gen_10) {
  int input_int = -2147483648;
  // -2147483648
  s21_decimal expected_result = {
      {0x80000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_int_to_decimal(input_int, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_int_to_decimal_suite() {
  Suite* from_int_to_decimal_suite = suite_create("from_int_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_int_to_decimal_input_equal_NULL);

  tcase_add_test(tc_core, test_from_int_to_decimal_gen_0);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_1);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_2);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_3);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_4);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_5);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_6);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_7);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_8);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_9);
  tcase_add_test(tc_core, test_from_int_to_decimal_gen_10);
  suite_add_tcase(from_int_to_decimal_suite, tc_core);

  return from_int_to_decimal_suite;
}