/*
** EPITECH PROJECT, 2024
** flag_f
** File description:
** replicate flag_f in printf
*/

#include "../../../include/protos_printf.h"

char *flag_f(va_list list, printf_t *elements)
{
    char *str = NULL;
    int preci = 6;
    int len = 0;
    char *plus = malloc(sizeof(char) * 2);

    plus[0] = '+';
    plus[1] = '\0';
    if (elements->precision_mod == '.')
        preci = elements->precision;
    str = my_put_double(va_arg(list, double), preci);
    len = my_strlen(str);
    if (elements->flags == '+')
        str = add_string(plus, str);
    else
        free(plus);
    return add_string(build_buffer(elements, len), str);
}
