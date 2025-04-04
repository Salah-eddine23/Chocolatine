/*
** EPITECH PROJECT, 2024
** flag_u
** File description:
** replicate flag_u in printf
*/

#include "../../../include/protos_printf.h"

char *flag_u(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;

    if (elements->length_mod >= 1)
        str = my_put_base_l(va_arg(list, int), "0123456789");
    if (elements->length_mod <= -1)
        str = my_put_base_h(va_arg(list, int), "0123456789");
    if (elements->length_mod == 0)
        str = my_put_base(va_arg(list, int), "0123456789");
    len = my_strlen(str);
    return add_string(build_buffer(elements, len), str);
}
