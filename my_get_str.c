/*
** EPITECH PROJECT, 2024
** my_get_str
** File description:
** gets the str specified
*/

#include "include/protos.h"

char *my_get_str(char *str)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * len + 1);
    int i = 0;

    while (str[i]) {
        result[i] = str[i];
    }
    return str;
}
