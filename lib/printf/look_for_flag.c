/*
** EPITECH PROJECT, 2024
** look_for_precidion
** File description:
** looks for the precision after the percent in the my_printf
*/

#include "../../include/protos_printf.h"

char look_for_flag(char *format, int i)
{
    while (format[i] != '%') {
        if (format[i] == 32)
            continue;
        if (check_is_flag(format[i])) {
            return format[i];
        }
        i--;
    }
    return '\0';
}
