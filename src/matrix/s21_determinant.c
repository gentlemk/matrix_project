#include <math.h>

#include "../helpers.h"
#include "../s21_matrix.h"

static int determinant(matrix_t* A, double* result);
static void swap_rows(matrix_t* A, int rows_1, int rows_2, double* result);
static void div_row_of_number(matrix_t* A, int row, double* result,
                              double number);
static void subtract_row_from_row(matrix_t* A, int row1, int row2,
                                  double number);

/**
 * @brief Функция вычисляет определитель квадратной матрицы
 * @param A Указатель на матрицу
 * @param result Указатель куда записать значение определителя
 * @return Результирующий код
 * @retval 0 - OK
 * @retval 1 - Ошибка, некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_determinant(matrix_t* A, double* result) {
  if (result == NULL || A == NULL || A->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != A->rows) return Error_Calculation;

  int output = OK;
  *result = 1;
  matrix_t B = {NULL, 0, 0};
  int a = copy_matrix(A, &B);
  if (a == OK) output = determinant(&B, result);
  s21_remove_matrix(&B);

  return output;
}

static int determinant(matrix_t* A, double* result) {
  int output = OK;
  for (int i = 0; i < A->rows && *result != 0; i++) {
    int max = i;
    if (fabs(A->matrix[i][i]) < EPSILON) {
      for (int j = i; j < A->columns; j++) {
        if (fabs(A->matrix[j][i]) > fabs(A->matrix[max][i])) {
          max = j;
        }
      }
    }

    if (fabs(A->matrix[i][max]) < EPSILON) {
      *result = 0;
    } else {
      if (max != i) {
        swap_rows(A, i, max, result);
      }

      div_row_of_number(A, i, result, A->matrix[i][i]);
      for (int n = i + 1; n < A->rows; n++) {
        double num = A->matrix[n][i];
        subtract_row_from_row(A, n, i, num);
      }
    }
  }
  return output;
}

/// @brief Делит строку на число
/// @param A Структура матрицы
/// @param row Строка матрицы, которую делят
/// @param result Определитель матрицы
/// @param number Число, на которое делят
static void div_row_of_number(matrix_t* A, int row, double* result,
                              double number) {
  for (int i = 0; i < A->columns; i++) {
    A->matrix[row][i] /= number;
  }
  *result *= number;
}

/// @brief Вычитает из строки под индексом row1 строку под индексом row2
/// домноженную на число number
/// @param A Матрица
/// @param row1 Строка из которой вычитают
/// @param row2 Строка которую вычитают
/// @param number Число на которое домножают
static void subtract_row_from_row(matrix_t* A, int row1, int row2,
                                  double number) {
  for (int i = 0; i < A->columns; i++) {
    A->matrix[row1][i] = A->matrix[row1][i] - number * A->matrix[row2][i];
  }
}

/// @brief Меняет две строки в матрице местами
/// @param A - исходная матрица
/// @param rows_1 - Первая строка
/// @param rows_2 - Вторая строка
/// @param result - определитель матрицы, который умножается на -1 при смене
/// строк местами
static void swap_rows(matrix_t* A, int rows_1, int rows_2, double* result) {
  for (int i = 0; i < A->columns; i++) {
    double t = A->matrix[rows_1][i];
    A->matrix[rows_1][i] = A->matrix[rows_2][i];
    A->matrix[rows_2][i] = t;
  }
  *result *= -1;
}