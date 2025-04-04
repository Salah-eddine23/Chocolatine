/*
** EPITECH PROJECT, 2024
** get_elements
** File description:
** gets all the specifiers after the percent
*/

#include "../../include/protos_printf.h"

static int is_a_number(char c)
{
    if (c >= 0 && c <= 9)
        return 1;
    return 0;
}

void initialize(printf_t *elements)
{
    elements->length_mod = 0;
    elements->precision_mod = 0;
    elements->flags = 0;
}

printf_t *get_elements(char const *format, int i)
{
    printf_t *elements = {0};

    elements = malloc(sizeof(printf_t) + 1);
    initialize(elements);
    if (!format)
        return NULL;
    elements->precision = look_for_precision(format, i);
    while (format[i] != '%') {
        if (format[i] == 'l')
            elements->length_mod += 1;
        if (format[i] == 'h')
            elements->length_mod -= 1;
        if (check_is_flag(format[i]) && !is_a_number(format[i - 1]))
            elements->flags = format[i];
        if (format[i] == '.')
            elements->precision_mod = '.';
        i--;
    }
    return elements;
}
