#include "s21_sprintf/s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  Format_Options fmt;
  char *p_str = (char *)calloc(1024, sizeof(char));
  PANIC(p_str);

  va_list factor;
  va_start(factor, format);

  int index_str = 0;
  int index_format = 0;

  for (char *ch = (char *)format; *ch; ++ch) {
    if (*ch != '%') {
      p_str[index_str++] = format[index_format++];
    } else {
      ch++;

      init_format_options(&fmt);
      int error =
          strncmp(format, "Unknown error %d", strlen("Unknown error %d"));
      if (error == 0) {
        fmt.name = 'R';
      }
      flag_handling(&ch, &fmt, &index_format);
      width_processing(&ch, factor, &fmt, &index_format);
      precision_processing(&ch, factor, &fmt, &index_format);
      length_processing(&ch, &fmt, &index_format);
      processing_of_specifiers(ch, &fmt, p_str, format, factor, &index_str,
                               &index_format);
    }
  }
  va_end(factor);
  p_str[index_str] = '\0';

  int length = 0;
  while (p_str[length++] != '\0');
  
  s21_memset(str, 0, length);

  s21_strncpy(str, p_str, s21_strlen(p_str));
  free(p_str);
  return index_str;
}
