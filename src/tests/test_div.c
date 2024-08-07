#include "../arithmetic.h"
// #include "../debug_funcs.h"
#include "../comparison.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_div_gen_0) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.2244545454545454545454545454
  s21_decimal expected_result = {
      {0xF8E8BA2E, 0xE72D1FD5, 0x0740A4FC, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_1) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2990224448349520692811970579
  s21_decimal expected_result = {
      {0x19B4B813, 0x6614088F, 0x29F94306, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_2) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_3) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_4) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000001558158059992
  s21_decimal expected_result = {
      {0xC97529D8, 0x0000016A, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_5) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000000338001
  s21_decimal expected_result = {
      {0x00052851, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_6) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000000004206370055
  s21_decimal expected_result = {
      {0xFAB81D07, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_7) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000291475630500510525056
  s21_decimal expected_result = {
      {0xD9F16680, 0xCD0975A2, 0x0000000F, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_8) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000001087
  s21_decimal expected_result = {
      {0x0000043F, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_9) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.308625
  s21_decimal expected_result = {
      {0x0004B591, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_10) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_11) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_12) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0037072072072072072072072072
  s21_decimal expected_result = {
      {0xE4350B88, 0x0DCFEDB0, 0x001EAA51, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_13) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0001
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_14) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 9.999450090994995828054462035
  s21_decimal expected_result = {
      {0xB1968E53, 0x9DA8D5DC, 0x204F59EB, 0b00000000000110110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_15) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -12.345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_16) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.000000004115
  s21_decimal expected_result = {
      {0x00001013, 0x00000000, 0x00000000, 0b10000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_17) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4.4552450384771162413932766302
  s21_decimal expected_result = {
      {0xA5D8645E, 0xD6092648, 0x8FF4EC56, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_18) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.7874633022213336419980427851
  s21_decimal expected_result = {
      {0x28CE424B, 0xB9687EE3, 0xBB00C63E, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_19) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_20) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_21) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000006941975965944
  s21_decimal expected_result = {
      {0x4E02F0F8, 0x00000650, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_22) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000001505879
  s21_decimal expected_result = {
      {0x0016FA57, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_23) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000000018740409319
  s21_decimal expected_result = {
      {0x5D03F3E7, 0x00000004, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_24) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000001298595356624388730506
  s21_decimal expected_result = {
      {0xC865AE8A, 0x65A17C98, 0x00000046, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_25) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000004844
  s21_decimal expected_result = {
      {0x000012EC, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_26) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.375
  s21_decimal expected_result = {
      {0x0000055F, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_27) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_28) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_29) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0165165165165165165165165165
  s21_decimal expected_result = {
      {0xDC843A6D, 0x8B67A053, 0x00889F15, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_30) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0004455245038477116241393276
  s21_decimal expected_result = {
      {0x22A0B67C, 0x51469B10, 0x0003AF6F, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_31) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 44.550000405405003689185533572
  s21_decimal expected_result = {
      {0x39D45E84, 0x304237ED, 0x8FF2E589, 0b00000000000110110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_32) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -55
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_33) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000183333333333333333333
  s21_decimal expected_result = {
      {0x359D5555, 0xF042D753, 0x00000009, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_34) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.7698096395301741595787768327
  s21_decimal expected_result = {
      {0x0C2FB207, 0xCA19535C, 0x18DFB751, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_35) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.1727872727272727272727272727
  s21_decimal expected_result = {
      {0x40745D17, 0x3C002542, 0x05954348, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_36) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_37) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_38) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000001199485094493
  s21_decimal expected_result = {
      {0x46E20A5D, 0x00000117, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_39) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000000260196
  s21_decimal expected_result = {
      {0x0003F864, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_40) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000000003238104216
  s21_decimal expected_result = {
      {0xC1018C98, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_41) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000224380750047428244047
  s21_decimal expected_result = {
      {0x14AC724F, 0x29E88F59, 0x0000000C, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_42) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000837
  s21_decimal expected_result = {
      {0x00000345, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_43) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.2375825
  s21_decimal expected_result = {
      {0x00244091, 0x00000000, 0x00000000, 0b00000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_44) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_45) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_46) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0028538438438438438438438438
  s21_decimal expected_result = {
      {0xB0580626, 0xD903D8A3, 0x00179B3F, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_47) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000769809639530174159578776
  s21_decimal expected_result = {
      {0xCF90E698, 0x76D46E6B, 0x0000A303, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_48) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7.6976730700488249374443069307
  s21_decimal expected_result = {
      {0x572C5F7B, 0xD0A711BD, 0xF8B9A8C4, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_49) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -9.5033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_50) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000031677666666666666666
  s21_decimal expected_result = {
      {0x73E62AAA, 0xB79DADFF, 0x00000001, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_51) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 64178341445333606799144552722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_52) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 14405120457138970471553445515
  s21_decimal expected_result = {
      {0xE8BA2E8B, 0xBA2E8BA2, 0x2E8BA2E8, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_53) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_div_gen_54) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_55) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 10000000000000
  s21_decimal expected_result = {
      {0x4E72A000, 0x00000918, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_56) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 2169238.2785762515472907268011
  s21_decimal expected_result = {
      {0x12C46FAB, 0x22B30145, 0x461784BB, 0b00000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_57) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -26995785366.699951589583147737
  s21_decimal expected_result = {
      {0x6DAAD2D9, 0x205D50A4, 0x573A63E9, 0b10000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_58) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1870642253725565897600.1828029
  s21_decimal expected_result = {
      {0x5EBEA4BD, 0xB75A2721, 0x3C71970D, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_59) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -6978.3304068721923616180431371
  s21_decimal expected_result = {
      {0x04F66A0B, 0xB9EB079F, 0xE17B656D, 0b10000000000110010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_60) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 19807040628566084398385987584
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x40000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_61) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_62) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_63) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 237922409952745758539171022.03
  s21_decimal expected_result = {
      {0x0C4CE07B, 0xC4CE07B0, 0x4CE07B00, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_64) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 6417834144533360679914455.2722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_65) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_div_gen_66) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_div_gen_67) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -264093875047547791978.47983445
  s21_decimal expected_result = {
      {0x55555555, 0x55555555, 0x55555555, 0b10000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_68) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -64178341445333606799144552722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_69) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -14405120457138970471553445515
  s21_decimal expected_result = {
      {0xE8BA2E8B, 0xBA2E8BA2, 0x2E8BA2E8, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_70) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_div_gen_71) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_72) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -10000000000000
  s21_decimal expected_result = {
      {0x4E72A000, 0x00000918, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_73) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -2169238.2785762515472907268011
  s21_decimal expected_result = {
      {0x12C46FAB, 0x22B30145, 0x461784BB, 0b10000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_74) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 26995785366.699951589583147737
  s21_decimal expected_result = {
      {0x6DAAD2D9, 0x205D50A4, 0x573A63E9, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_75) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1870642253725565897600.1828029
  s21_decimal expected_result = {
      {0x5EBEA4BD, 0xB75A2721, 0x3C71970D, 0b00000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_76) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 6978.3304068721923616180431371
  s21_decimal expected_result = {
      {0x04F66A0B, 0xB9EB079F, 0xE17B656D, 0b00000000000110010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_77) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -19807040628566084398385987584
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x40000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_78) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_79) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_80) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -237922409952745758539171022.03
  s21_decimal expected_result = {
      {0x0C4CE07B, 0xC4CE07B0, 0x4CE07B00, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_81) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -6417834144533360679914455.2722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_82) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_div_gen_83) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_div_gen_84) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 264093875047547791978.47983445
  s21_decimal expected_result = {
      {0x55555555, 0x55555555, 0x55555555, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_85) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 6417834144533360.6799144552722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_86) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1440512045713897.0471553445515
  s21_decimal expected_result = {
      {0xE8BA2E8B, 0xBA2E8BA2, 0x2E8BA2E8, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_87) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 8336910600976959.329237628017
  s21_decimal expected_result = {
      {0xB2567471, 0x4513BF8D, 0x1AF0217D, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_88) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000001
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_89) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000001
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_90) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000002169238278576251547290
  s21_decimal expected_result = {
      {0x85532E9A, 0x983A813F, 0x00000075, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_91) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0026995785366699951589583147
  s21_decimal expected_result = {
      {0xAD2A692B, 0x75063CC0, 0x00165494, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_92) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -187064225.37255658976001828029
  s21_decimal expected_result = {
      {0x5EBEA4BD, 0xB75A2721, 0x3C71970D, 0b10000000000101000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_93) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000006978330406872192361
  s21_decimal expected_result = {
      {0x42EC9569, 0x60D80288, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_94) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1980704062856608.4398385987584
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x40000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_95) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_96) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_97) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 23792240995274.575853917102203
  s21_decimal expected_result = {
      {0x0C4CE07B, 0xC4CE07B0, 0x4CE07B00, 0b00000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_98) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 641783414453.33606799144552722
  s21_decimal expected_result = {
      {0x3B9E8912, 0x13CDD0ED, 0xCF5F146D, 0b00000000000100010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_99) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 64174812220544904.657729232157
  s21_decimal expected_result = {
      {0x9BD81D1D, 0x6B0F6EA5, 0xCF5C2915, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_100) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -79228162514264337.593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_101) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -26409387.504754779197847983445
  s21_decimal expected_result = {
      {0x55555555, 0x55555555, 0x55555555, 0b10000000000101010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_102) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 29585657822457448679291.400979
  s21_decimal expected_result = {
      {0x74DAB313, 0x46AB9EBD, 0x5F98AEBC, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_103) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6640635378513403708106.4062744
  s21_decimal expected_result = {
      {0x45D1BF18, 0x08BF1D51, 0xD6920C64, 0b00000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_104) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 38432433556578999289283.969262
  s21_decimal expected_result = {
      {0x6CC980EE, 0xCC2198B0, 0x7C2E905D, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_105) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000004609913119624348815746
  s21_decimal expected_result = {
      {0x8E23D182, 0xE76565EE, 0x000000F9, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_106) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000004609913119624348815746
  s21_decimal expected_result = {
      {0x8E23D182, 0xE76565EE, 0x000000F9, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_107) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4609913.1196243488157462098967
  s21_decimal expected_result = {
      {0x73FAF417, 0xA21123D4, 0x94F44EBD, 0b00000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_108) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -12444.822513651311919332223394
  s21_decimal expected_result = {
      {0xC6EA69A2, 0x465D7316, 0x28361DAC, 0b10000000000110000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_109) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -862349826757314.6132844471486
  s21_decimal expected_result = {
      {0xBC2164BE, 0xCE6F89DB, 0x1BDD30C9, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_110) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0032169496895713639649531029
  s21_decimal expected_result = {
      {0xA9285495, 0xEBCD8837, 0x001A9C27, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_111) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 9130873645455930098646.308627
  s21_decimal expected_result = {
      {0x2CCCD713, 0x279A473B, 0x1D80E1B4, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_112) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_113) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_114) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 109680163909380541725.48118471
  s21_decimal expected_result = {
      {0x8B25B7C7, 0xF211BA45, 0x237087CF, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_115) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2958565782245744867.9291400979
  s21_decimal expected_result = {
      {0x74DAB313, 0x46AB9EBD, 0x5F98AEBC, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_116) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 295840308804918945320902.80194
  s21_decimal expected_result = {
      {0x92B2B902, 0x934BFB35, 0x5F975637, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_117) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -365234945818237203945852.34509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_118) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -121744981939412.40131528411503
  s21_decimal expected_result = {
      {0x3BBBC96F, 0x8A2309A4, 0x27568245, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_119) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -2377346707034475360.4293236128
  s21_decimal expected_result = {
      {0x772715A0, 0x424F13A8, 0x4CD0F378, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_120) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -533606274515283605.9
  s21_decimal expected_result = {
      {0x8807D1DB, 0x4A0D80CB, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_121) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -3088226731592246727.3999558048
  s21_decimal expected_result = {
      {0x3296A5A0, 0xC293615F, 0x63C93679, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_122) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0000000000370428193296249746
  s21_decimal expected_result = {
      {0xAC367392, 0x0524067A, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_123) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0000000000370428193296249746
  s21_decimal expected_result = {
      {0xAC367392, 0x0524067A, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_124) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -370.42819329624974605659622134
  s21_decimal expected_result = {
      {0xFF5F4AF6, 0x9BBE3FCA, 0x77B11A1B, 0b10000000000110100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_125) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.0000803547016362067762540820
  s21_decimal expected_result = {
      {0xBF52F114, 0x5EFC96BE, 0x0000AA28, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_126) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 69293863035.118618597939648607
  s21_decimal expected_result = {
      {0xAEFE985F, 0x21224FF9, 0xDFE68A42, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_127) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.0000002584970324841949609397
  s21_decimal expected_result = {
      {0x1A84BDB5, 0x21AB6EAF, 0x0000008C, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_128) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -733708627458514958.1125
  s21_decimal expected_result = {
      {0xA2002745, 0xBE86C52F, 0x0000018D, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_129) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_130) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_131) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -8813316846348528.025375375375
  s21_decimal expected_result = {
      {0x01BC800F, 0x94A94EE6, 0x1C7A346F, 0b10000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_132) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -237734670703447.53604293236128
  s21_decimal expected_result = {
      {0x772715A0, 0x424F13A8, 0x4CD0F378, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_133) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -23772159745982538331.286098815
  s21_decimal expected_result = {
      {0xD9E7537F, 0x1036CE31, 0x4CCFDEA2, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_134) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 29348345098340598324.5
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_135) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 9782781699.446866108166666667
  s21_decimal expected_result = {
      {0xC99B79AB, 0x93181793, 0x1F9C209A, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_136) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -34308185.500202511138112596193
  s21_decimal expected_result = {
      {0xF732E8E1, 0xAAF277AB, 0x6EDB10DE, 0b10000000000101010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_137) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -7700628.1818181818181818181818
  s21_decimal expected_result = {
      {0x1622E8BA, 0x1D7CDACE, 0xF8D21A76, 0b10000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_138) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -44567103.006324118990245493671
  s21_decimal expected_result = {
      {0x14427BA7, 0x0AC6A01B, 0x90010B27, 0b10000000000101010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_139) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000005345757
  s21_decimal expected_result = {
      {0x005191DD, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_140) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000005345757
  s21_decimal expected_result = {
      {0x005191DD, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_141) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.0000000053457575760859821687
  s21_decimal expected_result = {
      {0x9394F677, 0xE5DF75EC, 0x00000002, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_142) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.0000000000000011596221962034
  s21_decimal expected_result = {
      {0xF4B0D732, 0x00000A8B, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_143) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.0000000000144312924146427360
  s21_decimal expected_result = {
      {0x043EE5E0, 0x0200B3D7, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_144) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.0000000000000000037304462640
  s21_decimal expected_result = {
      {0xAF84ED30, 0x00000008, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_145) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -10588363.75
  s21_decimal expected_result = {
      {0x3F1C8F97, 0x00000000, 0x00000000, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_146) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_147) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_148) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -127187.55255255255255255255255
  s21_decimal expected_result = {
      {0x1D0688D7, 0xF3F51A25, 0x2918B52F, 0b10000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_149) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3430.8185500202511138112596193
  s21_decimal expected_result = {
      {0xF732E8E1, 0xAAF277AB, 0x6EDB10DE, 0b10000000000110010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_150) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -343062988.62187319645904608778
  s21_decimal expected_result = {
      {0xC4909E0A, 0xD0E6F39D, 0x6ED9815B, 0b10000000000101000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_151) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 423534550
  s21_decimal expected_result = {
      {0x193E9FD6, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_152) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.1411781833333333333333333333
  s21_decimal expected_result = {
      {0xCAA55555, 0x89ED61E0, 0x048FCC6E, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_153) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -9196804637128015065119302.552
  s21_decimal expected_result = {
      {0x20A9A398, 0x5FFC9390, 0x1DB76B22, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_154) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -2064264604460824472343596.1818
  s21_decimal expected_result = {
      {0xE3D7FDDA, 0x5EE4C43A, 0x42B33254, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_155) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -11946855644391458333305040.354
  s21_decimal expected_result = {
      {0x3EF36DE2, 0x337481CE, 0x269A3516, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_156) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0001433007527151780692093107
  s21_decimal expected_result = {
      {0x2839E8B3, 0x7E638945, 0x00012F73, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_157) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0001433007527151780692093107
  s21_decimal expected_result = {
      {0x2839E8B3, 0x7E638945, 0x00012F73, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_158) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -1433007527.1517806920931075681
  s21_decimal expected_result = {
      {0x5611E661, 0x10221D73, 0x2E4D8F79, 0b10000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_159) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -310.85347813855397979501726986
  s21_decimal expected_result = {
      {0x0E3D8D0A, 0x9CCB51F4, 0x64713271, 0b10000000000110100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_160) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 3868516.3631854924764962969831
  s21_decimal expected_result = {
      {0xE1A958E7, 0xA176A83B, 0x7CFF9E0A, 0b00000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_161) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 268064443019690709.95246501141
  s21_decimal expected_result = {
      {0xF5E14D15, 0x70B943B1, 0x569DC561, 0b00000000000010110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_162) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2838363831133633649472444.75
  s21_decimal expected_result = {
      {0xA65535BB, 0x28FC1B04, 0x00EAC8B1, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_163) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_164) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_165) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -34094460434037641435104.441441
  s21_decimal expected_result = {
      {0x4D447461, 0x9D7FFE25, 0x6E2A46D3, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_166) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -919680463712801506511.9302552
  s21_decimal expected_result = {
      {0x20A9A398, 0x5FFC9390, 0x1DB76B22, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_167) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -91962988965592929829802871.35
  s21_decimal expected_result = {
      {0xA8289A9F, 0x1FB02733, 0x1DB7000A, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_168) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 113534553245345345978897790
  s21_decimal expected_result = {
      {0xDC22157E, 0x76CB3E01, 0x005DE9E0, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_169) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 37844851081781781.99296593
  s21_decimal expected_result = {
      {0xA9789A51, 0x594B0A99, 0x00032165, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_170) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 3.2401782098015390846496557311
  s21_decimal expected_result = {
      {0x044048FF, 0x274C78EF, 0x68B2203F, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_171) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.7272727272727272727272727272
  s21_decimal expected_result = {
      {0xAE8BA2E8, 0x7303A4A3, 0x177FDBE7, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_172) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4.2090642197973335578167583892
  s21_decimal expected_result = {
      {0xEF21A494, 0x9E1D738D, 0x8800902D, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_173) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_174) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_175) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000005048709793414
  s21_decimal expected_result = {
      {0x7E8DC686, 0x00000497, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_176) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000001095185
  s21_decimal expected_result = {
      {0x0010B611, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_177) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000000013629388596
  s21_decimal expected_result = {
      {0x2C5FF734, 0x00000003, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_178) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000944432986635919076731
  s21_decimal expected_result = {
      {0x6332AD7B, 0x32A3FD86, 0x00000033, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_179) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000003523
  s21_decimal expected_result = {
      {0x00000DC3, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_180) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_181) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_182) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0120120120120120120120120120
  s21_decimal expected_result = {
      {0x2C031338, 0xC279E8F7, 0x00635C6C, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_183) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0003240178209801539084649655
  s21_decimal expected_result = {
      {0x5F0084B7, 0x69A7B697, 0x0002AE22, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_184) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 32.400000294840002683044024416
  s21_decimal expected_result = {
      {0x2A0ED060, 0x68EA5738, 0x68B0A6EF, 0b00000000000110110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_185) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -40
  s21_decimal expected_result = {
      {0x00000028, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_186) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000133333333333333333333
  s21_decimal expected_result = {
      {0x84155555, 0x3A5F283C, 0x00000007, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_187) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_188) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_189) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_190) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_191) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_192) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_193) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_194) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_195) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_196) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_197) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_198) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_199) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_200) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_201) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_202) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_203) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_204) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_205) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_206) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_207) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_208) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_209) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_210) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_211) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_212) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_213) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_214) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_215) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_216) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_217) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_218) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_219) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_220) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_221) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 269.74483596597812879708383961
  s21_decimal expected_result = {
      {0x6BDBEAD9, 0xDAF4C884, 0x5728C515, 0b00000000000110100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_222) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 60.545454545454545454545454545
  s21_decimal expected_result = {
      {0x0D1745D1, 0x9D7E5439, 0xC3A206B3, 0b00000000000110110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_223) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 350.40459629812801868824513590
  s21_decimal expected_result = {
      {0x99A30C36, 0xC6D4ADA3, 0x7138C9F2, 0b00000000000110100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_224) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000042
  s21_decimal expected_result = {
      {0x0000002A, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_225) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000042
  s21_decimal expected_result = {
      {0x0000002A, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_226) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000420305090301755
  s21_decimal expected_result = {
      {0xE79ACF3B, 0x00017E43, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_227) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000091174189
  s21_decimal expected_result = {
      {0x056F352D, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_228) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000001134646600631
  s21_decimal expected_result = {
      {0x2E3523B7, 0x00000108, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_229) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000078624046137440263137918
  s21_decimal expected_result = {
      {0xC23AEA7E, 0x37D431F3, 0x000010A6, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_230) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000293302
  s21_decimal expected_result = {
      {0x000479B6, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_231) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 83.25
  s21_decimal expected_result = {
      {0x00002085, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_232) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_233) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_234) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0269744835965978128797083839
  s21_decimal expected_result = {
      {0xA4EB28BF, 0xDBCA20B9, 0x00DF20B0, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_235) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 2697.3000245454302233634150326
  s21_decimal expected_result = {
      {0x282217B6, 0x3A8AC4C5, 0x57278AF9, 0b00000000000110010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_236) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -3330
  s21_decimal expected_result = {
      {0x00000D02, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_237) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00000111
  s21_decimal expected_result = {
      {0x0000006F, 0x00000000, 0x00000000, 0b10000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_238) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 10000
  s21_decimal expected_result = {
      {0x00002710, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_239) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 2244.5454545454545454545454545
  s21_decimal expected_result = {
      {0xB91745D1, 0x07C33E5B, 0x488671E1, 0b00000000000110010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_240) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12990.224448349520692811970579
  s21_decimal expected_result = {
      {0x19B4B813, 0x6614088F, 0x29F94306, 0b00000000000110000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_241) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000001558
  s21_decimal expected_result = {
      {0x00000616, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_242) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000001558
  s21_decimal expected_result = {
      {0x00000616, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_243) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000015581580599925425
  s21_decimal expected_result = {
      {0x70B29AB1, 0x00375B5D, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_244) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000003380016107
  s21_decimal expected_result = {
      {0xC976F3EB, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_245) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000042063700554952
  s21_decimal expected_result = {
      {0xB7EDF4C8, 0x00002641, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_246) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0002914756305005105250563383
  s21_decimal expected_result = {
      {0x65B3F537, 0x41832961, 0x00026939, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_247) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000010873341
  s21_decimal expected_result = {
      {0x00A5E9FD, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_248) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3086.25
  s21_decimal expected_result = {
      {0x0004B591, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_249) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_250) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_251) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 37.072072072072072072072072072
  s21_decimal expected_result = {
      {0x6F350B88, 0xF4387AFB, 0x77C94C9D, 0b00000000000110110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_252) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 99994.50090994995828054462035
  s21_decimal expected_result = {
      {0xB1968E53, 0x9DA8D5DC, 0x204F59EB, 0b00000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_253) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -123450
  s21_decimal expected_result = {
      {0x0001E23A, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_254) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00004115
  s21_decimal expected_result = {
      {0x00001013, 0x00000000, 0x00000000, 0b10000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_255) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.1000054993924665856622114216
  s21_decimal expected_result = {
      {0xB888B5A8, 0xD9D4E988, 0x033B39E1, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_256) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.0224466889090909090909090909
  s21_decimal expected_result = {
      {0x9001745D, 0x70AF1152, 0x00B9ACB6, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_257) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.1299093883177422579525007102
  s21_decimal expected_result = {
      {0x94C4B6FE, 0x852A7D39, 0x043295D4, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_258) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_259) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_260) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000000155824374921
  s21_decimal expected_result = {
      {0x47DB4489, 0x00000024, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_261) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000000033802
  s21_decimal expected_result = {
      {0x0000840A, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_262) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.0000000000000000000420660138
  s21_decimal expected_result = {
      {0x1912C3AA, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_263) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000029149165988937620319
  s21_decimal expected_result = {
      {0x2D865B5F, 0x9486A407, 0x00000001, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_264) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000108
  s21_decimal expected_result = {
      {0x0000006C, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_265) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.03086419725
  s21_decimal expected_result = {
      {0xB7F7070D, 0x00000000, 0x00000000, 0b00000000000010110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_266) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_267) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_268) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0003707411081081081081081081
  s21_decimal expected_result = {
      {0xC043ACF9, 0x284CB17C, 0x00031113, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_269) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000100005499392466585662211
  s21_decimal expected_result = {
      {0xA9CC3303, 0x4F19A59A, 0x0000152D, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_270) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -1.23456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b10000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_271) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00000000041152263
  s21_decimal expected_result = {
      {0x0273EF07, 0x00000000, 0x00000000, 0b10000000000100010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_272) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.0810044552450384771162413932
  s21_decimal expected_result = {
      {0xC6819B6C, 0x2DC84FD2, 0x029E0D9B, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_273) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.0181818181818181818181818181
  s21_decimal expected_result = {
      {0xE45D1745, 0x62E01750, 0x0096657F, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_274) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.1052266054949333389454189597
  s21_decimal expected_result = {
      {0x592DA41D, 0x23F3EFB0, 0x03666A01, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_275) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_276) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_277) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.0000000000000000126217744835
  s21_decimal expected_result = {
      {0x6329F1C3, 0x0000001D, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_278) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.0000000000000000000000027379
  s21_decimal expected_result = {
      {0x00006AF3, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_279) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.0000000000000000000340734714
  s21_decimal expected_result = {
      {0x144F32FA, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_280) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.0000000023610824665897976918
  s21_decimal expected_result = {
      {0x28E14456, 0x47AA7FF0, 0x00000001, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_281) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000000000088
  s21_decimal expected_result = {
      {0x00000058, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_282) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.025
  s21_decimal expected_result = {
      {0x00000019, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_283) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_284) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_285) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0003003003003003003003003003
  s21_decimal expected_result = {
      {0x944CE07B, 0x1E763F6C, 0x00027BE9, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_286) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0000081004455245038477116241
  s21_decimal expected_result = {
      {0x62600351, 0x42A4315D, 0x00001127, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_287) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.8100000073710000670761006104
  s21_decimal expected_result = {
      {0x0A83B418, 0xDA3A95CE, 0x1A2C29BB, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_288) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.0000000003333333333333333333
  s21_decimal expected_result = {
      {0x834D5555, 0x2E426101, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_289) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -243013365.73511543134872417983
  s21_decimal expected_result = {
      {0x433036BF, 0x5D795AB3, 0x4E85982F, 0b10000000000101000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_290) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -54545454.545454545454545454545
  s21_decimal expected_result = {
      {0x9D1745D1, 0xDE9B52CB, 0xB03EF147, 0b10000000000101010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_291) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -315679816.48480001683625687919
  s21_decimal expected_result = {
      {0x73593B6F, 0x369616AA, 0x66006C22, 0b10000000000101000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_292) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000037865323
  s21_decimal expected_result = {
      {0x0241C76B, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_293) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000037865323
  s21_decimal expected_result = {
      {0x0241C76B, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_294) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.0000000378653234506085666597
  s21_decimal expected_result = {
      {0xABEB8F25, 0x86DE8697, 0x00000014, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_295) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.0000000000000082138909059731
  s21_decimal expected_result = {
      {0x747F2A93, 0x00004AB4, 0x00000000, 0b10000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_296) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.0000000001022204144713299260
  s21_decimal expected_result = {
      {0xF591753C, 0x0E2F9940, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_297) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7.0832473997693930754881744594
  s21_decimal expected_result = {
      {0x3D85EED2, 0x8A88078E, 0xE4DF3FCD, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_298) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.0000000000000000264236738001
  s21_decimal expected_result = {
      {0x85BCA5D1, 0x0000003D, 0x00000000, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_299) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -75000000
  s21_decimal expected_result = {
      {0x047868C0, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_300) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_301) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(test_div_gen_302) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -900900.9009009009009009009009
  s21_decimal expected_result = {
      {0xE4E6A171, 0xF9B74069, 0x1D1C13DC, 0b10000000000101100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_303) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -24301.336573511543134872417983
  s21_decimal expected_result = {
      {0x433036BF, 0x5D795AB3, 0x4E85982F, 0b10000000000110000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_304) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -2430000022.1130002012283018312
  s21_decimal expected_result = {
      {0x1F8B1C48, 0x8EAFC16A, 0x4E847D33, 0b10000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_305) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 3000000000
  s21_decimal expected_result = {
      {0xB2D05E00, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_div_suite() {
  Suite* div_suite = suite_create("div");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_div_gen_0);
  tcase_add_test(tc_core, test_div_gen_1);
  tcase_add_test(tc_core, test_div_gen_2);
  tcase_add_test(tc_core, test_div_gen_3);
  tcase_add_test(tc_core, test_div_gen_4);
  tcase_add_test(tc_core, test_div_gen_5);
  tcase_add_test(tc_core, test_div_gen_6);
  tcase_add_test(tc_core, test_div_gen_7);
  tcase_add_test(tc_core, test_div_gen_8);
  tcase_add_test(tc_core, test_div_gen_9);
  tcase_add_test(tc_core, test_div_gen_10);
  tcase_add_test(tc_core, test_div_gen_11);
  tcase_add_test(tc_core, test_div_gen_12);
  tcase_add_test(tc_core, test_div_gen_13);
  tcase_add_test(tc_core, test_div_gen_14);
  tcase_add_test(tc_core, test_div_gen_15);
  tcase_add_test(tc_core, test_div_gen_16);
  tcase_add_test(tc_core, test_div_gen_17);
  tcase_add_test(tc_core, test_div_gen_18);
  tcase_add_test(tc_core, test_div_gen_19);
  tcase_add_test(tc_core, test_div_gen_20);
  tcase_add_test(tc_core, test_div_gen_21);
  tcase_add_test(tc_core, test_div_gen_22);
  tcase_add_test(tc_core, test_div_gen_23);
  tcase_add_test(tc_core, test_div_gen_24);
  tcase_add_test(tc_core, test_div_gen_25);
  tcase_add_test(tc_core, test_div_gen_26);
  tcase_add_test(tc_core, test_div_gen_27);
  tcase_add_test(tc_core, test_div_gen_28);
  tcase_add_test(tc_core, test_div_gen_29);
  tcase_add_test(tc_core, test_div_gen_30);
  tcase_add_test(tc_core, test_div_gen_31);
  tcase_add_test(tc_core, test_div_gen_32);
  tcase_add_test(tc_core, test_div_gen_33);
  tcase_add_test(tc_core, test_div_gen_34);
  tcase_add_test(tc_core, test_div_gen_35);
  tcase_add_test(tc_core, test_div_gen_36);
  tcase_add_test(tc_core, test_div_gen_37);
  tcase_add_test(tc_core, test_div_gen_38);
  tcase_add_test(tc_core, test_div_gen_39);
  tcase_add_test(tc_core, test_div_gen_40);
  tcase_add_test(tc_core, test_div_gen_41);
  tcase_add_test(tc_core, test_div_gen_42);
  tcase_add_test(tc_core, test_div_gen_43);
  tcase_add_test(tc_core, test_div_gen_44);
  tcase_add_test(tc_core, test_div_gen_45);
  tcase_add_test(tc_core, test_div_gen_46);
  tcase_add_test(tc_core, test_div_gen_47);
  tcase_add_test(tc_core, test_div_gen_48);
  tcase_add_test(tc_core, test_div_gen_49);
  tcase_add_test(tc_core, test_div_gen_50);
  tcase_add_test(tc_core, test_div_gen_51);
  tcase_add_test(tc_core, test_div_gen_52);
  tcase_add_test(tc_core, test_div_gen_53);
  tcase_add_test(tc_core, test_div_gen_54);
  tcase_add_test(tc_core, test_div_gen_55);
  tcase_add_test(tc_core, test_div_gen_56);
  tcase_add_test(tc_core, test_div_gen_57);
  tcase_add_test(tc_core, test_div_gen_58);
  tcase_add_test(tc_core, test_div_gen_59);
  tcase_add_test(tc_core, test_div_gen_60);
  tcase_add_test(tc_core, test_div_gen_61);
  tcase_add_test(tc_core, test_div_gen_62);
  tcase_add_test(tc_core, test_div_gen_63);
  tcase_add_test(tc_core, test_div_gen_64);
  tcase_add_test(tc_core, test_div_gen_65);
  tcase_add_test(tc_core, test_div_gen_66);
  tcase_add_test(tc_core, test_div_gen_67);
  tcase_add_test(tc_core, test_div_gen_68);
  tcase_add_test(tc_core, test_div_gen_69);
  tcase_add_test(tc_core, test_div_gen_70);
  tcase_add_test(tc_core, test_div_gen_71);
  tcase_add_test(tc_core, test_div_gen_72);
  tcase_add_test(tc_core, test_div_gen_73);
  tcase_add_test(tc_core, test_div_gen_74);
  tcase_add_test(tc_core, test_div_gen_75);
  tcase_add_test(tc_core, test_div_gen_76);
  tcase_add_test(tc_core, test_div_gen_77);
  tcase_add_test(tc_core, test_div_gen_78);
  tcase_add_test(tc_core, test_div_gen_79);
  tcase_add_test(tc_core, test_div_gen_80);
  tcase_add_test(tc_core, test_div_gen_81);
  tcase_add_test(tc_core, test_div_gen_82);
  tcase_add_test(tc_core, test_div_gen_83);
  tcase_add_test(tc_core, test_div_gen_84);
  tcase_add_test(tc_core, test_div_gen_85);
  tcase_add_test(tc_core, test_div_gen_86);
  tcase_add_test(tc_core, test_div_gen_87);
  tcase_add_test(tc_core, test_div_gen_88);
  tcase_add_test(tc_core, test_div_gen_89);
  tcase_add_test(tc_core, test_div_gen_90);
  tcase_add_test(tc_core, test_div_gen_91);
  tcase_add_test(tc_core, test_div_gen_92);
  tcase_add_test(tc_core, test_div_gen_93);
  tcase_add_test(tc_core, test_div_gen_94);
  tcase_add_test(tc_core, test_div_gen_95);
  tcase_add_test(tc_core, test_div_gen_96);
  tcase_add_test(tc_core, test_div_gen_97);
  tcase_add_test(tc_core, test_div_gen_98);
  tcase_add_test(tc_core, test_div_gen_99);
  tcase_add_test(tc_core, test_div_gen_100);
  tcase_add_test(tc_core, test_div_gen_101);
  tcase_add_test(tc_core, test_div_gen_102);
  tcase_add_test(tc_core, test_div_gen_103);
  tcase_add_test(tc_core, test_div_gen_104);
  tcase_add_test(tc_core, test_div_gen_105);
  tcase_add_test(tc_core, test_div_gen_106);
  tcase_add_test(tc_core, test_div_gen_107);
  tcase_add_test(tc_core, test_div_gen_108);
  tcase_add_test(tc_core, test_div_gen_109);
  tcase_add_test(tc_core, test_div_gen_110);
  tcase_add_test(tc_core, test_div_gen_111);
  tcase_add_test(tc_core, test_div_gen_112);
  tcase_add_test(tc_core, test_div_gen_113);
  tcase_add_test(tc_core, test_div_gen_114);
  tcase_add_test(tc_core, test_div_gen_115);
  tcase_add_test(tc_core, test_div_gen_116);
  tcase_add_test(tc_core, test_div_gen_117);
  tcase_add_test(tc_core, test_div_gen_118);
  tcase_add_test(tc_core, test_div_gen_119);
  tcase_add_test(tc_core, test_div_gen_120);
  tcase_add_test(tc_core, test_div_gen_121);
  tcase_add_test(tc_core, test_div_gen_122);
  tcase_add_test(tc_core, test_div_gen_123);
  tcase_add_test(tc_core, test_div_gen_124);
  tcase_add_test(tc_core, test_div_gen_125);
  tcase_add_test(tc_core, test_div_gen_126);
  tcase_add_test(tc_core, test_div_gen_127);
  tcase_add_test(tc_core, test_div_gen_128);
  tcase_add_test(tc_core, test_div_gen_129);
  tcase_add_test(tc_core, test_div_gen_130);
  tcase_add_test(tc_core, test_div_gen_131);
  tcase_add_test(tc_core, test_div_gen_132);
  tcase_add_test(tc_core, test_div_gen_133);
  tcase_add_test(tc_core, test_div_gen_134);
  tcase_add_test(tc_core, test_div_gen_135);
  tcase_add_test(tc_core, test_div_gen_136);
  tcase_add_test(tc_core, test_div_gen_137);
  tcase_add_test(tc_core, test_div_gen_138);
  tcase_add_test(tc_core, test_div_gen_139);
  tcase_add_test(tc_core, test_div_gen_140);
  tcase_add_test(tc_core, test_div_gen_141);
  tcase_add_test(tc_core, test_div_gen_142);
  tcase_add_test(tc_core, test_div_gen_143);
  tcase_add_test(tc_core, test_div_gen_144);
  tcase_add_test(tc_core, test_div_gen_145);
  tcase_add_test(tc_core, test_div_gen_146);
  tcase_add_test(tc_core, test_div_gen_147);
  tcase_add_test(tc_core, test_div_gen_148);
  tcase_add_test(tc_core, test_div_gen_149);
  tcase_add_test(tc_core, test_div_gen_150);
  tcase_add_test(tc_core, test_div_gen_151);
  tcase_add_test(tc_core, test_div_gen_152);
  tcase_add_test(tc_core, test_div_gen_153);
  tcase_add_test(tc_core, test_div_gen_154);
  tcase_add_test(tc_core, test_div_gen_155);
  tcase_add_test(tc_core, test_div_gen_156);
  tcase_add_test(tc_core, test_div_gen_157);
  tcase_add_test(tc_core, test_div_gen_158);
  tcase_add_test(tc_core, test_div_gen_159);
  tcase_add_test(tc_core, test_div_gen_160);
  tcase_add_test(tc_core, test_div_gen_161);
  tcase_add_test(tc_core, test_div_gen_162);
  tcase_add_test(tc_core, test_div_gen_163);
  tcase_add_test(tc_core, test_div_gen_164);
  tcase_add_test(tc_core, test_div_gen_165);
  tcase_add_test(tc_core, test_div_gen_166);
  tcase_add_test(tc_core, test_div_gen_167);
  tcase_add_test(tc_core, test_div_gen_168);
  tcase_add_test(tc_core, test_div_gen_169);
  tcase_add_test(tc_core, test_div_gen_170);
  tcase_add_test(tc_core, test_div_gen_171);
  tcase_add_test(tc_core, test_div_gen_172);
  tcase_add_test(tc_core, test_div_gen_173);
  tcase_add_test(tc_core, test_div_gen_174);
  tcase_add_test(tc_core, test_div_gen_175);
  tcase_add_test(tc_core, test_div_gen_176);
  tcase_add_test(tc_core, test_div_gen_177);
  tcase_add_test(tc_core, test_div_gen_178);
  tcase_add_test(tc_core, test_div_gen_179);
  tcase_add_test(tc_core, test_div_gen_180);
  tcase_add_test(tc_core, test_div_gen_181);
  tcase_add_test(tc_core, test_div_gen_182);
  tcase_add_test(tc_core, test_div_gen_183);
  tcase_add_test(tc_core, test_div_gen_184);
  tcase_add_test(tc_core, test_div_gen_185);
  tcase_add_test(tc_core, test_div_gen_186);
  tcase_add_test(tc_core, test_div_gen_187);
  tcase_add_test(tc_core, test_div_gen_188);
  tcase_add_test(tc_core, test_div_gen_189);
  tcase_add_test(tc_core, test_div_gen_190);
  tcase_add_test(tc_core, test_div_gen_191);
  tcase_add_test(tc_core, test_div_gen_192);
  tcase_add_test(tc_core, test_div_gen_193);
  tcase_add_test(tc_core, test_div_gen_194);
  tcase_add_test(tc_core, test_div_gen_195);
  tcase_add_test(tc_core, test_div_gen_196);
  tcase_add_test(tc_core, test_div_gen_197);
  tcase_add_test(tc_core, test_div_gen_198);
  tcase_add_test(tc_core, test_div_gen_199);
  tcase_add_test(tc_core, test_div_gen_200);
  tcase_add_test(tc_core, test_div_gen_201);
  tcase_add_test(tc_core, test_div_gen_202);
  tcase_add_test(tc_core, test_div_gen_203);
  tcase_add_test(tc_core, test_div_gen_204);
  tcase_add_test(tc_core, test_div_gen_205);
  tcase_add_test(tc_core, test_div_gen_206);
  tcase_add_test(tc_core, test_div_gen_207);
  tcase_add_test(tc_core, test_div_gen_208);
  tcase_add_test(tc_core, test_div_gen_209);
  tcase_add_test(tc_core, test_div_gen_210);
  tcase_add_test(tc_core, test_div_gen_211);
  tcase_add_test(tc_core, test_div_gen_212);
  tcase_add_test(tc_core, test_div_gen_213);
  tcase_add_test(tc_core, test_div_gen_214);
  tcase_add_test(tc_core, test_div_gen_215);
  tcase_add_test(tc_core, test_div_gen_216);
  tcase_add_test(tc_core, test_div_gen_217);
  tcase_add_test(tc_core, test_div_gen_218);
  tcase_add_test(tc_core, test_div_gen_219);
  tcase_add_test(tc_core, test_div_gen_220);
  tcase_add_test(tc_core, test_div_gen_221);
  tcase_add_test(tc_core, test_div_gen_222);
  tcase_add_test(tc_core, test_div_gen_223);
  tcase_add_test(tc_core, test_div_gen_224);
  tcase_add_test(tc_core, test_div_gen_225);
  tcase_add_test(tc_core, test_div_gen_226);
  tcase_add_test(tc_core, test_div_gen_227);
  tcase_add_test(tc_core, test_div_gen_228);
  tcase_add_test(tc_core, test_div_gen_229);
  tcase_add_test(tc_core, test_div_gen_230);
  tcase_add_test(tc_core, test_div_gen_231);
  tcase_add_test(tc_core, test_div_gen_232);
  tcase_add_test(tc_core, test_div_gen_233);
  tcase_add_test(tc_core, test_div_gen_234);
  tcase_add_test(tc_core, test_div_gen_235);
  tcase_add_test(tc_core, test_div_gen_236);
  tcase_add_test(tc_core, test_div_gen_237);
  tcase_add_test(tc_core, test_div_gen_238);
  tcase_add_test(tc_core, test_div_gen_239);
  tcase_add_test(tc_core, test_div_gen_240);
  tcase_add_test(tc_core, test_div_gen_241);
  tcase_add_test(tc_core, test_div_gen_242);
  tcase_add_test(tc_core, test_div_gen_243);
  tcase_add_test(tc_core, test_div_gen_244);
  tcase_add_test(tc_core, test_div_gen_245);
  tcase_add_test(tc_core, test_div_gen_246);
  tcase_add_test(tc_core, test_div_gen_247);
  tcase_add_test(tc_core, test_div_gen_248);
  tcase_add_test(tc_core, test_div_gen_249);
  tcase_add_test(tc_core, test_div_gen_250);
  tcase_add_test(tc_core, test_div_gen_251);
  tcase_add_test(tc_core, test_div_gen_252);
  tcase_add_test(tc_core, test_div_gen_253);
  tcase_add_test(tc_core, test_div_gen_254);
  tcase_add_test(tc_core, test_div_gen_255);
  tcase_add_test(tc_core, test_div_gen_256);
  tcase_add_test(tc_core, test_div_gen_257);
  tcase_add_test(tc_core, test_div_gen_258);
  tcase_add_test(tc_core, test_div_gen_259);
  tcase_add_test(tc_core, test_div_gen_260);
  tcase_add_test(tc_core, test_div_gen_261);
  tcase_add_test(tc_core, test_div_gen_262);
  tcase_add_test(tc_core, test_div_gen_263);
  tcase_add_test(tc_core, test_div_gen_264);
  tcase_add_test(tc_core, test_div_gen_265);
  tcase_add_test(tc_core, test_div_gen_266);
  tcase_add_test(tc_core, test_div_gen_267);
  tcase_add_test(tc_core, test_div_gen_268);
  tcase_add_test(tc_core, test_div_gen_269);
  tcase_add_test(tc_core, test_div_gen_270);
  tcase_add_test(tc_core, test_div_gen_271);
  tcase_add_test(tc_core, test_div_gen_272);
  tcase_add_test(tc_core, test_div_gen_273);
  tcase_add_test(tc_core, test_div_gen_274);
  tcase_add_test(tc_core, test_div_gen_275);
  tcase_add_test(tc_core, test_div_gen_276);
  tcase_add_test(tc_core, test_div_gen_277);
  tcase_add_test(tc_core, test_div_gen_278);
  tcase_add_test(tc_core, test_div_gen_279);
  tcase_add_test(tc_core, test_div_gen_280);
  tcase_add_test(tc_core, test_div_gen_281);
  tcase_add_test(tc_core, test_div_gen_282);
  tcase_add_test(tc_core, test_div_gen_283);
  tcase_add_test(tc_core, test_div_gen_284);
  tcase_add_test(tc_core, test_div_gen_285);
  tcase_add_test(tc_core, test_div_gen_286);
  tcase_add_test(tc_core, test_div_gen_287);
  tcase_add_test(tc_core, test_div_gen_288);
  tcase_add_test(tc_core, test_div_gen_289);
  tcase_add_test(tc_core, test_div_gen_290);
  tcase_add_test(tc_core, test_div_gen_291);
  tcase_add_test(tc_core, test_div_gen_292);
  tcase_add_test(tc_core, test_div_gen_293);
  tcase_add_test(tc_core, test_div_gen_294);
  tcase_add_test(tc_core, test_div_gen_295);
  tcase_add_test(tc_core, test_div_gen_296);
  tcase_add_test(tc_core, test_div_gen_297);
  tcase_add_test(tc_core, test_div_gen_298);
  tcase_add_test(tc_core, test_div_gen_299);
  tcase_add_test(tc_core, test_div_gen_300);
  tcase_add_test(tc_core, test_div_gen_301);
  tcase_add_test(tc_core, test_div_gen_302);
  tcase_add_test(tc_core, test_div_gen_303);
  tcase_add_test(tc_core, test_div_gen_304);
  tcase_add_test(tc_core, test_div_gen_305);
  suite_add_tcase(div_suite, tc_core);

  return div_suite;
}