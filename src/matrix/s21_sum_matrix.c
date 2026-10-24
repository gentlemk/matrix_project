#include "../helpers.h"
#include "../s21_matrix.h"

static int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);

/**
 * @brief Складывает две матрицы по принципу A[i][j] + B[i][j]
 * @param A Первая матрица слагаемое
 * @param B Вторая матрица слагаемое
 * @param result Указатель для результирующей матрицы
 * @return Результирующий код
 * @retval 0 - ОК
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL || B == NULL ||
      B->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != B->columns || A->rows != B->rows) return Error_Calculation;
  return sum_matrix(A, B, result);
}

static int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int output = OK;
  output = s21_create_matrix(A->rows, A->columns, result);

  if (output == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return output;
}
