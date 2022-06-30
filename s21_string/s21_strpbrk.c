#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

char* s21_strpbrk(const char *str1, const char *str2) {
    char *pt = s21_NULL;
    for (int i = 0; *(str1+i); i++) {
        for (int j = 0; *(str2 + j); j++) {
            if (str1[i] == str2[j]) {
                pt = (char*) str1 + i;
                break;
            }
        }
        if (pt != s21_NULL) break;
    }
    return pt;
}
/*
int main() {
    char str[10] = "equal";
    char chr[10] = "nnn";
    printf("%d\n", strpbrk(str, chr));
    printf("%d\n", s21_strpbrk(str, chr));
   return 0;
}
*/


