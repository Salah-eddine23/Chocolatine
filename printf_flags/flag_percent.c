/*
** EPITECH PROJECT, 2024
** flag_%
** File description:
** replicate flag_% in printf
*/

#include "../include/protos.h"

char *flag_percent(va_list list, printf_t *elements)
{
    char *str = NULL;

    str = my_putchar('%');
    return add_string(build_buffer(elements, 1), str);
}
