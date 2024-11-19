#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0

#include "math.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum codeResult { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);  // 1
void s21_remove_matrix(matrix_t *A);                             // 1
int s21_eq_matrix(matrix_t *A, matrix_t *B);                     // 1
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int null_pointer(matrix_t *matrix);
int non_positive_size(int columns, int rows);
int equal_size(const matrix_t *A, const matrix_t *B);
int is_inf_or_nan(const matrix_t *A);
void cpy_matrix(const matrix_t *A, matrix_t *B);
int find_nonzero_rows(const matrix_t *A, int rows, int columns);
void swap_rows(matrix_t *A, int a, int b);
void print_matrix(matrix_t *A);
void expunge_row_and_column(int row, int column, const matrix_t *A,
                            matrix_t *B);
void set_signs(matrix_t *A);
#endif