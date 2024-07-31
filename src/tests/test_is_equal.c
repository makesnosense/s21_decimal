#include "../comparison.h"
#include "run_tests.h"

START_TEST(comparison_eq_test) {
  s21_decimal input_decimal_1 = {{0x123U, 0x123U, 0x123U,
                                 0b00000000000001010000000000000000}};

  s21_decimal input_decimal_2 = {{0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000}};

  ComparisonResult result_1 = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(result_1, FALSE);

  // ck_assert_int_eq(s21_is_equal(input_decimal_1, input_decimal_2), 0);

  s21_decimal input_decimal_3 = {{0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000}};

  s21_decimal input_decimal_4 = {{0x123U, 0x123U, 0x123U,
                                 0b00000000000011100000000000000000}};

  ck_assert_int_eq(s21_is_equal(input_decimal_3, input_decimal_4), 0);

  // 999999999999 scale 0
  s21_decimal input_decimal_5 = {{0xD4A50FFF, 0xE8, 0x0,
                                 0b00000000000000000000000000000000}};
  // 999999999999000 scale 3
  s21_decimal input_decimal_6 = {{0xA4C67C18, 0x38D7E, 0x0,
                                 0b00000000000000110000000000000000}};

  ck_assert_int_eq(s21_is_equal(input_decimal_5, input_decimal_6), 1);

  // 2*(10**28) scale 28
  s21_decimal input_decimal_7 = {{0x20000000, 0x7C4A04C2, 0x409F9CBC,
                                 0b00000000000111000000000000000000}};

  // 2 scale 0
  s21_decimal input_decimal_8 = {{0x2, 0x0, 0x0,
                                 0b00000000000000000000000000000000}};

  ck_assert_int_eq(s21_is_equal(input_decimal_7, input_decimal_8), 1);

  s21_decimal input_decimal_9 = {{0x124U, 0x123U, 0x123U,
                                 0b00000000000000101000000000000000}};

  s21_decimal input_decimal_10 = {{0x124U, 0x123U, 0x123U,
                                  0b00000000000000101000000000000000}};

  ck_assert_int_eq(s21_is_equal(input_decimal_9, input_decimal_10), TRUE);

  // 0
  s21_decimal input_decimal_11 = {{0x0U, 0x0U, 0x0U,
                                  0b00000000000000101000000000000000}};
  // -0
  s21_decimal input_decimal_12 = {{0x0U, 0x0U, 0x0U,
                                  0b10000000000110110000000000000000}};

  ck_assert_int_eq(s21_is_equal(input_decimal_11, input_decimal_12), 1);
}
END_TEST

START_TEST(test_is_equal_gen_0) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_1) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_2) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_3) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_4) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_5) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_6) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_7) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_8) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_9) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_10) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_11) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_12) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_13) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_14) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_15) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_16) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_17) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_18) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_19) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_20) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_21) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_22) {
  // 79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_23) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_24) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_25) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_26) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_27) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_28) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_29) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_30) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_31) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_32) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_33) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_34) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_35) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_36) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_37) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_38) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_39) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_40) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_41) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_42) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_43) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_44) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_45) {
  // 7922816251426433759354395.5
  s21_decimal input_decimal_1 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_46) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_47) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_48) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_49) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_50) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_51) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_52) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_53) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_54) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_55) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_56) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_57) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_58) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_59) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_60) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_61) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_62) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_63) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_64) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_65) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_66) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_67) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_68) {
  // 7922816251426433759.950335
  s21_decimal input_decimal_1 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_69) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_70) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_71) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_72) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_73) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_74) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_75) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_76) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_77) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_78) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_79) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_80) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_81) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_82) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_83) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_84) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_85) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_86) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_87) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_88) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_89) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_90) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_91) {
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_92) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_93) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_94) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_95) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_96) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_97) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_98) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_99) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_100) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_101) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_102) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_103) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_104) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_105) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_106) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_107) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_108) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_109) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_110) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_111) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_112) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_113) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_114) {
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_115) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_116) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_117) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_118) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_119) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_120) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_121) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_122) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_123) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_124) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_125) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_126) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_127) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_128) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_129) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_130) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_131) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_132) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_133) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_134) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_135) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_136) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_137) {
  // 0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_138) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_139) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_140) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_141) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_142) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_143) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_144) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_145) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_146) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_147) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_148) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_149) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_150) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_151) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_152) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_153) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_154) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_155) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_156) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_157) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_158) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_159) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_160) {
  // 0.123000000000001
  s21_decimal input_decimal_1 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_161) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_162) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_163) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_164) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_165) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_166) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_167) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_168) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_169) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_170) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_171) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_172) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_173) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_174) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_175) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_176) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_177) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_178) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_179) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_180) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_181) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_182) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_183) {
  // 0.122999999999999999
  s21_decimal input_decimal_1 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_184) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_185) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_186) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_187) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_188) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_189) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_190) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_191) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_192) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_193) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_194) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_195) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_196) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_197) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_198) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_199) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_200) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_201) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_202) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_203) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_204) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_205) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_206) {
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_207) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_208) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_209) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_210) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_211) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_212) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_213) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_214) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_215) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_216) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_217) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_218) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_219) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_220) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_221) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_222) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_223) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_224) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_225) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_226) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_227) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_228) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_229) {
  // 0.1
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_230) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_231) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_232) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_233) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_234) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_235) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_236) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_237) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_238) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_239) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_240) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_241) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_242) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_243) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_244) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_245) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_246) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_247) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_248) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_249) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, TRUE);
}
END_TEST

START_TEST(test_is_equal_gen_250) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_251) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_252) {
  // 0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_253) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_254) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_255) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_256) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_257) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_258) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_259) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_260) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_261) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_262) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_263) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_264) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_265) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_266) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_267) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_268) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_269) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_270) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_271) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_272) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_273) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_274) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_275) {
  // 333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_276) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_277) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_278) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_279) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_280) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_281) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_282) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_283) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_284) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_285) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_286) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_287) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_288) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, TRUE);
}
END_TEST

START_TEST(test_is_equal_gen_289) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_290) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_291) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_292) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_293) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_294) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_295) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_296) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_297) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_298) {
  // 12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_299) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_300) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_301) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_302) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_303) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_304) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_305) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_306) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_307) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_308) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_309) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_310) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_311) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, TRUE);
}
END_TEST

START_TEST(test_is_equal_gen_312) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_313) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_314) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_315) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_316) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_317) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_318) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_319) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_320) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_321) {
  // 12.00
  s21_decimal input_decimal_1 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_322) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_323) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_324) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_325) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_326) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_327) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_328) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_329) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_330) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_331) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_332) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_333) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_334) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_335) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_336) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_337) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_338) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_339) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_340) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_341) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_342) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_343) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_344) {
  // 555555555555555.5555555555
  s21_decimal input_decimal_1 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_345) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_346) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_347) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_348) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_349) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_350) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_351) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_352) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_353) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_354) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_355) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_356) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_357) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_358) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_359) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_360) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_361) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_362) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_363) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_364) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_365) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_366) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_367) {
  // -79228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_368) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_369) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_370) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_371) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_372) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_373) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_374) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_375) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_376) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_377) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_378) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_379) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_380) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_381) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_382) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_383) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_384) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_385) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_386) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_387) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_388) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_389) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_390) {
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_1 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_391) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_392) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_393) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_394) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_395) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_396) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_397) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_398) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_399) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_400) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_401) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_402) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_403) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_404) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_405) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_406) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_407) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_408) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_409) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_410) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_411) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_412) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_413) {
  // 3.0
  s21_decimal input_decimal_1 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_414) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_415) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_416) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_417) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_418) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_419) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_420) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_421) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_422) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_423) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_424) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_425) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_426) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_427) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_428) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_429) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_430) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_431) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_432) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_433) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_434) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_435) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_436) {
  // -0.123
  s21_decimal input_decimal_1 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_437) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_438) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_439) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_440) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_441) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_442) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_443) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_444) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_445) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_446) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_447) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_448) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_449) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_450) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_451) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_452) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_453) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_454) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_455) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_456) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_457) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_458) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_459) {
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_1 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_460) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_461) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_462) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_463) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_464) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_465) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_466) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_467) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_468) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_469) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_470) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, TRUE);
}
END_TEST

START_TEST(test_is_equal_gen_471) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_472) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_473) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_474) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_475) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_476) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_477) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_478) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_479) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_480) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_481) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_482) {
  // -0
  s21_decimal input_decimal_1 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_483) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_484) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_485) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_486) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_487) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_488) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_489) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_490) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_491) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_492) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_493) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_494) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_495) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_496) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_497) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_498) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_499) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_500) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_501) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_502) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_503) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_504) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_505) {
  // -333333333.44444444
  s21_decimal input_decimal_1 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_506) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_507) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_508) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_509) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_510) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_511) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_512) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_513) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_514) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_515) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_516) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_517) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_518) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_519) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_520) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_521) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_522) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_523) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_524) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_525) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_526) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_527) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_528) {
  // -12
  s21_decimal input_decimal_1 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};
  // -555555555555555.55555
  s21_decimal input_decimal_2 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_529) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_530) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922816251426433759354395.5
  s21_decimal input_decimal_2 = {
      {0x9DB22D13, 0x4BC6A7EF, 0x00418937, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_531) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922816251426433759.950335
  s21_decimal input_decimal_2 = {
      {0x2967B5FF, 0xBAC710CB, 0x00068DB8, 0b00000000000001100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_532) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7922.8162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000110010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_533) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_534) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b00000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_535) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.123000000000001
  s21_decimal input_decimal_2 = {
      {0x2B4EB001, 0x00006FDE, 0x00000000, 0b00000000000011110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_536) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.122999999999999999
  s21_decimal input_decimal_2 = {
      {0x2B5F7FFF, 0x01B4FBD9, 0x00000000, 0b00000000000100100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_537) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_538) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0.1
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_539) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_540) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b00000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_541) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b00000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_542) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 12.00
  s21_decimal input_decimal_2 = {
      {0x000004B0, 0x00000000, 0x00000000, 0b00000000000000100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_543) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 555555555555555.5555555555
  s21_decimal input_decimal_2 = {
      {0x458E38E3, 0x45278EEF, 0x0004986F, 0b00000000000010100000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_544) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -79228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_545) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -7.9228162514264337593543950335
  s21_decimal input_decimal_2 = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_546) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // 3.0
  s21_decimal input_decimal_2 = {
      {0x0000001E, 0x00000000, 0x00000000, 0b00000000000000010000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_547) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -0.123
  s21_decimal input_decimal_2 = {
      {0x0000007B, 0x00000000, 0x00000000, 0b10000000000000110000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_548) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -0.0000000000000000000000000001
  s21_decimal input_decimal_2 = {
      {0x00000001, 0x00000000, 0x00000000, 0b10000000000111000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_549) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -0
  s21_decimal input_decimal_2 = {
      {0x00000000, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_550) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -333333333.44444444
  s21_decimal input_decimal_2 = {
      {0x752CE01C, 0x00766C7D, 0x00000000, 0b10000000000010000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

START_TEST(test_is_equal_gen_551) {
  // -555555555555555.55555
  s21_decimal input_decimal_1 = {
      {0x8C5E38E3, 0x02FCFB6E, 0x00000003, 0b10000000000001010000000000000000}};
  // -12
  s21_decimal input_decimal_2 = {
      {0x0000000C, 0x00000000, 0x00000000, 0b10000000000000000000000000000000}};

  ComparisonResult s21_result = s21_is_equal(input_decimal_1, input_decimal_2);
  ck_assert_int_eq(s21_result, FALSE);
}
END_TEST

Suite* make_is_equal_suite() {
  Suite* is_equal_suite = suite_create("is_equal");
  TCase* tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, comparison_eq_test);

  tcase_add_test(tc_core, test_is_equal_gen_0);
  tcase_add_test(tc_core, test_is_equal_gen_1);
  tcase_add_test(tc_core, test_is_equal_gen_2);
  tcase_add_test(tc_core, test_is_equal_gen_3);
  tcase_add_test(tc_core, test_is_equal_gen_4);
  tcase_add_test(tc_core, test_is_equal_gen_5);
  tcase_add_test(tc_core, test_is_equal_gen_6);
  tcase_add_test(tc_core, test_is_equal_gen_7);
  tcase_add_test(tc_core, test_is_equal_gen_8);
  tcase_add_test(tc_core, test_is_equal_gen_9);
  tcase_add_test(tc_core, test_is_equal_gen_10);
  tcase_add_test(tc_core, test_is_equal_gen_11);
  tcase_add_test(tc_core, test_is_equal_gen_12);
  tcase_add_test(tc_core, test_is_equal_gen_13);
  tcase_add_test(tc_core, test_is_equal_gen_14);
  tcase_add_test(tc_core, test_is_equal_gen_15);
  tcase_add_test(tc_core, test_is_equal_gen_16);
  tcase_add_test(tc_core, test_is_equal_gen_17);
  tcase_add_test(tc_core, test_is_equal_gen_18);
  tcase_add_test(tc_core, test_is_equal_gen_19);
  tcase_add_test(tc_core, test_is_equal_gen_20);
  tcase_add_test(tc_core, test_is_equal_gen_21);
  tcase_add_test(tc_core, test_is_equal_gen_22);
  tcase_add_test(tc_core, test_is_equal_gen_23);
  tcase_add_test(tc_core, test_is_equal_gen_24);
  tcase_add_test(tc_core, test_is_equal_gen_25);
  tcase_add_test(tc_core, test_is_equal_gen_26);
  tcase_add_test(tc_core, test_is_equal_gen_27);
  tcase_add_test(tc_core, test_is_equal_gen_28);
  tcase_add_test(tc_core, test_is_equal_gen_29);
  tcase_add_test(tc_core, test_is_equal_gen_30);
  tcase_add_test(tc_core, test_is_equal_gen_31);
  tcase_add_test(tc_core, test_is_equal_gen_32);
  tcase_add_test(tc_core, test_is_equal_gen_33);
  tcase_add_test(tc_core, test_is_equal_gen_34);
  tcase_add_test(tc_core, test_is_equal_gen_35);
  tcase_add_test(tc_core, test_is_equal_gen_36);
  tcase_add_test(tc_core, test_is_equal_gen_37);
  tcase_add_test(tc_core, test_is_equal_gen_38);
  tcase_add_test(tc_core, test_is_equal_gen_39);
  tcase_add_test(tc_core, test_is_equal_gen_40);
  tcase_add_test(tc_core, test_is_equal_gen_41);
  tcase_add_test(tc_core, test_is_equal_gen_42);
  tcase_add_test(tc_core, test_is_equal_gen_43);
  tcase_add_test(tc_core, test_is_equal_gen_44);
  tcase_add_test(tc_core, test_is_equal_gen_45);
  tcase_add_test(tc_core, test_is_equal_gen_46);
  tcase_add_test(tc_core, test_is_equal_gen_47);
  tcase_add_test(tc_core, test_is_equal_gen_48);
  tcase_add_test(tc_core, test_is_equal_gen_49);
  tcase_add_test(tc_core, test_is_equal_gen_50);
  tcase_add_test(tc_core, test_is_equal_gen_51);
  tcase_add_test(tc_core, test_is_equal_gen_52);
  tcase_add_test(tc_core, test_is_equal_gen_53);
  tcase_add_test(tc_core, test_is_equal_gen_54);
  tcase_add_test(tc_core, test_is_equal_gen_55);
  tcase_add_test(tc_core, test_is_equal_gen_56);
  tcase_add_test(tc_core, test_is_equal_gen_57);
  tcase_add_test(tc_core, test_is_equal_gen_58);
  tcase_add_test(tc_core, test_is_equal_gen_59);
  tcase_add_test(tc_core, test_is_equal_gen_60);
  tcase_add_test(tc_core, test_is_equal_gen_61);
  tcase_add_test(tc_core, test_is_equal_gen_62);
  tcase_add_test(tc_core, test_is_equal_gen_63);
  tcase_add_test(tc_core, test_is_equal_gen_64);
  tcase_add_test(tc_core, test_is_equal_gen_65);
  tcase_add_test(tc_core, test_is_equal_gen_66);
  tcase_add_test(tc_core, test_is_equal_gen_67);
  tcase_add_test(tc_core, test_is_equal_gen_68);
  tcase_add_test(tc_core, test_is_equal_gen_69);
  tcase_add_test(tc_core, test_is_equal_gen_70);
  tcase_add_test(tc_core, test_is_equal_gen_71);
  tcase_add_test(tc_core, test_is_equal_gen_72);
  tcase_add_test(tc_core, test_is_equal_gen_73);
  tcase_add_test(tc_core, test_is_equal_gen_74);
  tcase_add_test(tc_core, test_is_equal_gen_75);
  tcase_add_test(tc_core, test_is_equal_gen_76);
  tcase_add_test(tc_core, test_is_equal_gen_77);
  tcase_add_test(tc_core, test_is_equal_gen_78);
  tcase_add_test(tc_core, test_is_equal_gen_79);
  tcase_add_test(tc_core, test_is_equal_gen_80);
  tcase_add_test(tc_core, test_is_equal_gen_81);
  tcase_add_test(tc_core, test_is_equal_gen_82);
  tcase_add_test(tc_core, test_is_equal_gen_83);
  tcase_add_test(tc_core, test_is_equal_gen_84);
  tcase_add_test(tc_core, test_is_equal_gen_85);
  tcase_add_test(tc_core, test_is_equal_gen_86);
  tcase_add_test(tc_core, test_is_equal_gen_87);
  tcase_add_test(tc_core, test_is_equal_gen_88);
  tcase_add_test(tc_core, test_is_equal_gen_89);
  tcase_add_test(tc_core, test_is_equal_gen_90);
  tcase_add_test(tc_core, test_is_equal_gen_91);
  tcase_add_test(tc_core, test_is_equal_gen_92);
  tcase_add_test(tc_core, test_is_equal_gen_93);
  tcase_add_test(tc_core, test_is_equal_gen_94);
  tcase_add_test(tc_core, test_is_equal_gen_95);
  tcase_add_test(tc_core, test_is_equal_gen_96);
  tcase_add_test(tc_core, test_is_equal_gen_97);
  tcase_add_test(tc_core, test_is_equal_gen_98);
  tcase_add_test(tc_core, test_is_equal_gen_99);
  tcase_add_test(tc_core, test_is_equal_gen_100);
  tcase_add_test(tc_core, test_is_equal_gen_101);
  tcase_add_test(tc_core, test_is_equal_gen_102);
  tcase_add_test(tc_core, test_is_equal_gen_103);
  tcase_add_test(tc_core, test_is_equal_gen_104);
  tcase_add_test(tc_core, test_is_equal_gen_105);
  tcase_add_test(tc_core, test_is_equal_gen_106);
  tcase_add_test(tc_core, test_is_equal_gen_107);
  tcase_add_test(tc_core, test_is_equal_gen_108);
  tcase_add_test(tc_core, test_is_equal_gen_109);
  tcase_add_test(tc_core, test_is_equal_gen_110);
  tcase_add_test(tc_core, test_is_equal_gen_111);
  tcase_add_test(tc_core, test_is_equal_gen_112);
  tcase_add_test(tc_core, test_is_equal_gen_113);
  tcase_add_test(tc_core, test_is_equal_gen_114);
  tcase_add_test(tc_core, test_is_equal_gen_115);
  tcase_add_test(tc_core, test_is_equal_gen_116);
  tcase_add_test(tc_core, test_is_equal_gen_117);
  tcase_add_test(tc_core, test_is_equal_gen_118);
  tcase_add_test(tc_core, test_is_equal_gen_119);
  tcase_add_test(tc_core, test_is_equal_gen_120);
  tcase_add_test(tc_core, test_is_equal_gen_121);
  tcase_add_test(tc_core, test_is_equal_gen_122);
  tcase_add_test(tc_core, test_is_equal_gen_123);
  tcase_add_test(tc_core, test_is_equal_gen_124);
  tcase_add_test(tc_core, test_is_equal_gen_125);
  tcase_add_test(tc_core, test_is_equal_gen_126);
  tcase_add_test(tc_core, test_is_equal_gen_127);
  tcase_add_test(tc_core, test_is_equal_gen_128);
  tcase_add_test(tc_core, test_is_equal_gen_129);
  tcase_add_test(tc_core, test_is_equal_gen_130);
  tcase_add_test(tc_core, test_is_equal_gen_131);
  tcase_add_test(tc_core, test_is_equal_gen_132);
  tcase_add_test(tc_core, test_is_equal_gen_133);
  tcase_add_test(tc_core, test_is_equal_gen_134);
  tcase_add_test(tc_core, test_is_equal_gen_135);
  tcase_add_test(tc_core, test_is_equal_gen_136);
  tcase_add_test(tc_core, test_is_equal_gen_137);
  tcase_add_test(tc_core, test_is_equal_gen_138);
  tcase_add_test(tc_core, test_is_equal_gen_139);
  tcase_add_test(tc_core, test_is_equal_gen_140);
  tcase_add_test(tc_core, test_is_equal_gen_141);
  tcase_add_test(tc_core, test_is_equal_gen_142);
  tcase_add_test(tc_core, test_is_equal_gen_143);
  tcase_add_test(tc_core, test_is_equal_gen_144);
  tcase_add_test(tc_core, test_is_equal_gen_145);
  tcase_add_test(tc_core, test_is_equal_gen_146);
  tcase_add_test(tc_core, test_is_equal_gen_147);
  tcase_add_test(tc_core, test_is_equal_gen_148);
  tcase_add_test(tc_core, test_is_equal_gen_149);
  tcase_add_test(tc_core, test_is_equal_gen_150);
  tcase_add_test(tc_core, test_is_equal_gen_151);
  tcase_add_test(tc_core, test_is_equal_gen_152);
  tcase_add_test(tc_core, test_is_equal_gen_153);
  tcase_add_test(tc_core, test_is_equal_gen_154);
  tcase_add_test(tc_core, test_is_equal_gen_155);
  tcase_add_test(tc_core, test_is_equal_gen_156);
  tcase_add_test(tc_core, test_is_equal_gen_157);
  tcase_add_test(tc_core, test_is_equal_gen_158);
  tcase_add_test(tc_core, test_is_equal_gen_159);
  tcase_add_test(tc_core, test_is_equal_gen_160);
  tcase_add_test(tc_core, test_is_equal_gen_161);
  tcase_add_test(tc_core, test_is_equal_gen_162);
  tcase_add_test(tc_core, test_is_equal_gen_163);
  tcase_add_test(tc_core, test_is_equal_gen_164);
  tcase_add_test(tc_core, test_is_equal_gen_165);
  tcase_add_test(tc_core, test_is_equal_gen_166);
  tcase_add_test(tc_core, test_is_equal_gen_167);
  tcase_add_test(tc_core, test_is_equal_gen_168);
  tcase_add_test(tc_core, test_is_equal_gen_169);
  tcase_add_test(tc_core, test_is_equal_gen_170);
  tcase_add_test(tc_core, test_is_equal_gen_171);
  tcase_add_test(tc_core, test_is_equal_gen_172);
  tcase_add_test(tc_core, test_is_equal_gen_173);
  tcase_add_test(tc_core, test_is_equal_gen_174);
  tcase_add_test(tc_core, test_is_equal_gen_175);
  tcase_add_test(tc_core, test_is_equal_gen_176);
  tcase_add_test(tc_core, test_is_equal_gen_177);
  tcase_add_test(tc_core, test_is_equal_gen_178);
  tcase_add_test(tc_core, test_is_equal_gen_179);
  tcase_add_test(tc_core, test_is_equal_gen_180);
  tcase_add_test(tc_core, test_is_equal_gen_181);
  tcase_add_test(tc_core, test_is_equal_gen_182);
  tcase_add_test(tc_core, test_is_equal_gen_183);
  tcase_add_test(tc_core, test_is_equal_gen_184);
  tcase_add_test(tc_core, test_is_equal_gen_185);
  tcase_add_test(tc_core, test_is_equal_gen_186);
  tcase_add_test(tc_core, test_is_equal_gen_187);
  tcase_add_test(tc_core, test_is_equal_gen_188);
  tcase_add_test(tc_core, test_is_equal_gen_189);
  tcase_add_test(tc_core, test_is_equal_gen_190);
  tcase_add_test(tc_core, test_is_equal_gen_191);
  tcase_add_test(tc_core, test_is_equal_gen_192);
  tcase_add_test(tc_core, test_is_equal_gen_193);
  tcase_add_test(tc_core, test_is_equal_gen_194);
  tcase_add_test(tc_core, test_is_equal_gen_195);
  tcase_add_test(tc_core, test_is_equal_gen_196);
  tcase_add_test(tc_core, test_is_equal_gen_197);
  tcase_add_test(tc_core, test_is_equal_gen_198);
  tcase_add_test(tc_core, test_is_equal_gen_199);
  tcase_add_test(tc_core, test_is_equal_gen_200);
  tcase_add_test(tc_core, test_is_equal_gen_201);
  tcase_add_test(tc_core, test_is_equal_gen_202);
  tcase_add_test(tc_core, test_is_equal_gen_203);
  tcase_add_test(tc_core, test_is_equal_gen_204);
  tcase_add_test(tc_core, test_is_equal_gen_205);
  tcase_add_test(tc_core, test_is_equal_gen_206);
  tcase_add_test(tc_core, test_is_equal_gen_207);
  tcase_add_test(tc_core, test_is_equal_gen_208);
  tcase_add_test(tc_core, test_is_equal_gen_209);
  tcase_add_test(tc_core, test_is_equal_gen_210);
  tcase_add_test(tc_core, test_is_equal_gen_211);
  tcase_add_test(tc_core, test_is_equal_gen_212);
  tcase_add_test(tc_core, test_is_equal_gen_213);
  tcase_add_test(tc_core, test_is_equal_gen_214);
  tcase_add_test(tc_core, test_is_equal_gen_215);
  tcase_add_test(tc_core, test_is_equal_gen_216);
  tcase_add_test(tc_core, test_is_equal_gen_217);
  tcase_add_test(tc_core, test_is_equal_gen_218);
  tcase_add_test(tc_core, test_is_equal_gen_219);
  tcase_add_test(tc_core, test_is_equal_gen_220);
  tcase_add_test(tc_core, test_is_equal_gen_221);
  tcase_add_test(tc_core, test_is_equal_gen_222);
  tcase_add_test(tc_core, test_is_equal_gen_223);
  tcase_add_test(tc_core, test_is_equal_gen_224);
  tcase_add_test(tc_core, test_is_equal_gen_225);
  tcase_add_test(tc_core, test_is_equal_gen_226);
  tcase_add_test(tc_core, test_is_equal_gen_227);
  tcase_add_test(tc_core, test_is_equal_gen_228);
  tcase_add_test(tc_core, test_is_equal_gen_229);
  tcase_add_test(tc_core, test_is_equal_gen_230);
  tcase_add_test(tc_core, test_is_equal_gen_231);
  tcase_add_test(tc_core, test_is_equal_gen_232);
  tcase_add_test(tc_core, test_is_equal_gen_233);
  tcase_add_test(tc_core, test_is_equal_gen_234);
  tcase_add_test(tc_core, test_is_equal_gen_235);
  tcase_add_test(tc_core, test_is_equal_gen_236);
  tcase_add_test(tc_core, test_is_equal_gen_237);
  tcase_add_test(tc_core, test_is_equal_gen_238);
  tcase_add_test(tc_core, test_is_equal_gen_239);
  tcase_add_test(tc_core, test_is_equal_gen_240);
  tcase_add_test(tc_core, test_is_equal_gen_241);
  tcase_add_test(tc_core, test_is_equal_gen_242);
  tcase_add_test(tc_core, test_is_equal_gen_243);
  tcase_add_test(tc_core, test_is_equal_gen_244);
  tcase_add_test(tc_core, test_is_equal_gen_245);
  tcase_add_test(tc_core, test_is_equal_gen_246);
  tcase_add_test(tc_core, test_is_equal_gen_247);
  tcase_add_test(tc_core, test_is_equal_gen_248);
  tcase_add_test(tc_core, test_is_equal_gen_249);
  tcase_add_test(tc_core, test_is_equal_gen_250);
  tcase_add_test(tc_core, test_is_equal_gen_251);
  tcase_add_test(tc_core, test_is_equal_gen_252);
  tcase_add_test(tc_core, test_is_equal_gen_253);
  tcase_add_test(tc_core, test_is_equal_gen_254);
  tcase_add_test(tc_core, test_is_equal_gen_255);
  tcase_add_test(tc_core, test_is_equal_gen_256);
  tcase_add_test(tc_core, test_is_equal_gen_257);
  tcase_add_test(tc_core, test_is_equal_gen_258);
  tcase_add_test(tc_core, test_is_equal_gen_259);
  tcase_add_test(tc_core, test_is_equal_gen_260);
  tcase_add_test(tc_core, test_is_equal_gen_261);
  tcase_add_test(tc_core, test_is_equal_gen_262);
  tcase_add_test(tc_core, test_is_equal_gen_263);
  tcase_add_test(tc_core, test_is_equal_gen_264);
  tcase_add_test(tc_core, test_is_equal_gen_265);
  tcase_add_test(tc_core, test_is_equal_gen_266);
  tcase_add_test(tc_core, test_is_equal_gen_267);
  tcase_add_test(tc_core, test_is_equal_gen_268);
  tcase_add_test(tc_core, test_is_equal_gen_269);
  tcase_add_test(tc_core, test_is_equal_gen_270);
  tcase_add_test(tc_core, test_is_equal_gen_271);
  tcase_add_test(tc_core, test_is_equal_gen_272);
  tcase_add_test(tc_core, test_is_equal_gen_273);
  tcase_add_test(tc_core, test_is_equal_gen_274);
  tcase_add_test(tc_core, test_is_equal_gen_275);
  tcase_add_test(tc_core, test_is_equal_gen_276);
  tcase_add_test(tc_core, test_is_equal_gen_277);
  tcase_add_test(tc_core, test_is_equal_gen_278);
  tcase_add_test(tc_core, test_is_equal_gen_279);
  tcase_add_test(tc_core, test_is_equal_gen_280);
  tcase_add_test(tc_core, test_is_equal_gen_281);
  tcase_add_test(tc_core, test_is_equal_gen_282);
  tcase_add_test(tc_core, test_is_equal_gen_283);
  tcase_add_test(tc_core, test_is_equal_gen_284);
  tcase_add_test(tc_core, test_is_equal_gen_285);
  tcase_add_test(tc_core, test_is_equal_gen_286);
  tcase_add_test(tc_core, test_is_equal_gen_287);
  tcase_add_test(tc_core, test_is_equal_gen_288);
  tcase_add_test(tc_core, test_is_equal_gen_289);
  tcase_add_test(tc_core, test_is_equal_gen_290);
  tcase_add_test(tc_core, test_is_equal_gen_291);
  tcase_add_test(tc_core, test_is_equal_gen_292);
  tcase_add_test(tc_core, test_is_equal_gen_293);
  tcase_add_test(tc_core, test_is_equal_gen_294);
  tcase_add_test(tc_core, test_is_equal_gen_295);
  tcase_add_test(tc_core, test_is_equal_gen_296);
  tcase_add_test(tc_core, test_is_equal_gen_297);
  tcase_add_test(tc_core, test_is_equal_gen_298);
  tcase_add_test(tc_core, test_is_equal_gen_299);
  tcase_add_test(tc_core, test_is_equal_gen_300);
  tcase_add_test(tc_core, test_is_equal_gen_301);
  tcase_add_test(tc_core, test_is_equal_gen_302);
  tcase_add_test(tc_core, test_is_equal_gen_303);
  tcase_add_test(tc_core, test_is_equal_gen_304);
  tcase_add_test(tc_core, test_is_equal_gen_305);
  tcase_add_test(tc_core, test_is_equal_gen_306);
  tcase_add_test(tc_core, test_is_equal_gen_307);
  tcase_add_test(tc_core, test_is_equal_gen_308);
  tcase_add_test(tc_core, test_is_equal_gen_309);
  tcase_add_test(tc_core, test_is_equal_gen_310);
  tcase_add_test(tc_core, test_is_equal_gen_311);
  tcase_add_test(tc_core, test_is_equal_gen_312);
  tcase_add_test(tc_core, test_is_equal_gen_313);
  tcase_add_test(tc_core, test_is_equal_gen_314);
  tcase_add_test(tc_core, test_is_equal_gen_315);
  tcase_add_test(tc_core, test_is_equal_gen_316);
  tcase_add_test(tc_core, test_is_equal_gen_317);
  tcase_add_test(tc_core, test_is_equal_gen_318);
  tcase_add_test(tc_core, test_is_equal_gen_319);
  tcase_add_test(tc_core, test_is_equal_gen_320);
  tcase_add_test(tc_core, test_is_equal_gen_321);
  tcase_add_test(tc_core, test_is_equal_gen_322);
  tcase_add_test(tc_core, test_is_equal_gen_323);
  tcase_add_test(tc_core, test_is_equal_gen_324);
  tcase_add_test(tc_core, test_is_equal_gen_325);
  tcase_add_test(tc_core, test_is_equal_gen_326);
  tcase_add_test(tc_core, test_is_equal_gen_327);
  tcase_add_test(tc_core, test_is_equal_gen_328);
  tcase_add_test(tc_core, test_is_equal_gen_329);
  tcase_add_test(tc_core, test_is_equal_gen_330);
  tcase_add_test(tc_core, test_is_equal_gen_331);
  tcase_add_test(tc_core, test_is_equal_gen_332);
  tcase_add_test(tc_core, test_is_equal_gen_333);
  tcase_add_test(tc_core, test_is_equal_gen_334);
  tcase_add_test(tc_core, test_is_equal_gen_335);
  tcase_add_test(tc_core, test_is_equal_gen_336);
  tcase_add_test(tc_core, test_is_equal_gen_337);
  tcase_add_test(tc_core, test_is_equal_gen_338);
  tcase_add_test(tc_core, test_is_equal_gen_339);
  tcase_add_test(tc_core, test_is_equal_gen_340);
  tcase_add_test(tc_core, test_is_equal_gen_341);
  tcase_add_test(tc_core, test_is_equal_gen_342);
  tcase_add_test(tc_core, test_is_equal_gen_343);
  tcase_add_test(tc_core, test_is_equal_gen_344);
  tcase_add_test(tc_core, test_is_equal_gen_345);
  tcase_add_test(tc_core, test_is_equal_gen_346);
  tcase_add_test(tc_core, test_is_equal_gen_347);
  tcase_add_test(tc_core, test_is_equal_gen_348);
  tcase_add_test(tc_core, test_is_equal_gen_349);
  tcase_add_test(tc_core, test_is_equal_gen_350);
  tcase_add_test(tc_core, test_is_equal_gen_351);
  tcase_add_test(tc_core, test_is_equal_gen_352);
  tcase_add_test(tc_core, test_is_equal_gen_353);
  tcase_add_test(tc_core, test_is_equal_gen_354);
  tcase_add_test(tc_core, test_is_equal_gen_355);
  tcase_add_test(tc_core, test_is_equal_gen_356);
  tcase_add_test(tc_core, test_is_equal_gen_357);
  tcase_add_test(tc_core, test_is_equal_gen_358);
  tcase_add_test(tc_core, test_is_equal_gen_359);
  tcase_add_test(tc_core, test_is_equal_gen_360);
  tcase_add_test(tc_core, test_is_equal_gen_361);
  tcase_add_test(tc_core, test_is_equal_gen_362);
  tcase_add_test(tc_core, test_is_equal_gen_363);
  tcase_add_test(tc_core, test_is_equal_gen_364);
  tcase_add_test(tc_core, test_is_equal_gen_365);
  tcase_add_test(tc_core, test_is_equal_gen_366);
  tcase_add_test(tc_core, test_is_equal_gen_367);
  tcase_add_test(tc_core, test_is_equal_gen_368);
  tcase_add_test(tc_core, test_is_equal_gen_369);
  tcase_add_test(tc_core, test_is_equal_gen_370);
  tcase_add_test(tc_core, test_is_equal_gen_371);
  tcase_add_test(tc_core, test_is_equal_gen_372);
  tcase_add_test(tc_core, test_is_equal_gen_373);
  tcase_add_test(tc_core, test_is_equal_gen_374);
  tcase_add_test(tc_core, test_is_equal_gen_375);
  tcase_add_test(tc_core, test_is_equal_gen_376);
  tcase_add_test(tc_core, test_is_equal_gen_377);
  tcase_add_test(tc_core, test_is_equal_gen_378);
  tcase_add_test(tc_core, test_is_equal_gen_379);
  tcase_add_test(tc_core, test_is_equal_gen_380);
  tcase_add_test(tc_core, test_is_equal_gen_381);
  tcase_add_test(tc_core, test_is_equal_gen_382);
  tcase_add_test(tc_core, test_is_equal_gen_383);
  tcase_add_test(tc_core, test_is_equal_gen_384);
  tcase_add_test(tc_core, test_is_equal_gen_385);
  tcase_add_test(tc_core, test_is_equal_gen_386);
  tcase_add_test(tc_core, test_is_equal_gen_387);
  tcase_add_test(tc_core, test_is_equal_gen_388);
  tcase_add_test(tc_core, test_is_equal_gen_389);
  tcase_add_test(tc_core, test_is_equal_gen_390);
  tcase_add_test(tc_core, test_is_equal_gen_391);
  tcase_add_test(tc_core, test_is_equal_gen_392);
  tcase_add_test(tc_core, test_is_equal_gen_393);
  tcase_add_test(tc_core, test_is_equal_gen_394);
  tcase_add_test(tc_core, test_is_equal_gen_395);
  tcase_add_test(tc_core, test_is_equal_gen_396);
  tcase_add_test(tc_core, test_is_equal_gen_397);
  tcase_add_test(tc_core, test_is_equal_gen_398);
  tcase_add_test(tc_core, test_is_equal_gen_399);
  tcase_add_test(tc_core, test_is_equal_gen_400);
  tcase_add_test(tc_core, test_is_equal_gen_401);
  tcase_add_test(tc_core, test_is_equal_gen_402);
  tcase_add_test(tc_core, test_is_equal_gen_403);
  tcase_add_test(tc_core, test_is_equal_gen_404);
  tcase_add_test(tc_core, test_is_equal_gen_405);
  tcase_add_test(tc_core, test_is_equal_gen_406);
  tcase_add_test(tc_core, test_is_equal_gen_407);
  tcase_add_test(tc_core, test_is_equal_gen_408);
  tcase_add_test(tc_core, test_is_equal_gen_409);
  tcase_add_test(tc_core, test_is_equal_gen_410);
  tcase_add_test(tc_core, test_is_equal_gen_411);
  tcase_add_test(tc_core, test_is_equal_gen_412);
  tcase_add_test(tc_core, test_is_equal_gen_413);
  tcase_add_test(tc_core, test_is_equal_gen_414);
  tcase_add_test(tc_core, test_is_equal_gen_415);
  tcase_add_test(tc_core, test_is_equal_gen_416);
  tcase_add_test(tc_core, test_is_equal_gen_417);
  tcase_add_test(tc_core, test_is_equal_gen_418);
  tcase_add_test(tc_core, test_is_equal_gen_419);
  tcase_add_test(tc_core, test_is_equal_gen_420);
  tcase_add_test(tc_core, test_is_equal_gen_421);
  tcase_add_test(tc_core, test_is_equal_gen_422);
  tcase_add_test(tc_core, test_is_equal_gen_423);
  tcase_add_test(tc_core, test_is_equal_gen_424);
  tcase_add_test(tc_core, test_is_equal_gen_425);
  tcase_add_test(tc_core, test_is_equal_gen_426);
  tcase_add_test(tc_core, test_is_equal_gen_427);
  tcase_add_test(tc_core, test_is_equal_gen_428);
  tcase_add_test(tc_core, test_is_equal_gen_429);
  tcase_add_test(tc_core, test_is_equal_gen_430);
  tcase_add_test(tc_core, test_is_equal_gen_431);
  tcase_add_test(tc_core, test_is_equal_gen_432);
  tcase_add_test(tc_core, test_is_equal_gen_433);
  tcase_add_test(tc_core, test_is_equal_gen_434);
  tcase_add_test(tc_core, test_is_equal_gen_435);
  tcase_add_test(tc_core, test_is_equal_gen_436);
  tcase_add_test(tc_core, test_is_equal_gen_437);
  tcase_add_test(tc_core, test_is_equal_gen_438);
  tcase_add_test(tc_core, test_is_equal_gen_439);
  tcase_add_test(tc_core, test_is_equal_gen_440);
  tcase_add_test(tc_core, test_is_equal_gen_441);
  tcase_add_test(tc_core, test_is_equal_gen_442);
  tcase_add_test(tc_core, test_is_equal_gen_443);
  tcase_add_test(tc_core, test_is_equal_gen_444);
  tcase_add_test(tc_core, test_is_equal_gen_445);
  tcase_add_test(tc_core, test_is_equal_gen_446);
  tcase_add_test(tc_core, test_is_equal_gen_447);
  tcase_add_test(tc_core, test_is_equal_gen_448);
  tcase_add_test(tc_core, test_is_equal_gen_449);
  tcase_add_test(tc_core, test_is_equal_gen_450);
  tcase_add_test(tc_core, test_is_equal_gen_451);
  tcase_add_test(tc_core, test_is_equal_gen_452);
  tcase_add_test(tc_core, test_is_equal_gen_453);
  tcase_add_test(tc_core, test_is_equal_gen_454);
  tcase_add_test(tc_core, test_is_equal_gen_455);
  tcase_add_test(tc_core, test_is_equal_gen_456);
  tcase_add_test(tc_core, test_is_equal_gen_457);
  tcase_add_test(tc_core, test_is_equal_gen_458);
  tcase_add_test(tc_core, test_is_equal_gen_459);
  tcase_add_test(tc_core, test_is_equal_gen_460);
  tcase_add_test(tc_core, test_is_equal_gen_461);
  tcase_add_test(tc_core, test_is_equal_gen_462);
  tcase_add_test(tc_core, test_is_equal_gen_463);
  tcase_add_test(tc_core, test_is_equal_gen_464);
  tcase_add_test(tc_core, test_is_equal_gen_465);
  tcase_add_test(tc_core, test_is_equal_gen_466);
  tcase_add_test(tc_core, test_is_equal_gen_467);
  tcase_add_test(tc_core, test_is_equal_gen_468);
  tcase_add_test(tc_core, test_is_equal_gen_469);
  tcase_add_test(tc_core, test_is_equal_gen_470);
  tcase_add_test(tc_core, test_is_equal_gen_471);
  tcase_add_test(tc_core, test_is_equal_gen_472);
  tcase_add_test(tc_core, test_is_equal_gen_473);
  tcase_add_test(tc_core, test_is_equal_gen_474);
  tcase_add_test(tc_core, test_is_equal_gen_475);
  tcase_add_test(tc_core, test_is_equal_gen_476);
  tcase_add_test(tc_core, test_is_equal_gen_477);
  tcase_add_test(tc_core, test_is_equal_gen_478);
  tcase_add_test(tc_core, test_is_equal_gen_479);
  tcase_add_test(tc_core, test_is_equal_gen_480);
  tcase_add_test(tc_core, test_is_equal_gen_481);
  tcase_add_test(tc_core, test_is_equal_gen_482);
  tcase_add_test(tc_core, test_is_equal_gen_483);
  tcase_add_test(tc_core, test_is_equal_gen_484);
  tcase_add_test(tc_core, test_is_equal_gen_485);
  tcase_add_test(tc_core, test_is_equal_gen_486);
  tcase_add_test(tc_core, test_is_equal_gen_487);
  tcase_add_test(tc_core, test_is_equal_gen_488);
  tcase_add_test(tc_core, test_is_equal_gen_489);
  tcase_add_test(tc_core, test_is_equal_gen_490);
  tcase_add_test(tc_core, test_is_equal_gen_491);
  tcase_add_test(tc_core, test_is_equal_gen_492);
  tcase_add_test(tc_core, test_is_equal_gen_493);
  tcase_add_test(tc_core, test_is_equal_gen_494);
  tcase_add_test(tc_core, test_is_equal_gen_495);
  tcase_add_test(tc_core, test_is_equal_gen_496);
  tcase_add_test(tc_core, test_is_equal_gen_497);
  tcase_add_test(tc_core, test_is_equal_gen_498);
  tcase_add_test(tc_core, test_is_equal_gen_499);
  tcase_add_test(tc_core, test_is_equal_gen_500);
  tcase_add_test(tc_core, test_is_equal_gen_501);
  tcase_add_test(tc_core, test_is_equal_gen_502);
  tcase_add_test(tc_core, test_is_equal_gen_503);
  tcase_add_test(tc_core, test_is_equal_gen_504);
  tcase_add_test(tc_core, test_is_equal_gen_505);
  tcase_add_test(tc_core, test_is_equal_gen_506);
  tcase_add_test(tc_core, test_is_equal_gen_507);
  tcase_add_test(tc_core, test_is_equal_gen_508);
  tcase_add_test(tc_core, test_is_equal_gen_509);
  tcase_add_test(tc_core, test_is_equal_gen_510);
  tcase_add_test(tc_core, test_is_equal_gen_511);
  tcase_add_test(tc_core, test_is_equal_gen_512);
  tcase_add_test(tc_core, test_is_equal_gen_513);
  tcase_add_test(tc_core, test_is_equal_gen_514);
  tcase_add_test(tc_core, test_is_equal_gen_515);
  tcase_add_test(tc_core, test_is_equal_gen_516);
  tcase_add_test(tc_core, test_is_equal_gen_517);
  tcase_add_test(tc_core, test_is_equal_gen_518);
  tcase_add_test(tc_core, test_is_equal_gen_519);
  tcase_add_test(tc_core, test_is_equal_gen_520);
  tcase_add_test(tc_core, test_is_equal_gen_521);
  tcase_add_test(tc_core, test_is_equal_gen_522);
  tcase_add_test(tc_core, test_is_equal_gen_523);
  tcase_add_test(tc_core, test_is_equal_gen_524);
  tcase_add_test(tc_core, test_is_equal_gen_525);
  tcase_add_test(tc_core, test_is_equal_gen_526);
  tcase_add_test(tc_core, test_is_equal_gen_527);
  tcase_add_test(tc_core, test_is_equal_gen_528);
  tcase_add_test(tc_core, test_is_equal_gen_529);
  tcase_add_test(tc_core, test_is_equal_gen_530);
  tcase_add_test(tc_core, test_is_equal_gen_531);
  tcase_add_test(tc_core, test_is_equal_gen_532);
  tcase_add_test(tc_core, test_is_equal_gen_533);
  tcase_add_test(tc_core, test_is_equal_gen_534);
  tcase_add_test(tc_core, test_is_equal_gen_535);
  tcase_add_test(tc_core, test_is_equal_gen_536);
  tcase_add_test(tc_core, test_is_equal_gen_537);
  tcase_add_test(tc_core, test_is_equal_gen_538);
  tcase_add_test(tc_core, test_is_equal_gen_539);
  tcase_add_test(tc_core, test_is_equal_gen_540);
  tcase_add_test(tc_core, test_is_equal_gen_541);
  tcase_add_test(tc_core, test_is_equal_gen_542);
  tcase_add_test(tc_core, test_is_equal_gen_543);
  tcase_add_test(tc_core, test_is_equal_gen_544);
  tcase_add_test(tc_core, test_is_equal_gen_545);
  tcase_add_test(tc_core, test_is_equal_gen_546);
  tcase_add_test(tc_core, test_is_equal_gen_547);
  tcase_add_test(tc_core, test_is_equal_gen_548);
  tcase_add_test(tc_core, test_is_equal_gen_549);
  tcase_add_test(tc_core, test_is_equal_gen_550);
  tcase_add_test(tc_core, test_is_equal_gen_551);

  suite_add_tcase(is_equal_suite, tc_core);
  return is_equal_suite;
}