#ifndef LIBFT_H
#define LIBFT_H
#include <stdlib.h>
#include <stdio.h>

int     ft_abs(int d);
void    ft_bzero(void *s, size_t n);
div_t   ft_div(int a, int b);
int     ft_isalpha(int ch);
int     ft_isascii(int ch);
int     ft_isdigit(int ch);
char    *ft_strchr(const char *s, int c);
int     ft_tolower(int ch);
int     ft_toupper(int ch);
void    ft_striter(char *s, void (*f)(char *));
int     ft_memcmp(const void *st1, const void *st2, int size);
void    *ft_memcpy(void *dest, const void *source, int count);
void    *ft_memset (void *s, int c, size_t n);
char    *ft_strnstr(const char *str1, const char *str2, int len);
char    *ft_strstr(const char *str1, const char *str2);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s);
int     ft_strlen(char const *s);
char    **ft_strsplit(char const *s, char c);


#endif