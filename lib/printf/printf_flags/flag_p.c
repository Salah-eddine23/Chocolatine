/*
** EPITECH PROJECT, 2024
** flag_p.c
** File description:
** repliocates the flag p in printf
*/

#include "../../../include/protos_printf.h"

char *flag_p(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;

    str = my_put_base_l(va_arg(list, long int), "0123456789abcdef");
    len = my_strlen(str);
    str = add_address(str, 0);
    return add_string(build_buffer(elements, len + 2), str);
}
