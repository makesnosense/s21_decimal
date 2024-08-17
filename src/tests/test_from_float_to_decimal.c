#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_float_to_decimal_NULL) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -30.7339287
  float input_float = -30.7339287;
  // -30.73393

  int s21_return_code = s21_from_float_to_decimal(input_float, NULL);

  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_INFINITY) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // INFINITY
  float input_float = INFINITY;
  // INFINITY
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_negative_INFINITY) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -INFINITY
  float input_float = -INFINITY;
  // -INFINITY
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_NAN) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -INFINITY
  float input_float = NAN;
  // -INFINITY
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_negative_NAN) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -INFINITY
  float input_float = -NAN;
  // -INFINITY
  s21_decimal expected_result = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok) {
  s21_decimal s21_result_decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -30.7339287
  float input_float = -30.7339287;
  // -30.73393

  s21_decimal expected_result = {{0x2EE571, 0x0, 0x0, 0x80050000}};

  int s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);

  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);

  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_0) {
  float input_float = 0.9503300189971924f;
  // seven significant digits: 0.9503300
  s21_decimal expected_result = {
      {0x00910244, 0x00000000, 0x00000000, 0b00000000000001110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_1) {
  float input_float = 4.0f;
  // seven significant digits: 4.0
  s21_decimal expected_result = {
      {0x00000028, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_2) {
  float input_float = -333333344.0f;
  // seven significant digits: -333333300
  s21_decimal expected_result = {
      {0x13DE4334, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_3) {
  float input_float = -0.00000000000000000000000000010000000031710769f;
  // seven significant digits: -0.0000000000000000000000000001
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_4) {
  float input_float = 7922.81640625f;
  // seven significant digits: 7922.816
  s21_decimal expected_result = {
      {0x0078E480, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_5) {
  float input_float = 0.0000009999999974752427f;
  // seven significant digits: 0.000001000000
  s21_decimal expected_result = {
      {0x000F4240, 0x00000000, 0x00000000, 0b00000000000011000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_6) {
  float input_float = 333333344.0f;
  // seven significant digits: 333333300
  s21_decimal expected_result = {
      {0x13DE4334, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_7) {
  float input_float = -300000000.0f;
  // seven significant digits: -300000000
  s21_decimal expected_result = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_8) {
  float input_float = 0.00000000000000000000000000010000000031710769f;
  // seven significant digits: 0.0000000000000000000000000001
  s21_decimal expected_result = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_9) {
  float input_float = 10000000272564224.0f;
  // seven significant digits: 10000000000000000
  s21_decimal expected_result = {
      {0x6FC10000, 0x002386F2, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_10) {
  float input_float = -555555563241472.0f;
  // seven significant digits: -555555600000000
  s21_decimal expected_result = {
      {0x5E30E400, 0x0001F946, 0x00000000, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_11) {
  float input_float = -0.10000000149011612f;
  // seven significant digits: -0.1000000
  s21_decimal expected_result = {
      {0x000F4240, 0x00000000, 0x00000000, 0b10000000000001110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_12) {
  float input_float = 79228162514264340000000000000.0f;

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_13) {
  float input_float = 0.000000999999883788405f;
  // seven significant digits: 0.0000009999999
  s21_decimal expected_result = {
      {0x0098967F, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_14) {
  float input_float = -0.0f;
  // seven significant digits: -0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_15) {
  float input_float = 1234567813922816.0f;
  // seven significant digits: 1234568000000000
  s21_decimal expected_result = {
      {0x43175000, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_16) {
  float input_float = 0.12300000339746475f;
  // seven significant digits: 0.1230000
  s21_decimal expected_result = {
      {0x0012C4B0, 0x00000000, 0x00000000, 0b00000000000001110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_17) {
  float input_float = 5.5f;
  // seven significant digits: 5.5
  s21_decimal expected_result = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_18) {
  float input_float = 0.12345679104328156f;
  // seven significant digits: 0.1234568
  s21_decimal expected_result = {
      {0x0012D688, 0x00000000, 0x00000000, 0b00000000000001110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_19) {
  float input_float = -2934834578801557500.0f;
  // seven significant digits: -2934835000000000000
  s21_decimal expected_result = {
      {0x11623000, 0x28BAA0E2, 0x00000000, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_20) {
  float input_float = -0.12300000339746475f;
  // seven significant digits: -0.1230000
  s21_decimal expected_result = {
      {0x0012C4B0, 0x00000000, 0x00000000, 0b10000000000001110000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_21) {
  float input_float = -12.0f;
  // seven significant digits: -12.0
  s21_decimal expected_result = {
      {0x00000078, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_22) {
  float input_float = 7922816357207376000.0f;
  // seven significant digits: 7922816000000000000
  s21_decimal expected_result = {
      {0xD4C80000, 0x6DF37F2C, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_23) {
  float input_float = -79228162514264340000000000000.0f;

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_24) {
  float input_float = -42353456.0f;
  // seven significant digits: -42353460
  s21_decimal expected_result = {
      {0x02864334, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_25) {
  float input_float = 555555563241472.0f;
  // seven significant digits: 555555600000000
  s21_decimal expected_result = {
      {0x5E30E400, 0x0001F946, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_26) {
  float input_float = 12345.677734375f;
  // seven significant digits: 12345.68
  s21_decimal expected_result = {
      {0x0012D688, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_27) {
  float input_float = 12.0f;
  // seven significant digits: 12.0
  s21_decimal expected_result = {
      {0x00000078, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_28) {
  float input_float = 0.00000012345671507318912f;
  // seven significant digits: 0.0000001234567
  s21_decimal expected_result = {
      {0x0012D687, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_29) {
  float input_float = -7.922816276550293f;
  // seven significant digits: -7.922816
  s21_decimal expected_result = {
      {0x0078E480, 0x00000000, 0x00000000, 0b10000000000001100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_30) {
  float input_float = 7779227900590436000000000000000.0f;

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_31) {
  float input_float = -11353455621455670000000000.0f;
  // seven significant digits: -11353460000000000000000000
  s21_decimal expected_result = {
      {0xAD500000, 0x4CC3B6DE, 0x00096430, 0b10000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_32) {
  float input_float = 7.922816276550293f;
  // seven significant digits: 7.922816
  s21_decimal expected_result = {
      {0x0078E480, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_33) {
  float input_float = 1234567142834176.0f;
  // seven significant digits: 1234567000000000
  s21_decimal expected_result = {
      {0x077C8600, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_34) {
  float input_float = 12345.6708984375f;
  // seven significant digits: 12345.67
  s21_decimal expected_result = {
      {0x0012D687, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_35) {
  float input_float = 0.0f;
  // seven significant digits: 0.0
  s21_decimal expected_result = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_36) {
  float input_float = 0.0000000001000000013351432f;
  // seven significant digits: 0.0000000001000000
  s21_decimal expected_result = {
      {0x000F4240, 0x00000000, 0x00000000, 0b00000000000100000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_37) {
  float input_float = 1.2345000505447388f;
  // seven significant digits: 1.234500
  s21_decimal expected_result = {
      {0x0012D644, 0x00000000, 0x00000000, 0b00000000000001100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_38) {
  float input_float = 7922816051279261000000000.0f;
  // seven significant digits: 7922816000000000000000000
  s21_decimal expected_result = {
      {0xC2000000, 0xB749D1C8, 0x00068DB8, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_39) {
  float input_float = 3.0f;
  // seven significant digits: 3.0
  s21_decimal expected_result = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_40) {
  float input_float =
      0.0000000000000000000000000000000000000000010005271035279194f;

  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_41) {
  float input_float = 9999999198822400.0f;
  // seven significant digits: 9999999000000000
  s21_decimal expected_result = {
      {0x34263600, 0x002386F2, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_42) {
  float input_float = 99999.9921875f;
  // seven significant digits: 99999.99
  s21_decimal expected_result = {
      {0x0098967F, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_43) {
  float input_float = 12345.0f;
  // seven significant digits: 12345.0
  s21_decimal expected_result = {
      {0x0001E23A, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_44) {
  float input_float = 7922816112394240.0f;
  // seven significant digits: 7922816000000000
  s21_decimal expected_result = {
      {0x594D0000, 0x001C25C2, 0x00000000, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_45) {
  float input_float = 333.0f;
  // seven significant digits: 333.0
  s21_decimal expected_result = {
      {0x00000D02, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_46) {
  float input_float = 36523494920032480000000.0f;
  // seven significant digits: 36523490000000000000000
  s21_decimal expected_result = {
      {0xABBD0000, 0xF13E8541, 0x000007BB, 0b00000000000000000000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_47) {
  float input_float = 0.0000001234567861274627f;
  // seven significant digits: 0.0000001234568
  s21_decimal expected_result = {
      {0x0012D688, 0x00000000, 0x00000000, 0b00000000000011010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_float_to_decimal_gen_48) {
  float input_float = 100000.0f;
  // seven significant digits: 100000.0
  s21_decimal expected_result = {
      {0x000F4240, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  s21_decimal s21_result_decimal;
  ConversionResult s21_return_code =
      s21_from_float_to_decimal(input_float, &s21_result_decimal);
  ck_assert_int_eq(s21_is_equal(s21_result_decimal, expected_result), TRUE);
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_float_to_decimal_suite() {
  Suite* from_float_to_decimal_suite = suite_create("from_float_to_decimal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_float_to_decimal_NULL);
  tcase_add_test(tc_core, test_from_float_to_decimal_INFINITY);
  tcase_add_test(tc_core, test_from_float_to_decimal_negative_INFINITY);
  tcase_add_test(tc_core, test_from_float_to_decimal_NAN);
  tcase_add_test(tc_core, test_from_float_to_decimal_negative_NAN);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok);

  tcase_add_test(tc_core, test_from_float_to_decimal_gen_0);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_1);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_2);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_3);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_4);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_5);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_6);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_7);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_8);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_9);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_10);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_11);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_12);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_13);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_14);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_15);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_16);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_17);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_18);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_19);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_20);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_21);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_22);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_23);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_24);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_25);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_26);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_27);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_28);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_29);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_30);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_31);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_32);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_33);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_34);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_35);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_36);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_37);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_38);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_39);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_40);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_41);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_42);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_43);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_44);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_45);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_46);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_47);
  tcase_add_test(tc_core, test_from_float_to_decimal_gen_48);

  suite_add_tcase(from_float_to_decimal_suite, tc_core);

  return from_float_to_decimal_suite;
}