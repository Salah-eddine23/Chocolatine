/*
** EPITECH PROJECT, 2024
** flag_cap_x
** File description:
** replicate flag X in printf
*/

#include "../../../include/protos_printf.h"

char *flag_cap_x(va_list list, printf_t *elements)
{
    char *str = NULL;
    int preci = 0;
    int len = 0;

    if (elements->precision_mod == '.')
        preci = elements->precision;
    if (elements->length_mod >= 1)
        str = my_put_base_l(va_arg(list, int), "0123456789ABCDEF");
    if (elements->length_mod <= -1)
        str = my_put_base_h(va_arg(list, int), "0123456789ABCDEF");
    if (elements->length_mod == 0)
        str = my_put_base(va_arg(list, int), "0123456789ABCDEF");
    len = my_strlen(str);
    if (elements->flags == '#')
        str = add_address(str, 1);
    return add_string(build_buffer(elements, len), str);
}
