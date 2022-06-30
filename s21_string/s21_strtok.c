#include "../s21_string.h"

char* s21_strtok(char *str, const char *delim) {
    char *result = s21_NULL;

    static char *last = s21_NULL;

    if (str != s21_NULL || last != s21_NULL) {
        char *currentStr = str;
        if (last != s21_NULL)
            currentStr = last;

        char *currentDelim = s21_NULL;
        char *tok = s21_NULL;

        while (*currentStr != '\0') {
            s21_size_t isDelim = 0;
            currentDelim = (char *)delim;

            // Проверяем текущий символ в строке является разделителем (флаг - isDelim) ++
            while (*currentDelim != '\0') {
                if (*currentDelim == *currentStr) {
                    isDelim = 1;
                    break;
                }
                currentDelim++;
            }
            // Проверяем текущий символ в строке является разделителем (флаг - isDelim) --

            if (!isDelim) { // Если это не разделитель
                if (tok == s21_NULL)
                    tok = currentStr;
            } else { // Если текущий символ разделитель
                if (tok != s21_NULL) { // Если до разделителя были других символов
                    *currentStr = '\0';
                    last = ++currentStr;
                    break;
                }
            }

            currentStr++;
        }

        if (*currentStr == '\0')
            last = s21_NULL;

        result = tok;
    }

    return result;
}
