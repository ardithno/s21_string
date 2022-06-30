#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

int s21_strcmp(const char *str1, const char *str2) {
    int cmp = 0;
    for (; *str1 || *str2; str1++, str2++) {
        cmp = *str1 - *str2;
        if (cmp != 0) break;
    }
    return cmp;
}
/*

int main(void) {
// Результат такой подачи аргументов:
printf("%d\n", strcmp("ohaio", "i")); // Вернёт 1
// Отличается от результата такой:
char str1[6] = "ohaio";
char str2[2] = "i";
printf("%d\n", strcmp(str1, str2)); // Вернёт 6

printf("%d\n", s21_strcmp("ohaio", "i")); // Вернёт 1
printf("%d\n", s21_strcmp(str1, str2)); // Вернёт 6
}

*/