#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <limits.h>

#include "../helpers.h"
#include "../s21_matrix.h"

Suite* test_s21_eq_matrix();
Suite* test_s21_sum_matrix();
Suite* test_s21_sub_matrix();
Suite* test_s21_determinant();
Suite* test_s21_transpose();
Suite* test_s21_inverse_matrix();
Suite* test_s21_create_matrix();
Suite* test_s21_mult_matrix();
Suite* test_s21_mult_number();
Suite* test_s21_calc_complements();

void test_eq_matrix(matrix_t* A, matrix_t* B);

#endif