#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_NULL ((void*)0)

void *s21_trim(const char *src, const char *trim_chars);
void reverse_string(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    str[length] = '\0';
}
char *s21_strstr(const char *haystack, const char *needle);

int main() {
    char test_5[] = "Null";
    char test_6[] = "";
    char test_7[] = "aaaaa123aaa1234aaa";
    char test_8[] = "34";

    printf("s21 = %s\n", s21_strstr(test_5, test_6));
    printf("    = %s\n", strstr(test_5, test_6));

    printf("s21 = %s\n", s21_strstr(test_7, test_8));
    printf("    = %s\n", strstr(test_7, test_8));

    return 0;
}

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
            if (strlen(trim_chars) > 0) {
                s21_trim_handle(src, trim_chars, res, start_word, &result_index);
            } else {
                s21_trim_handle(src, def, res, start_word, &result_index);
            }
            reverse_string(res);

            start_word = 0;
            result_index = 0;
            if (strlen(trim_chars) > 0) {
                s21_trim_handle(res, trim_chars, res2, start_word, &result_index);
            } else {
                s21_trim_handle(res, def, res2, start_word, &result_index);
            }
            reverse_string(res2);

            free(res);
        }
    }
    return res2;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *result = NULL;
    int is_first_occurrence = 0;
    while (*haystack != '\0' && !is_first_occurrence) {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            result = (char *)haystack;
            is_first_occurrence = 1;
        } else {
            haystack++;
        }
    }

    return result;
}