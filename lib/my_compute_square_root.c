/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_compute_square_root.c
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0){
        return 0;
    }
    for (int i = 1; i * i != nb; i++){
        result = i;
        if (result > nb){
            return 0;
        }
    }
    return result + 1;
}
