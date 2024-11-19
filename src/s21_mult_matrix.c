#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(B) || null_pointer(result) ||
      non_positive_size(A->rows, A->columns) ||
      non_positive_size(B->rows, B->columns))
    flag = INCORRECT_MATRIX;
  else if (A->columns != B->rows || is_inf_or_nan(A) || is_inf_or_nan(B))
    flag = CALCULATION_ERROR;
  else if (!(flag = s21_create_matrix(A->rows, B->columns, result))) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++)
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }
  return flag;
}