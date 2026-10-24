#include "../helpers.h"
#include "../s21_matrix.h"

static int calc_complements(matrix_t* A, matrix_t* result);
static void get_minor(matrix_t* A, matrix_t* temp, int skip_rows,
                      int skip_columns);

/**
 * @brief Функция считает матрицу алгебраических дополнений
 * @param A Матрица
 * @param result Матрица алгебраических дополнений
 * @return int Результирующий код
 * @retval 0 - OK
 * @retval 1 - Ошибка некорректная матрица
 * @retval 2 - Ошибка вычислений
 */
int s21_calc_complements(matrix_t* A, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != A->rows) return Error_Calculation;

  int output = OK;
  output = s21_create_matrix(A->rows, A->columns, result);
  // matrix_t B = {NULL, 0, 0};
  // copy_matrix(A, &B);
  if (output == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      output = calc_complements(A, result);
    }
    // output = calc_complements(&B, result);
  }
  // s21_remove_matrix(&B);
  return output;
}

static int calc_complements(matrix_t* A, matrix_t* result) {
  int output = OK;
  matrix_t temp = {NULL, 0, 0};
  output = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  int sign = 0;
  double determinant = 0;
  for (int i = 0; i < A->rows && output == OK; i++) {
    for (int j = 0; j < A->columns && output == OK; j++) {
      sign = (i + j) % 2 == 0 ? 1 : -1;
      get_minor(A, &temp, i, j);
      determinant = 0;
      output = s21_determinant(&temp, &determinant);
      if (output == OK) {
        result->matrix[i][j] = sign * determinant;
      }
    }
  }
  s21_remove_matrix(&temp);
  return output;
}

static void get_minor(matrix_t* A, matrix_t* temp, int skip_rows,
                      int skip_columns) {
  for (int i = 0, i_temp = 0; i < A->rows; i++) {
    if (i != skip_rows) {
      for (int j = 0, j_temp = 0; j < A->columns; j++) {
        if (j != skip_columns) {
          temp->matrix[i_temp][j_temp] = A->matrix[i][j];
          ++j_temp;
        }
      }
      ++i_temp;
    }
  }
}