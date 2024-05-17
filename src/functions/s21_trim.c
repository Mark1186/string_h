#include "../s21_string.h"
#include "s21_sprintf/s21_sprintf.h"

void process_trim_conditions(const char *src, const char *trim_chars,
                             int *found, int *is_break, int start_word,
                             int index_src, int index_trim) {
    if (src[index_src] == trim_chars[index_trim] && !start_word) {
        *found = 1;
        *is_break = 1;
    }
}
void s21_trim_handle(const char *src, const char *trim_chars, char *res, int start_word, int *result_index) {
    for (int i = 0; src[i] != '\0'; ++i) {
        int found = 0;
        int is_break = 0;
        for (int j = 0; (trim_chars[j] != '\0') && !is_break; ++j) {
            process_trim_conditions(src, trim_chars, &found, &is_break, start_word,
                                    i, j);
        }
        if (!found) {
            res[(*result_index)++] = src[i];
            start_word = 1;
        }
    }
    res[*result_index] = '\0';
}
void *s21_trim(const char *src, const char *trim_chars) {
    char *res = s21_NULL;
    char *res2 = s21_NULL;
    if (src && trim_chars) {
        res = (char *) calloc(1024, sizeof(char));
        res2 = (char *) calloc(1024, sizeof(char));
        if (res && res2) {
            char *def = " \n";
            int start_word = 0;
            int result_index = 0;
            if (s21_strlen(trim_chars) > 0) {
                s21_trim_handle(src, trim_chars, res, start_word, &result_index);
            } else {
                s21_trim_handle(src, def, res, start_word, &result_index);
            }
            unsigned long length = s21_strlen(res);
            reverse_string(res, length);

            start_word = 0;
            result_index = 0;
            if (s21_strlen(trim_chars) > 0) {
                s21_trim_handle(res, trim_chars, res2, start_word, &result_index);
            } else {
                s21_trim_handle(res, def, res2, start_word, &result_index);
            }
            length = s21_strlen(res2);
            reverse_string(res2, length);

            free(res);
        }
    }
    return res2;
}
