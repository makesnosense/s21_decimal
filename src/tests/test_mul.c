#include "../arithmetic.h"
#include "../comparison.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_mul_gen_0) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_1) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_2) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_3) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_4) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 9780716662385932.475923000669
  s21_decimal expected_result = {
      {0xFEC56D5D, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_5) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 9780716662385932.475923000668
  s21_decimal expected_result = {
      {0xFEC56D5C, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_6) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.234500000000604905
  s21_decimal expected_result = {
      {0x97417AE9, 0x1121D335, 0x00000000, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_7) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 45088254061261382827115.472001
  s21_decimal expected_result = {
      {0xC62EE481, 0x57038DD1, 0x91B0212E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_8) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -3623053202390146863.159525
  s21_decimal expected_result = {
      {0x7BE558E5, 0x1B8F2747, 0x0002FF36, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_9) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -52285340.1975
  s21_decimal expected_result = {
      {0xBC7DC577, 0x00000079, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_10) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -14015840598137882961094932.176
  s21_decimal expected_result = {
      {0x343C76D0, 0x491BD9FF, 0x2D49A1B1, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_11) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_12) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_13) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_14) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 411.0885
  s21_decimal expected_result = {
      {0x003EBA25, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_15) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_16) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.1524074060205
  s21_decimal expected_result = {
      {0xD9E499AD, 0x00000162, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_17) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_18) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_19) {
  // 1.2345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.234500000001246845
  s21_decimal expected_result = {
      {0x974B467D, 0x1121D335, 0x00000000, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_20) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_21) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_22) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_23) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_24) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 43575489382845385.676449172684
  s21_decimal expected_result = {
      {0xCCCCCCCC, 0xCCCCCCCC, 0x8CCCCCCC, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_25) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 43575489382845385.676449172682
  s21_decimal expected_result = {
      {0xCCCCCCCA, 0xCCCCCCCC, 0x8CCCCCCC, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_26) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.500000000002695
  s21_decimal expected_result = {
      {0x8A43CA87, 0x00138A38, 0x00000000, 0b00000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_27) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 200879220200030462170218.78980
  s21_decimal expected_result = {
      {0x628F72C4, 0xBD869CB5, 0x40E856F2, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_28) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -16141589804087329078.475
  s21_decimal expected_result = {
      {0x6466BCCB, 0x098EE502, 0x0000036B, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_29) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -232944002.5
  s21_decimal expected_result = {
      {0x8AD86F19, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_30) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -62444004284939940288393784.5
  s21_decimal expected_result = {
      {0x3ABB7635, 0x8D5DD50A, 0x02048652, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_31) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_32) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_33) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_34) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1831.5
  s21_decimal expected_result = {
      {0x0000478B, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_35) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_36) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.6790123395
  s21_decimal expected_result = {
      {0x94B90F83, 0x00000001, 0x00000000, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_37) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_38) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_39) {
  // 5.5
  s21_decimal input_decimal_1 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.500000000005555
  s21_decimal expected_result = {
      {0x8A43D5B3, 0x00138A38, 0x00000000, 0b00000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_40) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_41) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_42) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 75292899682180827945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_43) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -75292899682180827945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_44) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7529289968218082.7945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_45) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7529289968218082.7945272622317
  s21_decimal expected_result = {
      {0x3BB83CED, 0x685DB76B, 0xF348D3AE, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_46) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.9503300000004656617
  s21_decimal expected_result = {
      {0xD63F4DE9, 0x83E280FF, 0x00000000, 0b00000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_47) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 34709372605944536202586.185911
  s21_decimal expected_result = {
      {0xCD7960B7, 0x3FAA8AFB, 0x7026EB8B, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_48) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2789061279730602080.5722085
  s21_decimal expected_result = {
      {0x21B7BFE5, 0x263B1E0E, 0x00171211, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_49) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -40249758.89015
  s21_decimal expected_result = {
      {0x23421277, 0x000003A9, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_50) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -10789529198564904264412593.677
  s21_decimal expected_result = {
      {0x41627E0D, 0xDBE6F106, 0x22DCE3AD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_51) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_52) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_53) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_54) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 316.45989
  s21_decimal expected_result = {
      {0x01E2E125, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_55) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_56) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.11732469029037
  s21_decimal expected_result = {
      {0xADA618AD, 0x00000AAB, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_57) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_58) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_59) {
  // 0.95033
  s21_decimal input_decimal_1 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.9503300000009598333
  s21_decimal expected_result = {
      {0xD68AB57D, 0x83E280FF, 0x00000000, 0b00000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_60) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_61) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_62) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 75292899682180827945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_63) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_64) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_65) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_66) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_67) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_68) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_69) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_70) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_71) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_72) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_73) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_74) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_75) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_76) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 9781254542381241816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_77) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -7922816251426433759354395033.5
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_78) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_79) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_80) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_81) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_82) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -75292899682180827945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_83) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_84) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_85) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_86) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_87) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_88) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_89) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_90) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_91) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_92) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_93) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_94) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_95) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_96) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -9781254542381241816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_97) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433759354395033.5
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_98) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_99) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_100) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 9780716662385932.475923000669
  s21_decimal expected_result = {
      {0xFEC56D5D, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_101) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 43575489382845385.676449172684
  s21_decimal expected_result = {
      {0xCCCCCCCC, 0xCCCCCCCC, 0x8CCCCCCC, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_102) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7529289968218082.7945272622322
  s21_decimal expected_result = {
      {0x3BB83CF2, 0x685DB76B, 0xF348D3AE, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_103) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_104) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_105) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_106) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251430315.939317593986
  s21_decimal expected_result = {
      {0x0F42B782, 0x99A7646C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_107) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_108) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_109) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -335558641578058148037297.19910
  s21_decimal expected_result = {
      {0x6263A266, 0xF9E02B4E, 0x6C6CC2A0, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_110) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_111) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 31691265005705735.037417580134
  s21_decimal expected_result = {
      {0x66666666, 0x66666666, 0x66666666, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_112) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_113) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_114) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2638297811725002441.8650135462
  s21_decimal expected_result = {
      {0x20C49BA6, 0x916872B0, 0x553F7CED, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_115) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 97807166623859324759.23000669
  s21_decimal expected_result = {
      {0xFEC56D5D, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_116) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 978125454238124.1816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_117) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -792281625142643.37593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_118) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2376844875427930127806318.5100
  s21_decimal expected_result = {
      {0xCCCCCCCC, 0xCCCCCCCC, 0x4CCCCCCC, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_119) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251434435.803768335732
  s21_decimal expected_result = {
      {0xC05EAD74, 0x99B6076A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_120) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 9780716662385932.475923000668
  s21_decimal expected_result = {
      {0xFEC56D5C, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_121) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 43575489382845385.676449172682
  s21_decimal expected_result = {
      {0xCCCCCCCA, 0xCCCCCCCC, 0x8CCCCCCC, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_122) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 7529289968218082.7945272622317
  s21_decimal expected_result = {
      {0x3BB83CED, 0x685DB76B, 0xF348D3AE, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_123) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_124) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_125) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_126) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251430315.939317593986
  s21_decimal expected_result = {
      {0x0F42B782, 0x99A7646C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_127) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_128) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_129) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -335558641578058148037297.19908
  s21_decimal expected_result = {
      {0x6263A264, 0xF9E02B4E, 0x6C6CC2A0, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_130) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_131) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 31691265005705735.037417580132
  s21_decimal expected_result = {
      {0x66666664, 0x66666666, 0x66666666, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_132) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_133) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_134) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 2638297811725002441.8650135460
  s21_decimal expected_result = {
      {0x20C49BA4, 0x916872B0, 0x553F7CED, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_135) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 97807166623859324759.23000668
  s21_decimal expected_result = {
      {0xFEC56D5C, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_136) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 978125454238124.1816510923238
  s21_decimal expected_result = {
      {0x242081E6, 0x39635F31, 0x1F9ADD37, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_137) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -792281625142643.37593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_138) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2376844875427930127806318.5099
  s21_decimal expected_result = {
      {0xCCCCCCCB, 0xCCCCCCCC, 0x4CCCCCCC, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_139) {
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251434435.803768335731
  s21_decimal expected_result = {
      {0xC05EAD73, 0x99B6076A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_140) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.234500000000604905
  s21_decimal expected_result = {
      {0x97417AE9, 0x1121D335, 0x00000000, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_141) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.500000000002695
  s21_decimal expected_result = {
      {0x8A43CA87, 0x00138A38, 0x00000000, 0b00000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_142) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.9503300000004656617
  s21_decimal expected_result = {
      {0xD63F4DE9, 0x83E280FF, 0x00000000, 0b00000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_143) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_144) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_145) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251430315.939317593986
  s21_decimal expected_result = {
      {0x0F42B782, 0x99A7646C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_146) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251430315.939317593986
  s21_decimal expected_result = {
      {0x0F42B782, 0x99A7646C, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_147) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581841616906930.328132
  s21_decimal expected_result = {
      {0x303F9244, 0x9EA8B1B5, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_148) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509835497901.3598186893
  s21_decimal expected_result = {
      {0x76250D8D, 0xB97B5DE4, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_149) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455.00002075319295
  s21_decimal expected_result = {
      {0x00E49BFF, 0x9939E46E, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_150) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324540097790998800.922
  s21_decimal expected_result = {
      {0xD264EA1A, 0x6777FC6B, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_151) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4.00000000000196
  s21_decimal expected_result = {
      {0x41E900C4, 0x00016BCC, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_152) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_153) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_154) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333.00000000016317
  s21_decimal expected_result = {
      {0x6F057FBD, 0x00764E2C, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_155) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345.00000000604905
  s21_decimal expected_result = {
      {0x97417AE9, 0x1121D335, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_156) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.12345678900006049382661
  s21_decimal expected_result = {
      {0x67D98105, 0x42B64D58, 0x0000029D, 0b00000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_157) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.100000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b10000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_158) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000.00014700000000
  s21_decimal expected_result = {
      {0x82F03300, 0x4DA25D33, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_159) {
  // 1.00000000000049
  s21_decimal input_decimal_1 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.0000000000015000000000004949
  s21_decimal expected_result = {
      {0xB7A19355, 0x3E5A4CCC, 0x204FCE5E, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_160) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 45088254061261382827115.472001
  s21_decimal expected_result = {
      {0xC62EE481, 0x57038DD1, 0x91B0212E, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_161) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 200879220200030462170218.78980
  s21_decimal expected_result = {
      {0x628F72C4, 0xBD869CB5, 0x40E856F2, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_162) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 34709372605944536202586.185911
  s21_decimal expected_result = {
      {0xCD7960B7, 0x3FAA8AFB, 0x7026EB8B, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_163) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_164) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_165) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_166) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_167) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581841616906930.328132
  s21_decimal expected_result = {
      {0x303F9244, 0x9EA8B1B5, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_168) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_169) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_170) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_171) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 146093978327294881578340.93804
  s21_decimal expected_result = {
      {0x47AE24EC, 0x729071F8, 0x2F349C53, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_172) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_173) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_174) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12162323695747298891396883.091
  s21_decimal expected_result = {
      {0xF91D2293, 0xAB88E3FF, 0x274C7038, 0b00000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_175) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 450882540612613828271154720.01
  s21_decimal expected_result = {
      {0xC62EE481, 0x57038DD1, 0x91B0212E, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_176) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 4509073364130854283949.3060393
  s21_decimal expected_result = {
      {0xDD7D6729, 0xA4C2C7B7, 0x91B22E40, 0b00000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_177) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -3652349458182372039458.5234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_178) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_179) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal_1 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581860609124112.876467
  s21_decimal expected_result = {
      {0x56E943B3, 0x9EEC2B07, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_180) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -3623053202390146863.159525
  s21_decimal expected_result = {
      {0x7BE558E5, 0x1B8F2747, 0x0002FF36, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_181) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -16141589804087329078.475
  s21_decimal expected_result = {
      {0x6466BCCB, 0x098EE502, 0x0000036B, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_182) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -2789061279730602080.5722085
  s21_decimal expected_result = {
      {0x21B7BFE5, 0x263B1E0E, 0x00171211, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_183) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_184) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_185) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_186) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_187) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509835497901.3598186893
  s21_decimal expected_result = {
      {0x76250D8D, 0xB97B5DE4, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_188) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_189) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 124300381344703910580978614.75
  s21_decimal expected_result = {
      {0xCB897363, 0x7938D194, 0x2829E2F5, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_190) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_191) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11739338039336239329.80
  s21_decimal expected_result = {
      {0xE6B85834, 0xA39AAEE8, 0x0000003F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_192) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.00
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_193) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.00
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_194) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -977299891774741924205.85
  s21_decimal expected_result = {
      {0x0772AEE9, 0xF40D613D, 0x000014B1, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_195) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -36230532023901468631595.25
  s21_decimal expected_result = {
      {0x7BE558E5, 0x1B8F2747, 0x0002FF36, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_196) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -362325244830501949.74815500305
  s21_decimal expected_result = {
      {0x548F3811, 0xF53679F3, 0x7512D77F, 0b10000000000010110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_197) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 293483450983405983.245
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b00000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_198) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 880450352950217949735000000.0
  s21_decimal expected_result = {
      {0xCF0BED80, 0xB795AED1, 0x1C72EA24, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_199) {
  // -2934834509834059832.45
  s21_decimal input_decimal_1 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509837024015.3049324004
  s21_decimal expected_result = {
      {0x61FF59E4, 0xB9B195D1, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_200) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -52285340.1975
  s21_decimal expected_result = {
      {0xBC7DC577, 0x00000079, 0x00000000, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_201) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -232944002.5
  s21_decimal expected_result = {
      {0x8AD86F19, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_202) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -40249758.89015
  s21_decimal expected_result = {
      {0x23421277, 0x000003A9, 0x00000000, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_203) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_204) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_205) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -335558641578058148037297.19910
  s21_decimal expected_result = {
      {0x6263A266, 0xF9E02B4E, 0x6C6CC2A0, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_206) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -335558641578058148037297.19908
  s21_decimal expected_result = {
      {0x6263A264, 0xF9E02B4E, 0x6C6CC2A0, 0b10000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_207) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455.00002075319295
  s21_decimal expected_result = {
      {0x00E49BFF, 0x9939E46E, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_208) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_209) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 124300381344703910580978614.75
  s21_decimal expected_result = {
      {0xCB897363, 0x7938D194, 0x2829E2F5, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_210) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_211) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -169413820
  s21_decimal expected_result = {
      {0x0A190CBC, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_212) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_213) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_214) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -14103700515
  s21_decimal expected_result = {
      {0x48A56423, 0x00000003, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_215) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -522853401975
  s21_decimal expected_result = {
      {0xBC7DC577, 0x00000079, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_216) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -5228821.557355995
  s21_decimal expected_result = {
      {0xE38525DB, 0x00129395, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_217) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 4235345.5
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_218) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12706036500000000
  s21_decimal expected_result = {
      {0xA815ED00, 0x002D2412, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_219) {
  // -42353455
  s21_decimal input_decimal_1 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455.00004277698955
  s21_decimal expected_result = {
      {0x842A418B, 0x9939E46E, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_220) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // -14015840598137882961094932.176
  s21_decimal expected_result = {
      {0x343C76D0, 0x491BD9FF, 0x2D49A1B1, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_221) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -62444004284939940288393784.5
  s21_decimal expected_result = {
      {0x3ABB7635, 0x8D5DD50A, 0x02048652, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_222) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // -10789529198564904264412593.677
  s21_decimal expected_result = {
      {0x41627E0D, 0xDBE6F106, 0x22DCE3AD, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_223) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_224) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_225) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_226) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_227) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324540097790998800.922
  s21_decimal expected_result = {
      {0xD264EA1A, 0x6777FC6B, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_228) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_229) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_230) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_231) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -45413821298138138391559116
  s21_decimal expected_result = {
      {0xF1A73BCC, 0x2F847F33, 0x002590C0, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_232) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_233) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_234) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -3780700623070000021097296407
  s21_decimal expected_result = {
      {0x55A23217, 0x73D65DA4, 0x0C37527F, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_235) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_236) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -1401661138421986561064878.2913
  s21_decimal expected_result = {
      {0xD2EB8841, 0xAECCBD87, 0x2D4A44E9, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_237) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1135345532453453459788977.9
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_238) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_239) {
  // -11353455324534534597889779
  s21_decimal input_decimal_1 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324546001587767558.880
  s21_decimal expected_result = {
      {0x9F9F42E0, 0x678CF5E4, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_240) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_241) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_242) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_243) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_244) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_245) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 31691265005705735.037417580134
  s21_decimal expected_result = {
      {0x66666666, 0x66666666, 0x66666666, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_246) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 31691265005705735.037417580132
  s21_decimal expected_result = {
      {0x66666664, 0x66666666, 0x66666666, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_247) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4.00000000000196
  s21_decimal expected_result = {
      {0x41E900C4, 0x00016BCC, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_248) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 146093978327294881578340.93804
  s21_decimal expected_result = {
      {0x47AE24EC, 0x729071F8, 0x2F349C53, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_249) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -11739338039336239329.80
  s21_decimal expected_result = {
      {0xE6B85834, 0xA39AAEE8, 0x0000003F, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_250) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -169413820
  s21_decimal expected_result = {
      {0x0A190CBC, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_251) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -45413821298138138391559116
  s21_decimal expected_result = {
      {0xF1A73BCC, 0x2F847F33, 0x002590C0, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_252) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_253) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_254) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1332
  s21_decimal expected_result = {
      {0x00000534, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_255) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_256) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.493827156
  s21_decimal expected_result = {
      {0x1D6F3454, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_257) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_258) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_259) {
  // 4
  s21_decimal input_decimal_1 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4.00000000000404
  s21_decimal expected_result = {
      {0x41E90194, 0x00016BCC, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_260) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_261) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_262) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_263) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_264) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_265) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_266) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_267) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_268) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 0.000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_269) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -0.00
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_270) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_271) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_272) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_273) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_274) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_275) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_276) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_277) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_278) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_279) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_280) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_281) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_282) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_283) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_284) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_285) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_286) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -0.0000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_287) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_288) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -0.000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_289) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 0.00
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_290) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_291) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_292) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_293) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_294) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_295) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_296) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_297) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_298) {
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
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_299) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_300) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 411.0885
  s21_decimal expected_result = {
      {0x003EBA25, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_301) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 1831.5
  s21_decimal expected_result = {
      {0x0000478B, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_302) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 316.45989
  s21_decimal expected_result = {
      {0x01E2E125, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_303) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_304) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_305) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 2638297811725002441.8650135462
  s21_decimal expected_result = {
      {0x20C49BA6, 0x916872B0, 0x553F7CED, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_306) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 2638297811725002441.8650135460
  s21_decimal expected_result = {
      {0x20C49BA4, 0x916872B0, 0x553F7CED, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_307) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333.00000000016317
  s21_decimal expected_result = {
      {0x6F057FBD, 0x00764E2C, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_308) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 12162323695747298891396883.091
  s21_decimal expected_result = {
      {0xF91D2293, 0xAB88E3FF, 0x274C7038, 0b00000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_309) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -977299891774741924205.85
  s21_decimal expected_result = {
      {0x0772AEE9, 0xF40D613D, 0x000014B1, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_310) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -14103700515
  s21_decimal expected_result = {
      {0x48A56423, 0x00000003, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_311) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -3780700623070000021097296407
  s21_decimal expected_result = {
      {0x55A23217, 0x73D65DA4, 0x0C37527F, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_312) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1332
  s21_decimal expected_result = {
      {0x00000534, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_313) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_314) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_315) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4110885
  s21_decimal expected_result = {
      {0x003EBA25, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_316) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 41.111110737
  s21_decimal expected_result = {
      {0x9269C451, 0x00000009, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_317) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -33.3
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_318) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -99900000000
  s21_decimal expected_result = {
      {0x42810700, 0x00000017, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_319) {
  // 333
  s21_decimal input_decimal_1 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333.00000000033633
  s21_decimal expected_result = {
      {0x6F05C361, 0x00764E2C, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_320) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_321) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_322) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_323) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_324) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_325) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 97807166623859324759.23000669
  s21_decimal expected_result = {
      {0xFEC56D5D, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_326) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 97807166623859324759.23000668
  s21_decimal expected_result = {
      {0xFEC56D5C, 0xB0F27BB2, 0x1F9A6B50, 0b00000000000010000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_327) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345.00000000604905
  s21_decimal expected_result = {
      {0x97417AE9, 0x1121D335, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_328) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 450882540612613828271154720.01
  s21_decimal expected_result = {
      {0xC62EE481, 0x57038DD1, 0x91B0212E, 0b00000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_329) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -36230532023901468631595.25
  s21_decimal expected_result = {
      {0x7BE558E5, 0x1B8F2747, 0x0002FF36, 0b10000000000000100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_330) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -522853401975
  s21_decimal expected_result = {
      {0xBC7DC577, 0x00000079, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_331) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_332) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_333) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_334) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_335) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4110885
  s21_decimal expected_result = {
      {0x003EBA25, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_336) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1524.074060205
  s21_decimal expected_result = {
      {0xD9E499AD, 0x00000162, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_337) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_338) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_339) {
  // 12345
  s21_decimal input_decimal_1 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345.00000001246845
  s21_decimal expected_result = {
      {0x974B467D, 0x1121D335, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_340) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 0.1524074060205
  s21_decimal expected_result = {
      {0xD9E499AD, 0x00000162, 0x00000000, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_341) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.6790123395
  s21_decimal expected_result = {
      {0x94B90F83, 0x00000001, 0x00000000, 0b00000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_342) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.11732469029037
  s21_decimal expected_result = {
      {0xADA618AD, 0x00000AAB, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_343) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 9781254542381241816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_344) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -9781254542381241816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_345) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 978125454238124.1816510923239
  s21_decimal expected_result = {
      {0x242081E7, 0x39635F31, 0x1F9ADD37, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_346) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 978125454238124.1816510923238
  s21_decimal expected_result = {
      {0x242081E6, 0x39635F31, 0x1F9ADD37, 0b00000000000011010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_347) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.12345678900006049382661
  s21_decimal expected_result = {
      {0x67D98105, 0x42B64D58, 0x0000029D, 0b00000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_348) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 4509073364130854283949.3060393
  s21_decimal expected_result = {
      {0xDD7D6729, 0xA4C2C7B7, 0x91B22E40, 0b00000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_349) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -362325244830501949.74815500305
  s21_decimal expected_result = {
      {0x548F3811, 0xF53679F3, 0x7512D77F, 0b10000000000010110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_350) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -5228821.557355995
  s21_decimal expected_result = {
      {0xE38525DB, 0x00129395, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_351) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -1401661138421986561064878.2913
  s21_decimal expected_result = {
      {0xD2EB8841, 0xAECCBD87, 0x2D4A44E9, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_352) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.493827156
  s21_decimal expected_result = {
      {0x1D6F3454, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_353) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_354) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_355) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 41.111110737
  s21_decimal expected_result = {
      {0x9269C451, 0x00000009, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_356) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 1524.074060205
  s21_decimal expected_result = {
      {0xD9E499AD, 0x00000162, 0x00000000, 0b00000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_357) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.0123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_358) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -37037036.700000000
  s21_decimal expected_result = {
      {0x18095F00, 0x008394FD, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_359) {
  // 0.123456789
  s21_decimal input_decimal_1 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.12345678900012469135689
  s21_decimal expected_result = {
      {0xE67F2949, 0x42B64D59, 0x0000029D, 0b00000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_360) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_361) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_362) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_363) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -7922816251426433759354395033.5
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_364) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395033.5
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_365) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -792281625142643.37593543950335
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_366) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -792281625142643.37593543950330
  s21_decimal expected_result = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_367) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.100000000000049
  s21_decimal expected_result = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b10000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_368) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // -3652349458182372039458.5234509
  s21_decimal expected_result = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b10000000000001110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_369) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 293483450983405983.245
  s21_decimal expected_result = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b00000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_370) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 4235345.5
  s21_decimal expected_result = {
      {0x0286432F, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_371) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // 1135345532453453459788977.9
  s21_decimal expected_result = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_372) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_373) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_374) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_375) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -33.3
  s21_decimal expected_result = {
      {0x0000014D, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_376) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_377) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -0.0123456789
  s21_decimal expected_result = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_378) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_379) {
  // -0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.100000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b10000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_380) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_381) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_382) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_383) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_384) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_385) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2376844875427930127806318.5100
  s21_decimal expected_result = {
      {0xCCCCCCCC, 0xCCCCCCCC, 0x4CCCCCCC, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_386) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // -2376844875427930127806318.5099
  s21_decimal expected_result = {
      {0xCCCCCCCB, 0xCCCCCCCC, 0x4CCCCCCC, 0b10000000000001000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_387) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000.00014700000000
  s21_decimal expected_result = {
      {0x82F03300, 0x4DA25D33, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_388) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_389) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // 880450352950217949735000000.0
  s21_decimal expected_result = {
      {0xCF0BED80, 0xB795AED1, 0x1C72EA24, 0b00000000000000010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_390) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12706036500000000
  s21_decimal expected_result = {
      {0xA815ED00, 0x002D2412, 0x00000000, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_391) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_392) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_393) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_394) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_395) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -99900000000
  s21_decimal expected_result = {
      {0x42810700, 0x00000017, 0x00000000, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_396) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_397) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // -37037036.700000000
  s21_decimal expected_result = {
      {0x18095F00, 0x008394FD, 0x00000000, 0b10000000000010010000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_398) {
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
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_399) {
  // -300000000
  s21_decimal input_decimal_1 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 1.00000000000101
  s21_decimal input_decimal_2 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000.00030300000000
  s21_decimal expected_result = {
      {0x24C54F00, 0x4DA25D37, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_400) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.2345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.234500000001246845
  s21_decimal expected_result = {
      {0x974B467D, 0x1121D335, 0x00000000, 0b00000000000100100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_401) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 5.5
  s21_decimal input_decimal_2 = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.500000000005555
  s21_decimal expected_result = {
      {0x8A43D5B3, 0x00138A38, 0x00000000, 0b00000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_402) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.95033
  s21_decimal input_decimal_2 = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.9503300000009598333
  s21_decimal expected_result = {
      {0xD68AB57D, 0x83E280FF, 0x00000000, 0b00000000000100110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_403) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_BIG);
}
END_TEST

START_TEST(test_mul_gen_404) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_return_code, TOO_SMALL);
}
END_TEST

START_TEST(test_mul_gen_405) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251434435.803768335732
  s21_decimal expected_result = {
      {0xC05EAD74, 0x99B6076A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_406) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 7922816251426433.7593543950330
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816251434435.803768335731
  s21_decimal expected_result = {
      {0xC05EAD73, 0x99B6076A, 0x19999999, 0b00000000000011000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_407) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.00000000000049
  s21_decimal input_decimal_2 = {
      {0x107A4031, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 1.0000000000015000000000004949
  s21_decimal expected_result = {
      {0xB7A19355, 0x3E5A4CCC, 0x204FCE5E, 0b00000000000111000000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_408) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 36523494581823720394585.234509
  s21_decimal input_decimal_2 = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494581860609124112.876467
  s21_decimal expected_result = {
      {0x56E943B3, 0x9EEC2B07, 0x760386D0, 0b00000000000001100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_409) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -2934834509834059832.45
  s21_decimal input_decimal_2 = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834509837024015.3049324004
  s21_decimal expected_result = {
      {0x61FF59E4, 0xB9B195D1, 0x5ED461CF, 0b10000000000010100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_410) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -42353455
  s21_decimal input_decimal_2 = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353455.00004277698955
  s21_decimal expected_result = {
      {0x842A418B, 0x9939E46E, 0x000000E5, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_411) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -11353455324534534597889779
  s21_decimal input_decimal_2 = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455324546001587767558.880
  s21_decimal expected_result = {
      {0x9F9F42E0, 0x678CF5E4, 0x24AF5BAE, 0b10000000000000110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_412) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 4
  s21_decimal input_decimal_2 = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4.00000000000404
  s21_decimal expected_result = {
      {0x41E90194, 0x00016BCC, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_413) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_414) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.00000000000000
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_415) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 333
  s21_decimal input_decimal_2 = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333.00000000033633
  s21_decimal expected_result = {
      {0x6F05C361, 0x00764E2C, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_416) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 12345
  s21_decimal input_decimal_2 = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345.00000001246845
  s21_decimal expected_result = {
      {0x974B467D, 0x1121D335, 0x00000000, 0b00000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_417) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.123456789
  s21_decimal input_decimal_2 = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.12345678900012469135689
  s21_decimal expected_result = {
      {0xE67F2949, 0x42B64D59, 0x0000029D, 0b00000000000101110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_418) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.100000000000101
  s21_decimal expected_result = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b10000000000011110000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_mul_gen_419) {
  // 1.00000000000101
  s21_decimal input_decimal_1 = {
      {0x107A4065, 0x00005AF3, 0x00000000, 0b00000000000011100000000000000000}};
  // -300000000
  s21_decimal input_decimal_2 = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000.00030300000000
  s21_decimal expected_result = {
      {0x24C54F00, 0x4DA25D37, 0x0000065A, 0b10000000000011100000000000000000}};

  s21_decimal s21_result_decimal;
  ArithmeticResult s21_return_code =
      s21_mul(input_decimal_1, input_decimal_2, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_mul_suite() {
  Suite* mul_suite = suite_create("mul");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mul_gen_0);
  tcase_add_test(tc_core, test_mul_gen_1);
  tcase_add_test(tc_core, test_mul_gen_2);
  tcase_add_test(tc_core, test_mul_gen_3);
  tcase_add_test(tc_core, test_mul_gen_4);
  tcase_add_test(tc_core, test_mul_gen_5);
  tcase_add_test(tc_core, test_mul_gen_6);
  tcase_add_test(tc_core, test_mul_gen_7);
  tcase_add_test(tc_core, test_mul_gen_8);
  tcase_add_test(tc_core, test_mul_gen_9);
  tcase_add_test(tc_core, test_mul_gen_10);
  tcase_add_test(tc_core, test_mul_gen_11);
  tcase_add_test(tc_core, test_mul_gen_12);
  tcase_add_test(tc_core, test_mul_gen_13);
  tcase_add_test(tc_core, test_mul_gen_14);
  tcase_add_test(tc_core, test_mul_gen_15);
  tcase_add_test(tc_core, test_mul_gen_16);
  tcase_add_test(tc_core, test_mul_gen_17);
  tcase_add_test(tc_core, test_mul_gen_18);
  tcase_add_test(tc_core, test_mul_gen_19);
  tcase_add_test(tc_core, test_mul_gen_20);
  tcase_add_test(tc_core, test_mul_gen_21);
  tcase_add_test(tc_core, test_mul_gen_22);
  tcase_add_test(tc_core, test_mul_gen_23);
  tcase_add_test(tc_core, test_mul_gen_24);
  tcase_add_test(tc_core, test_mul_gen_25);
  tcase_add_test(tc_core, test_mul_gen_26);
  tcase_add_test(tc_core, test_mul_gen_27);
  tcase_add_test(tc_core, test_mul_gen_28);
  tcase_add_test(tc_core, test_mul_gen_29);
  tcase_add_test(tc_core, test_mul_gen_30);
  tcase_add_test(tc_core, test_mul_gen_31);
  tcase_add_test(tc_core, test_mul_gen_32);
  tcase_add_test(tc_core, test_mul_gen_33);
  tcase_add_test(tc_core, test_mul_gen_34);
  tcase_add_test(tc_core, test_mul_gen_35);
  tcase_add_test(tc_core, test_mul_gen_36);
  tcase_add_test(tc_core, test_mul_gen_37);
  tcase_add_test(tc_core, test_mul_gen_38);
  tcase_add_test(tc_core, test_mul_gen_39);
  tcase_add_test(tc_core, test_mul_gen_40);
  tcase_add_test(tc_core, test_mul_gen_41);
  tcase_add_test(tc_core, test_mul_gen_42);
  tcase_add_test(tc_core, test_mul_gen_43);
  tcase_add_test(tc_core, test_mul_gen_44);
  tcase_add_test(tc_core, test_mul_gen_45);
  tcase_add_test(tc_core, test_mul_gen_46);
  tcase_add_test(tc_core, test_mul_gen_47);
  tcase_add_test(tc_core, test_mul_gen_48);
  tcase_add_test(tc_core, test_mul_gen_49);
  tcase_add_test(tc_core, test_mul_gen_50);
  tcase_add_test(tc_core, test_mul_gen_51);
  tcase_add_test(tc_core, test_mul_gen_52);
  tcase_add_test(tc_core, test_mul_gen_53);
  tcase_add_test(tc_core, test_mul_gen_54);
  tcase_add_test(tc_core, test_mul_gen_55);
  tcase_add_test(tc_core, test_mul_gen_56);
  tcase_add_test(tc_core, test_mul_gen_57);
  tcase_add_test(tc_core, test_mul_gen_58);
  tcase_add_test(tc_core, test_mul_gen_59);
  tcase_add_test(tc_core, test_mul_gen_60);
  tcase_add_test(tc_core, test_mul_gen_61);
  tcase_add_test(tc_core, test_mul_gen_62);
  tcase_add_test(tc_core, test_mul_gen_63);
  tcase_add_test(tc_core, test_mul_gen_64);
  tcase_add_test(tc_core, test_mul_gen_65);
  tcase_add_test(tc_core, test_mul_gen_66);
  tcase_add_test(tc_core, test_mul_gen_67);
  tcase_add_test(tc_core, test_mul_gen_68);
  tcase_add_test(tc_core, test_mul_gen_69);
  tcase_add_test(tc_core, test_mul_gen_70);
  tcase_add_test(tc_core, test_mul_gen_71);
  tcase_add_test(tc_core, test_mul_gen_72);
  tcase_add_test(tc_core, test_mul_gen_73);
  tcase_add_test(tc_core, test_mul_gen_74);
  tcase_add_test(tc_core, test_mul_gen_75);
  tcase_add_test(tc_core, test_mul_gen_76);
  tcase_add_test(tc_core, test_mul_gen_77);
  tcase_add_test(tc_core, test_mul_gen_78);
  tcase_add_test(tc_core, test_mul_gen_79);
  tcase_add_test(tc_core, test_mul_gen_80);
  tcase_add_test(tc_core, test_mul_gen_81);
  tcase_add_test(tc_core, test_mul_gen_82);
  tcase_add_test(tc_core, test_mul_gen_83);
  tcase_add_test(tc_core, test_mul_gen_84);
  tcase_add_test(tc_core, test_mul_gen_85);
  tcase_add_test(tc_core, test_mul_gen_86);
  tcase_add_test(tc_core, test_mul_gen_87);
  tcase_add_test(tc_core, test_mul_gen_88);
  tcase_add_test(tc_core, test_mul_gen_89);
  tcase_add_test(tc_core, test_mul_gen_90);
  tcase_add_test(tc_core, test_mul_gen_91);
  tcase_add_test(tc_core, test_mul_gen_92);
  tcase_add_test(tc_core, test_mul_gen_93);
  tcase_add_test(tc_core, test_mul_gen_94);
  tcase_add_test(tc_core, test_mul_gen_95);
  tcase_add_test(tc_core, test_mul_gen_96);
  tcase_add_test(tc_core, test_mul_gen_97);
  tcase_add_test(tc_core, test_mul_gen_98);
  tcase_add_test(tc_core, test_mul_gen_99);
  tcase_add_test(tc_core, test_mul_gen_100);
  tcase_add_test(tc_core, test_mul_gen_101);
  tcase_add_test(tc_core, test_mul_gen_102);
  tcase_add_test(tc_core, test_mul_gen_103);
  tcase_add_test(tc_core, test_mul_gen_104);
  tcase_add_test(tc_core, test_mul_gen_105);
  tcase_add_test(tc_core, test_mul_gen_106);
  tcase_add_test(tc_core, test_mul_gen_107);
  tcase_add_test(tc_core, test_mul_gen_108);
  tcase_add_test(tc_core, test_mul_gen_109);
  tcase_add_test(tc_core, test_mul_gen_110);
  tcase_add_test(tc_core, test_mul_gen_111);
  tcase_add_test(tc_core, test_mul_gen_112);
  tcase_add_test(tc_core, test_mul_gen_113);
  tcase_add_test(tc_core, test_mul_gen_114);
  tcase_add_test(tc_core, test_mul_gen_115);
  tcase_add_test(tc_core, test_mul_gen_116);
  tcase_add_test(tc_core, test_mul_gen_117);
  tcase_add_test(tc_core, test_mul_gen_118);
  tcase_add_test(tc_core, test_mul_gen_119);
  tcase_add_test(tc_core, test_mul_gen_120);
  tcase_add_test(tc_core, test_mul_gen_121);
  tcase_add_test(tc_core, test_mul_gen_122);
  tcase_add_test(tc_core, test_mul_gen_123);
  tcase_add_test(tc_core, test_mul_gen_124);
  tcase_add_test(tc_core, test_mul_gen_125);
  tcase_add_test(tc_core, test_mul_gen_126);
  tcase_add_test(tc_core, test_mul_gen_127);
  tcase_add_test(tc_core, test_mul_gen_128);
  tcase_add_test(tc_core, test_mul_gen_129);
  tcase_add_test(tc_core, test_mul_gen_130);
  tcase_add_test(tc_core, test_mul_gen_131);
  tcase_add_test(tc_core, test_mul_gen_132);
  tcase_add_test(tc_core, test_mul_gen_133);
  tcase_add_test(tc_core, test_mul_gen_134);
  tcase_add_test(tc_core, test_mul_gen_135);
  tcase_add_test(tc_core, test_mul_gen_136);
  tcase_add_test(tc_core, test_mul_gen_137);
  tcase_add_test(tc_core, test_mul_gen_138);
  tcase_add_test(tc_core, test_mul_gen_139);
  tcase_add_test(tc_core, test_mul_gen_140);
  tcase_add_test(tc_core, test_mul_gen_141);
  tcase_add_test(tc_core, test_mul_gen_142);
  tcase_add_test(tc_core, test_mul_gen_143);
  tcase_add_test(tc_core, test_mul_gen_144);
  tcase_add_test(tc_core, test_mul_gen_145);
  tcase_add_test(tc_core, test_mul_gen_146);
  tcase_add_test(tc_core, test_mul_gen_147);
  tcase_add_test(tc_core, test_mul_gen_148);
  tcase_add_test(tc_core, test_mul_gen_149);
  tcase_add_test(tc_core, test_mul_gen_150);
  tcase_add_test(tc_core, test_mul_gen_151);
  tcase_add_test(tc_core, test_mul_gen_152);
  tcase_add_test(tc_core, test_mul_gen_153);
  tcase_add_test(tc_core, test_mul_gen_154);
  tcase_add_test(tc_core, test_mul_gen_155);
  tcase_add_test(tc_core, test_mul_gen_156);
  tcase_add_test(tc_core, test_mul_gen_157);
  tcase_add_test(tc_core, test_mul_gen_158);
  tcase_add_test(tc_core, test_mul_gen_159);
  tcase_add_test(tc_core, test_mul_gen_160);
  tcase_add_test(tc_core, test_mul_gen_161);
  tcase_add_test(tc_core, test_mul_gen_162);
  tcase_add_test(tc_core, test_mul_gen_163);
  tcase_add_test(tc_core, test_mul_gen_164);
  tcase_add_test(tc_core, test_mul_gen_165);
  tcase_add_test(tc_core, test_mul_gen_166);
  tcase_add_test(tc_core, test_mul_gen_167);
  tcase_add_test(tc_core, test_mul_gen_168);
  tcase_add_test(tc_core, test_mul_gen_169);
  tcase_add_test(tc_core, test_mul_gen_170);
  tcase_add_test(tc_core, test_mul_gen_171);
  tcase_add_test(tc_core, test_mul_gen_172);
  tcase_add_test(tc_core, test_mul_gen_173);
  tcase_add_test(tc_core, test_mul_gen_174);
  tcase_add_test(tc_core, test_mul_gen_175);
  tcase_add_test(tc_core, test_mul_gen_176);
  tcase_add_test(tc_core, test_mul_gen_177);
  tcase_add_test(tc_core, test_mul_gen_178);
  tcase_add_test(tc_core, test_mul_gen_179);
  tcase_add_test(tc_core, test_mul_gen_180);
  tcase_add_test(tc_core, test_mul_gen_181);
  tcase_add_test(tc_core, test_mul_gen_182);
  tcase_add_test(tc_core, test_mul_gen_183);
  tcase_add_test(tc_core, test_mul_gen_184);
  tcase_add_test(tc_core, test_mul_gen_185);
  tcase_add_test(tc_core, test_mul_gen_186);
  tcase_add_test(tc_core, test_mul_gen_187);
  tcase_add_test(tc_core, test_mul_gen_188);
  tcase_add_test(tc_core, test_mul_gen_189);
  tcase_add_test(tc_core, test_mul_gen_190);
  tcase_add_test(tc_core, test_mul_gen_191);
  tcase_add_test(tc_core, test_mul_gen_192);
  tcase_add_test(tc_core, test_mul_gen_193);
  tcase_add_test(tc_core, test_mul_gen_194);
  tcase_add_test(tc_core, test_mul_gen_195);
  tcase_add_test(tc_core, test_mul_gen_196);
  tcase_add_test(tc_core, test_mul_gen_197);
  tcase_add_test(tc_core, test_mul_gen_198);
  tcase_add_test(tc_core, test_mul_gen_199);
  tcase_add_test(tc_core, test_mul_gen_200);
  tcase_add_test(tc_core, test_mul_gen_201);
  tcase_add_test(tc_core, test_mul_gen_202);
  tcase_add_test(tc_core, test_mul_gen_203);
  tcase_add_test(tc_core, test_mul_gen_204);
  tcase_add_test(tc_core, test_mul_gen_205);
  tcase_add_test(tc_core, test_mul_gen_206);
  tcase_add_test(tc_core, test_mul_gen_207);
  tcase_add_test(tc_core, test_mul_gen_208);
  tcase_add_test(tc_core, test_mul_gen_209);
  tcase_add_test(tc_core, test_mul_gen_210);
  tcase_add_test(tc_core, test_mul_gen_211);
  tcase_add_test(tc_core, test_mul_gen_212);
  tcase_add_test(tc_core, test_mul_gen_213);
  tcase_add_test(tc_core, test_mul_gen_214);
  tcase_add_test(tc_core, test_mul_gen_215);
  tcase_add_test(tc_core, test_mul_gen_216);
  tcase_add_test(tc_core, test_mul_gen_217);
  tcase_add_test(tc_core, test_mul_gen_218);
  tcase_add_test(tc_core, test_mul_gen_219);
  tcase_add_test(tc_core, test_mul_gen_220);
  tcase_add_test(tc_core, test_mul_gen_221);
  tcase_add_test(tc_core, test_mul_gen_222);
  tcase_add_test(tc_core, test_mul_gen_223);
  tcase_add_test(tc_core, test_mul_gen_224);
  tcase_add_test(tc_core, test_mul_gen_225);
  tcase_add_test(tc_core, test_mul_gen_226);
  tcase_add_test(tc_core, test_mul_gen_227);
  tcase_add_test(tc_core, test_mul_gen_228);
  tcase_add_test(tc_core, test_mul_gen_229);
  tcase_add_test(tc_core, test_mul_gen_230);
  tcase_add_test(tc_core, test_mul_gen_231);
  tcase_add_test(tc_core, test_mul_gen_232);
  tcase_add_test(tc_core, test_mul_gen_233);
  tcase_add_test(tc_core, test_mul_gen_234);
  tcase_add_test(tc_core, test_mul_gen_235);
  tcase_add_test(tc_core, test_mul_gen_236);
  tcase_add_test(tc_core, test_mul_gen_237);
  tcase_add_test(tc_core, test_mul_gen_238);
  tcase_add_test(tc_core, test_mul_gen_239);
  tcase_add_test(tc_core, test_mul_gen_240);
  tcase_add_test(tc_core, test_mul_gen_241);
  tcase_add_test(tc_core, test_mul_gen_242);
  tcase_add_test(tc_core, test_mul_gen_243);
  tcase_add_test(tc_core, test_mul_gen_244);
  tcase_add_test(tc_core, test_mul_gen_245);
  tcase_add_test(tc_core, test_mul_gen_246);
  tcase_add_test(tc_core, test_mul_gen_247);
  tcase_add_test(tc_core, test_mul_gen_248);
  tcase_add_test(tc_core, test_mul_gen_249);
  tcase_add_test(tc_core, test_mul_gen_250);
  tcase_add_test(tc_core, test_mul_gen_251);
  tcase_add_test(tc_core, test_mul_gen_252);
  tcase_add_test(tc_core, test_mul_gen_253);
  tcase_add_test(tc_core, test_mul_gen_254);
  tcase_add_test(tc_core, test_mul_gen_255);
  tcase_add_test(tc_core, test_mul_gen_256);
  tcase_add_test(tc_core, test_mul_gen_257);
  tcase_add_test(tc_core, test_mul_gen_258);
  tcase_add_test(tc_core, test_mul_gen_259);
  tcase_add_test(tc_core, test_mul_gen_260);
  tcase_add_test(tc_core, test_mul_gen_261);
  tcase_add_test(tc_core, test_mul_gen_262);
  tcase_add_test(tc_core, test_mul_gen_263);
  tcase_add_test(tc_core, test_mul_gen_264);
  tcase_add_test(tc_core, test_mul_gen_265);
  tcase_add_test(tc_core, test_mul_gen_266);
  tcase_add_test(tc_core, test_mul_gen_267);
  tcase_add_test(tc_core, test_mul_gen_268);
  tcase_add_test(tc_core, test_mul_gen_269);
  tcase_add_test(tc_core, test_mul_gen_270);
  tcase_add_test(tc_core, test_mul_gen_271);
  tcase_add_test(tc_core, test_mul_gen_272);
  tcase_add_test(tc_core, test_mul_gen_273);
  tcase_add_test(tc_core, test_mul_gen_274);
  tcase_add_test(tc_core, test_mul_gen_275);
  tcase_add_test(tc_core, test_mul_gen_276);
  tcase_add_test(tc_core, test_mul_gen_277);
  tcase_add_test(tc_core, test_mul_gen_278);
  tcase_add_test(tc_core, test_mul_gen_279);
  tcase_add_test(tc_core, test_mul_gen_280);
  tcase_add_test(tc_core, test_mul_gen_281);
  tcase_add_test(tc_core, test_mul_gen_282);
  tcase_add_test(tc_core, test_mul_gen_283);
  tcase_add_test(tc_core, test_mul_gen_284);
  tcase_add_test(tc_core, test_mul_gen_285);
  tcase_add_test(tc_core, test_mul_gen_286);
  tcase_add_test(tc_core, test_mul_gen_287);
  tcase_add_test(tc_core, test_mul_gen_288);
  tcase_add_test(tc_core, test_mul_gen_289);
  tcase_add_test(tc_core, test_mul_gen_290);
  tcase_add_test(tc_core, test_mul_gen_291);
  tcase_add_test(tc_core, test_mul_gen_292);
  tcase_add_test(tc_core, test_mul_gen_293);
  tcase_add_test(tc_core, test_mul_gen_294);
  tcase_add_test(tc_core, test_mul_gen_295);
  tcase_add_test(tc_core, test_mul_gen_296);
  tcase_add_test(tc_core, test_mul_gen_297);
  tcase_add_test(tc_core, test_mul_gen_298);
  tcase_add_test(tc_core, test_mul_gen_299);
  tcase_add_test(tc_core, test_mul_gen_300);
  tcase_add_test(tc_core, test_mul_gen_301);
  tcase_add_test(tc_core, test_mul_gen_302);
  tcase_add_test(tc_core, test_mul_gen_303);
  tcase_add_test(tc_core, test_mul_gen_304);
  tcase_add_test(tc_core, test_mul_gen_305);
  tcase_add_test(tc_core, test_mul_gen_306);
  tcase_add_test(tc_core, test_mul_gen_307);
  tcase_add_test(tc_core, test_mul_gen_308);
  tcase_add_test(tc_core, test_mul_gen_309);
  tcase_add_test(tc_core, test_mul_gen_310);
  tcase_add_test(tc_core, test_mul_gen_311);
  tcase_add_test(tc_core, test_mul_gen_312);
  tcase_add_test(tc_core, test_mul_gen_313);
  tcase_add_test(tc_core, test_mul_gen_314);
  tcase_add_test(tc_core, test_mul_gen_315);
  tcase_add_test(tc_core, test_mul_gen_316);
  tcase_add_test(tc_core, test_mul_gen_317);
  tcase_add_test(tc_core, test_mul_gen_318);
  tcase_add_test(tc_core, test_mul_gen_319);
  tcase_add_test(tc_core, test_mul_gen_320);
  tcase_add_test(tc_core, test_mul_gen_321);
  tcase_add_test(tc_core, test_mul_gen_322);
  tcase_add_test(tc_core, test_mul_gen_323);
  tcase_add_test(tc_core, test_mul_gen_324);
  tcase_add_test(tc_core, test_mul_gen_325);
  tcase_add_test(tc_core, test_mul_gen_326);
  tcase_add_test(tc_core, test_mul_gen_327);
  tcase_add_test(tc_core, test_mul_gen_328);
  tcase_add_test(tc_core, test_mul_gen_329);
  tcase_add_test(tc_core, test_mul_gen_330);
  tcase_add_test(tc_core, test_mul_gen_331);
  tcase_add_test(tc_core, test_mul_gen_332);
  tcase_add_test(tc_core, test_mul_gen_333);
  tcase_add_test(tc_core, test_mul_gen_334);
  tcase_add_test(tc_core, test_mul_gen_335);
  tcase_add_test(tc_core, test_mul_gen_336);
  tcase_add_test(tc_core, test_mul_gen_337);
  tcase_add_test(tc_core, test_mul_gen_338);
  tcase_add_test(tc_core, test_mul_gen_339);
  tcase_add_test(tc_core, test_mul_gen_340);
  tcase_add_test(tc_core, test_mul_gen_341);
  tcase_add_test(tc_core, test_mul_gen_342);
  tcase_add_test(tc_core, test_mul_gen_343);
  tcase_add_test(tc_core, test_mul_gen_344);
  tcase_add_test(tc_core, test_mul_gen_345);
  tcase_add_test(tc_core, test_mul_gen_346);
  tcase_add_test(tc_core, test_mul_gen_347);
  tcase_add_test(tc_core, test_mul_gen_348);
  tcase_add_test(tc_core, test_mul_gen_349);
  tcase_add_test(tc_core, test_mul_gen_350);
  tcase_add_test(tc_core, test_mul_gen_351);
  tcase_add_test(tc_core, test_mul_gen_352);
  tcase_add_test(tc_core, test_mul_gen_353);
  tcase_add_test(tc_core, test_mul_gen_354);
  tcase_add_test(tc_core, test_mul_gen_355);
  tcase_add_test(tc_core, test_mul_gen_356);
  tcase_add_test(tc_core, test_mul_gen_357);
  tcase_add_test(tc_core, test_mul_gen_358);
  tcase_add_test(tc_core, test_mul_gen_359);
  tcase_add_test(tc_core, test_mul_gen_360);
  tcase_add_test(tc_core, test_mul_gen_361);
  tcase_add_test(tc_core, test_mul_gen_362);
  tcase_add_test(tc_core, test_mul_gen_363);
  tcase_add_test(tc_core, test_mul_gen_364);
  tcase_add_test(tc_core, test_mul_gen_365);
  tcase_add_test(tc_core, test_mul_gen_366);
  tcase_add_test(tc_core, test_mul_gen_367);
  tcase_add_test(tc_core, test_mul_gen_368);
  tcase_add_test(tc_core, test_mul_gen_369);
  tcase_add_test(tc_core, test_mul_gen_370);
  tcase_add_test(tc_core, test_mul_gen_371);
  tcase_add_test(tc_core, test_mul_gen_372);
  tcase_add_test(tc_core, test_mul_gen_373);
  tcase_add_test(tc_core, test_mul_gen_374);
  tcase_add_test(tc_core, test_mul_gen_375);
  tcase_add_test(tc_core, test_mul_gen_376);
  tcase_add_test(tc_core, test_mul_gen_377);
  tcase_add_test(tc_core, test_mul_gen_378);
  tcase_add_test(tc_core, test_mul_gen_379);
  tcase_add_test(tc_core, test_mul_gen_380);
  tcase_add_test(tc_core, test_mul_gen_381);
  tcase_add_test(tc_core, test_mul_gen_382);
  tcase_add_test(tc_core, test_mul_gen_383);
  tcase_add_test(tc_core, test_mul_gen_384);
  tcase_add_test(tc_core, test_mul_gen_385);
  tcase_add_test(tc_core, test_mul_gen_386);
  tcase_add_test(tc_core, test_mul_gen_387);
  tcase_add_test(tc_core, test_mul_gen_388);
  tcase_add_test(tc_core, test_mul_gen_389);
  tcase_add_test(tc_core, test_mul_gen_390);
  tcase_add_test(tc_core, test_mul_gen_391);
  tcase_add_test(tc_core, test_mul_gen_392);
  tcase_add_test(tc_core, test_mul_gen_393);
  tcase_add_test(tc_core, test_mul_gen_394);
  tcase_add_test(tc_core, test_mul_gen_395);
  tcase_add_test(tc_core, test_mul_gen_396);
  tcase_add_test(tc_core, test_mul_gen_397);
  tcase_add_test(tc_core, test_mul_gen_398);
  tcase_add_test(tc_core, test_mul_gen_399);
  tcase_add_test(tc_core, test_mul_gen_400);
  tcase_add_test(tc_core, test_mul_gen_401);
  tcase_add_test(tc_core, test_mul_gen_402);
  tcase_add_test(tc_core, test_mul_gen_403);
  tcase_add_test(tc_core, test_mul_gen_404);
  tcase_add_test(tc_core, test_mul_gen_405);
  tcase_add_test(tc_core, test_mul_gen_406);
  tcase_add_test(tc_core, test_mul_gen_407);
  tcase_add_test(tc_core, test_mul_gen_408);
  tcase_add_test(tc_core, test_mul_gen_409);
  tcase_add_test(tc_core, test_mul_gen_410);
  tcase_add_test(tc_core, test_mul_gen_411);
  tcase_add_test(tc_core, test_mul_gen_412);
  tcase_add_test(tc_core, test_mul_gen_413);
  tcase_add_test(tc_core, test_mul_gen_414);
  tcase_add_test(tc_core, test_mul_gen_415);
  tcase_add_test(tc_core, test_mul_gen_416);
  tcase_add_test(tc_core, test_mul_gen_417);
  tcase_add_test(tc_core, test_mul_gen_418);
  tcase_add_test(tc_core, test_mul_gen_419);

  suite_add_tcase(mul_suite, tc_core);

  return mul_suite;
}