#include "../comparison.h"
#include "../conversion.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(test_from_decimal_to_float_fail_incorrect_decimal) {
  // 1234567800000000
  s21_decimal input_decimal = {
      {0x372B8E00, 0x000462D5, 0x00000000, 0b10000000100000000000000001000001}};
  // 1234567813922816
  uint32_t expected_result = 0;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_input_dst_equal_NULL) {
  // 1234567800000000
  s21_decimal input_decimal = {
      {0x372B8E00, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, NULL);

  ck_assert_int_eq(s21_return_code, CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_negative_zero) {
  // -0.0
  s21_decimal input_decimal = {
      {0x0, 0x0, 0x0, 0b10000000000000000000000000000000}};
  // -0
  uint32_t expected_result = 0b10000000000000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_0) {
  // 1234567800000000
  s21_decimal input_decimal = {
      {0x372B8E00, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  // 1234567813922816
  uint32_t expected_result = 0b01011000100011000101101010100111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_1) {
  // -300000000
  s21_decimal input_decimal = {
      {0x11E1A300, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -300000000
  uint32_t expected_result = 0b11001101100011110000110100011000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_2) {
  // 0.000000999999951234
  s21_decimal input_decimal = {
      {0xD4A45182, 0x000000E8, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.0000009999999974752427078783512115478515625
  uint32_t expected_result = 0b00110101100001100011011110111101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_3) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -7.92281627655029296875
  uint32_t expected_result = 0b11000000111111011000011110110110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_4) {
  // 12.00
  s21_decimal input_decimal = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 12
  uint32_t expected_result = 0b01000001010000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_5) {
  // 0.123456789
  s21_decimal input_decimal = {
      {0x075BCD15, 0x00000000, 0x00000000, 0b00000000000010010000000000000000}};
  // 0.12345679104328155517578125
  uint32_t expected_result = 0b00111101111111001101011011101010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_6) {
  // -79228162514264337593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950336
  uint32_t expected_result = 0b11101111100000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_7) {
  // -0.1
  s21_decimal input_decimal = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000000010000000000000000}};
  // -0.100000001490116119384765625
  uint32_t expected_result = 0b10111101110011001100110011001101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_8) {
  // 36523494581823720394585.234509
  s21_decimal input_decimal = {
      {0xB3335C4D, 0x9E691CEC, 0x760386D0, 0b00000000000001100000000000000000}};
  // 36523494920032480133120
  uint32_t expected_result = 0b01100100111101110111111000101010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_9) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7922.81640625
  uint32_t expected_result = 0b01000101111101111001011010001000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_10) {
  // 12
  s21_decimal input_decimal = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12
  uint32_t expected_result = 0b01000001010000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_11) {
  // 1234567812345678
  s21_decimal input_decimal = {
      {0x37E7EF4E, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  // 1234567813922816
  uint32_t expected_result = 0b01011000100011000101101010100111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_12) {
  // 7922816251426433.7593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000011010000000000000000}};
  // 7922816112394240
  uint32_t expected_result = 0b01011001111000010010111000010011;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_13) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.00000000000000000000000000010000000031710768509710513471352647538147514756461109453056224083411507308483123779296875
  uint32_t expected_result = 0b00010000111111011000011110110110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_14) {
  // -555555555555555.55555
  s21_decimal input_decimal = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -555555563241472
  uint32_t expected_result = 0b11010111111111001010001100101110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_15) {
  // 0.000000123456781234
  s21_decimal input_decimal = {
      {0xBE98FBB2, 0x0000001C, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.0000001234567861274626920931041240692138671875
  uint32_t expected_result = 0b00110100000001001000111110001011;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_16) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7.92281627655029296875
  uint32_t expected_result = 0b01000000111111011000011110110110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_17) {
  // 5.5
  s21_decimal input_decimal = {
      {0x00000037, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 5.5
  uint32_t expected_result = 0b01000000101100000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_18) {
  // 12345.6781234
  s21_decimal input_decimal = {
      {0xBE98FBB2, 0x0000001C, 0x00000000, 0b00000000000001110000000000000000}};
  // 12345.677734375
  uint32_t expected_result = 0b01000110010000001110011010110110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_19) {
  // 0.000000999999912345
  s21_decimal input_decimal = {
      {0xD4A3B999, 0x000000E8, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.00000099999988378840498626232147216796875
  uint32_t expected_result = 0b00110101100001100011011110111100;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_20) {
  // 12345
  s21_decimal input_decimal = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12345
  uint32_t expected_result = 0b01000110010000001110010000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_21) {
  // 0.00000099999995
  s21_decimal input_decimal = {
      {0x05F5E0FB, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.0000009999999974752427078783512115478515625
  uint32_t expected_result = 0b00110101100001100011011110111101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_22) {
  // 1.2345
  s21_decimal input_decimal = {
      {0x00003039, 0x00000000, 0x00000000, 0b00000000000001000000000000000000}};
  // 1.23450005054473876953125
  uint32_t expected_result = 0b00111111100111100000010000011001;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_23) {
  // -333333333.44444444
  s21_decimal input_decimal = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -333333344
  uint32_t expected_result = 0b11001101100111101111001000011011;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_24) {
  // 12345.6712345
  s21_decimal input_decimal = {
      {0xBE97EE99, 0x0000001C, 0x00000000, 0b00000000000001110000000000000000}};
  // 12345.6708984375
  uint32_t expected_result = 0b01000110010000001110011010101111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_25) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -0.00000000000000000000000000010000000031710768509710513471352647538147514756461109453056224083411507308483123779296875
  uint32_t expected_result = 0b10010000111111011000011110110110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_26) {
  // 0.123
  s21_decimal input_decimal = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.123000003397464752197265625
  uint32_t expected_result = 0b00111101111110111110011101101101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_27) {
  // 0.122999999999999999
  s21_decimal input_decimal = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.123000003397464752197265625
  uint32_t expected_result = 0b00111101111110111110011101101101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_28) {
  // 0.95033
  s21_decimal input_decimal = {
      {0x00017339, 0x00000000, 0x00000000, 0b00000000000001010000000000000000}};
  // 0.9503300189971923828125
  uint32_t expected_result = 0b00111111011100110100100011010100;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_29) {
  // 333
  s21_decimal input_decimal = {
      {0x0000014D, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333
  uint32_t expected_result = 0b01000011101001101000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_30) {
  // 1234567200000000
  s21_decimal input_decimal = {
      {0x13684800, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  // 1234567142834176
  uint32_t expected_result = 0b01011000100011000101101010100010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_31) {
  // 9999999912345678
  s21_decimal input_decimal = {
      {0x6A87804E, 0x002386F2, 0x00000000, 0b00000000000000000000000000000000}};
  // 10000000272564224
  uint32_t expected_result = 0b01011010000011100001101111001010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_32) {
  // 1234567123456789
  s21_decimal input_decimal = {
      {0x0ED85315, 0x000462D5, 0x00000000, 0b00000000000000000000000000000000}};
  // 1234567142834176
  uint32_t expected_result = 0b01011000100011000101101010100010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_33) {
  // -0.123
  s21_decimal input_decimal = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -0.123000003397464752197265625
  uint32_t expected_result = 0b10111101111110111110011101101101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_34) {
  // 0.123000000000001
  s21_decimal input_decimal = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.123000003397464752197265625
  uint32_t expected_result = 0b00111101111110111110011101101101;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_35) {
  // -11353455324534534597889779
  s21_decimal input_decimal = {
      {0xFC69CEF3, 0x0BE11FCC, 0x00096430, 0b10000000000000000000000000000000}};
  // -11353455621455669759049728
  uint32_t expected_result = 0b11101001000101100100001100000001;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_36) {
  // 0
  s21_decimal input_decimal = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  uint32_t expected_result = 0b00000000000000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_37) {
  // -12
  s21_decimal input_decimal = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -12
  uint32_t expected_result = 0b11000001010000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_38) {
  // 0.0000000001
  s21_decimal input_decimal = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000010100000000000000000}};
  // 0.000000000100000001335143196001808973960578441619873046875
  uint32_t expected_result = 0b00101110110110111110011011111111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_39) {
  // 333333333.44444444
  s21_decimal input_decimal = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 333333344
  uint32_t expected_result = 0b01001101100111101111001000011011;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_40) {
  // 9999999123456789
  s21_decimal input_decimal = {
      {0x3B820315, 0x002386F2, 0x00000000, 0b00000000000000000000000000000000}};
  // 9999999198822400
  uint32_t expected_result = 0b01011010000011100001101111001001;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_41) {
  // 99999.9912345
  s21_decimal input_decimal = {
      {0xD4A3B999, 0x000000E8, 0x00000000, 0b00000000000001110000000000000000}};
  // 99999.9921875
  uint32_t expected_result = 0b01000111110000110100111111111111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_42) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7922816051279260559605760
  uint32_t expected_result = 0b01101000110100011011011100010111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_43) {
  // -42353455
  s21_decimal input_decimal = {
      {0x0286432F, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -42353456
  uint32_t expected_result = 0b11001100001000011001000011001100;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_44) {
  // 4
  s21_decimal input_decimal = {
      {0x00000004, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 4
  uint32_t expected_result = 0b01000000100000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_45) {
  // 79228162514264337593543950335
  s21_decimal input_decimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950336
  uint32_t expected_result = 0b01101111100000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_46) {
  // 0.00000099999991
  s21_decimal input_decimal = {
      {0x05F5E0F7, 0x00000000, 0x00000000, 0b00000000000011100000000000000000}};
  // 0.00000099999988378840498626232147216796875
  uint32_t expected_result = 0b00110101100001100011011110111100;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_47) {
  // 0.000000123456712345
  s21_decimal input_decimal = {
      {0xBE97EE99, 0x0000001C, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.000000123456715073189116083085536956787109375
  uint32_t expected_result = 0b00110100000001001000111110000110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_48) {
  // 7922816251426433759.950335
  s21_decimal input_decimal = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7922816357207375872
  uint32_t expected_result = 0b01011110110110111110011011111111;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_49) {
  // -2934834509834059832.45
  s21_decimal input_decimal = {
      {0x39AE160D, 0xE8E6ABBA, 0x0000000F, 0b10000000000000100000000000000000}};
  // -2934834578801557504
  uint32_t expected_result = 0b11011110001000101110101010000010;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_50) {
  // 99999.9991234
  s21_decimal input_decimal = {
      {0xD4A4EDC2, 0x000000E8, 0x00000000, 0b00000000000001110000000000000000}};
  // 100000
  uint32_t expected_result = 0b01000111110000110101000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_51) {
  // 555555555555555.5555555555
  s21_decimal input_decimal = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 555555563241472
  uint32_t expected_result = 0b01010111111111001010001100101110;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

START_TEST(test_from_decimal_to_float_gen_52) {
  // 3.0
  s21_decimal input_decimal = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 3
  uint32_t expected_result = 0b01000000010000000000000000000000;

  float s21_result_float;
  ConversionResult s21_return_code =
      s21_from_decimal_to_float(input_decimal, &s21_result_float);

  ck_assert_mem_eq(&s21_result_float, &expected_result, sizeof(float));
  ck_assert_int_eq(s21_return_code, OK);
}
END_TEST

Suite* make_from_decimal_to_float_suite() {
  Suite* from_decimal_to_float_suite = suite_create("from_decimal_to_float");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_float_fail_incorrect_decimal);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_input_dst_equal_NULL);
  tcase_add_test(tc_core, test_from_decimal_to_float_negative_zero);

  tcase_add_test(tc_core, test_from_decimal_to_float_gen_0);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_1);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_2);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_3);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_4);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_5);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_6);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_7);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_8);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_9);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_10);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_11);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_12);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_13);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_14);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_15);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_16);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_17);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_18);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_19);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_20);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_21);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_22);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_23);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_24);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_25);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_26);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_27);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_28);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_29);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_30);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_31);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_32);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_33);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_34);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_35);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_36);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_37);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_38);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_39);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_40);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_41);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_42);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_43);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_44);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_45);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_46);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_47);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_48);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_49);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_50);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_51);
  tcase_add_test(tc_core, test_from_decimal_to_float_gen_52);
  suite_add_tcase(from_decimal_to_float_suite, tc_core);

  return from_decimal_to_float_suite;
}