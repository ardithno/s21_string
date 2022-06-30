#include "../s21_string.h"

void* s21_memcpy(void *dest, const void *src, s21_size_t count) {

    //char *a;
    char *p = (char *)dest;
    char *q = (char *)src;
    // if (p == q)
    //     a = p;

    while (count--)
    {
        *p++ = *q++;
    }
    // if (a != p) {
    //     a = dest;
    // }
    
    return dest;
}