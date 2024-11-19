#include "s21_matrix_tests.h"

START_TEST(calc_test1) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, 0);
    ck_assert_double_eq(result.matrix[0][0], 1);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(calc_test2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_test3) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(calc_test4) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (!code1 && !code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(calc_test5) {
  matrix_t A;
  if (!s21_create_matrix(1, 1, &A)) {
    A.matrix[0][0] = 2;
    matrix_t B;
    int res = s21_calc_complements(&A, &B);
    if (!res) ck_assert_double_eq(B.matrix[0][0], 1.);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}
END_TEST

Suite *calc_complements_suite(void) {
  Suite *s = suite_create("calc_test");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, calc_test1);
  tcase_add_test(tc, calc_test2);
  tcase_add_test(tc, calc_test3);
  tcase_add_test(tc, calc_test4);
  tcase_add_test(tc, calc_test5);
  suite_add_tcase(s, tc);

  return s;
}