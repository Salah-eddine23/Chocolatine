/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_str_isupper.c
*/

#include <stdio.h>

int my_str_isupper(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++){
        if (str[i] < 'A' || str[i] > 'Z'){
            return (0);
        }
    }
    return (1);
}
