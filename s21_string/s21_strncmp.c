#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int cmp = 0;
    for (s21_size_t i = 0; i < n; i++) {
        cmp = str1[i] - str2[i];
        if (cmp != 0) break;
    }
    return cmp;
}

/*

int main(void) {
    char *str1 = "ohaio";
    char *str2 = "oh";

    printf("%d\n", strncmp("ohaio", "oh", 8));
    printf("%d\n", strncmp(str1, str2, 8));

    printf("%d\n", s21_strncmp("ohaio", "oh", 8));
    printf("%d\n", s21_strncmp(str1, str2, 8));
}

*/

