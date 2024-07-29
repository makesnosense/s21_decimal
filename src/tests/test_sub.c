#include "../arithmetic.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_simple_sub_gen_0) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -4.2655
  s21_decimal expected_result = {
      {0x0000A69F, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_1) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.28417
  s21_decimal expected_result = {
      {0x00006F01, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_2) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2.7655
  s21_decimal expected_result = {
      {0x00006C07, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_3) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12343.7655
  s21_decimal expected_result = {
      {0x075B8257, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_4) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_5) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_6) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.3345
  s21_decimal expected_result = {
      {0x00003421, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_7) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000001.2345
  s21_decimal expected_result = {
      {0x7DEF6039, 0x000002BA, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_8) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678908.7655
  s21_decimal expected_result = {
      {0x860F05A7, 0x00007048, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_9) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333334.2345
  s21_decimal expected_result = {
      {0x74837889, 0x00766C7D, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_10) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 4.2655
  s21_decimal expected_result = {
      {0x0000A69F, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_11) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4.54967
  s21_decimal expected_result = {
      {0x0006F137, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_12) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.5
  s21_decimal expected_result = {
      {0x0000000F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_13) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12339.5
  s21_decimal expected_result = {
      {0x0001E203, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_14) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_15) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_16) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.6
  s21_decimal expected_result = {
      {0x00000038, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_17) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000005.5
  s21_decimal expected_result = {
      {0xB2D05E37, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_18) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678904.5
  s21_decimal expected_result = {
      {0xBE991A35, 0x0000001C, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_19) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333338.5
  s21_decimal expected_result = {
      {0x057E1589, 0x00001E51, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_20) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.28417
  s21_decimal expected_result = {
      {0x00006F01, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_21) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -4.54967
  s21_decimal expected_result = {
      {0x0006F137, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_22) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3.04967
  s21_decimal expected_result = {
      {0x0004A747, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_23) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12344.04967
  s21_decimal expected_result = {
      {0x49938667, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_24) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_25) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_26) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.05033
  s21_decimal expected_result = {
      {0x00019A49, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_27) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000000.95033
  s21_decimal expected_result = {
      {0xEB595339, 0x00001B48, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_28) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678909.04967
  s21_decimal expected_result = {
      {0x3C96A787, 0x000462D5, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_29) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333333.95033
  s21_decimal expected_result = {
      {0x8D224659, 0x04A03CE6, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_30) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 2.7655
  s21_decimal expected_result = {
      {0x00006C07, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_31) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -1.5
  s21_decimal expected_result = {
      {0x0000000F, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_32) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 3.04967
  s21_decimal expected_result = {
      {0x0004A747, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_33) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12341
  s21_decimal expected_result = {
      {0x00003035, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_34) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_35) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_36) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 4.1
  s21_decimal expected_result = {
      {0x00000029, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_37) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000004
  s21_decimal expected_result = {
      {0x11E1A304, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_38) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678906
  s21_decimal expected_result = {
      {0xDFDC1C3A, 0x00000002, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_39) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333337
  s21_decimal expected_result = {
      {0x1A263559, 0x00000308, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_40) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 12343.7655
  s21_decimal expected_result = {
      {0x075B8257, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_41) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12339.5
  s21_decimal expected_result = {
      {0x0001E203, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_42) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12344.04967
  s21_decimal expected_result = {
      {0x49938667, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_43) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12341
  s21_decimal expected_result = {
      {0x00003035, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_44) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_45) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_46) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12345.1
  s21_decimal expected_result = {
      {0x0001E23B, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_47) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300012345
  s21_decimal expected_result = {
      {0x11E1D339, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_48) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345666565
  s21_decimal expected_result = {
      {0xDFDBEC05, 0x00000002, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_49) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333345678
  s21_decimal expected_result = {
      {0x1A26658E, 0x00000308, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_50) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_51) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_52) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_53) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_54) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_55) {
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
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_56) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_57) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_58) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678910
  s21_decimal expected_result = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_59) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333333
  s21_decimal expected_result = {
      {0x1A263555, 0x00000308, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_60) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -1.2345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_61) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_62) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.95033
  s21_decimal expected_result = {
      {0x00017339, 0x00000000, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_63) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -4
  s21_decimal expected_result = {
      {0x00000004, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_64) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345
  s21_decimal expected_result = {
      {0x00003039, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_65) {
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
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_66) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.1
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_67) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_68) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345678910
  s21_decimal input_decimal_2 = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b00000000000000000000000000000000}};
  // -12345678910
  s21_decimal expected_result = {
      {0xDFDC1C3E, 0x00000002, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_69) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -3333333333333
  s21_decimal input_decimal_2 = {
      {0x1A263555, 0x00000308, 0x00000000, 0b10000000000000000000000000000000}};
  // 3333333333333
  s21_decimal expected_result = {
      {0x1A263555, 0x00000308, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_70) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -1.3345
  s21_decimal expected_result = {
      {0x00003421, 0x00000000, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_sub_gen_71) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -5.6
  s21_decimal expected_result = {
      {0x00000038, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_sub(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

Suite* make_sub_suite() {
  Suite* sub_suite = suite_create("sub");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_simple_sub_gen_0);
  tcase_add_test(tc_core, test_simple_sub_gen_1);
  tcase_add_test(tc_core, test_simple_sub_gen_2);
  tcase_add_test(tc_core, test_simple_sub_gen_3);
  tcase_add_test(tc_core, test_simple_sub_gen_4);
  tcase_add_test(tc_core, test_simple_sub_gen_5);
  tcase_add_test(tc_core, test_simple_sub_gen_6);
  tcase_add_test(tc_core, test_simple_sub_gen_7);
  tcase_add_test(tc_core, test_simple_sub_gen_8);
  tcase_add_test(tc_core, test_simple_sub_gen_9);
  tcase_add_test(tc_core, test_simple_sub_gen_10);
  tcase_add_test(tc_core, test_simple_sub_gen_11);
  tcase_add_test(tc_core, test_simple_sub_gen_12);
  tcase_add_test(tc_core, test_simple_sub_gen_13);
  tcase_add_test(tc_core, test_simple_sub_gen_14);
  tcase_add_test(tc_core, test_simple_sub_gen_15);
  tcase_add_test(tc_core, test_simple_sub_gen_16);
  tcase_add_test(tc_core, test_simple_sub_gen_17);
  tcase_add_test(tc_core, test_simple_sub_gen_18);
  tcase_add_test(tc_core, test_simple_sub_gen_19);
  tcase_add_test(tc_core, test_simple_sub_gen_20);
  tcase_add_test(tc_core, test_simple_sub_gen_21);
  tcase_add_test(tc_core, test_simple_sub_gen_22);
  tcase_add_test(tc_core, test_simple_sub_gen_23);
  tcase_add_test(tc_core, test_simple_sub_gen_24);
  tcase_add_test(tc_core, test_simple_sub_gen_25);
  tcase_add_test(tc_core, test_simple_sub_gen_26);
  tcase_add_test(tc_core, test_simple_sub_gen_27);
  tcase_add_test(tc_core, test_simple_sub_gen_28);
  tcase_add_test(tc_core, test_simple_sub_gen_29);
  tcase_add_test(tc_core, test_simple_sub_gen_30);
  tcase_add_test(tc_core, test_simple_sub_gen_31);
  tcase_add_test(tc_core, test_simple_sub_gen_32);
  tcase_add_test(tc_core, test_simple_sub_gen_33);
  tcase_add_test(tc_core, test_simple_sub_gen_34);
  tcase_add_test(tc_core, test_simple_sub_gen_35);
  tcase_add_test(tc_core, test_simple_sub_gen_36);
  tcase_add_test(tc_core, test_simple_sub_gen_37);
  tcase_add_test(tc_core, test_simple_sub_gen_38);
  tcase_add_test(tc_core, test_simple_sub_gen_39);
  tcase_add_test(tc_core, test_simple_sub_gen_40);
  tcase_add_test(tc_core, test_simple_sub_gen_41);
  tcase_add_test(tc_core, test_simple_sub_gen_42);
  tcase_add_test(tc_core, test_simple_sub_gen_43);
  tcase_add_test(tc_core, test_simple_sub_gen_44);
  tcase_add_test(tc_core, test_simple_sub_gen_45);
  tcase_add_test(tc_core, test_simple_sub_gen_46);
  tcase_add_test(tc_core, test_simple_sub_gen_47);
  tcase_add_test(tc_core, test_simple_sub_gen_48);
  tcase_add_test(tc_core, test_simple_sub_gen_49);
  tcase_add_test(tc_core, test_simple_sub_gen_50);
  tcase_add_test(tc_core, test_simple_sub_gen_51);
  tcase_add_test(tc_core, test_simple_sub_gen_52);
  tcase_add_test(tc_core, test_simple_sub_gen_53);
  tcase_add_test(tc_core, test_simple_sub_gen_54);
  tcase_add_test(tc_core, test_simple_sub_gen_55);
  tcase_add_test(tc_core, test_simple_sub_gen_56);
  tcase_add_test(tc_core, test_simple_sub_gen_57);
  tcase_add_test(tc_core, test_simple_sub_gen_58);
  tcase_add_test(tc_core, test_simple_sub_gen_59);
  tcase_add_test(tc_core, test_simple_sub_gen_60);
  tcase_add_test(tc_core, test_simple_sub_gen_61);
  tcase_add_test(tc_core, test_simple_sub_gen_62);
  tcase_add_test(tc_core, test_simple_sub_gen_63);
  tcase_add_test(tc_core, test_simple_sub_gen_64);
  tcase_add_test(tc_core, test_simple_sub_gen_65);
  tcase_add_test(tc_core, test_simple_sub_gen_66);
  tcase_add_test(tc_core, test_simple_sub_gen_67);
  tcase_add_test(tc_core, test_simple_sub_gen_68);
  tcase_add_test(tc_core, test_simple_sub_gen_69);
  tcase_add_test(tc_core, test_simple_sub_gen_70);
  tcase_add_test(tc_core, test_simple_sub_gen_71);

  // tcase_add_test(tc_core, test_sub_simple);

  suite_add_tcase(sub_suite, tc_core);

  return sub_suite;
}