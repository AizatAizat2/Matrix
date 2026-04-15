#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = 0;

  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    code = 1;
  } else {
    code = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns && !code; i++) {
      for (int j = 0; j < A->rows && !code; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return code;
}