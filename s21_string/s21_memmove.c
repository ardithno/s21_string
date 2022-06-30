#include "../s21_string.h"


void* s21_memmove(void *dest, const void *src, s21_size_t count) {

    if (dest < src)
    {
        char *p = (char *)dest;
        char *q = (char *)src;
        while (count--)
        {
            *p++ = *q++;
        }
    }
    else
    {
        char *p = (char *)dest + count;
        char *q = (char *)src + count;
        while (count--)
        {
            *--p = *--q;
        }
    }

    return dest;
}
