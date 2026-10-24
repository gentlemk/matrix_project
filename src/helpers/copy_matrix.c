#include "../helpers.h"
#include "../s21_matrix.h"

/**
 * @brief Копирует элементы матрицы A в матрицу result
 * @param A - Матрица из которой копируют
 * @param result - Матрица в которую копируют
 * @return
 */
int copy_matrix(matrix_t* A, matrix_t* result) {
  int output = s21_create_matrix(A->rows, A->columns, result);
  if (output == OK && A != NULL && result != NULL) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j];
      }
    }
  } else {
    output = Error_Invalid_Matrix;
  }
  return output;
}