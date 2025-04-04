/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_str_islower.c
*/

#include <stdio.h>

int my_str_islower(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++){
        if (str[i] < 'a' || str[i] > 'z'){
            return (0);
        }
    }
    return (1);
}
