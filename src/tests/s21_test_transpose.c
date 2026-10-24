#include "test.h"

static void test_transpose(int rows, int columns, double* arr, double* res,
                           result_code code_error);

START_TEST(test_s21_transpose_1) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double res[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

  test_transpose(rows, columns, (double*)arr, (double*)res, OK);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  const int rows = 1;
  const int columns = 3;
  double arr[1][3] = {{1, 2, 3}};
  double res[3][1] = {{1}, {2}, {3}};

  test_transpose(rows, columns, (double*)arr, (double*)res, OK);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  const int rows = 1;
  const int columns = 1;
  double arr[1][1] = {{1}};
  double res[1][1] = {{1}};

  test_transpose(rows, columns, (double*)arr, (double*)res, OK);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {2, 2, 2}, {3, 2, 1}};
  double res[3][3] = {{1, 2, 3}, {2, 2, 2}, {3, 2, 1}};
  test_transpose(rows, columns, (double*)arr, (double*)res, OK);
}
END_TEST

Suite* test_s21_transpose() {
  Suite* s = suite_create("s21_transpose");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_transpose_1);
  tcase_add_test(tc_core, test_s21_transpose_2);
  tcase_add_test(tc_core, test_s21_transpose_3);
  tcase_add_test(tc_core, test_s21_transpose_4);

  suite_add_tcase(s, tc_core);

  return s;
}

static void test_transpose(int rows, int columns, double* arr, double* res,
                           result_code code_error) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, arr, rows, columns);
  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(columns, rows, &result);
  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(columns, rows, &expected_result);
  fill_matrix_from_array(&expected_result, res, columns, rows);

  int result_number = s21_transpose(&A, &result);
  int expected_result_number = code_error;
  if (result_number == OK) {
    ck_assert_int_eq(result_number, expected_result_number);
    for (int i = 0; i < columns; i++) {
      for (int j = 0; j < rows; j++) {
        ck_assert_double_eq(result.matrix[i][j], expected_result.matrix[i][j]);
      }
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}