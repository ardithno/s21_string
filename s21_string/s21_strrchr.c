#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

char *s21_strrchr(const char *str, int c) {
    char *pt = s21_NULL;
    do {
        if (*str == c) {
            pt = (char*)str;
        }
    } while (*str++ != '\0');
    /*
    for (; *str == '\0'; str++) {
        if (*str == c) {
            pt = (char*)str;
        }
    }
    */
    return pt;
}
/*
int main() {
    char str[10] = "ohaio";
    char chr = 'f';
    char *test_pt = s21_strrchr(str, chr);
    printf("%d\n", test_pt - str + 1);
    printf("%d\n", strrchr(str, chr) - str + 1);
    
   return 0;
}
*/
