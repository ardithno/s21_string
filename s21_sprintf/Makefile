
CC			=gcc
FLAGS		=-Wall -Wextra -Werror
FLAGS_DEBUG	=-Wall -Werror -Wextra -g
FLAGS_TEST 	=-Wall -Wextra -Werror -std=c11 -lm -lcheck -lpthread

SRCS		=s21_sprintf.c s21_parse_flag.c \
				s21_flag_proc.c s21_processor.c s21_proc_char.c \
				s21_proc_string.c s21_proc_pointer.c s21_proc_int.c \
				s21_proc_uint.c s21_proc_hex.c s21_proc_percent.c \
				s21_isdigit.c s21_itoa.c s21_strlcpy.c s21_strdup.c s21_strlen.c \
				s21_putchar.c s21_proc_float.c s21_methods_float.c
lib_src		=../s21_string/
lib_string	=$(lib_src)s21_memchr.c $(lib_src)s21_memcmp.c $(lib_src)s21_memcpy.c \
				$(lib_src)s21_memmove.c $(lib_src)s21_memset.c $(lib_src)s21_strcat.c \
				$(lib_src)s21_strchr.c $(lib_src)s21_strcmp.c $(lib_src)s21_strcpy.c \
				$(lib_src)s21_strcspn.c $(lib_src)s21_strerror.c $(lib_src)s21_strlen.c \
				$(lib_src)s21_strncat.c $(lib_src)s21_strncmp.c $(lib_src)s21_strncpy.c \
				$(lib_src)s21_strpbrk.c $(lib_src)s21_strrchr.c $(lib_src)s21_strspn.c \
				$(lib_src)s21_strstr.c $(lib_src)s21_strtok.c

SOURCES =*.c
BUILD_DIR =.
OUTFILE_TEST =s21_string_test

dick:
	$(CC) $(FLAGS) $(SRCS) $(lib_string)

debug:
	$(CC) $(FLAGS_DEBUG) $(SRCS) $(lib_string)

test:
	checkmk s21_test.check > s21_test.c
	$(CC) $(CFLAGS_TEST) s21_sprintf.c s21_parse_flag.c s21_flag_proc.c s21_processor.c s21_proc_char.c s21_proc_string.c s21_proc_pointer.c s21_proc_int.c s21_proc_uint.c s21_proc_hex.c s21_proc_percent.c s21_isdigit.c \
	s21_itoa.c s21_strlcpy.c s21_strdup.c s21_strlen.c s21_strcat.c s21_proc_float.c s21_methods_float.c $(SOURCES_TEST) -o $(BUILD_DIR)/$(OUTFILE_TEST)
	$(BUILD_DIR)/$(OUTFILE_TEST) 

clean: 
	rm -rf *.o *.gch *.a