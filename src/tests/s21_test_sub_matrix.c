#include "test.h"

START_TEST(test_s21_sub_matrix_1) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double res[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_sub_matrix(&A, &B, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], expected_result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  const int rows = 1;
  const int columns = 3;
  double arr1[1][3] = {{3, -6, 0.0001}};
  double arr2[1][3] = {{-3, 6, 0.0002}};

  double res[1][3] = {{6, -12, -0.0001}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr1, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr2, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_sub_matrix(&A, &B, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected_result.matrix[i][j],
                              EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  const int rowsA = 1;
  const int columnsA = 3;
  double arr1[1][3] = {{3, -6, 0.0001}};

  const int rowsB = 3;
  const int columnsB = 1;
  double arr2[3][1] = {{3}, {-6}, {0.0002}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rowsA, columnsA, &A);
  fill_matrix_from_array(&A, *arr1, rowsA, columnsA);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rowsB, columnsB, &B);
  fill_matrix_from_array(&B, *arr2, rowsB, columnsB);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rowsA, columnsA, &result);

  int result_number = s21_sub_matrix(&A, &B, &result);

  int expected_result_number = Error_Calculation;
  ck_assert_int_eq(result_number, expected_result_number);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  const int rows = 1;
  const int columns = 3;
  double arr1[1][3] = {{0, 0, 0.0000001}};
  double arr2[1][3] = {{0, 0, 0.00000001}};

  double res[1][3] = {{0, 0, 0}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr1, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr2, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_sub_matrix(&A, &B, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected_result.matrix[i][j],
                              EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
  const int rows = 1;
  const int columns = 3;
  double arr1[1][3] = {{0, 0, -0.00000001}};
  double arr2[1][3] = {{0, 0, 0.00000001}};

  double res[1][3] = {{0, 0, 0}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr1, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr2, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_sub_matrix(&A, &B, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], expected_result.matrix[i][j],
                              EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_6) {
  matrix_t A = {NULL, 0, 0};

  matrix_t B = {NULL, 0, 0};

  matrix_t result = {NULL, 0, 0};

  int result_number = s21_sub_matrix(&A, &B, &result);
  int expected_result_number = Error_Invalid_Matrix;
  ck_assert_int_eq(result_number, expected_result_number);
}
END_TEST

Suite* test_s21_sub_matrix() {
  Suite* s = suite_create("s21_sub_matrix");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sub_matrix_1);
  tcase_add_test(tc_core, test_s21_sub_matrix_2);
  tcase_add_test(tc_core, test_s21_sub_matrix_3);
  tcase_add_test(tc_core, test_s21_sub_matrix_4);
  tcase_add_test(tc_core, test_s21_sub_matrix_5);
  tcase_add_test(tc_core, test_s21_sub_matrix_6);

  suite_add_tcase(s, tc_core);
  return s;
}