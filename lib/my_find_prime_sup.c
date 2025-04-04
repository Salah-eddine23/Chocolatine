/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_find_prime_sup.c
*/

#include <stdio.h>

static int my_is_prime2(int nb)
{
    if (nb < 2){
        return 2;
    }
    for (int i = 2; i != nb; i++){
        if (nb % i == 0){
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    for (int i = nb; i <= 2147483647; i++){
        if (my_is_prime2(i) == 1){
            return i;
        }
    }
    return 0;
}
