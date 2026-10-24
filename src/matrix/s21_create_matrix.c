#include <stdlib.h>

#include "../helpers.h"
#include "../s21_matrix.h"

static int init_matrix(int rows, int columns, matrix_t* result);

/**
 * @brief Инициализирует матрицу с нужным количеством строк и столбцов
 * @param rows количество строк в матрице
 * @param columns количество столбцов в матрице
 * @param result указатель куда нужно записать матрицу
 * @return Результирующий код
 * @retval 0 - OK
 * @retval 1 - Ошибка, некорректная матрица
 * @retval 2 - Ошибка вычислений (Несовпадающие размеры; матрица, для которой
 * нельзя провести вычисления)
 */
int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int output = OK;
  if (rows > 0 && columns > 0 && result != NULL) {
    output = init_matrix(rows, columns, result);
  } else {
    output = Error_Invalid_Matrix;
  }
  return output;
}

/**
 * Вспомогательная функция для выделения памяти для матрицы
 * @param rows количество строк в матрице
 * @param columns количество столбцов в матрице
 * @param result указатель куда нужно записать матрицу
 * @return Результирующий код
 * @retval 0 - OK
 * @retval 1 - Ошибка, некорректная матрица
 * @retval 2 - Ошибка вычислений (Несовпадающие размеры; матрица, для которой
 * нельзя провести вычисления)
 */
static int init_matrix(int rows, int columns, matrix_t* result) {
  int output = OK;

  result->columns = columns;
  result->rows = rows;

  result->matrix = (double**)calloc(rows, sizeof(double*));
  if (result->matrix != NULL) {
    for (int i = 0; i < rows && output == OK; i++) {
      result->matrix[i] = (double*)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        output = Error_Invalid_Matrix;
      }
    }
  } else {
    output = Error_Invalid_Matrix;
  }
  return output;
}
