/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** task04
*/

#include <stdio.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
