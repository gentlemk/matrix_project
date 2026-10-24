#include "../helpers.h"
#include "../s21_matrix.h"

static int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);

/**
 * @brief Вычитает из матрицы A матрицу B по принципу A[i][j] - B[i][j]
 * @param A Первая матрица уменьшаемое
 * @param B Вторая матрица вычитаемое
 * @param result Указатель для результирующей матрицы
 * @return Результирующий код
 * @retval 0 - ОК
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL || B == NULL ||
      B->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != B->columns || A->rows != B->rows) return Error_Calculation;
  return sub_matrix(A, B, result);
}

static int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int output = OK;
  output = s21_create_matrix(A->rows, A->columns, result);

  if (output == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return output;
}
