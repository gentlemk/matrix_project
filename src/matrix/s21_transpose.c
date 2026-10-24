#include "../helpers.h"
#include "../s21_matrix.h"

static int transpose(matrix_t* A, matrix_t* result);

/**
 * @brief Транспонирует матрицу
 * Строки становятся столбцами, а столбцы строками
 * @param A Указатель на матрицу для транспонирования
 * @param result Указатель на транспонированную матрицу
 * @return Результирующий код
 * @retval 0 - OK
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_transpose(matrix_t* A, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL)
    return Error_Invalid_Matrix;
  return transpose(A, result);
}

static int transpose(matrix_t* A, matrix_t* result) {
  int output = OK;
  matrix_t temp = {NULL, 0, 0};
  output = s21_create_matrix(A->columns, A->rows, &temp);

  if (output == OK) {
    for (int i = 0; i < temp.rows; i++) {
      for (int j = 0; j < temp.columns; j++) {
        temp.matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  output = s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = temp.matrix[i][j];
    }
  }
  s21_remove_matrix(&temp);
  return output;
}