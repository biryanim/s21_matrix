#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(result) || A->rows <= 0 ||
      A->columns <= 0)
    flag = INCORRECT_MATRIX;
  else if (A->rows != A->columns || is_inf_or_nan(A))
    flag = CALCULATION_ERROR;
  else if (!(flag = s21_create_matrix(A->rows, A->columns, result))) {
    if (A->rows == 1)
      result->matrix[0][0] = 1.;
    else {
      matrix_t det;
      double value;
      s21_create_matrix(A->rows - 1, A->columns - 1, &det);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
          expunge_row_and_column(i, j, A, &det);
          s21_determinant(&det, &value);
          result->matrix[i][j] = value;
        }
      }
      s21_remove_matrix(&det);
      set_signs(result);
    }
  }
  return flag;
}