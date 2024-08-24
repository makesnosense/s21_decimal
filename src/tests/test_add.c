#include "../arithmetic.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_add_null) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, NULL);

  ck_assert_int_eq(s21_return_code, INPUT_ERROR);
}
END_TEST

START_TEST(test_add_first_decimal_incorrect) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00100000000001000000000100000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, INPUT_ERROR);
}
END_TEST

START_TEST(test_add_second_decimal_incorrect) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000001000000010000000001000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, INPUT_ERROR);
}
END_TEST

START_TEST(test_add_both_decimals_incorrect) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00010000000001000000000010000100}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000001000000010000000001000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, INPUT_ERROR);
}
END_TEST

START_TEST(test_add_gen2_0) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.7345
  s21_decimal expected_result = {
      {0x00010711, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_1) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 2.18483
  s21_decimal expected_result = {
      {0x00035573, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_2) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_3) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_4) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.993854395034
  s21_decimal expected_result = {
      {0x0788B29A, 0x99999AB9, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_5) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.993854395033
  s21_decimal expected_result = {
      {0x0788B299, 0x99999AB9, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_6) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.23450000000049
  s21_decimal expected_result = {
      {0x01E00431, 0x0000CB3A, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_7) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394586.469009
  s21_decimal expected_result = {
      {0xB3463291, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_8) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059831.2155
  s21_decimal expected_result = {
      {0x88006CDB, 0xFA1B14BE, 0x00000636, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_9) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353453.7655
  s21_decimal expected_result = {
      {0x9CA02BB7, 0x00000062, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_10) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889777.766
  s21_decimal expected_result = {
      {0xFD506066, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_11) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.2345
  s21_decimal expected_result = {
      {0x0000CC79, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_12) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2.2345
  s21_decimal expected_result = {
      {0x00005749, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_13) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.2345
  s21_decimal expected_result = {
      {0x00000929, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_14) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_15) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_16) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 334.2345
  s21_decimal expected_result = {
      {0x00330009, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_17) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12346.2345
  s21_decimal expected_result = {
      {0x075BE2C9, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_18) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.357956789
  s21_decimal expected_result = {
      {0x50F0C6B5, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_19) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.1345
  s21_decimal expected_result = {
      {0x00002C51, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_20) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999998.7655
  s21_decimal expected_result = {
      {0x7DEEFFC7, 0x000002BA, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_21) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.23450000000101
  s21_decimal expected_result = {
      {0x01E00465, 0x0000CB3A, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_22) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 6.7345
  s21_decimal expected_result = {
      {0x00010711, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_23) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 6.45033
  s21_decimal expected_result = {
      {0x0009D7A9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_24) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_25) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_26) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426439.259354395034
  s21_decimal expected_result = {
      {0x2B25719A, 0x99999E9A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_27) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426439.259354395033
  s21_decimal expected_result = {
      {0x2B257199, 0x99999E9A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_28) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 6.50000000000049
  s21_decimal expected_result = {
      {0xEB1AA031, 0x00024F2B, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_29) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394590.734509
  s21_decimal expected_result = {
      {0xB38748AD, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_30) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059826.95
  s21_decimal expected_result = {
      {0x39AE13E7, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_31) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353449.5
  s21_decimal expected_result = {
      {0x193E9F9F, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_32) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889773.5
  s21_decimal expected_result = {
      {0xDC221547, 0x76CB3E01, 0x005DE9E0, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_33) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 9.5
  s21_decimal expected_result = {
      {0x0000005F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_34) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 6.5
  s21_decimal expected_result = {
      {0x00000041, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_35) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4.5
  s21_decimal expected_result = {
      {0x0000002D, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_36) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_37) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_38) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 338.5
  s21_decimal expected_result = {
      {0x00000D39, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_39) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12350.5
  s21_decimal expected_result = {
      {0x0001E271, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_40) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 5.623456789
  s21_decimal expected_result = {
      {0x4F2F2415, 0x00000001, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_41) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.4
  s21_decimal expected_result = {
      {0x00000036, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_42) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999994.5
  s21_decimal expected_result = {
      {0xB2D05DC9, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_43) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 6.50000000000101
  s21_decimal expected_result = {
      {0xEB1AA065, 0x00024F2B, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_44) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 2.18483
  s21_decimal expected_result = {
      {0x00035573, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_45) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.45033
  s21_decimal expected_result = {
      {0x0009D7A9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_46) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_47) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_48) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.709684395034
  s21_decimal expected_result = {
      {0xDDAE9C1A, 0x99999A76, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_49) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.709684395033
  s21_decimal expected_result = {
      {0xDDAE9C19, 0x99999A76, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_50) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.95033000000049
  s21_decimal expected_result = {
      {0xA8AF3A31, 0x0000B161, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_51) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394586.184839
  s21_decimal expected_result = {
      {0xB341DC87, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_52) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059831.49967
  s21_decimal expected_result = {
      {0x5004AF8F, 0xC50ECF71, 0x00003E25, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_53) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353454.04967
  s21_decimal expected_result = {
      {0x1E422427, 0x000003DA, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_54) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889778.050
  s21_decimal expected_result = {
      {0xFD506182, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_55) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4.95033
  s21_decimal expected_result = {
      {0x00078DB9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_56) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.95033
  s21_decimal expected_result = {
      {0x0002F9D9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_57) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.04967
  s21_decimal expected_result = {
      {0x00001367, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_58) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_59) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_60) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333.95033
  s21_decimal expected_result = {
      {0x01FD9159, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_61) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345.95033
  s21_decimal expected_result = {
      {0x49966CD9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_62) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.073786789
  s21_decimal expected_result = {
      {0x4000AFA5, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_63) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.85033
  s21_decimal expected_result = {
      {0x00014C29, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_64) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999999.04967
  s21_decimal expected_result = {
      {0xEB566CC7, 0x00001B48, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_65) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.95033000000101
  s21_decimal expected_result = {
      {0xA8AF3A65, 0x0000B161, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_66) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_67) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_68) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_69) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_70) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_71) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_72) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_73) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_74) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 79228162511329503083709890502
  s21_decimal expected_result = {
      {0x0EC87FC6, 0xD7455F90, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_75) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593501596880
  s21_decimal expected_result = {
      {0xFD79BCD0, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_76) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 79216809058939803058946060556
  s21_decimal expected_result = {
      {0x0396310C, 0xF41EE033, 0xFFF69BCF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_77) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_78) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_79) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_80) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_81) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_82) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_83) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_84) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_85) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_86) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593243950335
  s21_decimal expected_result = {
      {0xEE1E5CFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_87) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_88) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_89) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_90) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_91) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_92) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514256414777292523901
  s21_decimal expected_result = {
      {0x97B6897D, 0xFFE3DA3D, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_93) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514256414777292523901
  s21_decimal expected_result = {
      {0x97B6897D, 0xFFE3DA3D, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_94) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_95) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -79228125990769755769823555750
  s21_decimal expected_result = {
      {0x5CFBF0A6, 0x0EB13399, 0xFFFFF844, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_96) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_97) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_98) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_99) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950331
  s21_decimal expected_result = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_100) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_101) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_102) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_103) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_104) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950002
  s21_decimal expected_result = {
      {0xFFFFFEB2, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_105) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543937990
  s21_decimal expected_result = {
      {0xFFFFCFC6, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_106) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_107) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_108) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_109) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_110) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426434.993854395034
  s21_decimal expected_result = {
      {0x0788B29A, 0x99999AB9, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_111) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426439.259354395034
  s21_decimal expected_result = {
      {0x2B25719A, 0x99999E9A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_112) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426434.709684395034
  s21_decimal expected_result = {
      {0xDDAE9C1A, 0x99999A76, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_113) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_114) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514256414777292523901
  s21_decimal expected_result = {
      {0x97B6897D, 0xFFE3DA3D, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_115) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 15845632502852867.518708790066
  s21_decimal expected_result = {
      {0x33333332, 0x33333333, 0x33333333, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_116) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_117) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523502504639971821018.993863
  s21_decimal expected_result = {
      {0xA7B8D4C7, 0x1D92C8B7, 0x7603887E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_118) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2926911693582633398.6906456050
  s21_decimal expected_result = {
      {0xBF203FF2, 0x6D819ECB, 0x5E92D898, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_119) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816209072978.7593543950335
  s21_decimal expected_result = {
      {0xD9149FFF, 0x0A4702C1, 0xFFFFFFE9, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_120) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455316611718346463345.241
  s21_decimal expected_result = {
      {0x9E597A59, 0xF970B952, 0x24AF5BAD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_121) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426437.759354395034
  s21_decimal expected_result = {
      {0xEC2DD99A, 0x99999D3C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_122) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_123) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426432.7593543950335
  s21_decimal expected_result = {
      {0xB18D5FFF, 0xFFFFF6E7, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_124) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_125) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_126) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426766.759354395034
  s21_decimal expected_result = {
      {0x344F699A, 0x999AC876, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_127) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251438778.759354395034
  s21_decimal expected_result = {
      {0xE55A299A, 0x99C5754F, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_128) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.882811184034
  s21_decimal expected_result = {
      {0x5832B3A2, 0x999999B6, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_129) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.6593543950335
  s21_decimal expected_result = {
      {0x2B5AEFFF, 0xFFFFFF17, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_130) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922815951426433.7593543950335
  s21_decimal expected_result = {
      {0x641FFFFF, 0x5EA2F6AE, 0xFFFFFF5D, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_131) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_132) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426434.993854395033
  s21_decimal expected_result = {
      {0x0788B299, 0x99999AB9, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_133) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426439.259354395033
  s21_decimal expected_result = {
      {0x2B257199, 0x99999E9A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_134) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426434.709684395033
  s21_decimal expected_result = {
      {0xDDAE9C19, 0x99999A76, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_135) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_136) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514256414777292523901
  s21_decimal expected_result = {
      {0x97B6897D, 0xFFE3DA3D, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_137) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 15845632502852867.518708790066
  s21_decimal expected_result = {
      {0x33333332, 0x33333333, 0x33333333, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_138) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426434.759354395033
  s21_decimal expected_result = {
      {0x6E3EA999, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_139) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523502504639971821018.993863
  s21_decimal expected_result = {
      {0xA7B8D4C7, 0x1D92C8B7, 0x7603887E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_140) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2926911693582633398.6906456050
  s21_decimal expected_result = {
      {0xBF203FF2, 0x6D819ECB, 0x5E92D898, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_141) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816209072978.7593543950330
  s21_decimal expected_result = {
      {0xD9149FFA, 0x0A4702C1, 0xFFFFFFE9, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_142) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455316611718346463345.241
  s21_decimal expected_result = {
      {0x9E597A59, 0xF970B952, 0x24AF5BAD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_143) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426437.759354395033
  s21_decimal expected_result = {
      {0xEC2DD999, 0x99999D3C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_144) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426434.759354395033
  s21_decimal expected_result = {
      {0x6E3EA999, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_145) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426432.7593543950330
  s21_decimal expected_result = {
      {0xB18D5FFA, 0xFFFFF6E7, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_146) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_147) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_148) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426766.759354395033
  s21_decimal expected_result = {
      {0x344F6999, 0x999AC876, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_149) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251438778.759354395033
  s21_decimal expected_result = {
      {0xE55A2999, 0x99C5754F, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_150) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.882811184033
  s21_decimal expected_result = {
      {0x5832B3A1, 0x999999B6, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_151) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.6593543950330
  s21_decimal expected_result = {
      {0x2B5AEFFA, 0xFFFFFF17, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_152) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922815951426433.7593543950330
  s21_decimal expected_result = {
      {0x641FFFFA, 0x5EA2F6AE, 0xFFFFFF5D, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_153) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_154) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 2.23450000000049
  s21_decimal expected_result = {
      {0x01E00431, 0x0000CB3A, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_155) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.50000000000049
  s21_decimal expected_result = {
      {0xEB1AA031, 0x00024F2B, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_156) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.95033000000049
  s21_decimal expected_result = {
      {0xA8AF3A31, 0x0000B161, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_157) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_158) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_159) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_160) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395033
  s21_decimal expected_result = {
      {0x6E3EA999, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_161) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_162) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059831.4500000000
  s21_decimal expected_result = {
      {0x08C68900, 0xB94846B9, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_163) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353453.99999999999951
  s21_decimal expected_result = {
      {0x74B77FCF, 0x9939897A, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_164) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889778.000
  s21_decimal expected_result = {
      {0xFD506150, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_165) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.00000000000049
  s21_decimal expected_result = {
      {0x52634031, 0x0001C6BF, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_166) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2.00000000000049
  s21_decimal expected_result = {
      {0x20F48031, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_167) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.00000000000049
  s21_decimal expected_result = {
      {0x00000031, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_168) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_169) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_170) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 334.00000000000049
  s21_decimal expected_result = {
      {0x7F7F8031, 0x0076A91F, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_171) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12346.00000000000049
  s21_decimal expected_result = {
      {0xA7B28031, 0x11222E28, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_172) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.12345678900049
  s21_decimal expected_result = {
      {0x84486B51, 0x0000662D, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_173) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.90000000000049
  s21_decimal expected_result = {
      {0xC207A031, 0x000051DA, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_174) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999998.99999999999951
  s21_decimal expected_result = {
      {0x0645BFCF, 0x4DA2023D, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_175) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.00000000000150
  s21_decimal expected_result = {
      {0x20F48096, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_176) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 36523494581823720394586.469009
  s21_decimal expected_result = {
      {0xB3463291, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_177) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 36523494581823720394590.734509
  s21_decimal expected_result = {
      {0xB38748AD, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_178) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 36523494581823720394586.184839
  s21_decimal expected_result = {
      {0xB341DC87, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_179) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_180) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228125990769755769823555750
  s21_decimal expected_result = {
      {0x5CFBF0A6, 0x0EB13399, 0xFFFFF844, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_181) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523502504639971821018.993863
  s21_decimal expected_result = {
      {0xA7B8D4C7, 0x1D92C8B7, 0x7603887E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_182) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523502504639971821018.993863
  s21_decimal expected_result = {
      {0xA7B8D4C7, 0x1D92C8B7, 0x7603887E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_183) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_184) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 36520559747313886334752.784509
  s21_decimal expected_result = {
      {0x92F6007D, 0xEBD5027F, 0x76011956, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_185) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823678041130.234509
  s21_decimal expected_result = {
      {0x848F728D, 0x9E68F667, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_186) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11316931829952710877495193.765
  s21_decimal expected_result = {
      {0x357470A5, 0xCB95C7CD, 0x24912587, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_187) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394589.234509
  s21_decimal expected_result = {
      {0xB370654D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_188) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_189) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394584.234509
  s21_decimal expected_result = {
      {0xB3241A0D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_190) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_191) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_192) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394918.234509
  s21_decimal expected_result = {
      {0xC70C898D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_193) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720406930.234509
  s21_decimal expected_result = {
      {0x93051C8D, 0x9E691CEF, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_194) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 36523494581823720394585.357966
  s21_decimal expected_result = {
      {0xB3353E8E, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_195) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 36523494581823720394585.134509
  s21_decimal expected_result = {
      {0xB331D5AD, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_196) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823420394585.234509
  s21_decimal expected_result = {
      {0x81C49C4D, 0x9E680C13, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_197) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_198) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -2934834509834059831.2155
  s21_decimal expected_result = {
      {0x88006CDB, 0xFA1B14BE, 0x00000636, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_199) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -2934834509834059826.95
  s21_decimal expected_result = {
      {0x39AE13E7, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_200) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -2934834509834059831.49967
  s21_decimal expected_result = {
      {0x5004AF8F, 0xC50ECF71, 0x00003E25, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_201) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162511329503083709890502
  s21_decimal expected_result = {
      {0x0EC87FC6, 0xD7455F90, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_202) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_203) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2926911693582633398.6906456050
  s21_decimal expected_result = {
      {0xBF203FF2, 0x6D819ECB, 0x5E92D898, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_204) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2926911693582633398.6906456050
  s21_decimal expected_result = {
      {0xBF203FF2, 0x6D819ECB, 0x5E92D898, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_205) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059831.4500000000
  s21_decimal expected_result = {
      {0x08C68900, 0xB94846B9, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_206) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36520559747313886334752.784509
  s21_decimal expected_result = {
      {0x92F6007D, 0xEBD5027F, 0x76011956, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_207) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509876413287.45
  s21_decimal expected_result = {
      {0x36205469, 0xE8E6ABBB, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_208) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353458259369044431949611.45
  s21_decimal expected_result = {
      {0xD302ECF9, 0x8CD717CC, 0x03AB22D4, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_209) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059828.45
  s21_decimal expected_result = {
      {0x39AE147D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_210) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059831.45
  s21_decimal expected_result = {
      {0x39AE15A9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_211) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059833.45
  s21_decimal expected_result = {
      {0x39AE1671, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_212) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_213) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_214) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059499.45
  s21_decimal expected_result = {
      {0x39AD93F9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_215) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834047487.45
  s21_decimal expected_result = {
      {0x399B3FC9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_216) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -2934834509834059832.326543211
  s21_decimal expected_result = {
      {0xE852D76B, 0x92873A45, 0x097BA361, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_217) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -2934834509834059832.55
  s21_decimal expected_result = {
      {0x39AE1617, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_218) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834510134059832.45
  s21_decimal expected_result = {
      {0x35D1C20D, 0xE8E6ABC1, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_219) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059831.4500000000
  s21_decimal expected_result = {
      {0x08C68900, 0xB94846B9, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_220) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -42353453.7655
  s21_decimal expected_result = {
      {0x9CA02BB7, 0x00000062, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_221) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -42353449.5
  s21_decimal expected_result = {
      {0x193E9F9F, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_222) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -42353454.04967
  s21_decimal expected_result = {
      {0x1E422427, 0x000003DA, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_223) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593501596880
  s21_decimal expected_result = {
      {0xFD79BCD0, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_224) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_225) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816209072978.7593543950335
  s21_decimal expected_result = {
      {0xD9149FFF, 0x0A4702C1, 0xFFFFFFE9, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_226) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816209072978.7593543950330
  s21_decimal expected_result = {
      {0xD9149FFA, 0x0A4702C1, 0xFFFFFFE9, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_227) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353453.99999999999951
  s21_decimal expected_result = {
      {0x74B77FCF, 0x9939897A, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_228) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823678041130.234509
  s21_decimal expected_result = {
      {0x848F728D, 0x9E68F667, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_229) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509876413287.45
  s21_decimal expected_result = {
      {0x36205469, 0xE8E6ABBB, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_230) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534640243234
  s21_decimal expected_result = {
      {0xFEF01222, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_231) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353451
  s21_decimal expected_result = {
      {0x0286432B, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_232) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353454
  s21_decimal expected_result = {
      {0x0286432E, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_233) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353456
  s21_decimal expected_result = {
      {0x02864330, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_234) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_235) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_236) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353122
  s21_decimal expected_result = {
      {0x028641E2, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_237) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42341110
  s21_decimal expected_result = {
      {0x028612F6, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_238) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -42353454.876543211
  s21_decimal expected_result = {
      {0x28ED48EB, 0x0096783E, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_239) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -42353455.1
  s21_decimal expected_result = {
      {0x193E9FD7, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_240) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -342353455
  s21_decimal expected_result = {
      {0x1467E62F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_241) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353453.99999999999899
  s21_decimal expected_result = {
      {0x74B77F9B, 0x9939897A, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_242) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -11353455324534534597889777.766
  s21_decimal expected_result = {
      {0xFD506066, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_243) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -11353455324534534597889773.5
  s21_decimal expected_result = {
      {0xDC221547, 0x76CB3E01, 0x005DE9E0, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_244) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -11353455324534534597889778.050
  s21_decimal expected_result = {
      {0xFD506182, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_245) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79216809058939803058946060556
  s21_decimal expected_result = {
      {0x0396310C, 0xF41EE033, 0xFFF69BCF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_246) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_247) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455316611718346463345.241
  s21_decimal expected_result = {
      {0x9E597A59, 0xF970B952, 0x24AF5BAD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_248) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455316611718346463345.241
  s21_decimal expected_result = {
      {0x9E597A59, 0xF970B952, 0x24AF5BAD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_249) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889778.000
  s21_decimal expected_result = {
      {0xFD506150, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_250) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -11316931829952710877495193.765
  s21_decimal expected_result = {
      {0x357470A5, 0xCB95C7CD, 0x24912587, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_251) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -11353458259369044431949611.45
  s21_decimal expected_result = {
      {0xD302ECF9, 0x8CD717CC, 0x03AB22D4, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_252) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534640243234
  s21_decimal expected_result = {
      {0xFEF01222, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_253) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889775
  s21_decimal expected_result = {
      {0xFC69CEEF, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_254) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889778
  s21_decimal expected_result = {
      {0xFC69CEF2, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_255) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889780
  s21_decimal expected_result = {
      {0xFC69CEF4, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_256) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_257) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_258) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889446
  s21_decimal expected_result = {
      {0xFC69CDA6, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_259) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597877434
  s21_decimal expected_result = {
      {0xFC699EBA, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_260) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -11353455324534534597889778.876
  s21_decimal expected_result = {
      {0xFD5064BC, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_261) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -11353455324534534597889779.1
  s21_decimal expected_result = {
      {0xDC22157F, 0x76CB3E01, 0x005DE9E0, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_262) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534897889779
  s21_decimal expected_result = {
      {0x0E4B71F3, 0x0BE11FCD, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_263) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889778.000
  s21_decimal expected_result = {
      {0xFD506150, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_264) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.2345
  s21_decimal expected_result = {
      {0x0000CC79, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_265) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 9.5
  s21_decimal expected_result = {
      {0x0000005F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_266) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4.95033
  s21_decimal expected_result = {
      {0x00078DB9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_267) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_268) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950331
  s21_decimal expected_result = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_269) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426437.759354395034
  s21_decimal expected_result = {
      {0xEC2DD99A, 0x99999D3C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_270) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426437.759354395033
  s21_decimal expected_result = {
      {0xEC2DD999, 0x99999D3C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_271) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.00000000000049
  s21_decimal expected_result = {
      {0x52634031, 0x0001C6BF, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_272) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394589.234509
  s21_decimal expected_result = {
      {0xB370654D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_273) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059828.45
  s21_decimal expected_result = {
      {0x39AE147D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_274) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353451
  s21_decimal expected_result = {
      {0x0286432B, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_275) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889775
  s21_decimal expected_result = {
      {0xFC69CEEF, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_276) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5
  s21_decimal expected_result = {
      {0x00000005, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_277) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 3
  s21_decimal expected_result = {
      {0x00000003, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_278) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_279) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_280) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 337
  s21_decimal expected_result = {
      {0x00000151, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_281) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12349
  s21_decimal expected_result = {
      {0x0000303D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_282) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 4.123456789
  s21_decimal expected_result = {
      {0xF5C6F515, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_283) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 3.9
  s21_decimal expected_result = {
      {0x00000027, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_284) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999996
  s21_decimal expected_result = {
      {0x11E1A2FC, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_285) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.00000000000101
  s21_decimal expected_result = {
      {0x52634065, 0x0001C6BF, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_286) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 2.2345
  s21_decimal expected_result = {
      {0x00005749, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_287) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.5
  s21_decimal expected_result = {
      {0x00000041, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_288) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.95033
  s21_decimal expected_result = {
      {0x0002F9D9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_289) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_290) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_291) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_292) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395033
  s21_decimal expected_result = {
      {0x6E3EA999, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_293) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.00000000000049
  s21_decimal expected_result = {
      {0x20F48031, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_294) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_295) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059831.45
  s21_decimal expected_result = {
      {0x39AE15A9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_296) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353454
  s21_decimal expected_result = {
      {0x0286432E, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_297) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889778
  s21_decimal expected_result = {
      {0xFC69CEF2, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_298) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5
  s21_decimal expected_result = {
      {0x00000005, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_299) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_300) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_301) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_302) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 334
  s21_decimal expected_result = {
      {0x0000014E, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_303) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12346
  s21_decimal expected_result = {
      {0x0000303A, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_304) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.123456789
  s21_decimal expected_result = {
      {0x42F69715, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_305) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.9
  s21_decimal expected_result = {
      {0x00000009, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_306) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999999
  s21_decimal expected_result = {
      {0x11E1A2FF, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_307) {
  // 1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.00000000000101
  s21_decimal expected_result = {
      {0x20F48065, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_308) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.2345
  s21_decimal expected_result = {
      {0x00000929, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_309) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 4.5
  s21_decimal expected_result = {
      {0x0000002D, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_310) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.04967
  s21_decimal expected_result = {
      {0x00001367, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_311) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_312) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_313) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426432.7593543950335
  s21_decimal expected_result = {
      {0xB18D5FFF, 0xFFFFF6E7, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_314) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426432.7593543950330
  s21_decimal expected_result = {
      {0xB18D5FFA, 0xFFFFF6E7, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_315) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.00000000000049
  s21_decimal expected_result = {
      {0x00000031, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_316) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394584.234509
  s21_decimal expected_result = {
      {0xB3241A0D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_317) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059833.45
  s21_decimal expected_result = {
      {0x39AE1671, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_318) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353456
  s21_decimal expected_result = {
      {0x02864330, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_319) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889780
  s21_decimal expected_result = {
      {0xFC69CEF4, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_320) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3
  s21_decimal expected_result = {
      {0x00000003, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_321) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_322) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_323) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_324) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 332
  s21_decimal expected_result = {
      {0x0000014C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_325) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12344
  s21_decimal expected_result = {
      {0x00003038, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_326) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.876543211
  s21_decimal expected_result = {
      {0x343EFCEB, 0x00000000, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_327) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -1.1
  s21_decimal expected_result = {
      {0x0000000B, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_328) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000001
  s21_decimal expected_result = {
      {0x11E1A301, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_329) {
  // -1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.00000000000101
  s21_decimal expected_result = {
      {0x00000065, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_330) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_331) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_332) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_333) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_334) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_335) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_336) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_337) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_338) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_339) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059832.45
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_340) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_341) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_342) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_343) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_344) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_345) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_346) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_347) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_348) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_349) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_350) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_351) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_352) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_353) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_354) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_355) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_356) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_357) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_358) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_359) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_360) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_361) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059832.45
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_362) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_363) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_364) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_365) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_366) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_367) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_368) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_369) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_370) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_371) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_372) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_373) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_374) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 334.2345
  s21_decimal expected_result = {
      {0x00330009, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_375) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 338.5
  s21_decimal expected_result = {
      {0x00000D39, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_376) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 333.95033
  s21_decimal expected_result = {
      {0x01FD9159, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_377) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_378) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950002
  s21_decimal expected_result = {
      {0xFFFFFEB2, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_379) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426766.759354395034
  s21_decimal expected_result = {
      {0x344F699A, 0x999AC876, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_380) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426766.759354395033
  s21_decimal expected_result = {
      {0x344F6999, 0x999AC876, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_381) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 334.00000000000049
  s21_decimal expected_result = {
      {0x7F7F8031, 0x0076A91F, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_382) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394918.234509
  s21_decimal expected_result = {
      {0xC70C898D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_383) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059499.45
  s21_decimal expected_result = {
      {0x39AD93F9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_384) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353122
  s21_decimal expected_result = {
      {0x028641E2, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_385) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889446
  s21_decimal expected_result = {
      {0xFC69CDA6, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_386) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 337
  s21_decimal expected_result = {
      {0x00000151, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_387) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 334
  s21_decimal expected_result = {
      {0x0000014E, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_388) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 332
  s21_decimal expected_result = {
      {0x0000014C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_389) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_390) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_391) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12678
  s21_decimal expected_result = {
      {0x00003186, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_392) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 333.123456789
  s21_decimal expected_result = {
      {0x8FB48F15, 0x0000004D, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_393) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 332.9
  s21_decimal expected_result = {
      {0x00000D01, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_394) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999667
  s21_decimal expected_result = {
      {0x11E1A1B3, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_395) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 334.00000000000101
  s21_decimal expected_result = {
      {0x7F7F8065, 0x0076A91F, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_396) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12346.2345
  s21_decimal expected_result = {
      {0x075BE2C9, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_397) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12350.5
  s21_decimal expected_result = {
      {0x0001E271, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_398) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345.95033
  s21_decimal expected_result = {
      {0x49966CD9, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_399) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_400) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543937990
  s21_decimal expected_result = {
      {0xFFFFCFC6, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_401) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251438778.759354395034
  s21_decimal expected_result = {
      {0xE55A299A, 0x99C5754F, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_402) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251438778.759354395033
  s21_decimal expected_result = {
      {0xE55A2999, 0x99C5754F, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_403) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12346.00000000000049
  s21_decimal expected_result = {
      {0xA7B28031, 0x11222E28, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_404) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720406930.234509
  s21_decimal expected_result = {
      {0x93051C8D, 0x9E691CEF, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_405) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834047487.45
  s21_decimal expected_result = {
      {0x399B3FC9, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_406) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42341110
  s21_decimal expected_result = {
      {0x028612F6, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_407) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597877434
  s21_decimal expected_result = {
      {0xFC699EBA, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_408) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12349
  s21_decimal expected_result = {
      {0x0000303D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_409) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12346
  s21_decimal expected_result = {
      {0x0000303A, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_410) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12344
  s21_decimal expected_result = {
      {0x00003038, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_411) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_412) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_413) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12678
  s21_decimal expected_result = {
      {0x00003186, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_414) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 12345.123456789
  s21_decimal expected_result = {
      {0x52B2C715, 0x00000B3A, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_415) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12344.9
  s21_decimal expected_result = {
      {0x0001E239, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_416) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299987655
  s21_decimal expected_result = {
      {0x11E172C7, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_417) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12346.00000000000101
  s21_decimal expected_result = {
      {0xA7B28065, 0x11222E28, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_418) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.357956789
  s21_decimal expected_result = {
      {0x50F0C6B5, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_419) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.623456789
  s21_decimal expected_result = {
      {0x4F2F2415, 0x00000001, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_420) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.073786789
  s21_decimal expected_result = {
      {0x4000AFA5, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_421) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_422) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_423) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.882811184034
  s21_decimal expected_result = {
      {0x5832B3A2, 0x999999B6, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_424) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.882811184033
  s21_decimal expected_result = {
      {0x5832B3A1, 0x999999B6, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_425) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.12345678900049
  s21_decimal expected_result = {
      {0x84486B51, 0x0000662D, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_426) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394585.357966
  s21_decimal expected_result = {
      {0xB3353E8E, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_427) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059832.326543211
  s21_decimal expected_result = {
      {0xE852D76B, 0x92873A45, 0x097BA361, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_428) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353454.876543211
  s21_decimal expected_result = {
      {0x28ED48EB, 0x0096783E, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_429) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889778.876
  s21_decimal expected_result = {
      {0xFD5064BC, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_430) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4.123456789
  s21_decimal expected_result = {
      {0xF5C6F515, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_431) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.123456789
  s21_decimal expected_result = {
      {0x42F69715, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_432) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.876543211
  s21_decimal expected_result = {
      {0x343EFCEB, 0x00000000, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_433) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_434) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_435) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333.123456789
  s21_decimal expected_result = {
      {0x8FB48F15, 0x0000004D, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_436) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345.123456789
  s21_decimal expected_result = {
      {0x52B2C715, 0x00000B3A, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_437) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.023456789
  s21_decimal expected_result = {
      {0x0165EC15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_438) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999999.876543211
  s21_decimal expected_result = {
      {0x114232EB, 0x0429D069, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_439) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.12345678900101
  s21_decimal expected_result = {
      {0x84486B85, 0x0000662D, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_440) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.1345
  s21_decimal expected_result = {
      {0x00002C51, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_441) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.4
  s21_decimal expected_result = {
      {0x00000036, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_442) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.85033
  s21_decimal expected_result = {
      {0x00014C29, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_443) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_444) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_445) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.6593543950335
  s21_decimal expected_result = {
      {0x2B5AEFFF, 0xFFFFFF17, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_446) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.6593543950330
  s21_decimal expected_result = {
      {0x2B5AEFFA, 0xFFFFFF17, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_447) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.90000000000049
  s21_decimal expected_result = {
      {0xC207A031, 0x000051DA, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_448) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394585.134509
  s21_decimal expected_result = {
      {0xB331D5AD, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_449) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059832.55
  s21_decimal expected_result = {
      {0x39AE1617, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_450) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455.1
  s21_decimal expected_result = {
      {0x193E9FD7, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_451) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779.1
  s21_decimal expected_result = {
      {0xDC22157F, 0x76CB3E01, 0x005DE9E0, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_452) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.9
  s21_decimal expected_result = {
      {0x00000027, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_453) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.9
  s21_decimal expected_result = {
      {0x00000009, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_454) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1.1
  s21_decimal expected_result = {
      {0x0000000B, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_455) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_456) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_457) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 332.9
  s21_decimal expected_result = {
      {0x00000D01, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_458) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12344.9
  s21_decimal expected_result = {
      {0x0001E239, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_459) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.023456789
  s21_decimal expected_result = {
      {0x0165EC15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_460) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000.1
  s21_decimal expected_result = {
      {0xB2D05E01, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_461) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.90000000000101
  s21_decimal expected_result = {
      {0xC207A065, 0x000051DA, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_462) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -299999998.7655
  s21_decimal expected_result = {
      {0x7DEEFFC7, 0x000002BA, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_463) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -299999994.5
  s21_decimal expected_result = {
      {0xB2D05DC9, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_464) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -299999999.04967
  s21_decimal expected_result = {
      {0xEB566CC7, 0x00001B48, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_465) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593243950335
  s21_decimal expected_result = {
      {0xEE1E5CFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_466) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_add_gen2_467) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922815951426433.7593543950335
  s21_decimal expected_result = {
      {0x641FFFFF, 0x5EA2F6AE, 0xFFFFFF5D, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_468) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922815951426433.7593543950330
  s21_decimal expected_result = {
      {0x641FFFFA, 0x5EA2F6AE, 0xFFFFFF5D, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_469) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -299999998.99999999999951
  s21_decimal expected_result = {
      {0x0645BFCF, 0x4DA2023D, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_470) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823420394585.234509
  s21_decimal expected_result = {
      {0x81C49C4D, 0x9E680C13, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_471) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834510134059832.45
  s21_decimal expected_result = {
      {0x35D1C20D, 0xE8E6ABC1, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_472) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -342353455
  s21_decimal expected_result = {
      {0x1467E62F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_473) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534897889779
  s21_decimal expected_result = {
      {0x0E4B71F3, 0x0BE11FCD, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_474) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -299999996
  s21_decimal expected_result = {
      {0x11E1A2FC, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_475) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -299999999
  s21_decimal expected_result = {
      {0x11E1A2FF, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_476) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000001
  s21_decimal expected_result = {
      {0x11E1A301, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_477) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_478) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_479) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -299999667
  s21_decimal expected_result = {
      {0x11E1A1B3, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_480) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -299987655
  s21_decimal expected_result = {
      {0x11E172C7, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_481) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -299999999.876543211
  s21_decimal expected_result = {
      {0x114232EB, 0x0429D069, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_482) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -300000000.1
  s21_decimal expected_result = {
      {0xB2D05E01, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_483) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -299999998.99999999999899
  s21_decimal expected_result = {
      {0x0645BF9B, 0x4DA2023D, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_484) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 2.23450000000101
  s21_decimal expected_result = {
      {0x01E00465, 0x0000CB3A, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_485) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.50000000000101
  s21_decimal expected_result = {
      {0xEB1AA065, 0x00024F2B, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_486) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.95033000000101
  s21_decimal expected_result = {
      {0xA8AF3A65, 0x0000B161, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_487) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_add_gen2_488) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950334
  s21_decimal expected_result = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_489) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_490) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426434.759354395034
  s21_decimal expected_result = {
      {0x6E3EA99A, 0x99999A82, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_491) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 2.00000000000150
  s21_decimal expected_result = {
      {0x20F48096, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_492) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581823720394586.234509
  s21_decimal expected_result = {
      {0xB3429E8D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_493) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509834059831.4500000000
  s21_decimal expected_result = {
      {0x08C68900, 0xB94846B9, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_494) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353453.99999999999899
  s21_decimal expected_result = {
      {0x74B77F9B, 0x9939897A, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_495) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324534534597889778.000
  s21_decimal expected_result = {
      {0xFD506150, 0x676438B9, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_496) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.00000000000101
  s21_decimal expected_result = {
      {0x52634065, 0x0001C6BF, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_497) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2.00000000000101
  s21_decimal expected_result = {
      {0x20F48065, 0x0000B5E6, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_498) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.00000000000101
  s21_decimal expected_result = {
      {0x00000065, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_499) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_500) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_501) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 334.00000000000101
  s21_decimal expected_result = {
      {0x7F7F8065, 0x0076A91F, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_502) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12346.00000000000101
  s21_decimal expected_result = {
      {0xA7B28065, 0x11222E28, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_503) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.12345678900101
  s21_decimal expected_result = {
      {0x84486B85, 0x0000662D, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_504) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.90000000000101
  s21_decimal expected_result = {
      {0xC207A065, 0x000051DA, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_add_gen2_505) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -299999998.99999999999899
  s21_decimal expected_result = {
      {0x0645BF9B, 0x4DA2023D, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_add(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_add_suite() {
  Suite* add_suite = suite_create("add");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_add_null);
  tcase_add_test(tc_core, test_add_first_decimal_incorrect);
  tcase_add_test(tc_core, test_add_second_decimal_incorrect);
  tcase_add_test(tc_core, test_add_both_decimals_incorrect);

  tcase_add_test(tc_core, test_add_gen2_0);
  tcase_add_test(tc_core, test_add_gen2_1);
  tcase_add_test(tc_core, test_add_gen2_2);
  tcase_add_test(tc_core, test_add_gen2_3);
  tcase_add_test(tc_core, test_add_gen2_4);
  tcase_add_test(tc_core, test_add_gen2_5);
  tcase_add_test(tc_core, test_add_gen2_6);
  tcase_add_test(tc_core, test_add_gen2_7);
  tcase_add_test(tc_core, test_add_gen2_8);
  tcase_add_test(tc_core, test_add_gen2_9);
  tcase_add_test(tc_core, test_add_gen2_10);
  tcase_add_test(tc_core, test_add_gen2_11);
  tcase_add_test(tc_core, test_add_gen2_12);
  tcase_add_test(tc_core, test_add_gen2_13);
  tcase_add_test(tc_core, test_add_gen2_14);
  tcase_add_test(tc_core, test_add_gen2_15);
  tcase_add_test(tc_core, test_add_gen2_16);
  tcase_add_test(tc_core, test_add_gen2_17);
  tcase_add_test(tc_core, test_add_gen2_18);
  tcase_add_test(tc_core, test_add_gen2_19);
  tcase_add_test(tc_core, test_add_gen2_20);
  tcase_add_test(tc_core, test_add_gen2_21);
  tcase_add_test(tc_core, test_add_gen2_22);
  tcase_add_test(tc_core, test_add_gen2_23);
  tcase_add_test(tc_core, test_add_gen2_24);
  tcase_add_test(tc_core, test_add_gen2_25);
  tcase_add_test(tc_core, test_add_gen2_26);
  tcase_add_test(tc_core, test_add_gen2_27);
  tcase_add_test(tc_core, test_add_gen2_28);
  tcase_add_test(tc_core, test_add_gen2_29);
  tcase_add_test(tc_core, test_add_gen2_30);
  tcase_add_test(tc_core, test_add_gen2_31);
  tcase_add_test(tc_core, test_add_gen2_32);
  tcase_add_test(tc_core, test_add_gen2_33);
  tcase_add_test(tc_core, test_add_gen2_34);
  tcase_add_test(tc_core, test_add_gen2_35);
  tcase_add_test(tc_core, test_add_gen2_36);
  tcase_add_test(tc_core, test_add_gen2_37);
  tcase_add_test(tc_core, test_add_gen2_38);
  tcase_add_test(tc_core, test_add_gen2_39);
  tcase_add_test(tc_core, test_add_gen2_40);
  tcase_add_test(tc_core, test_add_gen2_41);
  tcase_add_test(tc_core, test_add_gen2_42);
  tcase_add_test(tc_core, test_add_gen2_43);
  tcase_add_test(tc_core, test_add_gen2_44);
  tcase_add_test(tc_core, test_add_gen2_45);
  tcase_add_test(tc_core, test_add_gen2_46);
  tcase_add_test(tc_core, test_add_gen2_47);
  tcase_add_test(tc_core, test_add_gen2_48);
  tcase_add_test(tc_core, test_add_gen2_49);
  tcase_add_test(tc_core, test_add_gen2_50);
  tcase_add_test(tc_core, test_add_gen2_51);
  tcase_add_test(tc_core, test_add_gen2_52);
  tcase_add_test(tc_core, test_add_gen2_53);
  tcase_add_test(tc_core, test_add_gen2_54);
  tcase_add_test(tc_core, test_add_gen2_55);
  tcase_add_test(tc_core, test_add_gen2_56);
  tcase_add_test(tc_core, test_add_gen2_57);
  tcase_add_test(tc_core, test_add_gen2_58);
  tcase_add_test(tc_core, test_add_gen2_59);
  tcase_add_test(tc_core, test_add_gen2_60);
  tcase_add_test(tc_core, test_add_gen2_61);
  tcase_add_test(tc_core, test_add_gen2_62);
  tcase_add_test(tc_core, test_add_gen2_63);
  tcase_add_test(tc_core, test_add_gen2_64);
  tcase_add_test(tc_core, test_add_gen2_65);
  tcase_add_test(tc_core, test_add_gen2_66);
  tcase_add_test(tc_core, test_add_gen2_67);
  tcase_add_test(tc_core, test_add_gen2_68);
  tcase_add_test(tc_core, test_add_gen2_69);
  tcase_add_test(tc_core, test_add_gen2_70);
  tcase_add_test(tc_core, test_add_gen2_71);
  tcase_add_test(tc_core, test_add_gen2_72);
  tcase_add_test(tc_core, test_add_gen2_73);
  tcase_add_test(tc_core, test_add_gen2_74);
  tcase_add_test(tc_core, test_add_gen2_75);
  tcase_add_test(tc_core, test_add_gen2_76);
  tcase_add_test(tc_core, test_add_gen2_77);
  tcase_add_test(tc_core, test_add_gen2_78);
  tcase_add_test(tc_core, test_add_gen2_79);
  tcase_add_test(tc_core, test_add_gen2_80);
  tcase_add_test(tc_core, test_add_gen2_81);
  tcase_add_test(tc_core, test_add_gen2_82);
  tcase_add_test(tc_core, test_add_gen2_83);
  tcase_add_test(tc_core, test_add_gen2_84);
  tcase_add_test(tc_core, test_add_gen2_85);
  tcase_add_test(tc_core, test_add_gen2_86);
  tcase_add_test(tc_core, test_add_gen2_87);
  tcase_add_test(tc_core, test_add_gen2_88);
  tcase_add_test(tc_core, test_add_gen2_89);
  tcase_add_test(tc_core, test_add_gen2_90);
  tcase_add_test(tc_core, test_add_gen2_91);
  tcase_add_test(tc_core, test_add_gen2_92);
  tcase_add_test(tc_core, test_add_gen2_93);
  tcase_add_test(tc_core, test_add_gen2_94);
  tcase_add_test(tc_core, test_add_gen2_95);
  tcase_add_test(tc_core, test_add_gen2_96);
  tcase_add_test(tc_core, test_add_gen2_97);
  tcase_add_test(tc_core, test_add_gen2_98);
  tcase_add_test(tc_core, test_add_gen2_99);
  tcase_add_test(tc_core, test_add_gen2_100);
  tcase_add_test(tc_core, test_add_gen2_101);
  tcase_add_test(tc_core, test_add_gen2_102);
  tcase_add_test(tc_core, test_add_gen2_103);
  tcase_add_test(tc_core, test_add_gen2_104);
  tcase_add_test(tc_core, test_add_gen2_105);
  tcase_add_test(tc_core, test_add_gen2_106);
  tcase_add_test(tc_core, test_add_gen2_107);
  tcase_add_test(tc_core, test_add_gen2_108);
  tcase_add_test(tc_core, test_add_gen2_109);
  tcase_add_test(tc_core, test_add_gen2_110);
  tcase_add_test(tc_core, test_add_gen2_111);
  tcase_add_test(tc_core, test_add_gen2_112);
  tcase_add_test(tc_core, test_add_gen2_113);
  tcase_add_test(tc_core, test_add_gen2_114);
  tcase_add_test(tc_core, test_add_gen2_115);
  tcase_add_test(tc_core, test_add_gen2_116);
  tcase_add_test(tc_core, test_add_gen2_117);
  tcase_add_test(tc_core, test_add_gen2_118);
  tcase_add_test(tc_core, test_add_gen2_119);
  tcase_add_test(tc_core, test_add_gen2_120);
  tcase_add_test(tc_core, test_add_gen2_121);
  tcase_add_test(tc_core, test_add_gen2_122);
  tcase_add_test(tc_core, test_add_gen2_123);
  tcase_add_test(tc_core, test_add_gen2_124);
  tcase_add_test(tc_core, test_add_gen2_125);
  tcase_add_test(tc_core, test_add_gen2_126);
  tcase_add_test(tc_core, test_add_gen2_127);
  tcase_add_test(tc_core, test_add_gen2_128);
  tcase_add_test(tc_core, test_add_gen2_129);
  tcase_add_test(tc_core, test_add_gen2_130);
  tcase_add_test(tc_core, test_add_gen2_131);
  tcase_add_test(tc_core, test_add_gen2_132);
  tcase_add_test(tc_core, test_add_gen2_133);
  tcase_add_test(tc_core, test_add_gen2_134);
  tcase_add_test(tc_core, test_add_gen2_135);
  tcase_add_test(tc_core, test_add_gen2_136);
  tcase_add_test(tc_core, test_add_gen2_137);
  tcase_add_test(tc_core, test_add_gen2_138);
  tcase_add_test(tc_core, test_add_gen2_139);
  tcase_add_test(tc_core, test_add_gen2_140);
  tcase_add_test(tc_core, test_add_gen2_141);
  tcase_add_test(tc_core, test_add_gen2_142);
  tcase_add_test(tc_core, test_add_gen2_143);
  tcase_add_test(tc_core, test_add_gen2_144);
  tcase_add_test(tc_core, test_add_gen2_145);
  tcase_add_test(tc_core, test_add_gen2_146);
  tcase_add_test(tc_core, test_add_gen2_147);
  tcase_add_test(tc_core, test_add_gen2_148);
  tcase_add_test(tc_core, test_add_gen2_149);
  tcase_add_test(tc_core, test_add_gen2_150);
  tcase_add_test(tc_core, test_add_gen2_151);
  tcase_add_test(tc_core, test_add_gen2_152);
  tcase_add_test(tc_core, test_add_gen2_153);
  tcase_add_test(tc_core, test_add_gen2_154);
  tcase_add_test(tc_core, test_add_gen2_155);
  tcase_add_test(tc_core, test_add_gen2_156);
  tcase_add_test(tc_core, test_add_gen2_157);
  tcase_add_test(tc_core, test_add_gen2_158);
  tcase_add_test(tc_core, test_add_gen2_159);
  tcase_add_test(tc_core, test_add_gen2_160);
  tcase_add_test(tc_core, test_add_gen2_161);
  tcase_add_test(tc_core, test_add_gen2_162);
  tcase_add_test(tc_core, test_add_gen2_163);
  tcase_add_test(tc_core, test_add_gen2_164);
  tcase_add_test(tc_core, test_add_gen2_165);
  tcase_add_test(tc_core, test_add_gen2_166);
  tcase_add_test(tc_core, test_add_gen2_167);
  tcase_add_test(tc_core, test_add_gen2_168);
  tcase_add_test(tc_core, test_add_gen2_169);
  tcase_add_test(tc_core, test_add_gen2_170);
  tcase_add_test(tc_core, test_add_gen2_171);
  tcase_add_test(tc_core, test_add_gen2_172);
  tcase_add_test(tc_core, test_add_gen2_173);
  tcase_add_test(tc_core, test_add_gen2_174);
  tcase_add_test(tc_core, test_add_gen2_175);
  tcase_add_test(tc_core, test_add_gen2_176);
  tcase_add_test(tc_core, test_add_gen2_177);
  tcase_add_test(tc_core, test_add_gen2_178);
  tcase_add_test(tc_core, test_add_gen2_179);
  tcase_add_test(tc_core, test_add_gen2_180);
  tcase_add_test(tc_core, test_add_gen2_181);
  tcase_add_test(tc_core, test_add_gen2_182);
  tcase_add_test(tc_core, test_add_gen2_183);
  tcase_add_test(tc_core, test_add_gen2_184);
  tcase_add_test(tc_core, test_add_gen2_185);
  tcase_add_test(tc_core, test_add_gen2_186);
  tcase_add_test(tc_core, test_add_gen2_187);
  tcase_add_test(tc_core, test_add_gen2_188);
  tcase_add_test(tc_core, test_add_gen2_189);
  tcase_add_test(tc_core, test_add_gen2_190);
  tcase_add_test(tc_core, test_add_gen2_191);
  tcase_add_test(tc_core, test_add_gen2_192);
  tcase_add_test(tc_core, test_add_gen2_193);
  tcase_add_test(tc_core, test_add_gen2_194);
  tcase_add_test(tc_core, test_add_gen2_195);
  tcase_add_test(tc_core, test_add_gen2_196);
  tcase_add_test(tc_core, test_add_gen2_197);
  tcase_add_test(tc_core, test_add_gen2_198);
  tcase_add_test(tc_core, test_add_gen2_199);
  tcase_add_test(tc_core, test_add_gen2_200);
  tcase_add_test(tc_core, test_add_gen2_201);
  tcase_add_test(tc_core, test_add_gen2_202);
  tcase_add_test(tc_core, test_add_gen2_203);
  tcase_add_test(tc_core, test_add_gen2_204);
  tcase_add_test(tc_core, test_add_gen2_205);
  tcase_add_test(tc_core, test_add_gen2_206);
  tcase_add_test(tc_core, test_add_gen2_207);
  tcase_add_test(tc_core, test_add_gen2_208);
  tcase_add_test(tc_core, test_add_gen2_209);
  tcase_add_test(tc_core, test_add_gen2_210);
  tcase_add_test(tc_core, test_add_gen2_211);
  tcase_add_test(tc_core, test_add_gen2_212);
  tcase_add_test(tc_core, test_add_gen2_213);
  tcase_add_test(tc_core, test_add_gen2_214);
  tcase_add_test(tc_core, test_add_gen2_215);
  tcase_add_test(tc_core, test_add_gen2_216);
  tcase_add_test(tc_core, test_add_gen2_217);
  tcase_add_test(tc_core, test_add_gen2_218);
  tcase_add_test(tc_core, test_add_gen2_219);
  tcase_add_test(tc_core, test_add_gen2_220);
  tcase_add_test(tc_core, test_add_gen2_221);
  tcase_add_test(tc_core, test_add_gen2_222);
  tcase_add_test(tc_core, test_add_gen2_223);
  tcase_add_test(tc_core, test_add_gen2_224);
  tcase_add_test(tc_core, test_add_gen2_225);
  tcase_add_test(tc_core, test_add_gen2_226);
  tcase_add_test(tc_core, test_add_gen2_227);
  tcase_add_test(tc_core, test_add_gen2_228);
  tcase_add_test(tc_core, test_add_gen2_229);
  tcase_add_test(tc_core, test_add_gen2_230);
  tcase_add_test(tc_core, test_add_gen2_231);
  tcase_add_test(tc_core, test_add_gen2_232);
  tcase_add_test(tc_core, test_add_gen2_233);
  tcase_add_test(tc_core, test_add_gen2_234);
  tcase_add_test(tc_core, test_add_gen2_235);
  tcase_add_test(tc_core, test_add_gen2_236);
  tcase_add_test(tc_core, test_add_gen2_237);
  tcase_add_test(tc_core, test_add_gen2_238);
  tcase_add_test(tc_core, test_add_gen2_239);
  tcase_add_test(tc_core, test_add_gen2_240);
  tcase_add_test(tc_core, test_add_gen2_241);
  tcase_add_test(tc_core, test_add_gen2_242);
  tcase_add_test(tc_core, test_add_gen2_243);
  tcase_add_test(tc_core, test_add_gen2_244);
  tcase_add_test(tc_core, test_add_gen2_245);
  tcase_add_test(tc_core, test_add_gen2_246);
  tcase_add_test(tc_core, test_add_gen2_247);
  tcase_add_test(tc_core, test_add_gen2_248);
  tcase_add_test(tc_core, test_add_gen2_249);
  tcase_add_test(tc_core, test_add_gen2_250);
  tcase_add_test(tc_core, test_add_gen2_251);
  tcase_add_test(tc_core, test_add_gen2_252);
  tcase_add_test(tc_core, test_add_gen2_253);
  tcase_add_test(tc_core, test_add_gen2_254);
  tcase_add_test(tc_core, test_add_gen2_255);
  tcase_add_test(tc_core, test_add_gen2_256);
  tcase_add_test(tc_core, test_add_gen2_257);
  tcase_add_test(tc_core, test_add_gen2_258);
  tcase_add_test(tc_core, test_add_gen2_259);
  tcase_add_test(tc_core, test_add_gen2_260);
  tcase_add_test(tc_core, test_add_gen2_261);
  tcase_add_test(tc_core, test_add_gen2_262);
  tcase_add_test(tc_core, test_add_gen2_263);
  tcase_add_test(tc_core, test_add_gen2_264);
  tcase_add_test(tc_core, test_add_gen2_265);
  tcase_add_test(tc_core, test_add_gen2_266);
  tcase_add_test(tc_core, test_add_gen2_267);
  tcase_add_test(tc_core, test_add_gen2_268);
  tcase_add_test(tc_core, test_add_gen2_269);
  tcase_add_test(tc_core, test_add_gen2_270);
  tcase_add_test(tc_core, test_add_gen2_271);
  tcase_add_test(tc_core, test_add_gen2_272);
  tcase_add_test(tc_core, test_add_gen2_273);
  tcase_add_test(tc_core, test_add_gen2_274);
  tcase_add_test(tc_core, test_add_gen2_275);
  tcase_add_test(tc_core, test_add_gen2_276);
  tcase_add_test(tc_core, test_add_gen2_277);
  tcase_add_test(tc_core, test_add_gen2_278);
  tcase_add_test(tc_core, test_add_gen2_279);
  tcase_add_test(tc_core, test_add_gen2_280);
  tcase_add_test(tc_core, test_add_gen2_281);
  tcase_add_test(tc_core, test_add_gen2_282);
  tcase_add_test(tc_core, test_add_gen2_283);
  tcase_add_test(tc_core, test_add_gen2_284);
  tcase_add_test(tc_core, test_add_gen2_285);
  tcase_add_test(tc_core, test_add_gen2_286);
  tcase_add_test(tc_core, test_add_gen2_287);
  tcase_add_test(tc_core, test_add_gen2_288);
  tcase_add_test(tc_core, test_add_gen2_289);
  tcase_add_test(tc_core, test_add_gen2_290);
  tcase_add_test(tc_core, test_add_gen2_291);
  tcase_add_test(tc_core, test_add_gen2_292);
  tcase_add_test(tc_core, test_add_gen2_293);
  tcase_add_test(tc_core, test_add_gen2_294);
  tcase_add_test(tc_core, test_add_gen2_295);
  tcase_add_test(tc_core, test_add_gen2_296);
  tcase_add_test(tc_core, test_add_gen2_297);
  tcase_add_test(tc_core, test_add_gen2_298);
  tcase_add_test(tc_core, test_add_gen2_299);
  tcase_add_test(tc_core, test_add_gen2_300);
  tcase_add_test(tc_core, test_add_gen2_301);
  tcase_add_test(tc_core, test_add_gen2_302);
  tcase_add_test(tc_core, test_add_gen2_303);
  tcase_add_test(tc_core, test_add_gen2_304);
  tcase_add_test(tc_core, test_add_gen2_305);
  tcase_add_test(tc_core, test_add_gen2_306);
  tcase_add_test(tc_core, test_add_gen2_307);
  tcase_add_test(tc_core, test_add_gen2_308);
  tcase_add_test(tc_core, test_add_gen2_309);
  tcase_add_test(tc_core, test_add_gen2_310);
  tcase_add_test(tc_core, test_add_gen2_311);
  tcase_add_test(tc_core, test_add_gen2_312);
  tcase_add_test(tc_core, test_add_gen2_313);
  tcase_add_test(tc_core, test_add_gen2_314);
  tcase_add_test(tc_core, test_add_gen2_315);
  tcase_add_test(tc_core, test_add_gen2_316);
  tcase_add_test(tc_core, test_add_gen2_317);
  tcase_add_test(tc_core, test_add_gen2_318);
  tcase_add_test(tc_core, test_add_gen2_319);
  tcase_add_test(tc_core, test_add_gen2_320);
  tcase_add_test(tc_core, test_add_gen2_321);
  tcase_add_test(tc_core, test_add_gen2_322);
  tcase_add_test(tc_core, test_add_gen2_323);
  tcase_add_test(tc_core, test_add_gen2_324);
  tcase_add_test(tc_core, test_add_gen2_325);
  tcase_add_test(tc_core, test_add_gen2_326);
  tcase_add_test(tc_core, test_add_gen2_327);
  tcase_add_test(tc_core, test_add_gen2_328);
  tcase_add_test(tc_core, test_add_gen2_329);
  tcase_add_test(tc_core, test_add_gen2_330);
  tcase_add_test(tc_core, test_add_gen2_331);
  tcase_add_test(tc_core, test_add_gen2_332);
  tcase_add_test(tc_core, test_add_gen2_333);
  tcase_add_test(tc_core, test_add_gen2_334);
  tcase_add_test(tc_core, test_add_gen2_335);
  tcase_add_test(tc_core, test_add_gen2_336);
  tcase_add_test(tc_core, test_add_gen2_337);
  tcase_add_test(tc_core, test_add_gen2_338);
  tcase_add_test(tc_core, test_add_gen2_339);
  tcase_add_test(tc_core, test_add_gen2_340);
  tcase_add_test(tc_core, test_add_gen2_341);
  tcase_add_test(tc_core, test_add_gen2_342);
  tcase_add_test(tc_core, test_add_gen2_343);
  tcase_add_test(tc_core, test_add_gen2_344);
  tcase_add_test(tc_core, test_add_gen2_345);
  tcase_add_test(tc_core, test_add_gen2_346);
  tcase_add_test(tc_core, test_add_gen2_347);
  tcase_add_test(tc_core, test_add_gen2_348);
  tcase_add_test(tc_core, test_add_gen2_349);
  tcase_add_test(tc_core, test_add_gen2_350);
  tcase_add_test(tc_core, test_add_gen2_351);
  tcase_add_test(tc_core, test_add_gen2_352);
  tcase_add_test(tc_core, test_add_gen2_353);
  tcase_add_test(tc_core, test_add_gen2_354);
  tcase_add_test(tc_core, test_add_gen2_355);
  tcase_add_test(tc_core, test_add_gen2_356);
  tcase_add_test(tc_core, test_add_gen2_357);
  tcase_add_test(tc_core, test_add_gen2_358);
  tcase_add_test(tc_core, test_add_gen2_359);
  tcase_add_test(tc_core, test_add_gen2_360);
  tcase_add_test(tc_core, test_add_gen2_361);
  tcase_add_test(tc_core, test_add_gen2_362);
  tcase_add_test(tc_core, test_add_gen2_363);
  tcase_add_test(tc_core, test_add_gen2_364);
  tcase_add_test(tc_core, test_add_gen2_365);
  tcase_add_test(tc_core, test_add_gen2_366);
  tcase_add_test(tc_core, test_add_gen2_367);
  tcase_add_test(tc_core, test_add_gen2_368);
  tcase_add_test(tc_core, test_add_gen2_369);
  tcase_add_test(tc_core, test_add_gen2_370);
  tcase_add_test(tc_core, test_add_gen2_371);
  tcase_add_test(tc_core, test_add_gen2_372);
  tcase_add_test(tc_core, test_add_gen2_373);
  tcase_add_test(tc_core, test_add_gen2_374);
  tcase_add_test(tc_core, test_add_gen2_375);
  tcase_add_test(tc_core, test_add_gen2_376);
  tcase_add_test(tc_core, test_add_gen2_377);
  tcase_add_test(tc_core, test_add_gen2_378);
  tcase_add_test(tc_core, test_add_gen2_379);
  tcase_add_test(tc_core, test_add_gen2_380);
  tcase_add_test(tc_core, test_add_gen2_381);
  tcase_add_test(tc_core, test_add_gen2_382);
  tcase_add_test(tc_core, test_add_gen2_383);
  tcase_add_test(tc_core, test_add_gen2_384);
  tcase_add_test(tc_core, test_add_gen2_385);
  tcase_add_test(tc_core, test_add_gen2_386);
  tcase_add_test(tc_core, test_add_gen2_387);
  tcase_add_test(tc_core, test_add_gen2_388);
  tcase_add_test(tc_core, test_add_gen2_389);
  tcase_add_test(tc_core, test_add_gen2_390);
  tcase_add_test(tc_core, test_add_gen2_391);
  tcase_add_test(tc_core, test_add_gen2_392);
  tcase_add_test(tc_core, test_add_gen2_393);
  tcase_add_test(tc_core, test_add_gen2_394);
  tcase_add_test(tc_core, test_add_gen2_395);
  tcase_add_test(tc_core, test_add_gen2_396);
  tcase_add_test(tc_core, test_add_gen2_397);
  tcase_add_test(tc_core, test_add_gen2_398);
  tcase_add_test(tc_core, test_add_gen2_399);
  tcase_add_test(tc_core, test_add_gen2_400);
  tcase_add_test(tc_core, test_add_gen2_401);
  tcase_add_test(tc_core, test_add_gen2_402);
  tcase_add_test(tc_core, test_add_gen2_403);
  tcase_add_test(tc_core, test_add_gen2_404);
  tcase_add_test(tc_core, test_add_gen2_405);
  tcase_add_test(tc_core, test_add_gen2_406);
  tcase_add_test(tc_core, test_add_gen2_407);
  tcase_add_test(tc_core, test_add_gen2_408);
  tcase_add_test(tc_core, test_add_gen2_409);
  tcase_add_test(tc_core, test_add_gen2_410);
  tcase_add_test(tc_core, test_add_gen2_411);
  tcase_add_test(tc_core, test_add_gen2_412);
  tcase_add_test(tc_core, test_add_gen2_413);
  tcase_add_test(tc_core, test_add_gen2_414);
  tcase_add_test(tc_core, test_add_gen2_415);
  tcase_add_test(tc_core, test_add_gen2_416);
  tcase_add_test(tc_core, test_add_gen2_417);
  tcase_add_test(tc_core, test_add_gen2_418);
  tcase_add_test(tc_core, test_add_gen2_419);
  tcase_add_test(tc_core, test_add_gen2_420);
  tcase_add_test(tc_core, test_add_gen2_421);
  tcase_add_test(tc_core, test_add_gen2_422);
  tcase_add_test(tc_core, test_add_gen2_423);
  tcase_add_test(tc_core, test_add_gen2_424);
  tcase_add_test(tc_core, test_add_gen2_425);
  tcase_add_test(tc_core, test_add_gen2_426);
  tcase_add_test(tc_core, test_add_gen2_427);
  tcase_add_test(tc_core, test_add_gen2_428);
  tcase_add_test(tc_core, test_add_gen2_429);
  tcase_add_test(tc_core, test_add_gen2_430);
  tcase_add_test(tc_core, test_add_gen2_431);
  tcase_add_test(tc_core, test_add_gen2_432);
  tcase_add_test(tc_core, test_add_gen2_433);
  tcase_add_test(tc_core, test_add_gen2_434);
  tcase_add_test(tc_core, test_add_gen2_435);
  tcase_add_test(tc_core, test_add_gen2_436);
  tcase_add_test(tc_core, test_add_gen2_437);
  tcase_add_test(tc_core, test_add_gen2_438);
  tcase_add_test(tc_core, test_add_gen2_439);
  tcase_add_test(tc_core, test_add_gen2_440);
  tcase_add_test(tc_core, test_add_gen2_441);
  tcase_add_test(tc_core, test_add_gen2_442);
  tcase_add_test(tc_core, test_add_gen2_443);
  tcase_add_test(tc_core, test_add_gen2_444);
  tcase_add_test(tc_core, test_add_gen2_445);
  tcase_add_test(tc_core, test_add_gen2_446);
  tcase_add_test(tc_core, test_add_gen2_447);
  tcase_add_test(tc_core, test_add_gen2_448);
  tcase_add_test(tc_core, test_add_gen2_449);
  tcase_add_test(tc_core, test_add_gen2_450);
  tcase_add_test(tc_core, test_add_gen2_451);
  tcase_add_test(tc_core, test_add_gen2_452);
  tcase_add_test(tc_core, test_add_gen2_453);
  tcase_add_test(tc_core, test_add_gen2_454);
  tcase_add_test(tc_core, test_add_gen2_455);
  tcase_add_test(tc_core, test_add_gen2_456);
  tcase_add_test(tc_core, test_add_gen2_457);
  tcase_add_test(tc_core, test_add_gen2_458);
  tcase_add_test(tc_core, test_add_gen2_459);
  tcase_add_test(tc_core, test_add_gen2_460);
  tcase_add_test(tc_core, test_add_gen2_461);
  tcase_add_test(tc_core, test_add_gen2_462);
  tcase_add_test(tc_core, test_add_gen2_463);
  tcase_add_test(tc_core, test_add_gen2_464);
  tcase_add_test(tc_core, test_add_gen2_465);
  tcase_add_test(tc_core, test_add_gen2_466);
  tcase_add_test(tc_core, test_add_gen2_467);
  tcase_add_test(tc_core, test_add_gen2_468);
  tcase_add_test(tc_core, test_add_gen2_469);
  tcase_add_test(tc_core, test_add_gen2_470);
  tcase_add_test(tc_core, test_add_gen2_471);
  tcase_add_test(tc_core, test_add_gen2_472);
  tcase_add_test(tc_core, test_add_gen2_473);
  tcase_add_test(tc_core, test_add_gen2_474);
  tcase_add_test(tc_core, test_add_gen2_475);
  tcase_add_test(tc_core, test_add_gen2_476);
  tcase_add_test(tc_core, test_add_gen2_477);
  tcase_add_test(tc_core, test_add_gen2_478);
  tcase_add_test(tc_core, test_add_gen2_479);
  tcase_add_test(tc_core, test_add_gen2_480);
  tcase_add_test(tc_core, test_add_gen2_481);
  tcase_add_test(tc_core, test_add_gen2_482);
  tcase_add_test(tc_core, test_add_gen2_483);
  tcase_add_test(tc_core, test_add_gen2_484);
  tcase_add_test(tc_core, test_add_gen2_485);
  tcase_add_test(tc_core, test_add_gen2_486);
  tcase_add_test(tc_core, test_add_gen2_487);
  tcase_add_test(tc_core, test_add_gen2_488);
  tcase_add_test(tc_core, test_add_gen2_489);
  tcase_add_test(tc_core, test_add_gen2_490);
  tcase_add_test(tc_core, test_add_gen2_491);
  tcase_add_test(tc_core, test_add_gen2_492);
  tcase_add_test(tc_core, test_add_gen2_493);
  tcase_add_test(tc_core, test_add_gen2_494);
  tcase_add_test(tc_core, test_add_gen2_495);
  tcase_add_test(tc_core, test_add_gen2_496);
  tcase_add_test(tc_core, test_add_gen2_497);
  tcase_add_test(tc_core, test_add_gen2_498);
  tcase_add_test(tc_core, test_add_gen2_499);
  tcase_add_test(tc_core, test_add_gen2_500);
  tcase_add_test(tc_core, test_add_gen2_501);
  tcase_add_test(tc_core, test_add_gen2_502);
  tcase_add_test(tc_core, test_add_gen2_503);
  tcase_add_test(tc_core, test_add_gen2_504);
  tcase_add_test(tc_core, test_add_gen2_505);

  suite_add_tcase(add_suite, tc_core);

  return add_suite;
}
