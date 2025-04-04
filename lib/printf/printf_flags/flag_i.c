/*
** EPITECH PROJECT, 2024
** flag_i
** File description:
** replicate flag_i in printf
*/

#include "../../../include/protos_printf.h"

char *flag_i(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;
    char *plus = malloc(sizeof(char) * 2);

    plus[0] = '+';
    plus[1] = '\0';
    str = my_put_nbr_printf(va_arg(list, int));
    len = my_strlen(str);
    if (elements->flags == '+' && str[0] != '-')
        str = add_string(plus, str);
    if (elements->precision_mod == '.') {
        elements->flags = '0';
        elements->precision_mod = '\0';
    }
    if (elements->flags != '+')
        free(plus);
    return add_string(build_buffer(elements, len), str);
}
