#include "../../s21_sprintf.h"

int ul_find_count(unsigned long n) {
  int count = 0;

  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}
