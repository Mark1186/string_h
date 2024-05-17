#include "../s21_string.h"

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