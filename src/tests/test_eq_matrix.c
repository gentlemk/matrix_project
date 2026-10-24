#include "test.h"

void test_eq_matrix(matrix_t* A, matrix_t* B) {
  ck_assert_int_eq(A->columns, B->columns);
  ck_assert_int_eq(A->rows, B->rows);
  if (A->columns == B->columns && A->rows == B->columns) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        ck_assert_double_eq_tol(A->matrix[i][j], B->matrix[i][j], EPSILON);
      }
    }
  }
}
