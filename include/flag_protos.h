/*
** EPITECH PROJECT, 2024
** flag_protos
** File description:
** includes all flags
*/

#ifndef FLAG_PROTOS
    #define FLAG_PROTOS
    #include <stdarg.h>
    #include "printf_struct.h"
char *flag_cap_g(va_list list, printf_t *elements);
char *flag_cap_x(va_list list, printf_t *elements);
char *flag_cap_e(va_list list, printf_t *elements);
char *flag_cap_f(va_list list, printf_t *elements);
char *flag_e(va_list list, printf_t *elements);
char *flag_g1(va_list list, printf_t *elements);
char *flag_x(va_list list, printf_t *elements);
char *flag_u(va_list list, printf_t *elements);
char *flag_o(va_list list, printf_t *elements);
char *flag_s(va_list list, printf_t *elements);
char *flag_percent(va_list list, printf_t *elements);
char *flag_d(va_list list, printf_t *elements);
char *flag_f(va_list list, printf_t *elements);
char *flag_i(va_list list, printf_t *elements);
char *flag_c(va_list list, printf_t *elements);
char *flag_p(va_list list, printf_t *elements);
#endif
