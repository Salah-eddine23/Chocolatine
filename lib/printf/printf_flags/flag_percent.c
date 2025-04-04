/*
** EPITECH PROJECT, 2024
** flag_%
** File description:
** replicate flag_% in printf
*/

#include "../../../include/protos_printf.h"

char *flag_percent(va_list list, printf_t *elements)
{
    char *str = NULL;

    str = my_putchar_malloc('%');
    return add_string(build_buffer(elements, 1), str);
}
