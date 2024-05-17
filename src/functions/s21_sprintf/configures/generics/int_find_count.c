#include "../../s21_sprintf.h"

int int_find_count(int n) {
  int count = 0;
  if (n < 0) {
    count++;
  }
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}
