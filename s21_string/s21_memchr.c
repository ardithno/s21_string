#include "../s21_string.h"

void* s21_memchr(const void *str, int c, s21_size_t n) {
    char *res = s21_NULL;
    int count = 0;
    char *str2 = (char*)str;
    while (str2[count] != (char)c && (n-1 >= (s21_size_t)count)) {
        count+=1;
    }
    if ((s21_size_t)count > n-1) {
        res = s21_NULL;
    }
    else {res = &str2[count];}
    return res;
}

