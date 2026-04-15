#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = 0;
  if (result == NULL) {
    code = 1;
  } else if (columns < 1 || rows < 1) {
    code = 1;
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
  } else {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      code = 1;
    }
    for (int i = 0; i < rows && !code; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        code = 1;
      }
    }
  }

  return code;
}