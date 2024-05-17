#include "../s21_sprintf.h"

void init_num_ulong(va_list factor, Format_Options *fmt,
                    unsigned long *arg_num) {
  if (fmt->length.h) {
    unsigned short arg_short = va_arg(factor, int);
    *arg_num = arg_short;
  } else if (fmt->length.l) {
    unsigned long arg_ulong = va_arg(factor, long);
    *arg_num = arg_ulong;
  } else {
    unsigned int arg_uint = va_arg(factor, int);
    *arg_num = arg_uint;
  }
}
