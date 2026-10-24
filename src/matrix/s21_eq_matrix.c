#include <math.h>

#include "../helpers.h"
#include "../s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

static int is_equal_double_number(double num1, double num2);

/**
 * @brief Сравнивает две матрицы
 * @param A Указатель на первую структуру матрицы
 * @param B Указатель на вторую структуру матрицы
 * @return Результат сравнения
 * @retval 1 - матрицы равны
 * @retval 0 - матрицы не равны
 */
int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int output = A && B && (A->columns == B->columns) && (A->rows == B->rows);
  for (int i = 0; i < A->rows && output; i++) {
    for (int j = 0; j < A->columns && output; j++) {
      if (!is_equal_double_number(A->matrix[i][j], B->matrix[i][j])) {
        output = FAILURE;
      }
    }
  }
  return output;
}

static int is_equal_double_number(double num1, double num2) {
  return fabs(num1 - num2) <= EPSILON;
}