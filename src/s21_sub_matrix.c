#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 0;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1 ||
      B == NULL || B->matrix == NULL || B->rows < 1 || B->columns < 1) {
    code = 1;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    code = 2;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && !code; i++) {
      for (int j = 0; j < A->columns && !code; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return code;
}
