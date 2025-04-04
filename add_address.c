/*
** EPITECH PROJECT, 2024
** add_adress
** File description:
** add adress
*/

#include "include/protos.h"

void add_rest(char *str, char *preffix, int i)
{
    int n = 0;

    for (i; str[n]; i++) {
        if (str[n] == '-' && n == 0) {
            n++;
        }
        preffix[i] = str[n];
        n++;
    }
    free(str);
    preffix[i] = '\0';
}

char *add_address(char *str, int cap)
{
    char *preffix = NULL;
    int i = 0;
    int len = my_strlen(str);

    preffix = malloc(sizeof(char) * (len + 4));
    if (str[0] == '-') {
        preffix[i] = '-';
        i++;
    }
    preffix[i] = '0';
    i++;
    if (cap) {
        preffix[i] = 'X';
        i++;
    } else {
        preffix[i] = 'x';
        i++;
    }
    add_rest(str, preffix, i);
    return preffix;
}
