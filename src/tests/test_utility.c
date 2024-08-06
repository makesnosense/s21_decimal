#include "../arithmetic.h"
#include "../debug_funcs.h"
#include "../utility.h"
#include "run_tests.h"

START_TEST(mantissa_addition_test) {
  // 4 573 498 578 943 759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b100000011111110010010, 0b0};
  // 3 648 576 347 873 449 873
  uint32_t term_2[3] = {0b01111110111000111001011110010001,
                        0b110010101000100101100011011011, 0b0};
  uint32_t sum[3] = {0b0, 0b0, 0b0};
  // 3 653 149 846 452 393 632
  uint32_t expected[3] = {0b00011101000100010101011010100000,
                          0b110010101100101001100001101110, 0b0};
  int overflow = add_mantissas(term_1, term_2, sum);

  ck_assert_mem_eq(sum, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(overflow, 0);
}
END_TEST
// 11 0010 1011 0010 1001 1000 0110 1110
// 0001 1101 0001 0001 0101 0110 1010 0000

START_TEST(mantissa_addition_to_self_test) {
  // 4 573 498 578 943 759
  uint32_t term_1[3] = {0b10011110001011011011111100001111,
                        0b100000011111110010010, 0b0};
  uint32_t one[3] = {1, 0, 0};
  add_mantissas(term_1, one, term_1);
}
END_TEST

START_TEST(long_mantissa_addition_test) {
  // 7922816251426433759354395035792281625142643375935439503
  uint32_t term_1[6] = {0xA0F5C28F, 0x08B342E4, 0x071569B1,
                        0xE4000000, 0xDCC80CD2, 0x52B7D2};
  // 7922816251426433759354395035792281625142643375935439503

  uint32_t term_2[6] = {0xA0F5C28F, 0x08B342E4, 0x071569B1,
                        0xE4000000, 0xDCC80CD2, 0x52B7D2};
  uint32_t sum[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
  // 15845632502852867518708790071584563250285286751870879006
  uint32_t expected_sum[6] = {0x41EB851E, 0x116685C9, 0x0E2AD362,
                              0xC8000000, 0xB99019A5, 0xA56FA5};

  int overflow = add_long_mantissas(term_1, term_2, sum);
  ck_assert_mem_eq(sum, expected_sum, sizeof(uint32_t) * 6);
  ck_assert_int_eq(overflow, 0);
}
END_TEST

START_TEST(test_long_mantissas_addition_1) {
  // 333328162514264337593543950335
  uint32_t term_1[6] = {0x13FFFFFF, 0x6DA74941, 0x350A97F9,
                        0x00000004, 0x00000000, 0x00000000};
  // 5633328162514264337593543950335
  uint32_t term_2[6] = {0x33FFFFFF, 0x16463634, 0x1A43D716,
                        0x00000047, 0x00000000, 0x00000000};
  // 5966656325028528675187087900670
  uint32_t expected_sum[6] = {0x47FFFFFE, 0x83ED7F75, 0x4F4E6F0F,
                              0x0000004B, 0x00000000, 0x00000000};

  uint32_t sum[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int overflow = add_long_mantissas(term_1, term_2, sum);

  ck_assert_mem_eq(sum, expected_sum, sizeof(uint32_t) * 6);
  ck_assert_int_eq(overflow, 0);
}
END_TEST

START_TEST(test_long_mantissas_addition_2) {
  // 945734349573434345343495873493453475983459384593457
  uint32_t term_1[6] = {0x86A88C31, 0x6E8B1578, 0xD3EFA905,
                        0x6804060D, 0x1902EF57, 0x00000287};
  // 945734349573434345343495873493453475983459384593457
  uint32_t term_2[6] = {0x86A88C31, 0x6E8B1578, 0xD3EFA905,
                        0x6804060D, 0x1902EF57, 0x00000287};
  // 1891468699146868690686991746986906951966918769186914
  uint32_t expected_sum[6] = {0x0D511862, 0xDD162AF1, 0xA7DF520A,
                              0xD0080C1B, 0x3205DEAE, 0x0000050E};

  uint32_t sum[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int overflow = add_long_mantissas(term_1, term_2, sum);

  ck_assert_mem_eq(sum, expected_sum, sizeof(uint32_t) * 6);
  ck_assert_int_eq(overflow, 0);
}
END_TEST

START_TEST(test_long_mantissas_substraction_1) {
  // 333328162514264337593543950334
  uint32_t minuend[6] = {0x13FFFFFE, 0x6DA74941, 0x350A97F9,
                         0x00000004, 0x00000000, 0x00000000};
  // 5633328162514264337593543950335
  uint32_t subtrahend[6] = {0x33FFFFFF, 0x16463634, 0x1A43D716,
                            0x00000047, 0x00000000, 0x00000000};
  // -5300000000000000000000000000001
  uint32_t expected_result[6] = {0x20000001, 0xA89EECF3, 0xE5393F1C,
                                 0x00000042, 0x00000000, 0x00000000};

  uint32_t result[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int is_negative = subtract_long_mantissas(minuend, subtrahend, result);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 6);
  ck_assert_int_eq(is_negative, 1);
}
END_TEST

START_TEST(test_long_mantissas_substraction_2) {
  // 1231243453434598789456645745683034558034321234564564354
  uint32_t minuend[6] = {0x82B14582, 0x5456BA68, 0xFECEDC81,
                         0xB4D51AA3, 0xF510409D, 0x000CDAD2};
  // 85437594753753753975345645675675767000097534985495689
  uint32_t subtrahend[6] = {0xF1A5E489, 0xC25EEA0B, 0x27E14430,
                            0x9D6B1AD4, 0xC64A5E8B, 0x0000E45A};
  // 1145805858680845035481300100007358791034223699579068665
  uint32_t expected_result[6] = {0x910B60F9, 0x91F7D05C, 0xD6ED9850,
                                 0x1769FFCF, 0x2EC5E212, 0x000BF678};

  uint32_t result[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int is_negative = subtract_long_mantissas(minuend, subtrahend, result);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 6);
  ck_assert_int_eq(is_negative, 0);
}
END_TEST

START_TEST(test_long_mantissas_substraction_3) {
  // 1231243453434598789456645745683034558034321234564564354
  uint32_t minuend[6] = {0x82B14582, 0x5456BA68, 0xFECEDC81,
                         0xB4D51AA3, 0xF510409D, 0x000CDAD2};
  // 0
  uint32_t subtrahend[6] = {0x00000000, 0x00000000, 0x00000000,
                            0x00000000, 0x00000000, 0x00000000};
  // 1231243453434598789456645745683034558034321234564564354
  uint32_t expected_result[6] = {0x82B14582, 0x5456BA68, 0xFECEDC81,
                                 0xB4D51AA3, 0xF510409D, 0x000CDAD2};

  uint32_t result[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int is_negative = subtract_long_mantissas(minuend, subtrahend, result);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 6);
  ck_assert_int_eq(is_negative, 0);
}
END_TEST

START_TEST(test_long_mantissas_substraction_4) {
  // 0
  uint32_t minuend[6] = {0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000};
  // 1231243453434598789456645745683034558034321234564564354
  uint32_t subtrahend[6] = {0x82B14582, 0x5456BA68, 0xFECEDC81,
                            0xB4D51AA3, 0xF510409D, 0x000CDAD2};
  // -1231243453434598789456645745683034558034321234564564354
  uint32_t expected_result[6] = {0x82B14582, 0x5456BA68, 0xFECEDC81,
                                 0xB4D51AA3, 0xF510409D, 0x000CDAD2};

  uint32_t result[6] = {0b0, 0b0, 0b0, 0b0, 0b0, 0b0};

  int is_negative = subtract_long_mantissas(minuend, subtrahend, result);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 6);
  ck_assert_int_eq(is_negative, 1);
}
END_TEST

START_TEST(mantissa_bitflip_test) {
  uint32_t number_1[3] = {0b00000000000000000000000000000000,
                          0b11111111111111111111111111111111,
                          0b00000000000000000000000000000000};
  uint32_t number_2[3] = {0b11111111111111111111111111111111,
                          0b00000000000000000000000000000000,
                          0b11111111111111111111111111111111};
  uint32_t result_1[3] = {0, 0, 0};
  uint32_t result_2[3] = {0, 0, 0};
  bitflip_mantissa(number_1, result_1);
  bitflip_mantissa(number_2, result_2);
  ck_assert_mem_eq(result_1, number_2, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(result_2, number_1, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(long_mantissa_bitflip_test) {
  uint32_t number_1[6] = {
      0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
      0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
      0b00000000000000000000000000000000, 0b11111111111111111111111111111111};
  uint32_t number_2[6] = {
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
      0b11111111111111111111111111111111, 0b00000000000000000000000000000000};
  uint32_t result_1[6] = {0, 0, 0, 0, 0, 0};
  uint32_t result_2[6] = {0, 0, 0, 0, 0, 0};
  bitflip_long_mantissa(number_1, result_1);
  bitflip_long_mantissa(number_2, result_2);
  ck_assert_mem_eq(result_1, number_2, sizeof(uint32_t) * 6);
  ck_assert_mem_eq(result_2, number_1, sizeof(uint32_t) * 6);
}
END_TEST

START_TEST(mantissa_copy_test) {
  uint32_t src[3] = {0b00011101000100010101011010100000,
                     0b110010101100101001100001101110, 0b0};
  uint32_t result[3] = {0, 0, 0};
  copy_mantissa(src, result);
  ck_assert_mem_eq(result, src, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(mantissa_zero_subtraction_test) {
  uint32_t minuend[3] = {0b00011101000100010101011010100000,
                         0b110010101100101001100001101110, 0b0};

  uint32_t subtrahend[3] = {0, 0, 0};
  uint32_t result[3] = {0, 0, 0};
  // debug_print_mantissa_as_binary(minuend, 3);
  // debug_print_mantissa_as_binary(subtrahend, 3);
  // debug_print_mantissa_as_binary(result, 3);

  int is_negative = subtract_mantissas(minuend, subtrahend, result);
  // debug_print_mantissa_as_binary(minuend, 3);
  // debug_print_mantissa_as_binary(subtrahend, 3);
  // debug_print_mantissa_as_binary(result, 3);

  ck_assert_mem_eq(result, minuend, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negative, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_1) {
  uint32_t minuend[3] = {3, 0, 0};
  uint32_t subtrahend[3] = {10, 0, 0};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {7, 0, 0};
  int is_negative = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negative, 1);
}
END_TEST

START_TEST(mantissa_subtraction_test_2) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFFFFFU};
  uint32_t subtrahend[3] = {0xFFFFFFFEU, 0xFFFFFFFFU, 0x7FFFFFFFU};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0x1U, 0x0U, 0x80000000U};
  int is_negaive = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_3) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0x0U, 0x0U};
  uint32_t subtrahend[3] = {0x55555554U, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xAAAAAAABU, 0x0U, 0x0U};
  int is_negaive = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_4) {
  uint32_t minuend[3] = {0xFFFFFFFFU, 0x3FFFFU, 0x0U};
  uint32_t subtrahend[3] = {0x3U, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xFFFFFFFCU, 0x3FFFFU, 0x0U};
  int is_negative = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negative, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_5) {
  uint32_t minuend[3] = {0x55555554U, 0x0U, 0x0U};
  uint32_t subtrahend[3] = {0xFFFFFFFFU, 0x0U, 0x0U};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0xAAAAAAABU, 0x0U, 0x0U};
  int is_negaive = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 1);
}
END_TEST

START_TEST(mantissa_subtraction_test_6) {
  // 10^28
  uint32_t minuend[3] = {0x10000000, 0x3E250261, 0x204FCE5E};
  uint32_t subtrahend[3] = {0x1, 0x0, 0x0};
  uint32_t result[3] = {0, 0, 0};
  uint32_t expected[3] = {0x0FFFFFFF, 0x3E250261, 0x204FCE5E};
  int is_negaive = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negaive, 0);
}
END_TEST

START_TEST(mantissa_subtraction_test_7) {
  // 10^28
  uint32_t minuend[3] = {0x10000000, 0x3E250261, 0x204FCE5E};
  // 2166546186782710593811906561
  uint32_t subtrahend[3] = {0x1, 0x20000040, 0x7002000};
  uint32_t result[3] = {0, 0, 0};
  // 7833453813217289406188093439
  uint32_t expected[3] = {0x0FFFFFFF, 0x1E250221, 0x194FAE5E};
  int is_negative = subtract_mantissas(minuend, subtrahend, result);
  ck_assert_mem_eq(result, expected, sizeof(uint32_t) * 3);
  ck_assert_int_eq(is_negative, 0);
}
END_TEST

START_TEST(mantissa_shift_left_test_1) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b11100000000000000000000000000111,
                          0b00000000000000000000000000000000};
  uint32_t expected[3] = {0b00000000000000000000000000111000,
                          0b00000000000000000000000000111000,
                          0b00000000000000000000000000000111};
  shift_mantissa_left(mantissa, 3);
  ck_assert_mem_eq(mantissa, expected, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(mantissa_shift_left_test_2) {
  uint32_t mantissa[3] = {0x107A4000, 0x5AF3, 0x0};
  uint32_t expected[3] = {0x0, 0x80000000, 0xB5E620F4};
  shift_mantissa_left(mantissa, 49);
  ck_assert_mem_eq(mantissa, expected, sizeof(uint32_t) * 3);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_1) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b11100000000000000000000000000111,
                          0b00000000000000000000000000000111};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 66);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_2) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_3) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000111,
                          0b00000000000000000000000000000010,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, 33);
}
END_TEST

START_TEST(find_highest_mantissa_bit_test_4) {
  uint32_t mantissa[3] = {0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  int result = find_highest_mantissa_bit(mantissa);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(mantissa_division_test_1) {
  uint32_t divident[3] = {0b00000000000000000000000000000100,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  int result = divide_mantissas(divident, divisor, NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(mantissa_division_test_2) {
  uint32_t divident[3] = {0b00000000000000000000000000001011,
                          0b00000000000000000000000000000000,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000100,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  uint32_t result[3];
  uint32_t remainder[3];
  uint32_t expected_result[3] = {2, 0, 0};
  uint32_t expected_remainder[3] = {3, 0, 0};
  int division_error = divide_mantissas(divident, divisor, result, remainder);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_3) {
  uint32_t divident[3] = {0b00000000000000000000000000000000,
                          0b00000000000000000000000000000001,
                          0b00000000000000000000000000000000};
  uint32_t divisor[3] = {0b00000000000000000000000000000101,
                         0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000};
  uint32_t result[3];
  uint32_t remainder[3];
  uint32_t expected_result[3] = {0x33333333, 0, 0};
  uint32_t expected_remainder[3] = {1, 0, 0};
  int division_error = divide_mantissas(divident, divisor, result, remainder);
  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_4) {
  // 4398046511103
  uint32_t divident[3] = {0xFFFFFFFF, 0x3FF, 0x0};
  // 5452542852
  uint32_t divisor[3] = {0x44FF3384, 0x1, 0x0};
  uint32_t result[3];
  uint32_t remainder[3];
  // 806
  uint32_t expected_result[3] = {0x326, 0, 0};
  // 3296972391
  uint32_t expected_remainder[3] = {0xC483CE67, 0x0, 0x0};
  int division_error = divide_mantissas(divident, divisor, result, remainder);
  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_test_5) {
  // 79228162514264337593543950335
  uint32_t divident[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  // 10^14 = 100000000000000
  uint32_t divisor[3] = {0x107A4000, 0x5AF3, 0x0};

  uint32_t result[3];
  uint32_t remainder[3];

  // 792281625142643
  uint32_t expected_result[3] = {0x70D42573, 0x2D093, 0x0};
  // 37593543950335
  uint32_t expected_remainder[3] = {0xEDD53FFF, 0x2230, 0x0};
  divide_mantissas(divident, divisor, result, remainder);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
}

START_TEST(mantissa_division_test_6) {
  // 79228162514264337593543950320
  uint32_t divident[3] = {0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF};
  // 79228162514264337593543950335
  uint32_t divisor[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

  uint32_t result[3];
  uint32_t remainder[3];

  // 0
  uint32_t expected_result[3] = {0x0, 0x0, 0x0};
  // 79228162514264337593543950335
  uint32_t expected_remainder[3] = {0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF};
  divide_mantissas(divident, divisor, result, remainder);

  ck_assert_mem_eq(result, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
}

START_TEST(mantissa_division_inplace_test_1) {
  // 4398046511103
  uint32_t divident[3] = {0xFFFFFFFF, 0x3FF, 0x0};
  // 5452542852
  uint32_t divisor[3] = {0x44FF3384, 0x1, 0x0};
  uint32_t remainder[3];
  // 806
  uint32_t expected_result[3] = {0x326, 0, 0};
  // 3296972391
  uint32_t expected_remainder[3] = {0xC483CE67, 0x0, 0x0};
  int division_error = divide_mantissas(divident, divisor, divident, remainder);
  ck_assert_mem_eq(divident, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
  ck_assert_int_eq(division_error, 0);
}
END_TEST

START_TEST(mantissa_division_inplace_test_2) {
  // 79228162514264337593543950335
  uint32_t divident[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  // 10^14 = 100000000000000
  uint32_t divisor[3] = {0x107A4000, 0x5AF3, 0x0};

  uint32_t remainder[3];

  // 792281625142643
  uint32_t expected_result[3] = {0x70D42573, 0x2D093, 0x0};
  // 37593543950335
  uint32_t expected_remainder[3] = {0xEDD53FFF, 0x2230, 0x0};
  divide_mantissas(divident, divisor, divident, remainder);

  ck_assert_mem_eq(divident, expected_result, sizeof(uint32_t) * 3);
  ck_assert_mem_eq(remainder, expected_remainder, sizeof(uint32_t) * 3);
}

START_TEST(get_scale_test) {
  uint32_t service_parts[] = {
      0b00000000000000000000000000000000, 0b00000000000000010000000000000000,
      0b00000000000000100000000000000000, 0b00000000000000110000000000000000,
      0b00000000000001000000000000000000, 0b00000000000001010000000000000000,
      0b00000000000001100000000000000000, 0b00000000000001110000000000000000,
      0b00000000000010000000000000000000, 0b00000000000010010000000000000000,
      0b00000000000010100000000000000000, 0b00000000000010110000000000000000,
      0b00000000000011000000000000000000, 0b00000000000011010000000000000000,
      0b00000000000011100000000000000000, 0b00000000000011110000000000000000,
      0b00000000000100000000000000000000, 0b00000000000100010000000000000000,
      0b00000000000100100000000000000000, 0b00000000000100110000000000000000,
      0b00000000000101000000000000000000, 0b00000000000101010000000000000000,
      0b00000000000101100000000000000000, 0b00000000000101110000000000000000,
      0b00000000000110000000000000000000, 0b00000000000110010000000000000000,
      0b00000000000110100000000000000000, 0b00000000000110110000000000000000,
      0b00000000000111000000000000000000};

  // printf("\n%d\n", get_scale(scales[1]));
  for (int i = 0; i < 29; i++) {
    ck_assert_int_eq(get_scale(service_parts[i]), i);
  }

  //   s21_decimal input_decimal = {{0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000}};
  // int scale_before = get_scale(input_decimal.bits[3]);
  // int scale_to_set = 6;

  // set_scale(&input_decimal.bits[3], scale_to_set);
  // int scale_after = get_scale(input_decimal.bits[3]);
  // ck_assert_int_ne(scale_before, scale_after);
  // ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

START_TEST(test_set_scale) {
  s21_decimal input_decimal = {
      {0x123U, 0x123U, 0x123U, 0b00000000000000000000000000000000}};
  for (int i = 0; i < 29; i++) {
    set_scale(&input_decimal.bits[3], i);
    ck_assert_int_eq(get_scale(input_decimal.bits[3]), i);
  }
}

START_TEST(set_scale_test) {
  s21_decimal input_decimal = {
      {0x123U, 0x123U, 0x123U, 0b00000000000000101000000000000000}};
  int scale_before = get_scale(input_decimal.bits[3]);
  int scale_to_set = 6;

  set_scale(&input_decimal.bits[3], scale_to_set);
  int scale_after = get_scale(input_decimal.bits[3]);
  ck_assert_int_ne(scale_before, scale_after);
  ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

START_TEST(multiply_test) {
  // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
  //                              0b00000000000000101000000000000000};
  uint32_t num_1[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t num_2[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32_t res[6] = {0};

  multiply_mantissas(num_1, num_2, res);

  // debug_print_mantissa_as_binary(res, 6);

  // ck_assert_int_ne(scale_before, scale_after);
  // ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

// START_TEST(multiply_test_2) {
//   // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
//   //                              0b00000000000000101000000000000000};
//   uint32_t num_1[3] = {0xF485787A, 0x7F29ABCA, 0x1AD};
//   uint32_t num_2[3] = {0xD83C94FB, 0x1, 0x0};
//   uint32_t res[6] = {0};
//   // debug_print_decimal_as_binary(input_decimal);

//   multiply_mantissas(num_1, num_2, res);

//   debug_print_mantissa_as_binary(res, 6);

//   // ck_assert_int_ne(scale_before, scale_after);
//   // ck_assert_int_eq(scale_after, scale_to_set);
// }
// END_TEST

// START_TEST(print_mantissa_as_binary_test) {
//   // s21_decimal input_decimal = {0x123U, 0x123U, 0x123U,
//   //                              0b00000000000000101000000000000000};
//   uint32_t num_1[3] = {0x0, 0x0, 0x1869F};
//   debug_print_mantissa_as_binary(num_1, 3);
//   // debug_print_decimal_as_binary(input_decimal);

//   // ck_assert_int_ne(scale_before, scale_after);
//   // ck_assert_int_eq(scale_after, scale_to_set);
// }
// END_TEST

// START_TEST(convert_arr_to_decimal) {
//   // 4573498578943759
//   uint32_t term_1[3] = {0b10011110001011011011111100001111,
//                         0b10000001111111001001000001000010,
//                         0b01010010001001001010101010100101};

//   s21_decimal input_decimal1 = {0b10011110001011011011111100001111,
//                                 0b10000001111111001001000001000010,
//                                 0b01010010001001001010101010100101, 0x0U};
//   s21_decimal input_decimal2 = {0x0U, 0x0U, 0x0U, 0x0U};

//   write_in_mantissa_to_decimal(term_1, &input_decimal2);

//   debug_print_decimal_as_binary(input_decimal1);
//   putchar('\n');
//   debug_print_decimal_as_binary(input_decimal2);
// }
// END_TEST

// START_TEST(get_power_test) {
//   // print_mantissa_as_binary(get_power_of_ten(25), 3);
//   uint32_t* term_1 = get_mantissa_with_power_of_ten(28);
//   debug_print_mantissa_as_binary(term_1, 3);

//   putchar('\n');
// }
// END_TEST

START_TEST(shift_decimal_test) {
  s21_decimal input_decimal = {
      {0x0C8BBE0C, 0x4DD5DBB5, 0x00005751, 0b00000000000101110000000000000000}};

  // debug_print_decimal_as_binary_in_one_line(input_decimal);

  shift_decimal_right(&input_decimal);

  // debug_print_decimal_as_binary_in_one_line(input_decimal);
  // uint32_t num_1[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  // uint32_t num_2[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  // uint32_t res[6] = {0};
  // debug_print_decimal_as_binary(input_decimal);

  // debug_print_mantissa_as_binary(res, 6);

  // ck_assert_int_ne(scale_before, scale_after);
  // ck_assert_int_eq(scale_after, scale_to_set);
}
END_TEST

Suite* make_utility_suite() {
  Suite* utility_suite = suite_create("utility");
  TCase* tc_core;

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, get_scale_test);
  tcase_add_test(tc_core, mantissa_addition_test);
  tcase_add_test(tc_core, mantissa_addition_to_self_test);
  tcase_add_test(tc_core, long_mantissa_addition_test);
  tcase_add_test(tc_core, mantissa_bitflip_test);
  tcase_add_test(tc_core, long_mantissa_bitflip_test);
  tcase_add_test(tc_core, mantissa_copy_test);
  tcase_add_test(tc_core, mantissa_zero_subtraction_test);
  tcase_add_test(tc_core, mantissa_subtraction_test_1);
  tcase_add_test(tc_core, mantissa_subtraction_test_2);
  tcase_add_test(tc_core, mantissa_subtraction_test_3);
  tcase_add_test(tc_core, mantissa_subtraction_test_4);
  tcase_add_test(tc_core, mantissa_subtraction_test_5);
  tcase_add_test(tc_core, mantissa_subtraction_test_6);
  tcase_add_test(tc_core, mantissa_subtraction_test_7);
  tcase_add_test(tc_core, mantissa_shift_left_test_1);
  tcase_add_test(tc_core, mantissa_shift_left_test_2);
  tcase_add_test(tc_core, mantissa_division_test_1);
  tcase_add_test(tc_core, mantissa_division_test_2);
  tcase_add_test(tc_core, mantissa_division_test_3);
  tcase_add_test(tc_core, mantissa_division_test_4);
  tcase_add_test(tc_core, mantissa_division_test_5);
  tcase_add_test(tc_core, mantissa_division_test_6);
  tcase_add_test(tc_core, mantissa_division_inplace_test_1);
  tcase_add_test(tc_core, mantissa_division_inplace_test_2);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_1);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_2);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_3);
  tcase_add_test(tc_core, find_highest_mantissa_bit_test_4);
  tcase_add_test(tc_core, set_scale_test);
  tcase_add_test(tc_core, test_set_scale);

  tcase_add_test(tc_core, multiply_test);
  tcase_add_test(tc_core, shift_decimal_test);
  tcase_add_test(tc_core, test_long_mantissas_addition_1);
  tcase_add_test(tc_core, test_long_mantissas_addition_2);

  tcase_add_test(tc_core, test_long_mantissas_substraction_1);
  tcase_add_test(tc_core, test_long_mantissas_substraction_2);
  tcase_add_test(tc_core, test_long_mantissas_substraction_3);
  tcase_add_test(tc_core, test_long_mantissas_substraction_4);

  // tcase_add_test(tc_core, multiply_test_2);
  // tcase_add_test(tc_core, get_power_test);
  // tcase_add_test(tc_core, print_mantissa_as_binary_test);
  // tcase_add_test(tc_core, convert_arr_to_decimal);
  // tcase_add_test(tc_core, comparison_eq_test);
  suite_add_tcase(utility_suite, tc_core);
  return utility_suite;
}