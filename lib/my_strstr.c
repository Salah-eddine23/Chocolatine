/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strstr.c
*/

#include <stdio.h>

static int my_strlenbis(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int size = 0;
    int len = my_strlenbis(to_find);

    while (str[i + size] != '\0'){
        if (str[i + size] != to_find[size]){
            size = 0;
            i += 1;
        }
        if (str[i + size] == to_find[size]){
            size += 1;
        }
        if (size == len){
            return &str[i];
        }
    }
    return &str[-1];
}
