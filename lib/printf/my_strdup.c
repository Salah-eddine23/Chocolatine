/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** my_strdup.c
*/

#include <stdlib.h>

static int str_len(const char *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(const char *src)
{
    int size = str_len(src);
    char *memo = malloc(sizeof(char) * (size + 1));

    if (memo == NULL || size <= -1)
        return NULL;
    for (int i = 0; i < size && src[i]; i++) {
        memo[i] = src[i];
    }
    memo[size] = '\0';
    return memo;
}
