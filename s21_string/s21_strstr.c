#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

char* s21_strstr(const char *haystack, const char *needle) {
    char *res = s21_NULL;
    int pt = 0;
        for (int i = 0; *(haystack + i); i++) {
            if (haystack[i] == needle[0]) {
                pt = 1;
                for (int j = 0; *(needle + j); j++) {
                    if (haystack[i + j] != needle[j]) pt = 0;
                }
                if (pt != 0) {
                    res = (char*)haystack + i;
                }
            }
            if (res != s21_NULL) break;
        }
        if (*needle == '\0') {
            res = (char*)haystack;
    }
    return res;
}
/*
int main() {
    char *str1 = "q";
    char *str2 = "";
    printf("%s\n", s21_strstr(str1, str2));
    printf("%s\n", strstr(str1, str2));
    // printf("%s\n", s21_strstr("ohaio", "ha"));
}
*/
