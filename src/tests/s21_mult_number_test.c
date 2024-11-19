#include "s21_matrix_tests.h"

START_TEST(mult_number_matrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(-10e5, 10e5);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix3) {
  matrix_t m;
  int code = s21_create_matrix(2, 3, &m);
  if (!code) {
    matrix_t res;
    double value = INFINITY;
    int flag = s21_mult_number(&m, value, &res);
    ck_assert_int_eq(flag, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(mult_number_matrix4) {
  matrix_t m;
  int code = s21_create_matrix(2, 3, &m);
  if (!code) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 1;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 2;
    m.matrix[1][1] = -INFINITY;
    m.matrix[1][2] = 3;
    matrix_t res;
    double value = 5;
    int flag = s21_mult_number(&m, value, &res);
    ck_assert_int_eq(flag, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s = suite_create("mult_number_test");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, mult_number_matrix1);
  tcase_add_test(tc, mult_number_matrix2);
  tcase_add_test(tc, mult_number_matrix3);
  tcase_add_test(tc, mult_number_matrix4);

  suite_add_tcase(s, tc);

  return s;
}