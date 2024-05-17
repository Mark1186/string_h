#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
    char *result = s21_NULL;
    _Bool is_first_occurrence = FALSE;

    while (*str && !is_first_occurrence) {
        if (*str == c) {
            result = (char *) str;
            is_first_occurrence = TRUE;
        } else {
            str++;
        }
    }

    if (c == '\0'){
        result = (char *) str;
    }

    return result;
}