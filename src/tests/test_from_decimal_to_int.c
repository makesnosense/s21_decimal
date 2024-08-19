#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_decimal_to_int_fail_incorrect_decimal) {
  // -2147483640
  s21_decimal input_decimal = {
      {0x7FFFFFF8, 0x00000000, 0x00000000, 0b11000000010000000000000000001000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_NULL) {
  // -2147483640
  s21_decimal input_decimal = {
      {0x7FFFFFF8, 0x00000000, 0x00000000, 0b11000000010000000000000000001000}};

  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, NULL);

  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_0) {
  // -2147483640
  s21_decimal input_decimal = {
      {0x7FFFFFF8, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  int expected_result = -2147483640;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_1) {
  // 5
  s21_decimal input_decimal = {
      {0x00000005, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 5;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_2) {
  // -42353455
  s21_decimal input_decimal = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  int expected_result = -42353455;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_3) {
  // 4
  s21_decimal input_decimal = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 4;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_4) {
  // 0
  s21_decimal input_decimal = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 0;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_5) {
  // -0
  s21_decimal input_decimal = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  int expected_result = -0;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_6) {
  // 333
  s21_decimal input_decimal = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 333;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_7) {
  // 12345
  s21_decimal input_decimal = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 12345;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_8) {
  // -300000000
  s21_decimal input_decimal = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  int expected_result = -300000000;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_9) {
  // 2147483647
  s21_decimal input_decimal = {
      {0x7FFFFFFF, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  int expected_result = 2147483647;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_10) {
  // 2147483647.9
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0x00000004, 0x00000000, 0b00000000000000010000000000000000}};
  int expected_result = 2147483647;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_11) {
  // -2147483649.99999999
  s21_decimal input_decimal = {
      {0x0BEBC1FF, 0x02FAF080, 0x00000000, 0b10000000000010000000000000000000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_12) {
  // -2147483648.9999
  s21_decimal input_decimal = {
      {0x0000270F, 0x00001388, 0x00000000, 0b10000000000001000000000000000000}};
  int expected_result = -2147483648;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_13) {
  // -1234567.34513
  s21_decimal input_decimal = {
      {0xBE984531, 0x0000001C, 0x00000000, 0b10000000000001010000000000000000}};
  int expected_result = -1234567;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_14) {
  // 7777.777777
  s21_decimal input_decimal = {
      {0xCF977871, 0x00000001, 0x00000000, 0b00000000000001100000000000000000}};
  int expected_result = 7777;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_15) {
  // 2147483648.01
  s21_decimal input_decimal = {
      {0x00000001, 0x00000032, 0x00000000, 0b00000000000000100000000000000000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_16) {
  // -2147483648
  s21_decimal input_decimal = {
      {0x80000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  int expected_result = -2147483648;

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);

  ck_assert_int_eq(s21_result_int, expected_result);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_17) {
  // -2147483649
  s21_decimal input_decimal = {
      {0x80000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_18) {
  // -5555555555555
  s21_decimal input_decimal = {
      {0x80EA58E3, 0x0000050D, 0x00000000, 0b10000000000000000000000000000000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_gen_19) {
  // 7777777777777777
  s21_decimal input_decimal = {
      {0x01961C71, 0x001BA1D9, 0x00000000, 0b00000000000000000000000000000000}};

  int s21_result_int;
  ConversionResult s21_return_code =
      s21_from_decimal_to_int(input_decimal, &s21_result_int);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

Suite* make_from_decimal_to_int_suite() {
  Suite* from_decimal_to_int_suite = suite_create("from_decimal_to_int");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_int_fail_incorrect_decimal);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_NULL);

  tcase_add_test(tc_core, test_from_decimal_to_int_gen_0);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_1);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_2);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_3);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_4);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_5);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_6);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_7);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_8);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_9);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_10);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_11);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_12);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_13);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_14);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_15);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_16);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_17);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_18);
  tcase_add_test(tc_core, test_from_decimal_to_int_gen_19);

  suite_add_tcase(from_decimal_to_int_suite, tc_core);

  return from_decimal_to_int_suite;
}
