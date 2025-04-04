/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_is_prime.c
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    if (nb < 2){
        return 0;
    }
    for (int i = 2; i != nb; i++){
        if (nb % i == 0){
            return 0;
        }
    }
    return 1;
}
