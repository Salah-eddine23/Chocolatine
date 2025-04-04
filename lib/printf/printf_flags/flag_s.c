/*
** EPITECH PROJECT, 2024
** flag_s
** File description:
** replicate flag_s in printf
*/

#include "../../../include/protos_printf.h"

char *flag_s(va_list list, printf_t *elements)
{
    char *str = NULL;
    int len = 0;

    str = my_strdup(va_arg(list, char *));
    len = my_strlen(str);
    return add_string(build_buffer(elements, len), str);
}
