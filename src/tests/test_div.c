#include "../arithmetic.h"
// #include "../debug_funcs.h"
#include "../comparison.h"
#include "../utility.h"
#include "run_tests.h"

// START_TEST(test_div_simple) {
//   s21_decimal input_decimal1 = {0x0, 0x1, 0x0,
//                                 0b00000000000000000000000000000000};

//   s21_decimal input_decimal2 = {0x2, 0x0, 0x0,
//                                 0b00000000000000000000000000000000};
//   s21_decimal result_decimal = {0x0, 0x0, 0x0, 0x0};

//   s21_div(input_decimal1, input_decimal2, &result_decimal);

//   // debug_print_decimal_as_binary(result_decimal);
// }
// END_TEST

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

START_TEST(test_div_gen_4) {
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

START_TEST(test_div_gen_5) {
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

START_TEST(test_div_gen_6) {
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

START_TEST(test_div_gen_7) {
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

START_TEST(test_div_gen_8) {
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

START_TEST(test_div_gen_9) {
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

START_TEST(test_div_gen_10) {
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

START_TEST(test_div_gen_11) {
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

START_TEST(test_div_gen_12) {
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

START_TEST(test_div_gen_13) {
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

START_TEST(test_div_gen_14) {
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

START_TEST(test_div_gen_15) {
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

START_TEST(test_div_gen_16) {
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

START_TEST(test_div_gen_17) {
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

START_TEST(test_div_gen_18) {
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

START_TEST(test_div_gen_19) {
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

START_TEST(test_div_gen_20) {
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

START_TEST(test_div_gen_21) {
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

START_TEST(test_div_gen_22) {
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

START_TEST(test_div_gen_23) {
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

START_TEST(test_div_gen_24) {
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

START_TEST(test_div_gen_25) {
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

START_TEST(test_div_gen_26) {
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

START_TEST(test_div_gen_27) {
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

START_TEST(test_div_gen_28) {
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

START_TEST(test_div_gen_29) {
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

START_TEST(test_div_gen_30) {
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

START_TEST(test_div_gen_31) {
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

START_TEST(test_div_gen_32) {
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

START_TEST(test_div_gen_33) {
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

START_TEST(test_div_gen_34) {
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

START_TEST(test_div_gen_35) {
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

START_TEST(test_div_gen_36) {
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

START_TEST(test_div_gen_37) {
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

START_TEST(test_div_gen_38) {
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

START_TEST(test_div_gen_39) {
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

START_TEST(test_div_gen_40) {
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

START_TEST(test_div_gen_41) {
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

START_TEST(test_div_gen_42) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 8336910600976959.3292376280171
  s21_decimal expected_result = {
      {0xF7608C6B, 0xB2C57B88, 0x0D614EE4, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_43) {
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

START_TEST(test_div_gen_44) {
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

START_TEST(test_div_gen_45) {
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

START_TEST(test_div_gen_46) {
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

START_TEST(test_div_gen_47) {
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

START_TEST(test_div_gen_48) {
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

START_TEST(test_div_gen_49) {
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

START_TEST(test_div_gen_50) {
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

START_TEST(test_div_gen_51) {
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

START_TEST(test_div_gen_52) {
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

START_TEST(test_div_gen_53) {
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

START_TEST(test_div_gen_54) {
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

START_TEST(test_div_gen_55) {
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

START_TEST(test_div_gen_56) {
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

START_TEST(test_div_gen_57) {
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

START_TEST(test_div_gen_58) {
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

START_TEST(test_div_gen_59) {
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

START_TEST(test_div_gen_60) {
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

START_TEST(test_div_gen_61) {
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

START_TEST(test_div_gen_62) {
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

START_TEST(test_div_gen_63) {
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

START_TEST(test_div_gen_64) {
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

START_TEST(test_div_gen_65) {
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

START_TEST(test_div_gen_66) {
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

START_TEST(test_div_gen_67) {
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

START_TEST(test_div_gen_68) {
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

START_TEST(test_div_gen_69) {
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

START_TEST(test_div_gen_70) {
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

START_TEST(test_div_gen_71) {
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

START_TEST(test_div_gen_72) {
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

START_TEST(test_div_gen_73) {
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

START_TEST(test_div_gen_74) {
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

START_TEST(test_div_gen_75) {
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

START_TEST(test_div_gen_76) {
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

START_TEST(test_div_gen_77) {
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

START_TEST(test_div_gen_78) {
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

START_TEST(test_div_gen_79) {
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

START_TEST(test_div_gen_80) {
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

START_TEST(test_div_gen_81) {
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

START_TEST(test_div_gen_82) {
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

START_TEST(test_div_gen_83) {
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

START_TEST(test_div_gen_84) {
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

START_TEST(test_div_gen_85) {
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

START_TEST(test_div_gen_86) {
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

START_TEST(test_div_gen_87) {
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

START_TEST(test_div_gen_88) {
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

START_TEST(test_div_gen_89) {
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

START_TEST(test_div_gen_90) {
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

START_TEST(test_div_gen_91) {
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

START_TEST(test_div_gen_92) {
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

START_TEST(test_div_gen_93) {
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

START_TEST(test_div_gen_94) {
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

START_TEST(test_div_gen_95) {
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

START_TEST(test_div_gen_96) {
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

START_TEST(test_div_gen_97) {
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

START_TEST(test_div_gen_98) {
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

START_TEST(test_div_gen_99) {
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

START_TEST(test_div_gen_100) {
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

START_TEST(test_div_gen_101) {
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

START_TEST(test_div_gen_102) {
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

START_TEST(test_div_gen_103) {
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

START_TEST(test_div_gen_104) {
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

START_TEST(test_div_gen_105) {
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

START_TEST(test_div_gen_106) {
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

START_TEST(test_div_gen_107) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -900900.90090090090090090090090
  s21_decimal expected_result = {
      {0xF1024E6A, 0xC1288422, 0x2318C6A1, 0b10000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_div_gen_108) {
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

START_TEST(test_div_gen_109) {
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

  // tcase_add_test(tc_core, test_div_simple);
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
  suite_add_tcase(div_suite, tc_core);

  return div_suite;
}