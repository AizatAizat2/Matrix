#include <check.h>

#include "s21_matrix.h"

#define S21_OK 0
#define S21_ERROR 1
#define S21_CALC_ERROR 2

START_TEST(test_s21_create_matrix_fail0) {
  printf("\nTesting s21_create_matrix:\n");
  matrix_t A;
  int code = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(code, S21_ERROR);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(0, 1, &A) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_fail1) {
  matrix_t A;
  int code = s21_create_matrix(1, -1, &A);
  ck_assert_int_eq(code, S21_ERROR);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(1, -1, &A) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_fail2) {
  matrix_t A;
  int code = s21_create_matrix(-3, 5, &A);
  ck_assert_int_eq(code, S21_ERROR);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(-3, 5, &A) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_fail3) {
  int code = s21_create_matrix(2, 2, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(2, 2, NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_create_matrix_fail4) {
  int code = s21_create_matrix(0, 0, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(0, 0, NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_create_matrix_ok0) {
  matrix_t A;
  int code = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 1);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(1, 1, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok1) {
  matrix_t A;
  int code = s21_create_matrix(3, 1, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 3);
  ck_assert_int_eq(A.columns, 1);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(3, 1, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok2) {
  matrix_t A;
  int code = s21_create_matrix(1, 4, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 4);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(1, 4, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok3) {
  matrix_t A;
  int code = s21_create_matrix(7, 7, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 7);
  ck_assert_int_eq(A.columns, 7);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(7, 7, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok4) {
  matrix_t A;
  int code = s21_create_matrix(10, 5, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 10);
  ck_assert_int_eq(A.columns, 5);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(10, 5, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok5) {
  matrix_t A;
  int code = s21_create_matrix(50, 50, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 50);
  ck_assert_int_eq(A.columns, 50);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(50, 50, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok6) {
  matrix_t A;
  int code = s21_create_matrix(4, 4, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 4);
  ck_assert_int_eq(A.columns, 4);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(4, 4, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_ok7) {
  matrix_t A;
  int code = s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(A.rows, 5);
  ck_assert_int_eq(A.columns, 5);
  printf("\033[0;32m[PASS]\033[0;0m s21_create_matrix(5, 5, A) - OK\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_remove_matrix0) {
  printf("\nTesting s21_remove_matrix:\n");
  matrix_t A;
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_remove_matrix(5x5) - OK\n");
}
END_TEST

START_TEST(test_s21_remove_matrix1) {
  matrix_t A;
  s21_create_matrix(1, 100, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_remove_matrix(1x100) - OK\n");
}
END_TEST

START_TEST(test_s21_remove_matrix2) {
  matrix_t A;
  s21_create_matrix(50, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_remove_matrix(50x1) - OK\n");
}
END_TEST

START_TEST(test_s21_remove_matrix3) {
  matrix_t A = {0};
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf("\033[0;32m[PASS]\033[0;0m s21_remove_matrix(uninitialized) - OK\n");
}
END_TEST

START_TEST(test_s21_remove_matrix4) {
  matrix_t A;
  s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_remove_matrix(0x0 after failed create) - "
      "OK\n");
}
END_TEST

START_TEST(test_s21_eq_matrix_fail0) {
  printf("\nTesting s21_eq_matrix:\n");
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A, NULL) - FAILURE\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail1) {
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  int code = s21_eq_matrix(NULL, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(NULL, B) - FAILURE\n");
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail2) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(3x3, 3x2) - FAILURE\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail3) {
  matrix_t A, B;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(5, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(1x5, 5x1) - FAILURE\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail4) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  B.matrix[0][0] = 1.00002;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_eq_matrix(2x2 with epsilon diff) - "
      "FAILURE\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail5) {
  matrix_t A, B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  A.matrix[3][3] = -0.000001;
  B.matrix[3][3] = 0.000001;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_eq_matrix(4x4 with sign diff) - "
      "FAILURE\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail6) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[1][1] = 1.000001;
  A.matrix[1][1] = 1.000002;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 != B_3x3) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail7) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[1][1] = 1.000001;
  A.matrix[1][1] = 1.000002;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 != B_3x3) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail8) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[1][1] = 1.000002;
  A.matrix[1][1] = 1.000001;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 != B_3x3) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail9) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[1][1] = 1.000002;
  s21_fill_sequential(&A);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 != B_3x3) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_fail10) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.0000001;
  B.matrix[1][1] = 1.0000002;
  s21_fill_sequential(&A);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_FAILURE);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 != B_3x3) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok0) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_1x1 == B_1x1) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok1) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_2x2 == B_2x2) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok2) {
  matrix_t A, B;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_1x2 == B_1x2) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok3) {
  matrix_t A, B;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_2x1 == B_2x1) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok4) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok5) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&A);
  s21_fill_sequential(&B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok6) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1;
  B.matrix[1][1] = 1;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok7) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.1;
  B.matrix[1][1] = 1.1;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok8) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.11;
  B.matrix[1][1] = 1.11;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok9) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.111;
  B.matrix[1][1] = 1.111;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok10) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.1111;
  B.matrix[1][1] = 1.1111;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok11) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.11111;
  B.matrix[1][1] = 1.11111;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_ok12) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 1.111111;
  B.matrix[1][1] = 1.111111;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, S21_SUCCESS);
  printf("\033[0;32m[PASS]\033[0;0m s21_eq_matrix(A_3x3 == B_3x3) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail0) {
  printf("\nTesting s21_sum_matrix:\n");
  int code = s21_sum_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(NULL, NULL, NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_sum_matrix_fail1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_sum_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A, NULL, NULL) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail2) {
  matrix_t A, B;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  int code = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_sum_matrix(2x3, 3x2, NULL) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail3) {
  matrix_t A, B, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(5, 1, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_sum_matrix(1x5, 5x1) - CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail4) {
  matrix_t A, B, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_sum_matrix(4x4, 3x3) - CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail5) {
  matrix_t B, result;
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(NULL, &B, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(NULL + B_3x3 -> result) - "
      "ERROR\n");
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail6) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_2x2 + B_3x3 -> result) - "
      "CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_fail7) {
  matrix_t A, B, result;
  s21_create_matrix(4, 4, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_4x4 + B_3x3 -> result) - "
      "CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok0) {
  matrix_t A, B, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_1x1 + B_1x1 = result_1x1) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_2x2 + B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok2) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_3x3 + B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(2, 2, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_2x2 + B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok4) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_3x3 + B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok5) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_2x2 + B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok6) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_3x3 + B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok7) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_2x2 + B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_ok8) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sum_matrix(A_3x3 + B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail0) {
  printf("\nTesting s21_sub_matrix:\n");
  int code = s21_sub_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(NULL - NULL -> NULL) - "
      "ERROR\n");
}
END_TEST

START_TEST(test_s21_sub_matrix_fail1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  int code = s21_sub_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - NULL -> NULL) - "
      "ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail2) {
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(NULL, &B, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(NULL - B_3x3 -> NULL) - "
      "ERROR\n");
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail3) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - B_3x3 -> NULL) - "
      "ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail4) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  int code = s21_sub_matrix(&A, NULL, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - NULL -> result) - "
      "ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail5) {
  matrix_t B, result;
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(NULL, &B, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(NULL - B_3x3 -> result) - "
      "ERROR\n");
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail6) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_2x2 - B_3x3 -> result) - "
      "CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_fail7) {
  matrix_t A, B, result;
  s21_create_matrix(4, 4, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_4x4 - B_3x3 -> result) - "
      "CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok0) {
  matrix_t A, B, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_1x1 - B_1x1 = result_1x1) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_2x2 - B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok2) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(2, 2, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_2x2 - B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok4) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok5) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_2x2 - B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok6) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_fill_sequential(&B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok7) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_2x2 - B_2x2 = result_2x2) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_ok8) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_sub_matrix(A_3x3 - B_3x3 = result_3x3) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_fail0) {
  printf("\nTesting s21_mult_number:\n");
  double number = 0;
  int code = s21_mult_number(NULL, number, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(NULL, %lf -> NULL) - ERROR\n",
      number);
}
END_TEST

START_TEST(test_s21_mult_number_fail1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double number = 0;
  int code = s21_mult_number(&A, number, NULL);

  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_mult_number(A, %lf -> NULL) - ERROR\n",
         number);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_fail2) {
  matrix_t result;
  double number = 0;
  int code = s21_mult_number(NULL, number, &result);

  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(NULL, %lf -> result) - "
      "ERROR\n",
      number);
}
END_TEST

START_TEST(test_s21_mult_number_fail3) {
  matrix_t A, result;
  s21_create_matrix(0, 0, &A);
  double number = 0;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_0x0, %lf -> result) - "
      "ERROR\n",
      number);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_ok0) {
  matrix_t A, check, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  double number = 0;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok1) {
  matrix_t A, check, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  double number = 0;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok2) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  double number = 0;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok3) {
  matrix_t A, check, result;
  s21_create_matrix(4, 1, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  double number = 0;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok4) {
  matrix_t A, check, result;
  double number = 2;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 4;
  check.matrix[0][2] = 6;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok5) {
  matrix_t A, check, result;
  double number = 3;
  s21_create_matrix(1, 4, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 3;
  check.matrix[0][1] = 6;
  check.matrix[0][2] = 9;
  check.matrix[0][3] = 12;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok6) {
  matrix_t A, check, result;
  double number = 10;
  s21_create_matrix(1, 4, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 10;
  check.matrix[0][1] = 20;
  check.matrix[0][2] = 30;
  check.matrix[0][3] = 40;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok7) {
  matrix_t A, check, result;
  double number = 2.5;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 2.5;
  check.matrix[0][1] = 5.0;
  check.matrix[0][2] = 7.5;
  check.matrix[0][3] = 10;
  check.matrix[0][4] = 12.5;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_ok8) {
  matrix_t A, check, result;
  double number = 3;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(A.rows, A.columns, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 3;
  check.matrix[0][1] = 6;
  check.matrix[1][0] = 9;
  check.matrix[1][1] = 12;
  int code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_number(A_%dx%d, %lf -> result) - "
      "OK\n",
      A.rows, A.columns, number);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_fail0) {
  printf("\nTesting s21_mult_matrix:\n");
  int code = s21_mult_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(NULL, NULL, NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_mult_matrix_fail1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int code = s21_mult_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(A * NULL -> NULL) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_matrix_fail2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int code = s21_mult_matrix(NULL, &A, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(NULL * A -> NULL) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_matrix_fail3) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(A * B -> NULL) - ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_fail4) {
  matrix_t A, B, result;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(A_%dx%d * B_%dx%d -> result) "
      "- CALC_ERROR\n",
      A.rows, A.columns, B.rows, B.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_fail5) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(1, 3, &B);
  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(A_%dx%d * B_%dx%d -> result) "
      "- CALC_ERROR\n",
      A.rows, A.columns, B.rows, B.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok0) {
  matrix_t A, B, check, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  A.matrix[0][0] = 5.5;
  B.matrix[0][0] = 2.0;
  check.matrix[0][0] = 11.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(1x1 * 1x1) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok1) {
  matrix_t A, B, check, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(2, 1, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  B.matrix[0][0] = 2.0;
  B.matrix[1][0] = 1.0;
  B.matrix[2][0] = 3.0;

  check.matrix[0][0] = 13.0;
  check.matrix[1][0] = 31.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(2x3 * 3x1) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok2) {
  matrix_t A, B, check, result;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 4, &B);
  s21_create_matrix(3, 4, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -1.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 0.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 1.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[0][3] = 4.0;
  B.matrix[1][0] = 5.0;
  B.matrix[1][1] = 6.0;
  B.matrix[1][2] = 7.0;
  B.matrix[1][3] = 8.0;

  check.matrix[0][0] = -4.0;
  check.matrix[0][1] = -4.0;
  check.matrix[0][2] = -4.0;
  check.matrix[0][3] = -4.0;
  check.matrix[1][0] = 2.0;
  check.matrix[1][1] = 4.0;
  check.matrix[1][2] = 6.0;
  check.matrix[1][3] = 8.0;
  check.matrix[2][0] = 8.0;
  check.matrix[2][1] = 12.0;
  check.matrix[2][2] = 16.0;
  check.matrix[2][3] = 20.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(3x2 * 2x4) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok3) {
  matrix_t A, B, check, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &check);

  for (int i = 0; i < 4; i++) {
    A.matrix[i][i] = 1.0;
    B.matrix[i][i] = 1.0;
    check.matrix[i][i] = 1.0;
  }

  A.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  check.matrix[0][0] = 7.0;
  check.matrix[0][1] = 2.0;
  check.matrix[1][0] = 3.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf(
      "\033[0;32m[PASS]\033[0;0m s21_mult_matrix(4x4 modified identity) - "
      "OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok4) {
  matrix_t A, B, check, result;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(1, 1, &check);

  // Fill A (1x3)
  A.matrix[0][0] = 0.5;
  A.matrix[0][1] = 1.5;
  A.matrix[0][2] = 2.5;

  // Fill B (3x1)
  B.matrix[0][0] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[2][0] = 3.0;

  // Expected result (1x1)
  check.matrix[0][0] = 11.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(1x3 * 3x1) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_ok5) {
  matrix_t A, B, check, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  // Fill A (2x2)
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;

  // Fill B (2x2)
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  // Expected result (2x2) - zero matrix
  check.matrix[0][0] = 0.0;
  check.matrix[0][1] = 0.0;
  check.matrix[1][0] = 0.0;
  check.matrix[1][1] = 0.0;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_mult_matrix(zero * non-zero) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_fail0) {
  printf("\nTesting s21_transpose:\n");
  int code = s21_transpose(NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_transpose(NULL, -> NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_transpose_fail1) {
  matrix_t result;
  int code = s21_transpose(NULL, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_transpose(NULL, -> result) - ERROR\n");
}
END_TEST

START_TEST(test_s21_transpose_fail2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_transpose(&A, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> NULL) - ERROR\n",
         A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_fail3) {
  matrix_t A, result;
  s21_create_matrix(0, 0, &A);
  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result) - ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_fail4) {
  matrix_t A, result;
  s21_create_matrix(-1, -1, &A);
  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_-1x-1, -> result) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_ok0) {
  matrix_t A, check, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 1;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok1) {
  matrix_t A, check, result;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 1;
  check.matrix[1][0] = 2;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok2) {
  matrix_t A, check, result;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 1;
  check.matrix[1][0] = 2;
  check.matrix[2][0] = 3;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok3) {
  matrix_t A, check, result;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok4) {
  matrix_t A, check, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  s21_fill_sequential(&A);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok5) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  A.matrix[0][0] = 4;
  A.matrix[0][2] = 31;
  A.matrix[1][0] = 52;
  A.matrix[1][1] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 3;

  check.matrix[0][0] = 4;
  check.matrix[0][1] = 52;
  check.matrix[1][1] = 2;
  check.matrix[1][2] = 3;
  check.matrix[2][0] = 31;
  check.matrix[2][2] = 3;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_ok6) {
  matrix_t A, check, result;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(A.columns, A.rows, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = -3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = -1;

  check.matrix[0][0] = 2;
  check.matrix[0][1] = -3;
  check.matrix[0][2] = 4;
  check.matrix[1][0] = 1;
  check.matrix[1][2] = -1;

  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, S21_OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_transpose(A_%dx%d, -> result_%dx%d) - "
      "OK\n",
      A.rows, A.columns, result.rows, result.columns);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_fail0) {
  printf("\nTesting s21_calc_complements:\n");
  int code = s21_calc_complements(NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(NULL -> NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_calc_complements_fail1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_calc_complements(A -> NULL) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_fail2) {
  matrix_t result;
  int code = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(NULL -> result) - "
      "ERROR\n");
}
END_TEST

START_TEST(test_s21_calc_complements_fail3) {
  matrix_t A, result;
  s21_create_matrix(0, 0, &A);
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(A_%dx%d -> result) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_fail4) {
  matrix_t A, result;
  s21_create_matrix(-1, -1, &A);
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(A_%dx%d -> result) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_fail5) {
  matrix_t A, result;
  s21_create_matrix(1, 2, &A);
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(A_%dx%d -> result) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_fail6) {
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(A_%dx%d -> result) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_ok0) {
  matrix_t A, check, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = -3.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 4.0;

  check.matrix[0][0] = 4.0;
  check.matrix[0][1] = -1.0;
  check.matrix[1][0] = 3.0;
  check.matrix[1][1] = 5.0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_calc_complements(2x2 basic) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_ok1) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = 2.0;
  A.matrix[1][0] = -1.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 1.0;
  A.matrix[2][2] = 4.0;

  check.matrix[0][0] = 12.0;
  check.matrix[0][1] = 4.0;
  check.matrix[0][2] = -7.0;
  check.matrix[1][0] = 2.0;
  check.matrix[1][1] = 0.0;
  check.matrix[1][2] = -1.0;
  check.matrix[2][0] = -6.0;
  check.matrix[2][1] = -2.0;
  check.matrix[2][2] = 3.0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_calc_complements(3x3 basic) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_ok2) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 1.0;
  A.matrix[0][2] = 1.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 2.0;
  A.matrix[1][2] = 1.0;
  A.matrix[2][0] = 1.0;
  A.matrix[2][1] = 1.0;
  A.matrix[2][2] = 2.0;

  check.matrix[0][0] = 3.0;
  check.matrix[0][1] = -1.0;
  check.matrix[0][2] = -1.0;
  check.matrix[1][0] = -1.0;
  check.matrix[1][1] = 3.0;
  check.matrix[1][2] = -1.0;
  check.matrix[2][0] = -1.0;
  check.matrix[2][1] = -1.0;
  check.matrix[2][2] = 3.0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf(
      "\033[0;32m[PASS]\033[0;0m s21_calc_complements(3x3 symmetric) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_ok3) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = (i == j) ? 1.5 : 0.0;
    }
  }

  check.matrix[0][0] = 2.25;
  check.matrix[0][1] = 0.0;
  check.matrix[0][2] = 0.0;
  check.matrix[1][0] = 0.0;
  check.matrix[1][1] = 2.25;
  check.matrix[1][2] = 0.0;
  check.matrix[2][0] = 0.0;
  check.matrix[2][1] = 0.0;
  check.matrix[2][2] = 2.25;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_calc_complements(3x3 diagonal) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_ok4) {
  matrix_t A, check, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);

  A.matrix[0][0] = -5.0;
  check.matrix[0][0] = 1.0;

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_calc_complements(1x1 negative) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_determinant_fail0) {
  printf("\nTesting s21_determinant:\n");
  int code = s21_determinant(NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(NULL -> NULL) - "
      "ERROR\n");
}
END_TEST

START_TEST(test_s21_determinant_fail1) {
  double det = 0;
  int code = s21_determinant(NULL, &det);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(NULL -> det) - "
      "ERROR\n");
}
END_TEST

START_TEST(test_s21_determinant_fail2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_determinant(&A, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_determinant(A -> NULL) - ERROR\n");
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_fail3) {
  matrix_t A;
  s21_create_matrix(0, 0, &A);
  double det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> det) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_fail4) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);
  double det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> det) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_fail5) {
  matrix_t A;
  s21_create_matrix(3, 2, &A);
  double det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> det) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok0) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  double det = 0;
  double check_det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 15.1;
  double det = 0;
  double check_det = 15.1;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_fill_sequential(&A);
  double det = 0;
  double check_det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  double det = 0;
  double check_det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 63;
  A.matrix[1][2] = 12;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  double det = 0;
  double check_det = 39;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok5) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 5;
  A.matrix[0][3] = 5;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 5;
  A.matrix[1][3] = 5;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 5;
  A.matrix[2][3] = 5;
  A.matrix[3][3] = 5;
  double det = 0;
  double check_det = 0;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = -3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = -2;
  A.matrix[2][0] = -7;
  A.matrix[2][1] = 3;
  double det = 0;
  double check_det = -11;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_ok7) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 2;
  double det = 0;
  double check_det = 74;
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq_tol(det, check_det, 1e-7);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_determinant(A_%dx%d -> "
      "%.7lf[%.7lf]) - "
      "OK\n",
      A.rows, A.columns, det, check_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail0) {
  printf("\nTesting s21_inverse_matrix:\n");
  int code = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(NULL -> NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail1) {
  matrix_t result;
  int code = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(NULL -> result) - ERROR\n");
}

END_TEST

START_TEST(test_s21_inverse_matrix_fail2) {
  matrix_t A;
  s21_create_matrix(-1, 2, &A);
  int code = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(code, S21_ERROR);
  printf("\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A -> NULL) - ERROR\n");
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail3) {
  matrix_t A, result;
  s21_create_matrix(0, 0, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A_%dx%d -> result) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail4) {
  matrix_t A, result;
  s21_create_matrix(-1, -1, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A_%dx%d -> result) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail5) {
  matrix_t A, result;
  s21_create_matrix(-4, -2, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A_%dx%d -> result) - "
      "ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail6) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A_%dx%d -> result) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail7) {
  matrix_t A, result;
  s21_create_matrix(3, 1, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(A_%dx%d -> result) - "
      "CALC_ERROR\n",
      A.rows, A.columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_fail8) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &result);

  A.matrix[0][0] = 1.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_CALC_ERROR);

  printf(
      "\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(3x3 det = 0) - "
      "CALC_ERROR\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_ok0) {
  printf("\nTesting s21_inverse_matrix:\n");
  matrix_t A, check, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 4.0;
  A.matrix[0][1] = 3.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 2.0;

  check.matrix[0][0] = -2.0;
  check.matrix[0][1] = 3.0;
  check.matrix[1][0] = 3.0;
  check.matrix[1][1] = -4.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(2x2 basic) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_ok1) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  check.matrix[0][0] = 1.0;
  check.matrix[0][1] = -1.0;
  check.matrix[0][2] = 1.0;
  check.matrix[1][0] = -38.0;
  check.matrix[1][1] = 41.0;
  check.matrix[1][2] = -34.0;
  check.matrix[2][0] = 27.0;
  check.matrix[2][1] = -29.0;
  check.matrix[2][2] = 24.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(3x3 integer) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_ok2) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 0.0;

  check.matrix[0][0] = -24.0;
  check.matrix[0][1] = 18.0;
  check.matrix[0][2] = 5.0;
  check.matrix[1][0] = 20.0;
  check.matrix[1][1] = -15.0;
  check.matrix[1][2] = -4.0;
  check.matrix[2][0] = -5.0;
  check.matrix[2][1] = 4.0;
  check.matrix[2][2] = 1.0;

  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), S21_SUCCESS);

  printf("\033[0;32m[PASS]\033[0;0m s21_inverse_matrix(3x3 with zero) - OK\n");
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_s21_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_create_matrix_fail0);
  tcase_add_test(tc_core, test_s21_create_matrix_fail1);
  tcase_add_test(tc_core, test_s21_create_matrix_fail2);
  tcase_add_test(tc_core, test_s21_create_matrix_fail3);
  tcase_add_test(tc_core, test_s21_create_matrix_fail4);

  tcase_add_test(tc_core, test_s21_create_matrix_ok0);
  tcase_add_test(tc_core, test_s21_create_matrix_ok1);
  tcase_add_test(tc_core, test_s21_create_matrix_ok2);
  tcase_add_test(tc_core, test_s21_create_matrix_ok3);
  tcase_add_test(tc_core, test_s21_create_matrix_ok4);
  tcase_add_test(tc_core, test_s21_create_matrix_ok5);
  tcase_add_test(tc_core, test_s21_create_matrix_ok6);
  tcase_add_test(tc_core, test_s21_create_matrix_ok7);

  tcase_add_test(tc_core, test_s21_remove_matrix0);
  tcase_add_test(tc_core, test_s21_remove_matrix1);
  tcase_add_test(tc_core, test_s21_remove_matrix2);
  tcase_add_test(tc_core, test_s21_remove_matrix3);
  tcase_add_test(tc_core, test_s21_remove_matrix4);

  tcase_add_test(tc_core, test_s21_eq_matrix_fail0);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail1);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail2);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail3);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail4);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail5);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail6);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail7);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail8);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail9);
  tcase_add_test(tc_core, test_s21_eq_matrix_fail10);

  tcase_add_test(tc_core, test_s21_eq_matrix_ok0);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok1);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok2);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok3);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok4);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok5);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok6);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok7);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok8);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok9);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok10);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok11);
  tcase_add_test(tc_core, test_s21_eq_matrix_ok12);

  tcase_add_test(tc_core, test_s21_sum_matrix_fail0);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail1);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail2);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail3);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail4);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail5);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail6);
  tcase_add_test(tc_core, test_s21_sum_matrix_fail7);

  tcase_add_test(tc_core, test_s21_sum_matrix_ok0);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok1);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok2);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok3);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok4);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok5);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok6);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok7);
  tcase_add_test(tc_core, test_s21_sum_matrix_ok8);

  tcase_add_test(tc_core, test_s21_sub_matrix_fail0);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail1);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail2);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail3);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail4);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail5);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail6);
  tcase_add_test(tc_core, test_s21_sub_matrix_fail7);

  tcase_add_test(tc_core, test_s21_sub_matrix_ok0);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok1);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok2);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok3);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok4);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok5);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok6);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok7);
  tcase_add_test(tc_core, test_s21_sub_matrix_ok8);

  tcase_add_test(tc_core, test_s21_mult_number_fail0);
  tcase_add_test(tc_core, test_s21_mult_number_fail1);
  tcase_add_test(tc_core, test_s21_mult_number_fail2);
  tcase_add_test(tc_core, test_s21_mult_number_fail3);

  tcase_add_test(tc_core, test_s21_mult_number_ok0);
  tcase_add_test(tc_core, test_s21_mult_number_ok1);
  tcase_add_test(tc_core, test_s21_mult_number_ok2);
  tcase_add_test(tc_core, test_s21_mult_number_ok3);
  tcase_add_test(tc_core, test_s21_mult_number_ok4);
  tcase_add_test(tc_core, test_s21_mult_number_ok5);
  tcase_add_test(tc_core, test_s21_mult_number_ok6);
  tcase_add_test(tc_core, test_s21_mult_number_ok7);
  tcase_add_test(tc_core, test_s21_mult_number_ok8);

  tcase_add_test(tc_core, test_s21_mult_matrix_fail0);
  tcase_add_test(tc_core, test_s21_mult_matrix_fail1);
  tcase_add_test(tc_core, test_s21_mult_matrix_fail2);
  tcase_add_test(tc_core, test_s21_mult_matrix_fail3);
  tcase_add_test(tc_core, test_s21_mult_matrix_fail4);
  tcase_add_test(tc_core, test_s21_mult_matrix_fail5);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok0);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok1);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok2);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok3);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok4);
  tcase_add_test(tc_core, test_s21_mult_matrix_ok5);

  tcase_add_test(tc_core, test_s21_transpose_fail0);
  tcase_add_test(tc_core, test_s21_transpose_fail1);
  tcase_add_test(tc_core, test_s21_transpose_fail2);
  tcase_add_test(tc_core, test_s21_transpose_fail3);
  tcase_add_test(tc_core, test_s21_transpose_fail4);

  tcase_add_test(tc_core, test_s21_transpose_ok0);
  tcase_add_test(tc_core, test_s21_transpose_ok1);
  tcase_add_test(tc_core, test_s21_transpose_ok2);
  tcase_add_test(tc_core, test_s21_transpose_ok3);
  tcase_add_test(tc_core, test_s21_transpose_ok4);
  tcase_add_test(tc_core, test_s21_transpose_ok5);
  tcase_add_test(tc_core, test_s21_transpose_ok6);

  tcase_add_test(tc_core, test_s21_calc_complements_fail0);
  tcase_add_test(tc_core, test_s21_calc_complements_fail1);
  tcase_add_test(tc_core, test_s21_calc_complements_fail2);
  tcase_add_test(tc_core, test_s21_calc_complements_fail3);
  tcase_add_test(tc_core, test_s21_calc_complements_fail4);
  tcase_add_test(tc_core, test_s21_calc_complements_fail5);
  tcase_add_test(tc_core, test_s21_calc_complements_fail6);

  tcase_add_test(tc_core, test_s21_calc_complements_ok0);
  tcase_add_test(tc_core, test_s21_calc_complements_ok1);
  tcase_add_test(tc_core, test_s21_calc_complements_ok2);
  tcase_add_test(tc_core, test_s21_calc_complements_ok3);
  tcase_add_test(tc_core, test_s21_calc_complements_ok4);

  tcase_add_test(tc_core, test_s21_determinant_fail0);
  tcase_add_test(tc_core, test_s21_determinant_fail1);
  tcase_add_test(tc_core, test_s21_determinant_fail2);
  tcase_add_test(tc_core, test_s21_determinant_fail3);
  tcase_add_test(tc_core, test_s21_determinant_fail4);
  tcase_add_test(tc_core, test_s21_determinant_fail5);

  tcase_add_test(tc_core, test_s21_determinant_ok0);
  tcase_add_test(tc_core, test_s21_determinant_ok1);
  tcase_add_test(tc_core, test_s21_determinant_ok2);
  tcase_add_test(tc_core, test_s21_determinant_ok3);
  tcase_add_test(tc_core, test_s21_determinant_ok4);
  tcase_add_test(tc_core, test_s21_determinant_ok5);
  tcase_add_test(tc_core, test_s21_determinant_ok6);
  tcase_add_test(tc_core, test_s21_determinant_ok7);

  tcase_add_test(tc_core, test_s21_inverse_matrix_fail0);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail2);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail3);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail4);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail5);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail6);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail7);
  tcase_add_test(tc_core, test_s21_inverse_matrix_fail8);

  tcase_add_test(tc_core, test_s21_inverse_matrix_ok0);
  tcase_add_test(tc_core, test_s21_inverse_matrix_ok1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_ok2);

  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite *s = s21_matrix_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}
