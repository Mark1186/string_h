#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>

#include "../../s21_string.h"

#define convert_to_string(value, result)   \
  _Generic((value), int                    \
           : int_to_string, unsigned int   \
           : uint_to_string, short         \
           : short_to_string, long         \
           : long_to_string, unsigned long \
           : ul_to_string)((value), (result))

#define convert_double_to_string(value, result, precision) \
  _Generic((value), double                                 \
           : double_to_string, long double                 \
           : ldouble_to_string)((value), (result), (precision))

#define find_count(value)                          \
  _Generic((value), int                            \
           : int_find_count(value), unsigned int   \
           : uint_find_count(value), short         \
           : short_find_count(value), long         \
           : long_find_count(value), unsigned long \
           : ul_find_count(value))

#define PANIC(...)                                                 \
  do {                                                             \
    if (__VA_ARGS__ == NULL) {                                     \
      fprintf(stderr, "%s's variable -> memory allocator is NULL", \
              #__VA_ARGS__);                                       \
    }                                                              \
  } while (0)

typedef struct {
  char minus;
  char plus;
  char space;
  char zero;
  char hashtag;
} Flag;
typedef struct {
  int enable;
  int number;
  int star;
} Width;
typedef struct {
  int dot_enable;
  int dot_number;
  int dot_star;
} Precision;
typedef struct {
  char h;
  char l;
  char L;
} Length;
typedef struct {
  char name;
  Flag flag;
  Width width;
  Precision precision;
  Length length;
} Format_Options;
typedef struct {
  char *tmp_str;
  char *des_str;
  char *res_str;
} Resources;

Resources *constructor();
void destructor(Resources *res);

int int_find_count(int n);
int uint_find_count(unsigned int n);
int long_find_count(long n);
int ul_find_count(unsigned long n);

int short_find_count(short n);
void int_to_string(int num, char *des_str);
void uint_to_string(unsigned int num, char *des_str);
void long_to_string(long num, char *des_str);
void ul_to_string(unsigned long num, char *des_str);
void short_to_string(short num, char *des_str);
void reverse_string(char *str, unsigned long length);
void double_to_string(double number, char *result, int precision);

void ldouble_to_string(long double number, char *result, int precision);
void convert_dec_to_oct(char *des_str, unsigned int num);

void convert_dec_to_hex_ulong(char *des_str, unsigned long num,
                              Format_Options *fmt);

void del_symbol_in_string(char *des_str, char ch);
void writing_numbers(char *des_str, int *index_str, int index, int *is_break);
void round_string_of_math_rules(char *tmp_str, char *des_str);
void insert_symbol_in_string(char *des_str, char ch, int index);
void rounded(char *des_str, Format_Options *fmt);
void del_zero_startstr(char *des_str);
void del_zero_endstr(char *des_str);
void output_zero_e(char *des_str, char name, int precision);
void find_exponent(double number, int *exponent, int *precision);
void configure_precision(int *precision, int exponent, Format_Options *fmt);
void modify_and_concatenate_string(Resources *res, char *des_str, char ch,
                                   int exponent);

void custom_plus(char *des_str, const int is_neg, const Format_Options *fmt);
void custom_width(char *des_str, const int is_neg, const Format_Options *fmt);
void custom_precision(char *des_str, const Format_Options *fmt);
void custom_format_e(char *des_str, double number, Format_Options *fmt,
                     int precision);
void custom_format_g(char *des_str, Format_Options *fmt, double number,
                     int exponent, int precision, int is_neg);
void set_index_format(Format_Options *fmt, int *index_format);
void init_num_int(va_list factor, Format_Options *fmt, long *arg_num);
void init_num_ulong(va_list factor, Format_Options *fmt,
                    unsigned long *arg_num);
void representation_of_num_in_hex(char *tmp_str, uintptr_t *arg_p, int length);
void count_of_hex_digits(uintptr_t num, int *length);

void specifier_e(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_f(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_g(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_n(char *p_str, va_list factor, int *index_format);
void specifier_c(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_d(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_o(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_u(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_s(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_x(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);
void specifier_p(char *p_str, va_list factor, Format_Options *fmt,
                 int *index_str, int *index_format);

void init_format_options(Format_Options *fmt);
void flag_handling(char **ch, Format_Options *fmt, int *index_format);
void width_processing(char **ch, va_list factor, Format_Options *fmt,
                      int *index_format);
void precision_processing(char **ch, va_list factor, Format_Options *fmt,
                          int *index_format);
void length_processing(char **ch, Format_Options *fmt, int *index_format);
void processing_of_specifiers(const char *ch, Format_Options *fmt, char *p_str,
                              const char *format, va_list factor,
                              int *index_str, int *index_format);

#endif