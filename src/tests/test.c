#include "test.h"

#include <stdio.h>

// int main() {
//   matrix_t A = {0};
//   s21_create_matrix(3, 3, &A);
//   double arr[3][3] = {
//     {1, 2, 3},
//     {1, 5, 6},
//     {7, -8, 9}
//   };
//   fill_matrix_from_array(&A, *arr, 3, 3);
//   // A.matrix[0][0] = 1;
//   // A.matrix[0][1] = 2;
//   // A.matrix[0][2] = 3;
//   // A.matrix[1][0] = 1;
//   // A.matrix[1][1] = 2;
//   // A.matrix[1][2] = 3;
//   // A.matrix[2][0] = 1;
//   // A.matrix[2][1] = 2;
//   // A.matrix[2][2] = 3;
//   print_matrix(A);
//   matrix_t res = {0};
//   s21_inverse_matrix(&A, &res);
//   print_matrix(A);
//   print_matrix(res);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&res);
// }

int main() {
  int count_failed = 0;
  SRunner* sr = srunner_create(NULL);

  srunner_add_suite(sr, test_s21_eq_matrix());
  srunner_add_suite(sr, test_s21_sum_matrix());
  srunner_add_suite(sr, test_s21_sub_matrix());
  srunner_add_suite(sr, test_s21_determinant());
  srunner_add_suite(sr, test_s21_transpose());
  srunner_add_suite(sr, test_s21_inverse_matrix());
  srunner_add_suite(sr, test_s21_calc_complements());
  srunner_add_suite(sr, test_s21_create_matrix());
  srunner_add_suite(sr, test_s21_mult_matrix());
  srunner_add_suite(sr, test_s21_mult_number());

  srunner_run_all(sr, CK_VERBOSE);

  count_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return count_failed;
}