#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(B) || null_pointer(result) ||
      non_positive_size(A->columns, A->rows) ||
      non_positive_size(B->columns, B->rows))
    flag = INCORRECT_MATRIX;
  else if (equal_size(A, B) || is_inf_or_nan(A) || is_inf_or_nan(B))
    flag = CALCULATION_ERROR;
  else if (!(flag = s21_create_matrix(A->rows, A->columns, result))) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return flag;
}