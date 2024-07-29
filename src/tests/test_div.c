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

START_TEST(test_simple_div_gen_0) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.22445454545454545454545454545
  s21_decimal expected_result = {
      {0xB91745D1, 0x07C33E5B, 0x488671E1, 0b00000000000111010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_1) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_2) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_3) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_4) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_5) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_6) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_7) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_8) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_9) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.00044552450384771162413932766302
  s21_decimal expected_result = {
      {0xA5D8645E, 0xD6092648, 0x8FF4EC56, 0b00000000001000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_10) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_11) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.000000018333333333333333333333333333
  s21_decimal expected_result = {
      {0x9D555555, 0x71EE845C, 0x3B3CFA57, 0b10000000001001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_12) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.76980963953017415957877683273
  s21_decimal expected_result = {
      {0x79DCF449, 0xE4FD4198, 0xF8BD2931, 0b00000000000111010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_13) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.17278727272727272727272727273
  s21_decimal expected_result = {
      {0x848BA2E9, 0x58017496, 0x37D4A0D2, 0b00000000000111010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_14) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_15) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.000076980963953017415957877683273
  s21_decimal expected_result = {
      {0x79DCF449, 0xE4FD4198, 0xF8BD2931, 0b00000000001000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_16) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_17) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000031677666666666666666666666667
  s21_decimal expected_result = {
      {0x9DAAAAAB, 0xF6AD55BE, 0x665B26D6, 0b10000000001001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_18) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_19) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.72727272727272727272727272727
  s21_decimal expected_result = {
      {0xD1745D17, 0x7E246E64, 0xEAFE970A, 0b00000000000111010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_20) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_21) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.00032401782098015390846496557311
  s21_decimal expected_result = {
      {0x044048FF, 0x274C78EF, 0x68B2203F, 0b00000000001000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_22) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_23) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.000000013333333333333333333333333333
  s21_decimal expected_result = {
      {0x15555555, 0x52DC032C, 0x2B151328, 0b10000000001001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_24) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_25) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_26) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_27) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_28) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_29) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_30) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -0.081004455245038477116241393277
  s21_decimal expected_result = {
      {0x8AA0B67D, 0xE23F2E55, 0x05BD509D, 0b10000000000111100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_31) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.018181818181818181818181818182
  s21_decimal expected_result = {
      {0x345D1746, 0x9F891B99, 0x3ABFA5C2, 0b10000000000111100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_32) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -0.10522660549493333894541895973
  s21_decimal expected_result = {
      {0x7BC86925, 0x67875CE3, 0x2200240B, 0b10000000000111010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_33) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_34) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0000081004455245038477116241393277
  s21_decimal expected_result = {
      {0x8AA0B67D, 0xE23F2E55, 0x05BD509D, 0b10000000001000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_35) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.00000000033333333333333333333333333333
  s21_decimal expected_result = {
      {0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0b00000000001001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_36) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_37) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_38) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_39) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_40) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

START_TEST(test_simple_div_gen_41) {
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
  ArithmeticResult s21_result_code =
      s21_div(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_result_code, OK);
}
END_TEST

Suite* make_div_suite() {
  Suite* div_suite = suite_create("div");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_simple_div_gen_0);
  tcase_add_test(tc_core, test_simple_div_gen_1);
  tcase_add_test(tc_core, test_simple_div_gen_2);
  tcase_add_test(tc_core, test_simple_div_gen_3);
  tcase_add_test(tc_core, test_simple_div_gen_4);
  tcase_add_test(tc_core, test_simple_div_gen_5);
  tcase_add_test(tc_core, test_simple_div_gen_6);
  tcase_add_test(tc_core, test_simple_div_gen_7);
  tcase_add_test(tc_core, test_simple_div_gen_8);
  tcase_add_test(tc_core, test_simple_div_gen_9);
  tcase_add_test(tc_core, test_simple_div_gen_10);
  tcase_add_test(tc_core, test_simple_div_gen_11);
  tcase_add_test(tc_core, test_simple_div_gen_12);
  tcase_add_test(tc_core, test_simple_div_gen_13);
  tcase_add_test(tc_core, test_simple_div_gen_14);
  tcase_add_test(tc_core, test_simple_div_gen_15);
  tcase_add_test(tc_core, test_simple_div_gen_16);
  tcase_add_test(tc_core, test_simple_div_gen_17);
  tcase_add_test(tc_core, test_simple_div_gen_18);
  tcase_add_test(tc_core, test_simple_div_gen_19);
  tcase_add_test(tc_core, test_simple_div_gen_20);
  tcase_add_test(tc_core, test_simple_div_gen_21);
  tcase_add_test(tc_core, test_simple_div_gen_22);
  tcase_add_test(tc_core, test_simple_div_gen_23);
  tcase_add_test(tc_core, test_simple_div_gen_24);
  tcase_add_test(tc_core, test_simple_div_gen_25);
  tcase_add_test(tc_core, test_simple_div_gen_26);
  tcase_add_test(tc_core, test_simple_div_gen_27);
  tcase_add_test(tc_core, test_simple_div_gen_28);
  tcase_add_test(tc_core, test_simple_div_gen_29);
  tcase_add_test(tc_core, test_simple_div_gen_30);
  tcase_add_test(tc_core, test_simple_div_gen_31);
  tcase_add_test(tc_core, test_simple_div_gen_32);
  tcase_add_test(tc_core, test_simple_div_gen_33);
  tcase_add_test(tc_core, test_simple_div_gen_34);
  tcase_add_test(tc_core, test_simple_div_gen_35);
  tcase_add_test(tc_core, test_simple_div_gen_36);
  tcase_add_test(tc_core, test_simple_div_gen_37);
  tcase_add_test(tc_core, test_simple_div_gen_38);
  tcase_add_test(tc_core, test_simple_div_gen_39);
  tcase_add_test(tc_core, test_simple_div_gen_40);
  tcase_add_test(tc_core, test_simple_div_gen_41);

  // tcase_add_test(tc_core, test_div_simple);

  suite_add_tcase(div_suite, tc_core);

  return div_suite;
}