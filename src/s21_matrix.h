#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_SUCCESS 1
#define S21_FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
void s21_remove_matrix(matrix_t *A);
void s21_fill_sequential(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
void s21_minor(matrix_t *A, matrix_t *matrix_temp, int i_temp, int j_temp);
void s21_process_determinant(matrix_t *temp, double *det, int *sign);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);