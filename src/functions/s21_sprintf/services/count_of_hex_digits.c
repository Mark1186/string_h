#include "../s21_sprintf.h"

void count_of_hex_digits(uintptr_t num, int *length) {
  while (num > 0) {
    num /= 16;
    (*length)++;
  }
}
