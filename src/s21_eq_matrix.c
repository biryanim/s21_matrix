#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (null_pointer(A) || null_pointer(B) || equal_size(A, B)) {
    flag = FAILURE;
  } else if (A->rows <= 0 || A->columns <= 0)
    flag = FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          flag = FAILURE;
          j = A->columns;
          i = A->rows;
        }
      }
    }
  }
  return flag;
}