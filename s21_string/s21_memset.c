#include "../s21_string.h"
// #include <string.h>
// #include <stdio.h>

void* s21_memset(void* dest, int c, s21_size_t n) {
    char* str = (char*)dest;
    for (s21_size_t i = 0; i < n; i++) {
        str[i] = c;
    }
    return &str[0];
}

/*
int main() {
    s21_memset(str1, 'w', 5);
    printf("5) memset: %s ", str1);
    memset(str2, 'w', 5);
    printf("%s\n", str2);
}
*/
