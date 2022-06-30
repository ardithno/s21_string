#include "../s21_string.h"
// #include <string.h>
// #include <stdio.h>

char* s21_strchr(const char * string, int symbol) {
    char *res = s21_NULL;
    char *str = (char*)string;
    for (; *str; str++) {
        if (*str == symbol) {
            res = str;
            break;
        }
    }
    if (symbol == '\0') res = str;
    return res;
}

/*
int main() {
    char *str1 = "qwerty";
    printf("%p\n", strchr(str1, 'c'));
    printf("%p\n", s21_strchr(str1, 'c'));
}
*/
