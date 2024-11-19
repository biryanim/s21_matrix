#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(result) ||
      non_positive_size(A->columns, A->rows))
    flag = INCORRECT_MATRIX;
  else if (isnan(number) || isinf(number) || is_inf_or_nan(A))
    flag = CALCULATION_ERROR;
  else if (!(flag = s21_create_matrix(A->rows, A->columns, result))) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
  }
  return flag;
}