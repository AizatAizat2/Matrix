#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = 0;

  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    code = 1;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !code; i++) {
      for (int j = 0; j < A->columns && !code; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }

  return code;
}