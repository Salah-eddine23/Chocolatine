/*
** EPITECH PROJECT, 2024
** my_put_base
** File description:
** my_putbase.c for long numbers
*/

#include "include/protos.h"

static int nbr_len_l(unsigned long int num, int base_num)
{
    int i = 0;

    while (num > 1) {
        num /= base_num;
        i++;
    }
    i++;
    return i;
}

char *my_put_base_l(unsigned long int num, char *base)
{
    int base_len = my_strlen(base);
    int num_len = nbr_len_l(num, base_len);
    char *str = malloc(sizeof(char) * num_len + 1);

    for (int i = 0; i < num_len; i++) {
        str[i] = base[num % base_len];
        num /= base_len;
    }
    if (str[num_len - 1] == '0')
        str[num_len - 1] = '\0';
    return my_revstr(str);
}
