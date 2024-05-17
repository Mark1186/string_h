#ifndef S21_STRING_S21_TEST_H
#define S21_STRING_S21_TEST_H

#include <check.h>

#include "../s21_string.h"

Suite *s21_memchr_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_sprintf_suite(void);
Suite *s21_sscanf_suite(void);

Suite *s21_tolower_suite(void);
Suite *s21_toupper_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

#endif
