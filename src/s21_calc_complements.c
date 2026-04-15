#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = 0;
  double determinant = 0;
  matrix_t matrix_temp = {0};

  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1 ||
      result == NULL) {
    code = 1;
  } else if (A->rows != A->columns) {
    code = 2;
  } else if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    if (code == 0) {
      result->matrix[0][0] = 1;
    }
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &matrix_temp);
    for (int i = 0; i < A->rows && !code; i++) {
      for (int j = 0; j < A->columns && !code; j++) {
        s21_minor(A, &matrix_temp, i, j);
        code = s21_determinant(&matrix_temp, &determinant);
        result->matrix[i][j] = determinant * ((i + j) % 2 == 0 ? 1 : -1);
      }
    }
    s21_remove_matrix(&matrix_temp);
  }

  return code;
}
