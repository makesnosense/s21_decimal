#include "../calculation.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_truncate_gen_0) {
  // 1.2345678910111213141516123235
  s21_decimal input_decimal_1 = {
      {0xCCA47C63, 0xC1EEF784, 0x27E41B32, 0b00000000000111000000000000000000}};
  // 1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_1) {
  // 5.50
  s21_decimal input_decimal_1 = {
      {0x00000226, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 5
  s21_decimal expected_result = {
      {0x00000005, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_2) {
  // -5.500
  s21_decimal input_decimal_1 = {
      {0x0000157C, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -5
  s21_decimal expected_result = {
      {0x00000005, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_3) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_4) {
  // 792281625142643375935439503.9
  s21_decimal input_decimal_1 = {
      {0x9999999F, 0x99999999, 0x19999999, 0b00000000000000010000000000000000}};
  // 792281625142643375935439503
  s21_decimal expected_result = {
      {0x28F5C28F, 0xF5C28F5C, 0x028F5C28, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_5) {
  // 7922816251426433759354395033.4
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395033
  s21_decimal expected_result = {
      {0x99999999, 0x99999999, 0x19999999, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_6) {
  // -792281625142643375935439503.9
  s21_decimal input_decimal_1 = {
      {0x9999999F, 0x99999999, 0x19999999, 0b10000000000000010000000000000000}};
  // -792281625142643375935439503
  s21_decimal expected_result = {
      {0x28F5C28F, 0xF5C28F5C, 0x028F5C28, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_7) {
  // 7922816251426433759354395033.1
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395033
  s21_decimal expected_result = {
      {0x99999999, 0x99999999, 0x19999999, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_8) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7
  s21_decimal expected_result = {
      {0x00000007, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_9) {
  // -7922816251426433759354395033.5
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000010000000000000000}};
  // -7922816251426433759354395033
  s21_decimal expected_result = {
      {0x99999999, 0x99999999, 0x19999999, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_10) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433
  s21_decimal expected_result = {
      {0x68497681, 0x001C25C2, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_11) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394585
  s21_decimal expected_result = {
      {0xA3040F59, 0xF14ECC66, 0x000007BB, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_12) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059832
  s21_decimal expected_result = {
      {0xF1378038, 0x28BAA06F, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_13) {
  // -42.353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};
  // -42
  s21_decimal expected_result = {
      {0x0000002A, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_14) {
  // -11353455324534534597889.779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000110000000000000000}};
  // -11353455324534534597889
  s21_decimal expected_result = {
      {0xD4386D01, 0x78D8087A, 0x00000267, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_15) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_16) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_17) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_18) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_19) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_20) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_21) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_truncate_gen_22) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  CalculationResult s21_return_code =
      s21_truncate(input_decimal_1, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_truncate_suite() {
  Suite* truncate_suite = suite_create("truncate");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_truncate_gen_0);
  tcase_add_test(tc_core, test_truncate_gen_1);
  tcase_add_test(tc_core, test_truncate_gen_2);
  tcase_add_test(tc_core, test_truncate_gen_3);
  tcase_add_test(tc_core, test_truncate_gen_4);
  tcase_add_test(tc_core, test_truncate_gen_5);
  tcase_add_test(tc_core, test_truncate_gen_6);
  tcase_add_test(tc_core, test_truncate_gen_7);
  tcase_add_test(tc_core, test_truncate_gen_8);
  tcase_add_test(tc_core, test_truncate_gen_9);
  tcase_add_test(tc_core, test_truncate_gen_10);
  tcase_add_test(tc_core, test_truncate_gen_11);
  tcase_add_test(tc_core, test_truncate_gen_12);
  tcase_add_test(tc_core, test_truncate_gen_13);
  tcase_add_test(tc_core, test_truncate_gen_14);
  tcase_add_test(tc_core, test_truncate_gen_15);
  tcase_add_test(tc_core, test_truncate_gen_16);
  tcase_add_test(tc_core, test_truncate_gen_17);
  tcase_add_test(tc_core, test_truncate_gen_18);
  tcase_add_test(tc_core, test_truncate_gen_19);
  tcase_add_test(tc_core, test_truncate_gen_20);
  tcase_add_test(tc_core, test_truncate_gen_21);
  tcase_add_test(tc_core, test_truncate_gen_22);

  suite_add_tcase(truncate_suite, tc_core);

  return truncate_suite;
}