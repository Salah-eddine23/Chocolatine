/*
** EPITECH PROJECT, 2024
** my_to_science
** File description:
** turns a decimal number to scientifical notation
*/

#include "../../include/protos_printf.h"

static int num_len_science(int num)
{
    int n = 0;

    while (num > 0) {
        num /= 10;
        n += 1;
    }
    return n;
}

char *add_end(int n, int i, char *notation)
{
    if (n <= 1) {
        notation[i] = '0';
        i += 1;
        notation[i] = ABS(n) + '0';
        i += 1;
        notation[i] = '\0';
        return notation;
    } else {
        return add_string(notation, my_put_nbr_printf(n));
    }
}

char *add_notation(int n, long double num, char *str, int cap)
{
    int n_len = num_len_science(n);
    char *notation = malloc(sizeof(char) * n_len + 5);
    int i = 0;

    notation[i] = cap;
    i++;
    if (n < 0) {
        notation[i] = '-';
        i++;
    } else {
        notation[i] = '+';
        i++;
    }
    return add_end(n, i, notation);
}

char *my_to_science(long double num, int precision, char cap)
{
    char *str = NULL;
    int n = 0;
    char *result_str = NULL;

    while (ABS(num) > 10 || ABS(num) < 1) {
        if (ABS(num) >= 9) {
            num /= 10;
            n += 1;
            continue;
        }
        n -= 1;
        num *= 10;
    }
    str = my_put_double(num, precision);
    return add_string(str, add_notation(n, num, str, cap));
}
