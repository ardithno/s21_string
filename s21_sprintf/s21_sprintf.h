#ifndef S21_SPRINTF_H
# define S21_SPRINTF_H

#include <stdio.h>
#include <stdlib.h> 
#include <stdarg.h>
#include <unistd.h>
#include <math.h>

#include "../s21_string/s21_string.h"

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
	int sh;
	int l;
	int L;
	int plus;
	int space;
}				t_flags;
int	s21_sprintf(char *buf, const char *format, ...);
size_t	s21_parse_flag(const char *format, size_t i, \
		t_flags *flags, va_list arg);
void	s21_flag_dot(const char *format, size_t *i, t_flags *flags, va_list arg);
void	s21_flag_minus(t_flags *flags);
void	s21_flag_width(t_flags *flags, va_list arg);
void	s21_flag_digit(char c, t_flags *flags);
int		s21_is_type(int c);
size_t	s21_processor(char type, t_flags *flags, va_list arg, char* buf);
size_t	s21_add_width(int width, int prec, int zero, char* buf);
size_t	s21_putstr_prec(char *str, int precision, char *buf);
size_t	s21_proc_char(t_flags *flags, char c, char* buf);
size_t	s21_proc_string(t_flags *flags, char *str, char* buf);
size_t	s21_proc_pointer(t_flags *flags, unsigned long p, char* buf);
size_t	s21_proc_int(t_flags *flags, long int i, char* buf);
size_t	s21_proc_uint(t_flags *flags, unsigned int i, char* buf);
size_t	s21_proc_hex(t_flags *flags, unsigned int h, int capitals, char* buf);
size_t	put_of_uint_minus(t_flags *flags, char *str, char* buf);
size_t	put_of_uint_prec(t_flags *flags, char* buf);
size_t s21_proc_percent(t_flags *flags, char* buf);
int	s21_isdigit(int c);
size_t	s21_strlen(const char *s);
int	s21_len(long int n, t_flags *flags);
char	*s21_exclude(int n);
char	*s21_itoa(long int n, t_flags *flags);
size_t	s21_strlcpy(char *dst, const char *src, size_t dstsize);
char	*s21_strdup(const char *s1);
size_t	put_char(char c, char *buf);

// eren ++
s21_size_t	s21_proc_float(t_flags *flags, va_list arg, char* buf);

//s21_methods_float ++

s21_size_t s21_len_float(long double ld, s21_size_t precision);
void s21_ftoa(long double lf, char *str, s21_size_t precision);

//s21_methods_float ++

char* s21_putchar(const char *dest, char c);

// eren --

#endif