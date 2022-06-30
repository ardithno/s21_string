#include "s21_sprintf.h"
#include <math.h>

s21_size_t s21_len_float(long double ld, s21_size_t precision) {
	s21_size_t len = 0;

	if (isnormal(ld) == 0) {
		len = 1;
	} else {
        int i = (int)ld;
        if (i < 0) {
            i *= -1;
            len++;
        }
        while (i > 0) {
            len++;
            i /= 10;
        }
    }

    if (precision) {
        len = len + precision;
    } else {
        len = len + 6;
    }

	return len;
}

void s21_intToStr(long long int x, char *str) {
    if (x < 0) {
        x = x * (-1);
    }

    int count = 0;
    while (x / 10 != 0) {
        str[count++] = (x % 10) + '0';
        x /= 10;
    }
    str[count++] = x + '0';
    str[count] = '\0';

    char buf;
    for (int i = 0; i < count / 2; i++) {
        buf = str[i];
        str[i] = str[count - 1 - i];
        str[count- 1 - i] = buf;
    }
}

void s21_ftoa(long double lf, char *str, s21_size_t precision) {
    long long int i = (int)lf;

    s21_intToStr(i, str);

    s21_putchar(str, '.');

    double residueLf = (lf - i) * 10;
    while(precision--) {
        i = (int)residueLf;

        s21_putchar(str, i + '0');

        residueLf = (residueLf - i) * 10;  
    }
}