#include "../s21_sprintf.h"

void init_num_int(va_list factor, Format_Options *fmt, long *arg_num) {
  if (fmt->length.h) {
    short arg_short = va_arg(factor, int);
    *arg_num = arg_short;
  } else if (fmt->length.l) {
    long arg_long = va_arg(factor, long);
    *arg_num = arg_long;
  } else {
    int arg_int = va_arg(factor, int);
    *arg_num = arg_int;
  }
}
