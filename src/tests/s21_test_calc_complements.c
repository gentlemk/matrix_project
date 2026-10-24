#include "test.h"

START_TEST(test_s21_calc_complements_1) {
  const int rows = 2;
  const int columns = 2;
  double arr[2][2] = {{1, 2}, {3, 4}};
  double res[2][2] = {{4, -3}, {-2, 1}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_calc_complements(&A, &result);
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

START_TEST(test_s21_calc_complements_2) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {-1, 5, 3}, {3, 4, 6}};
  double res[3][3] = {{18, 15, -19}, {0, -3, 2}, {-9, -6, 7}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_calc_complements(&A, &result);
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

START_TEST(test_s21_calc_complements_3) {
  const int rows = 3;
  const int columns = 3;
  double arr[3][3] = {{1, 0, 0}, {-1, 0, 0}, {3, 4, 6}};
  double res[3][3] = {{0, 6, -4}, {0, 6, -4}, {0, 0, 0}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_calc_complements(&A, &result);
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

START_TEST(test_s21_calc_complements_4) {
  const int rows = 4;
  const int columns = 4;
  double arr[4][4] = {{0.32, -6.25, 15.26, 0.0015},
                      {156.3, -12.3006, 12.00001, 3.0035},
                      {15.0326, -15.26, 591.2, 15},
                      {0.0045, -9.065, 45, 1.32}};
  double res[4][4] = {
      {11347.6686593, -18257.9907413, 17938.6789954, -736969.9283139},
      {2419.2344760, -267.0410284, -160.4589482, 3628.0599943},
      {577.3607564, 3175.8073364, 1290.7820997, -22196.2872009},
      {-12078.4875740, -35460.3525239, -14323.2583811, 540557.0965122}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  matrix_t expected_result = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &expected_result);
  fill_matrix_from_array(&expected_result, *res, rows, columns);

  int result_number = s21_calc_complements(&A, &result);
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

START_TEST(test_s21_calc_complements_5) {
  const int rows = 2;
  const int columns = 3;
  double arr[2][3] = {{0.002, -0.021, 0.313}, {-1.0165, 3.156, 5.0561}};

  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  matrix_t result = {NULL, 0, 0};
  // s21_create_matrix(rows, columns, &result);

  int result_number = s21_calc_complements(&A, &result);
  int expected_result_number = Error_Calculation;
  ck_assert_int_eq(result_number, expected_result_number);

  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

Suite* test_s21_calc_complements() {
  Suite* s = suite_create("s21_calc_complements");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_calc_complements_1);
  tcase_add_test(tc_core, test_s21_calc_complements_2);
  tcase_add_test(tc_core, test_s21_calc_complements_3);
  tcase_add_test(tc_core, test_s21_calc_complements_4);
  tcase_add_test(tc_core, test_s21_calc_complements_5);

  suite_add_tcase(s, tc_core);
  return s;
}