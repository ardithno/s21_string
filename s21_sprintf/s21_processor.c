#include "s21_sprintf.h"

size_t	s21_add_width(int width, int prec, int zero, char* buf)
{
	size_t	len;

	len = 0;
	while (width - prec > 0)
	{
		if (zero)
			s21_putchar(buf, '0');
		else
			s21_putchar(buf, ' ');
		len++;
		width--;
	}
	return (len);
}

size_t	s21_putstr_prec(char *str, int precision, char *buf)
{
	size_t	len;

	len = 0;
	while (str[len] && (int)len < precision)
	{	
		s21_putchar(buf, str[len]);
		len++;
	}
	return (len);
}

size_t	s21_processor(char type, t_flags *flags, va_list arg, char* buf)
{
	size_t	len;

	len = 0;
	if (type == 'c')
		len = s21_proc_char(flags, va_arg(arg, int), buf);
	if (type == 's')
		len = s21_proc_string(flags, va_arg(arg, char *), buf);
	if (type == 'p')
		len = s21_proc_pointer(flags, va_arg(arg, unsigned long), buf);
	if (type == 'd' || type == 'i')
		len = s21_proc_int(flags, va_arg(arg, long int), buf);
	if (type == 'f')
		len = s21_proc_float(flags, arg, buf);
	if (type == 'u')
		len = s21_proc_uint(flags, va_arg(arg, unsigned int), buf);
	if (type == 'x')
		len = s21_proc_hex(flags, va_arg(arg, unsigned int), 0, buf);
	if (type == 'X')
		len = s21_proc_hex(flags, va_arg(arg, unsigned int), 1, buf);
	if (type == '%')
		len = s21_proc_percent(flags, buf);
	return (len);
}
