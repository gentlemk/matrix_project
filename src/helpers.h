#ifndef HELPERS
#define HELPERS

#include "./s21_matrix.h"

void fill_matrix_from_array(matrix_t* matrix, double* array, int rows,
                            int columns);
int copy_matrix(matrix_t* A, matrix_t* result);
// void print_matrix(matrix_t A);

#endif