/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "../include/protos_lib.h"

int intlen(int nb)
{
    int count = 0;

    for (count; nb >= 10; count++){
        nb = nb / 10;
    }
    return count + 1;
}

int my_put_nbr(int nb)
{
    int result = nb;
    int len = intlen(result);

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    for (int i = 1; i <= len; i++){
        for (int a = len - i; a > 0; a = a - 1){
            result = result / 10;
        }
        for (int j = i - 1; j > 0; j = j - 1){
            result = result % 10;
        }
        my_putchar(result + 48);
        result = nb;
    }
    return result;
}
