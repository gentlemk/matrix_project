#include "../helpers.h"
#include "../s21_matrix.h"

/**
 * @brief Заполняет структуру матрицы числами из массива array
 * @param matrix Матрица для заполнения
 * @param array Массив, числами которого нужно заполнить матрицу
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 * @return Результирующий код
 * @retval 1 - успешно
 * @retval 0 - не успешно
 */
void fill_matrix_from_array(matrix_t* matrix, double* array, int rows,
                            int columns) {
  rows = rows;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = array[i * columns + j];
    }
  }
}