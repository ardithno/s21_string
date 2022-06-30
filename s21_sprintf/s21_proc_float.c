#include "s21_sprintf.h"

s21_size_t put_of_float_zero(t_flags *flags, char *str, long double ld, char* buf) {
	s21_size_t len = 0;

	s21_size_t tempLen = s21_strlen(str);

	if (ld < 0) {
		s21_putchar(buf, '-');
		tempLen++;
		len++;
	} else if (ld >= 0 && flags->plus == 1) {
		s21_putchar(buf, '+');
		tempLen++;
		len++;
	} else if (flags->space) {
		s21_putchar(buf, ' ');
		tempLen++;
		len++;
	}

	len += s21_add_width(flags->width, tempLen, 1, buf);

	return (len);
}

s21_size_t put_of_float_shift(t_flags *flags, char *str, long double ld, char* buf) {
	s21_size_t len = 0;

	s21_size_t tempLen = s21_strlen(str);
	if (ld < 0) {
		tempLen++;
	} else if (ld >= 0 && flags->plus == 1) {
		tempLen++;
	}

	len += s21_add_width(flags->width, tempLen, 0, buf);

	if (ld < 0) {
		s21_putchar(buf, '-');
		len++;
	} else if (ld >= 0 && flags->plus == 1) {
		s21_putchar(buf, '+');
		len++;
	}

	return (len);
}

s21_size_t s21_proc_float(t_flags *flags, va_list arg, char* buf) {
	s21_size_t len = 0;

	if (flags->precision < 0)
		flags->precision = 6;

	int forRound = (int)pow((double)10, (double)flags->precision);

	long double Ld;
	if (flags->L) {
		long double currentFloat = va_arg(arg, long double);
		Ld = round(currentFloat * forRound);
		Ld = Ld / forRound;
	} else if (flags->l) {
		double currentFloat = va_arg(arg, double);
		Ld = (long double)currentFloat;
		Ld = round(Ld * forRound);
		Ld = Ld / forRound;
	} else {
		float currentFloat = (float)va_arg(arg, double);
		Ld = (long double)currentFloat;
		Ld = round(Ld * forRound);
		Ld = Ld / forRound;
	}

	// Создаем нужную нам временную строку ++
	s21_size_t sizeStr = s21_len_float(Ld, flags->precision);
	char *str = malloc((sizeStr + 1) * sizeof(char));
	// Создаем нужную нам временную строку --

	if (str) {
		s21_ftoa(Ld, str, flags->precision); // переводим флоат в строку

		if (!flags->minus) {
			if (flags->zero)
				len += put_of_float_zero(flags, str, Ld, buf);
			else if (flags->width)
				len += put_of_float_shift(flags, str, Ld, buf);

			buf = s21_strcat(buf, str);
			len += s21_strlen(str);
		} else {
			s21_size_t tempLen = s21_strlen(str);
			if (Ld < 0) {
				s21_putchar(buf, '-');
				len++;
			} else if (Ld >= 0 && flags->plus == 1) {
				s21_putchar(buf, '+');
				len++;
			} else if (flags->space) {
				s21_putchar(buf, ' ');
				len++;
			}

			buf = s21_strcat(buf, str);
			len += s21_strlen(str);

			len += s21_add_width(flags->width, len, 0, buf);
		}

		free(str);
	}

	return len;
}
