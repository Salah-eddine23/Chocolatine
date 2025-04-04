/*
** EPITECH PROJECT, 2024
** protos
** File description:
** prototyped functions for printf
*/

#ifndef PROTOS
    #define PROTOS
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include "macro_abs.h"
    #include "printf_struct.h"
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int initial_check(char const *format);
int check_is_flag(char c);
int check_is_element(char element);
int check_is_len(char flag);
int check_is_specifier(char flag);
int my_printf(const char *format, ...);
int look_for_precision(char const *format, int i);
int skip_over(int i, char const *format);
char *add_string(char *str1, char *str2);
int num_size(int num);
printf_t *get_elements(char const *format, int index);
char *flag_g(long double num, int precision, char cap);
char *my_to_science(long double num, int precision, char cap);
char *my_put_double(long double num, int precision);
char *my_putchar(char c);
char *my_put_nbr(long long int num);
char *build_buffer(printf_t *elements, int len);
char *my_strdup(char *src);
char *my_put_base(unsigned int num, char *base);
char *my_put_base_l(unsigned long int num, char *base);
char *my_put_base_h(unsigned short int num, char *base);
char *add_address(char *str, int cap);
#endif
