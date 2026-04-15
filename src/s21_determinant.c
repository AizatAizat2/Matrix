#include "s21_matrix.h"

void s21_process_determinant(matrix_t *temp, double *det, int *sign) {
  int singular = 0;
  for (int k = 0; k < temp->rows && !singular; k++) {
    int max_row = k;
    for (int i = k + 1; i < temp->rows; i++) {
      if (fabs(temp->matrix[i][k]) > fabs(temp->matrix[max_row][k])) {
        max_row = i;
      }
    }

    if (fabs(temp->matrix[max_row][k]) < 1e-12) {
      *det = 0.0;
      singular = 1;
    }

    if (!singular) {
      if (max_row != k) {
        for (int j = 0; j < temp->columns; j++) {
          double tmp = temp->matrix[k][j];
          temp->matrix[k][j] = temp->matrix[max_row][j];
          temp->matrix[max_row][j] = tmp;
        }
        *sign *= -1;
      }

      for (int i = k + 1; i < temp->rows; i++) {
        double factor = temp->matrix[i][k] / temp->matrix[k][k];
        for (int j = k; j < temp->columns; j++) {
          temp->matrix[i][j] -= factor * temp->matrix[k][j];
        }
      }
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int code = 0;
  double det = 1.0;
  int sign = 1;
  matrix_t temp = {0};

  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1 ||
      result == NULL) {
    code = 1;
  } else if (A->rows != A->columns) {
    code = 2;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else if ((code = s21_create_matrix(A->rows, A->columns, &temp)) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        temp.matrix[i][j] = A->matrix[i][j];
      }
    }
    s21_process_determinant(&temp, &det, &sign);
    for (int i = 0; i < temp.rows; i++) det *= temp.matrix[i][i];
    *result = det * sign;
    s21_remove_matrix(&temp);
  }
  return code;
}