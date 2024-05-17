#include "../s21_sprintf.h"

void destructor(Resources *res) {
  if (res) {
    if (res->tmp_str) {
      free(res->tmp_str);
      res->tmp_str = NULL;
    }
    if (res->des_str) {
      free(res->des_str);
      res->des_str = NULL;
    }
    if (res->res_str) {
      free(res->res_str);
      res->res_str = NULL;
    }
    free(res);
  }
}
