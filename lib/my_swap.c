/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_swap.c
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
