/*
** EPITECH PROJECT, 2024
** flag_g1
** File description:
** call the function flag g from printf
*/

#include "../include/protos.h"

char *flag_g1(va_list list, printf_t *elements)
{
    char *str = NULL;
    int preci = 6;
    int len = 0;
    char *plus = malloc(sizeof(char) * 2);

    plus[0] = '+';
    plus[1] = '\0';
    if (!elements)
        return NULL;
    if (elements->precision_mod == '.')
        preci = elements->precision;
    str = flag_g(va_arg(list, double), preci, 'e');
    len = my_strlen(str);
    if (elements->flags == '+')
        str = add_string(plus, str);
    if (elements->flags != '+')
        free(plus);
    return add_string(build_buffer(elements, len), str);
}
