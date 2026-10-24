#include "test.h"

void test_create_matrix(int rows, int columns, result_code code);

START_TEST(test_s21_create_matrix_1) { test_create_matrix(1, 1, OK); }
END_TEST

START_TEST(test_s21_create_matrix_2) {
  test_create_matrix(10, 0, Error_Invalid_Matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  test_create_matrix(1, -1, Error_Invalid_Matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  test_create_matrix(-1, -1, Error_Invalid_Matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
  test_create_matrix(-1, 1, Error_Invalid_Matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_6) { test_create_matrix(1, 1, OK); }
END_TEST

Suite* test_s21_create_matrix() {
  Suite* s = suite_create("s21_create_matrix");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_create_matrix_1);
  tcase_add_test(tc_core, test_s21_create_matrix_2);
  tcase_add_test(tc_core, test_s21_create_matrix_3);
  tcase_add_test(tc_core, test_s21_create_matrix_4);
  tcase_add_test(tc_core, test_s21_create_matrix_5);
  tcase_add_test(tc_core, test_s21_create_matrix_6);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_create_matrix(int rows, int columns, result_code code) {
  matrix_t A = {NULL, 0, 0};
  int output = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(output, code);

  s21_remove_matrix(&A);
}