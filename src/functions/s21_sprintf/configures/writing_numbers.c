#include "../s21_sprintf.h"

void writing_numbers(char *des_str, int *index_str, int index, int *is_break) {
  int digit = des_str[index - 1] - '0';
  if (digit < 9) {
    des_str[*index_str - 1] = ++digit + '0';
    *is_break = 1;
  } else {
    des_str[*index_str - 1] = '0';
  }
}