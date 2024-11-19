#ifndef S21_MATRIX_TESTS_H
#define S21_MATRIX_TESTS_H

#include <check.h>
#include <float.h>
#include <time.h>

#include "../s21_matrix.h"

Suite *create_matrix_suite(void);
Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_suite(void);
Suite *calc_complements_suite(void);
Suite *determinant_suite(void);
Suite *inverse_matrix_suite(void);

double get_rand(double min, double max);

#endif