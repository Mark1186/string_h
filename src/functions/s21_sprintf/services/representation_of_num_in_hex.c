#include "../s21_sprintf.h"

void representation_of_num_in_hex(char *tmp_str, uintptr_t *arg_p, int length) {
  for (int i = length - 1; i >= 0; i--) {
    int digit = *arg_p % 16;
    tmp_str[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    *arg_p /= 16;
  }
  tmp_str[length + 2] = '\0';
}
