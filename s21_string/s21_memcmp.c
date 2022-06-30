#include "../s21_string.h"

int s21_memcmp(const void* buf1, const void* buf2, s21_size_t count) {
    int a;
    if (!count)
         a = 0;

    while(--count && *(char*)buf1 == *(char*)buf2 ) {
        // if (a == 0) {
        //     break;
        // }
        buf1 = (char*)buf1 + 1;
        buf2 = (char*)buf2 + 1;
    }
    if (a!=0) {
        a = (*((unsigned char*)buf1) - *((unsigned char*)buf2));
    }
    return a;
//     return(*((unsigned char*)buf1) - *((unsigned char*)buf2));
}

