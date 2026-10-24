#include "../helpers.h"
#include "../s21_matrix.h"

static int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);

/**
 * @brief Умножает матрицу A на матрицу B.
 * Количество строк первой матрицы должно быть равно количество столбцов второй
 * матрицы
 * @param A Первая матрица
 * @param B Вторая матрица
 * @param result Результат произведения
 * @return Результирующий код
 * @retval 0 - ОК
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL || B == NULL ||
      B->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != B->rows) return Error_Calculation;

  return mult_matrix(A, B, result);
}

static int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int output = s21_create_matrix(A->rows, B->columns, result);
  if (output == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return output;
}