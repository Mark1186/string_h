#include "../s21_string.h"
#include "s21_sprintf/s21_sprintf.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *result = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src) + s21_strlen(str))) {
      result = (char *) calloc(1024, sizeof(char));
      int i = 0;
      int index = 0;
      int index_res = 0;
      s21_strncpy(result, src, s21_strlen(src));
      for (; i < (int)start_index; ++i) {
          result[index++] = src[i];
          index_res++;
      }
      for (size_t j = 0; str[j] != '\0'; ++j) {
          result[i++] = str[j];
          index_res++;
      }
      for (size_t j = index; src[j] != '\0'; ++j) {
          result[index_res++] = src[index++];
      }
  }
  return (void *)result;
}
