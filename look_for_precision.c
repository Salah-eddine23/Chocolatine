/*
** EPITECH PROJECT, 2024
** look_for_precidion
** File description:
** looks for the precision after the percent in the my_printf
*/

#include "include/protos.h"

static int is_number(char c)
{
    if ((c >= '0') && c <= '9')
        return 1;
    return 0;
}

int look_for_precision(char const *format, int i)
{
    int num = 0;
    int index = i;

    while (format[index] != '%') {
        index -= 1;
    }
    while (index <= i) {
        index++;
        if (is_number(format[index])) {
            num *= 10;
            num += format[index] - '0';
        }
    }
    if (num == 0)
        return 0;
    return num;
}
