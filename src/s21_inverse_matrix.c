#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det = 0;
  int code = s21_determinant(A, &det);
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1 ||
      result == NULL) {
    code = 1;
  } else if (A->rows != A->columns) {
    code = 2;
  } else if (det == 0) {
    code = 2;
  } else if (code == 0) {
    matrix_t M = {0};
    matrix_t MT = {0};
    s21_calc_complements(A, &M);
    s21_transpose(&M, &MT);
    s21_mult_number(&MT, (double)1 / det, result);
    s21_remove_matrix(&M);
    s21_remove_matrix(&MT);
  }
  return code;
}