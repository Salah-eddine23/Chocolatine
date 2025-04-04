/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_putchar.c
*/

#include "../../include/protos_printf.h"


char *my_putchar_malloc(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = '\0';
    return str;
}
