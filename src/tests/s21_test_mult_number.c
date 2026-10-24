#include "test.h"

void test(matrix_t* A, double number, matrix_t* res, matrix_t* exp_res,
          int exp_out_res);

START_TEST(test_s21_mult_number_1) {
  int rows = 3;
  int columns = 3;
  double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double exp_arr[3][3] = {{5, 10, 15}, {20, 25, 30}, {35, 40, 45}};
  double number = 5;

  matrix_t A = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};
  matrix_t exp_res = {NULL, 0, 0};

  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  s21_create_matrix(rows, columns, &exp_res);
  fill_matrix_from_array(&exp_res, *exp_arr, rows, columns);

  test(&A, number, &res, &exp_res, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&exp_res);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  int rows = 3;
  int columns = 3;
  double arr[3][3] = {{0.521, -0.6542, 0.143},
                      {-4.2654, 5.0645, 6.265},
                      {7.1500001, 8.03265, 90.15236}};
  double exp_arr[3][3] = {{6.2705601, -7.8737052, 1.7210942},
                          {-51.3367506, 60.9544177, 75.4031843},
                          {86.054713, 96.6779551, 1085.0399076}};
  double number = 12.035624;

  matrix_t A = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};
  matrix_t exp_res = {NULL, 0, 0};

  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  s21_create_matrix(rows, columns, &exp_res);
  fill_matrix_from_array(&exp_res, *exp_arr, rows, columns);

  test(&A, number, &res, &exp_res, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&exp_res);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  int rows = 3;
  int columns = 1;
  double arr[3][1] = {{1}, {2}, {-3}};
  double exp_arr[3][3] = {{-12.261}, {-24.522}, {-36.783}};
  double number = -12.261;

  matrix_t A = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};
  matrix_t exp_res = {NULL, 0, 0};

  s21_create_matrix(rows, columns, &A);
  fill_matrix_from_array(&A, *arr, rows, columns);

  s21_create_matrix(rows, columns, &exp_res);
  fill_matrix_from_array(&exp_res, *exp_arr, rows, columns);

  test(&A, number, &res, &exp_res, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&exp_res);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};
  matrix_t exp_res = {NULL, 0, 0};

  test(&A, 4, &res, &exp_res, Error_Invalid_Matrix);
}
END_TEST

void test(matrix_t* A, double number, matrix_t* res, matrix_t* exp_res,
          int exp_out_res) {
  int output = s21_mult_number(A, number, res);
  ck_assert_int_eq(output, exp_out_res);
  test_eq_matrix(res, exp_res);
}

Suite* test_s21_mult_number() {
  Suite* s = suite_create("s21_mult_number");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_mult_number_1);
  tcase_add_test(tc_core, test_s21_mult_number_2);
  tcase_add_test(tc_core, test_s21_mult_number_3);
  tcase_add_test(tc_core, test_s21_mult_number_4);

  suite_add_tcase(s, tc_core);
  return s;
}