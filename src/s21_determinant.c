#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (null_pointer(A) || A->rows <= 0 || A->columns <= 0)
    flag = INCORRECT_MATRIX;
  else if (A->rows != A->columns || is_inf_or_nan(A))
    flag = CALCULATION_ERROR;
  else {
    int sign = 1;
    matrix_t copy;
    if (!(flag = s21_create_matrix(A->rows, A->rows, &copy))) {
      cpy_matrix(A, &copy);
      for (int i = 0; i < copy.rows; i++) {
        if (copy.matrix[i][i] == 0) {
          int swap;
          if (!(swap = find_nonzero_rows(&copy, i, i))) {
            *result = 0;
            break;
          } else {
            swap_rows(&copy, i, swap);
            sign *= -1;
          }
        }
        for (int j = i + 1; j < copy.rows; j++) {
          double mult = copy.matrix[j][i] / copy.matrix[i][i];
          if (mult == 0) continue;
          for (int k = i; k < copy.rows; k++) {
            copy.matrix[j][k] -= mult * copy.matrix[i][k];
          }
        }
      }
      *result = 1;
      for (int i = 0; i < copy.rows; i++) *result *= copy.matrix[i][i];
      *result *= sign;
      s21_remove_matrix(&copy);
    }
  }
  return flag;
}