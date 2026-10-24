#include "../helpers.h"
#include "../s21_matrix.h"

static int inverse_matrix(matrix_t* A, matrix_t* result);

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  if (result == NULL || A == NULL || A->matrix == NULL)
    return Error_Invalid_Matrix;
  if (A->columns != A->rows) return Error_Calculation;

  return inverse_matrix(A, result);
}

static int inverse_matrix(matrix_t* A, matrix_t* result) {
  int output = OK;
  // s21_create_matrix(A->rows, A->columns, result);
  double determinant = 0;

  matrix_t calc_compl = {0};
  matrix_t trans = {0};

  output = s21_determinant(A, &determinant);
  if (output == OK && determinant == 0) {
    output = Error_Calculation;
  }

  if (output == OK) {
    output = s21_calc_complements(A, &calc_compl);
  }

  if (output == OK) {
    output = s21_transpose(&calc_compl, &trans);
  }

  if (output == OK) {
    output = s21_mult_number(&trans, 1.0 / determinant, result);
  }
  s21_remove_matrix(&calc_compl);
  s21_remove_matrix(&trans);
  return output;
}