#include "test.h"

START_TEST(test_s21_determinant_1) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = 0;
  int result_number = s21_determinant(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, -30, 1523}, {-45.2, 101, 15003}, {456, -0.01, 0}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = -275383489.57399964;

  int result_number = s21_determinant(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  const int rows = 2;
  const int columns = 3;
  double arr[2][3] = {{4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = result;

  int result_number = s21_determinant(&A, &result);
  int expected_result_number = Error_Calculation;

  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{0, 9, 1}, {0, 1, 4}, {0, 2, -1}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = 0;

  int result_number = s21_determinant(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{-12.0001001, 0.0045309, 0.0550001},
                      {0.0200009, -0.0700101, -0.1000044},
                      {7.0000006, 0.0000002, -0.000501}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = 0.023361;

  int result_number = s21_determinant(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{0, 1, 8}, {0, 2, 4}, {31, 1, 4}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  double result = 0;
  double expected_result = -372;

  int result_number = s21_determinant(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);
  ck_assert_double_eq_tol(result, expected_result, EPSILON);
  s21_remove_matrix(&A);
}
END_TEST

Suite* test_s21_determinant() {
  Suite* s = suite_create("s21_determinant");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_s21_determinant_3);
  tcase_add_test(tc_core, test_s21_determinant_4);
  tcase_add_test(tc_core, test_s21_determinant_5);
  tcase_add_test(tc_core, test_s21_determinant_6);

  suite_add_tcase(s, tc_core);
  return s;
}