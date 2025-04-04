/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strncpy.c
*/

#include <string.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;
    int len = 0;

    while (src[index] != '\0' && index != n){
        dest[index] = src[index];
        index++;
    len++;
    }
    if (n < len){
        dest[len + 1] = '\0';
        return dest;
    }
    return dest;
}
