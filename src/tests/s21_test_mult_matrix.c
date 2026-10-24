#include "test.h"

START_TEST(test_s21_mult_matrix_1) {
  const int rows = 2;
  const int columns = 2;
  double arr1[2][2] = {{5, 6}, {-3, 9}};
  double arr2[2][2] = {{4, -1}, {8, 4}};

  double res[2][2] = {{68, 19}, {60, 39}};

  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t expected_result = {NULL, 0, 0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  // s21_create_matrix(rows, columns, &result);
  s21_create_matrix(rows, columns, &expected_result);

  fill_matrix_from_array(&A, *arr1, rows, columns);
  fill_matrix_from_array(&B, *arr2, rows, columns);
  fill_matrix_from_array(&expected_result, *res, rows, columns);
  int result_number = s21_mult_matrix(&A, &B, &result);
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

START_TEST(test_s21_mult_matrix_2) {
  const int rows1 = 1;
  const int columns1 = 3;
  double arr1[1][3] = {{5, 6, 7}};
  const int rows2 = columns1;
  const int columns2 = rows1;
  double arr2[3][1] = {{4}, {8}, {8}};

  double res[1][1] = {{5 * 4 + 6 * 8 + 7 * 8}};

  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t expected_result = {NULL, 0, 0};

  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  // s21_create_matrix(rows1, columns2, &result);
  s21_create_matrix(rows1, columns2, &expected_result);

  fill_matrix_from_array(&A, *arr1, rows1, columns1);
  fill_matrix_from_array(&B, *arr2, rows2, columns2);
  fill_matrix_from_array(&expected_result, *res, rows1, columns2);
  int result_number = s21_mult_matrix(&A, &B, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns2; j++) {
      ck_assert_double_eq(result.matrix[i][j], expected_result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  const int rows1 = 1;
  const int columns1 = 3;
  double arr1[1][3] = {{5, 6, 7}};
  const int rows2 = columns1;
  const int columns2 = rows1;
  double arr2[3][1] = {{4}, {8}, {8}};

  double res[3][3] = {{20, 24, 28}, {40, 48, 56}, {40, 48, 56}};

  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t expected_result = {NULL, 0, 0};

  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  // s21_create_matrix(rows1, columns2, &result);
  s21_create_matrix(rows1, columns2, &expected_result);

  fill_matrix_from_array(&A, *arr1, rows1, columns1);
  fill_matrix_from_array(&B, *arr2, rows2, columns2);
  fill_matrix_from_array(&expected_result, *res, rows1, columns2);
  int result_number = s21_mult_matrix(&B, &A, &result);
  int expected_result_number = OK;
  ck_assert_int_eq(result_number, expected_result_number);

  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns2; j++) {
      ck_assert_double_eq(result.matrix[i][j], expected_result.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

Suite* test_s21_mult_matrix() {
  Suite* s = suite_create("s21_mult_matrix");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_mult_matrix_1);
  tcase_add_test(tc_core, test_s21_mult_matrix_2);
  tcase_add_test(tc_core, test_s21_mult_matrix_3);

  suite_add_tcase(s, tc_core);
  return s;
}