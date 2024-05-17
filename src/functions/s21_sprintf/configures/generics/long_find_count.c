#include "../../s21_sprintf.h"

int long_find_count(long n) {
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
