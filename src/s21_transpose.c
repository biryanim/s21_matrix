#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(result) ||
      non_positive_size(A->rows, A->columns))
    flag = INCORRECT_MATRIX;
  else if (!(flag = s21_create_matrix(A->columns, A->rows, result))) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  }
  return flag;
}