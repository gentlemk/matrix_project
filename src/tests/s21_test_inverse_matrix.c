#include "test.h"

START_TEST(test_s21_inverse_matrix_1) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{2, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double res[3][3] = {{1, -2, 1}, {-2, 1, 0}, {1, 0.6666667, -0.6666667}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_inverse_matrix(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected_result.matrix[i][j],
                              EPSILON);
    }
  }
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{7, -3, 2}, {6, -5, 1}, {1, 20, 3}};
  double res[3][3] = {{-0.625, 0.875, 0.125},
                      {-0.303571, 0.339285, 0.089285},
                      {2.232142, -2.553571, -0.303571}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_inverse_matrix(&A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected_result.matrix[i][j],
                              EPSILON);
    }
  }
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  const int rows = -1;
  const int columns = 3;
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  int result_number = s21_inverse_matrix(&A, &result);
  int expected_result_number = Error_Invalid_Matrix;
  ck_assert_int_eq(result_number, expected_result_number);

  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  int result_number = s21_inverse_matrix(&A, &result);
  int expected_result_number = Error_Calculation;
  ck_assert_int_eq(result_number, expected_result_number);

  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_5) {
  const int rows = 2;
  const int columns = 3;
  double arr[2][3] = {{5, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  int result_number = s21_inverse_matrix(&A, &result);
  int expected_result_number = Error_Calculation;
  ck_assert_int_eq(result_number, expected_result_number);

  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

Suite* test_s21_inverse_matrix() {
  Suite* s = suite_create("s21_inverse_matrix");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_2);
  tcase_add_test(tc_core, test_s21_inverse_matrix_3);
  tcase_add_test(tc_core, test_s21_inverse_matrix_4);
  tcase_add_test(tc_core, test_s21_inverse_matrix_5);

  suite_add_tcase(s, tc_core);
  return s;
}