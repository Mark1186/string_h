#include "../s21_sprintf.h"

void find_exponent(double number, int *exponent, int *precision) {
  if (number != 0.0) {
    *exponent = (int)floor(log10(fabs(number)));
  }
  if (*exponent < 0) {
    *precision += abs(*exponent);
  }
}
