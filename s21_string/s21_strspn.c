#include "../s21_string.h"
// #include <string.h>
// #include <stdio.h>

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    int len_str1 = s21_strlen(str1);
    int len_str2 = s21_strlen(str2);
    for (int i = 0; i < len_str1; i++) {
        int avail = 0;
        for (int j = 0; j < len_str2; j++) {
            if (str1[i] == str2[j]) avail++;
        }
        if (avail > 0) res++;
        else if (avail == 0) break;
    }
    return res;
}

/*
int main() {
    char *a = "qwerty";
    char *b = "qwe";
    char *c = "jkl";
    printf("s21_strspn: stroka - \"%s\" + \"%s\"; result - %ld\n", a, b, s21_strspn(a, b));
    printf("s21_strspn: stroka - \"%s\" + \"%s\"; result - %ld\n", a, c, s21_strspn(a, c));
}
*/

