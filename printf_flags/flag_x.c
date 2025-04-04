/*
** EPITECH PROJECT, 2024
** flag_x
** File description:
** replicate flag_x in printf
*/

#include "../include/protos.h"

char *flag_x(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;

    if (elements->length_mod >= 1)
        str = my_put_base_l(va_arg(list, int), "0123456789abcdef");
    if (elements->length_mod <= -1)
        str = my_put_base_h(va_arg(list, int), "0123456789abcdef");
    if (elements->length_mod == 0)
        str = my_put_base(va_arg(list, int), "0123456789abcdef");
    len = my_strlen(str);
    if (elements->flags == '#')
        str = add_address(str, 0);
    return add_string(build_buffer(elements, len), str);
}
