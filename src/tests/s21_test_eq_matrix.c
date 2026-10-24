#include "test.h"

/**
 * Сравнение одинаковых матриц
 */
START_TEST(test_s21_eq_matrix_1) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr, rows, columns);

  int result = s21_eq_matrix(&A, &B);
  int expected_result = 1;
  ck_assert_int_eq(result, expected_result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * Сравнение чисел 1 и 0.9999999
 */
START_TEST(test_s21_eq_matrix_2) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr, rows, columns);
  B.matrix[0][0] = 0.9999999;

  int result = s21_eq_matrix(&A, &B);
  int expected_result = 1;
  ck_assert_int_eq(result, expected_result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * Сравнение матриц разных размерностей
 */
START_TEST(test_s21_eq_matrix_3) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows - 1, columns - 1, &B);

  int result = s21_eq_matrix(&A, &B);
  int expected_result = 0;
  ck_assert_int_eq(result, expected_result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * Сравнение чисел 1 и 0.999999
 */
START_TEST(test_s21_eq_matrix_4) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &B);
  fill_matrix_from_array(&B, *arr, rows, columns);
  B.matrix[0][0] = 0.999999;

  int result = s21_eq_matrix(&A, &B);
  int expected_result = 0;
  ck_assert_int_eq(result, expected_result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * Сравнение с NULL
 */
START_TEST(test_s21_eq_matrix_5) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  int result = s21_eq_matrix(&A, NULL);
  int expected_result = 0;
  ck_assert_int_eq(result, expected_result);

  s21_remove_matrix(&A);
}
END_TEST

Suite* test_s21_eq_matrix() {
  Suite* s = suite_create("s21_eq_matrix");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_eq_matrix_1);
  tcase_add_test(tc_core, test_s21_eq_matrix_2);
  tcase_add_test(tc_core, test_s21_eq_matrix_3);
  tcase_add_test(tc_core, test_s21_eq_matrix_4);
  tcase_add_test(tc_core, test_s21_eq_matrix_5);

  suite_add_tcase(s, tc_core);
  return s;
}