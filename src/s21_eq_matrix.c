#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = S21_SUCCESS;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    result = S21_FAILURE;
  } else if ((A->columns == B->columns && A->rows == B->rows)) {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
          result = S21_FAILURE;
        }
      }
    }
  } else {
    result = S21_FAILURE;
  }

  return result;
}