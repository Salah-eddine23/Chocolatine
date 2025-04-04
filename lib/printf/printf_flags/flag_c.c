/*
** EPITECH PROJECT, 2024
** flag_c
** File description:
** replicate flag_c in printf
*/

#include "../../../include/protos_printf.h"

char *flag_c(va_list list, printf_t *elements)
{
    char *str = NULL;

    str = my_putchar_malloc(va_arg(list, int));
    return add_string(build_buffer(elements, my_strlen(str)), str);
}
