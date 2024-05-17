#include "../../s21_sprintf.h"

int uint_find_count(unsigned int n) {
  int count = 0;

  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}
