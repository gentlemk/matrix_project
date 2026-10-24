#include <math.h>

#include "../helpers.h"
#include "../s21_matrix.h"

static int mult_number(matrix_t* A, double number, matrix_t* result);

/**
 * @brief Умножает матрицу A на число number и записывает результирующую матрицу
 * в result
 * @param A Матрица
 * @param number Число, на которое умножают
 * @param result Матрица куда записывается результат умножения
 * @return Результирующий код
 * @retval 0 - ОК
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL)
    return Error_Invalid_Matrix;
  return mult_number(A, number, result);
}

static int mult_number(matrix_t* A, double number, matrix_t* result) {
  int output = OK;
  output = s21_create_matrix(A->rows, A->columns, result);
  if (output == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return output;
}