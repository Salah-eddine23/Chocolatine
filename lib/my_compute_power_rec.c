/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_compute_power_rec.c
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    long int resultat = nb;

    if (p < 0){
        return (0);
    }
    if (p == 0){
        return 1;
    }
    if (p == 1){
        return nb;
    }
    resultat = resultat * my_compute_power_rec(nb, p - 1);
    if (resultat > 2147483647){
        return (0);
    }
    return resultat;
}
