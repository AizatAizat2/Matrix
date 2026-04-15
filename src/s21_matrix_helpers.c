#include "s21_matrix.h"

void s21_fill_sequential(matrix_t *A) {
  int k = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = k++;
    }
  }
}

void s21_minor(matrix_t *A, matrix_t *minor, int skip_row, int skip_col) {
  int minor_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != skip_row) {
      int minor_j = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != skip_col) {
          minor->matrix[minor_i][minor_j] = A->matrix[i][j];
          minor_j++;
        }
      }
      minor_i++;
    }
  }
}
