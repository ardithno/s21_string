#ifndef	_S21_STRING_H_
#define	_S21_STRING_H_

#define s21_NULL (void*)0

typedef long unsigned s21_size_t;

// bloc Copy ++
//ЭТИ ДВЕ ФУНКЦИИ ТУПО КОПИПАСТ ИЗ ИНЕТА, ВРОДЕ РАБОТАЕТ
void* s21_memcpy(void *dest, const void *src, s21_size_t count); // +
void* s21_memmove(void *dest, const void *src, s21_size_t count); // +
void* s21_memset(char* dest, int c, s21_size_t n); // +

char* s21_strcpy(char *dest, const char *src); // +
char* s21_strncpy(char *dest, const char *src, s21_size_t n); // +
// bloc Copy --


// bloc search ++
void* s21_memchr(char *str, int c, s21_size_t n);  // Все збс,но два ретурна
char* s21_strchr(char * string, int symbol); // +, но два ретурна
char* s21_strpbrk(const char *str1, const char *str2);
char* s21_strrchr(const char *str, int c);
char* s21_strstr(const char *haystack, const char *needle);
// bloc search --


// bloc Cmp ++
int s21_memcmp(const void* buf1,const void* buf2, s21_size_t count); // +
int s21_strcmp(const char *str1, const char *str2); // +
int s21_strncmp(const char *str1, const char *str2, s21_size_t n); // +
// bloc Cmp --


// bloc Sup Eren ++
char* s21_strtok(char *str, const char *delim); // +
char* s21_strerror(int errnum); // +
char* s21_strcat(char *dest, const char *src); // +
char* s21_strncat(char *dest, const char *src, s21_size_t n); // +
// bloc Sup Eren --


// bloc computation Sen ++
s21_size_t s21_strcspn(const char *str1, const char *str2); // +
s21_size_t s21_strlen(const char *str); // +
s21_size_t s21_strspn(const char *str1, const char *str2); // +
// bloc computation Sen --

#endif
