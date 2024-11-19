#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (null_pointer(A) || null_pointer(result) || A->rows <= 0 ||
      A->columns <= 0)
    flag = INCORRECT_MATRIX;
  else if (A->rows != A->columns || is_inf_or_nan(A))
    flag = CALCULATION_ERROR;
  else {
    double det;
    s21_determinant(A, &det);
    if (det) {
      matrix_t minor, transpose;
      s21_calc_complements(A, &minor);
      s21_transpose(&minor, &transpose);
      det = 1 / det;
      s21_mult_number(&transpose, det, result);
      s21_remove_matrix(&minor);
      s21_remove_matrix(&transpose);
    } else
      flag = CALCULATION_ERROR;
  }
  return flag;
}