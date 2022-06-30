#include "s21_sprintf.h"

char* s21_putchar(const char *dest, char c) {
    char *save = (char *)dest;
    while (*save) {
        save++;
    }
    *save++ = c;
    *save = '\0';
    
    return (char *)dest;
}