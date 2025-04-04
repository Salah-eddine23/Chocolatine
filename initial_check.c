/*
** EPITECH PROJECT, 2024
** initial check
** File description:
** initial check of printf
*/

#include "include/protos.h"

static int percent_loop(char const *format, int index)
{
    int i = index;

    while (format[i]) {
        if (check_is_specifier(format[i]))
            return 1;
        i++;
    }
    return 0;
}

int initial_check(char const *format)
{
    int n = 2;

    if (!format)
        return 0;
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i -1] != '%')
            n = percent_loop(format, (i + 1));
        if (n == 0)
            return 0;
    }
    return 1;
}
