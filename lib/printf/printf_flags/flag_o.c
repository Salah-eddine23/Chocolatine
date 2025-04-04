/*
** EPITECH PROJECT, 2024
** flag_o
** File description:
** replicate flag_o in printf
*/

#include "../../../include/protos_printf.h"

char *flag_o(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;

    if (elements->length_mod >= 1)
        str = my_put_base_l(va_arg(list, int), "01234567");
    if (elements->length_mod <= -1)
        str = my_put_base_h(va_arg(list, int), "01234567");
    if (elements->length_mod == 0)
        str = my_put_base(va_arg(list, int), "01234567");
    len = my_strlen(str);
    if (elements->flags == '#')
        str = add_address(str, 2);
    return add_string(build_buffer(elements, len), str);
}
