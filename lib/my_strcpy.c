/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** strcpy.c
*/

#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;

    while (src[index] != '\0'){
        dest[index] = src[index];
        index++;
    }
    return dest;
}
