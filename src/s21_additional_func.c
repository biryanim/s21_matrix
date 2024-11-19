#include "s21_matrix.h"

int null_pointer(matrix_t *matrix) { return matrix == NULL; }

int non_positive_size(int columns, int rows) {
  return (columns <= 0 || rows <= 0);
}

int equal_size(const matrix_t *A, const matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int is_inf_or_nan(const matrix_t *A) {
  int flag = 0;
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        flag = 1;
        j = A->columns;
        i = A->rows;
      }
  return flag;
}

void cpy_matrix(const matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) B->matrix[i][j] = A->matrix[i][j];
}

int find_nonzero_rows(const matrix_t *A, int rows, int columns) {
  int res = 0;
  for (int i = rows; i < A->rows; i++)
    if (A->matrix[i][columns] != 0) {
      res = i;
      break;
    }
  return res;
}

void swap_rows(matrix_t *A, int a, int b) {
  double *tmp = A->matrix[a];
  A->matrix[a] = A->matrix[b];
  A->matrix[b] = tmp;
}

void expunge_row_and_column(int row, int column, const matrix_t *A,
                            matrix_t *B) {
  for (int i = 0, m = 0; i < A->rows; i++)
    for (int j = 0, n = 0; j < A->columns; j++)
      if (i != row && j != column) {
        B->matrix[m][n] = A->matrix[i][j];
        n++;
        if (n >= B->columns) {
          n = 0;
          m++;
        }
      }
}

void set_signs(matrix_t *A) {
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      A->matrix[i][j] *= ((i + j) % 2 == 0) ? 1 : -1;
}