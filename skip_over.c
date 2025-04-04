/*
** EPITECH PROJECT, 2024
** skip_over
** File description:
** skips over the flag part in prints
*/

#include "include/protos.h"

int skip_over(int i, char const *format)
{
    while (!check_is_specifier(format[i])){
        i++;
    }
    return i + 1;
}
