#include <stdio.h>

#include "../s21_matrix.h"
#include "s21_matrix_tests.h"

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}

int main(void) {
  int failed = 0;
  Suite *s21_matrix_test[] = {create_matrix_suite(),
                              eq_matrix_suite(),
                              sum_matrix_suite(),
                              sub_matrix_suite(),
                              mult_number_suite(),
                              mult_matrix_suite(),
                              transpose_suite(),
                              calc_complements_suite(),
                              determinant_suite(),
                              inverse_matrix_suite(),
                              NULL};
  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
