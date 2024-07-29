#include "../arithmetic.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

// START_TEST(test_mul_simple) {
//   s21_decimal input_decimal1 = {0x0, 0x1, 0x0,
//                                 0b00000000000000000000000000000000};

//   s21_decimal input_decimal2 = {0x2, 0x0, 0x0,
//                                 0b00000000000000000000000000000000};
//   s21_decimal result_decimal = {0x0, 0x0, 0x0, 0x0};

//   s21_mul(input_decimal1, input_decimal2, &result_decimal);

//   // debug_print_decimal_as_binary(result_decimal);
// }
// END_TEST

START_TEST(test_simple_mul_gen_0) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 6.78975
  s21_decimal expected_result = {
      {0x000A5C3F, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_1) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.173182385
  s21_decimal expected_result = {
      {0x45ED57B1, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_2) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4.9380
  s21_decimal expected_result = {
      {0x0000C0E4, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_3) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 15239.9025
  s21_decimal expected_result = {
      {0x09156CB1, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_4) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_5) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_6) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_7) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -370350000.0000
  s21_decimal expected_result = {
      {0x49CD4B00, 0x0000035E, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_8) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 6.78975
  s21_decimal expected_result = {
      {0x000A5C3F, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_9) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.226815
  s21_decimal expected_result = {
      {0x004FC13F, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_10) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 22.0
  s21_decimal expected_result = {
      {0x000000DC, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_11) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 67897.5
  s21_decimal expected_result = {
      {0x000A5C3F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_12) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_13) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_14) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.55
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_15) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1650000000.0
  s21_decimal expected_result = {
      {0xD77A0500, 0x00000003, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_16) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.173182385
  s21_decimal expected_result = {
      {0x45ED57B1, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_17) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.226815
  s21_decimal expected_result = {
      {0x004FC13F, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_18) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.80132
  s21_decimal expected_result = {
      {0x0005CCE4, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_19) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 11731.82385
  s21_decimal expected_result = {
      {0x45ED57B1, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_20) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.00000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_21) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_22) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.095033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_23) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -285099000.00000
  s21_decimal expected_result = {
      {0xFA764B00, 0x000019ED, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_24) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4.9380
  s21_decimal expected_result = {
      {0x0000C0E4, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_25) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 22.0
  s21_decimal expected_result = {
      {0x000000DC, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_26) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 3.80132
  s21_decimal expected_result = {
      {0x0005CCE4, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_27) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 49380
  s21_decimal expected_result = {
      {0x0000C0E4, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_28) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_29) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_30) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_31) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -1200000000
  s21_decimal expected_result = {
      {0x47868C00, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_32) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 15239.9025
  s21_decimal expected_result = {
      {0x09156CB1, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_33) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 67897.5
  s21_decimal expected_result = {
      {0x000A5C3F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_34) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 11731.82385
  s21_decimal expected_result = {
      {0x45ED57B1, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_35) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 49380
  s21_decimal expected_result = {
      {0x0000C0E4, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_36) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_37) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_38) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -1234.5
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_39) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -3703500000000
  s21_decimal expected_result = {
      {0x49CD4B00, 0x0000035E, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_40) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.0000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_41) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_42) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.00000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_43) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_44) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_45) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_46) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_47) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_48) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.0000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_49) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_50) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.00000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_51) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_52) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_53) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_54) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_55) {
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
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_56) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_57) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.55
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_58) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.095033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_59) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_60) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1234.5
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_61) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_62) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_63) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 30000000.0
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_64) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -370350000.0000
  s21_decimal expected_result = {
      {0x49CD4B00, 0x0000035E, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_65) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -1650000000.0
  s21_decimal expected_result = {
      {0xD77A0500, 0x00000003, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_66) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -285099000.00000
  s21_decimal expected_result = {
      {0xFA764B00, 0x000019ED, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_67) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -1200000000
  s21_decimal expected_result = {
      {0x47868C00, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_68) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3703500000000
  s21_decimal expected_result = {
      {0x49CD4B00, 0x0000035E, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_69) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_70) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_mul_gen_71) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 30000000.0
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

Suite* make_mul_suite() {
  Suite* mul_suite = suite_create("mul");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_simple_mul_gen_0);
  tcase_add_test(tc_core, test_simple_mul_gen_1);
  tcase_add_test(tc_core, test_simple_mul_gen_2);
  tcase_add_test(tc_core, test_simple_mul_gen_3);
  tcase_add_test(tc_core, test_simple_mul_gen_4);
  tcase_add_test(tc_core, test_simple_mul_gen_5);
  tcase_add_test(tc_core, test_simple_mul_gen_6);
  tcase_add_test(tc_core, test_simple_mul_gen_7);
  tcase_add_test(tc_core, test_simple_mul_gen_8);
  tcase_add_test(tc_core, test_simple_mul_gen_9);
  tcase_add_test(tc_core, test_simple_mul_gen_10);
  tcase_add_test(tc_core, test_simple_mul_gen_11);
  tcase_add_test(tc_core, test_simple_mul_gen_12);
  tcase_add_test(tc_core, test_simple_mul_gen_13);
  tcase_add_test(tc_core, test_simple_mul_gen_14);
  tcase_add_test(tc_core, test_simple_mul_gen_15);
  tcase_add_test(tc_core, test_simple_mul_gen_16);
  tcase_add_test(tc_core, test_simple_mul_gen_17);
  tcase_add_test(tc_core, test_simple_mul_gen_18);
  tcase_add_test(tc_core, test_simple_mul_gen_19);
  tcase_add_test(tc_core, test_simple_mul_gen_20);
  tcase_add_test(tc_core, test_simple_mul_gen_21);
  tcase_add_test(tc_core, test_simple_mul_gen_22);
  tcase_add_test(tc_core, test_simple_mul_gen_23);
  tcase_add_test(tc_core, test_simple_mul_gen_24);
  tcase_add_test(tc_core, test_simple_mul_gen_25);
  tcase_add_test(tc_core, test_simple_mul_gen_26);
  tcase_add_test(tc_core, test_simple_mul_gen_27);
  tcase_add_test(tc_core, test_simple_mul_gen_28);
  tcase_add_test(tc_core, test_simple_mul_gen_29);
  tcase_add_test(tc_core, test_simple_mul_gen_30);
  tcase_add_test(tc_core, test_simple_mul_gen_31);
  tcase_add_test(tc_core, test_simple_mul_gen_32);
  tcase_add_test(tc_core, test_simple_mul_gen_33);
  tcase_add_test(tc_core, test_simple_mul_gen_34);
  tcase_add_test(tc_core, test_simple_mul_gen_35);
  tcase_add_test(tc_core, test_simple_mul_gen_36);
  tcase_add_test(tc_core, test_simple_mul_gen_37);
  tcase_add_test(tc_core, test_simple_mul_gen_38);
  tcase_add_test(tc_core, test_simple_mul_gen_39);
  tcase_add_test(tc_core, test_simple_mul_gen_40);
  tcase_add_test(tc_core, test_simple_mul_gen_41);
  tcase_add_test(tc_core, test_simple_mul_gen_42);
  tcase_add_test(tc_core, test_simple_mul_gen_43);
  tcase_add_test(tc_core, test_simple_mul_gen_44);
  tcase_add_test(tc_core, test_simple_mul_gen_45);
  tcase_add_test(tc_core, test_simple_mul_gen_46);
  tcase_add_test(tc_core, test_simple_mul_gen_47);
  tcase_add_test(tc_core, test_simple_mul_gen_48);
  tcase_add_test(tc_core, test_simple_mul_gen_49);
  tcase_add_test(tc_core, test_simple_mul_gen_50);
  tcase_add_test(tc_core, test_simple_mul_gen_51);
  tcase_add_test(tc_core, test_simple_mul_gen_52);
  tcase_add_test(tc_core, test_simple_mul_gen_53);
  tcase_add_test(tc_core, test_simple_mul_gen_54);
  tcase_add_test(tc_core, test_simple_mul_gen_55);
  tcase_add_test(tc_core, test_simple_mul_gen_56);
  tcase_add_test(tc_core, test_simple_mul_gen_57);
  tcase_add_test(tc_core, test_simple_mul_gen_58);
  tcase_add_test(tc_core, test_simple_mul_gen_59);
  tcase_add_test(tc_core, test_simple_mul_gen_60);
  tcase_add_test(tc_core, test_simple_mul_gen_61);
  tcase_add_test(tc_core, test_simple_mul_gen_62);
  tcase_add_test(tc_core, test_simple_mul_gen_63);
  tcase_add_test(tc_core, test_simple_mul_gen_64);
  tcase_add_test(tc_core, test_simple_mul_gen_65);
  tcase_add_test(tc_core, test_simple_mul_gen_66);
  tcase_add_test(tc_core, test_simple_mul_gen_67);
  tcase_add_test(tc_core, test_simple_mul_gen_68);
  tcase_add_test(tc_core, test_simple_mul_gen_69);
  tcase_add_test(tc_core, test_simple_mul_gen_70);
  tcase_add_test(tc_core, test_simple_mul_gen_71);

  // tcase_add_test(tc_core, test_mul_simple);

  suite_add_tcase(mul_suite, tc_core);

  return mul_suite;
}