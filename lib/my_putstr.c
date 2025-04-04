/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** my_putstr.c
*/

#include "../include/protos_lib.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
