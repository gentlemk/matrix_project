#include <stdlib.h>

#include "../s21_matrix.h"

/**
 * @brief Очищает память, выделенную под матрицу
 * @param A Структура матрицы
 */
void s21_remove_matrix(matrix_t* A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
  }
  A->columns = 0;
  A->rows = 0;
  A->matrix = NULL;
}