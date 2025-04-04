/*
** EPITECH PROJECT, 2024
** my_putnbr
** File description:
** function that displays the number passed as parameter
*/

#include "../../include/protos_printf.h"

static int power(long long int num, int power)
{
    for (int i = 0; i < power; i++) {
        if (num >= 0) {
            num *= 10;
            continue;
        }
        return -1;
    }
    return num;
}

char *get_result(long long int num, long long int divider, int i, char *str)
{
    long long int new_number = num;

    while (divider >= 1) {
        new_number /= divider;
        if (i > 0)
            new_number %= 10;
        divider /= 10;
        str[i] = (new_number + '0');
        new_number = num;
        i++;
    }
    str[i] = '\0';
    return str;
}

static int get_power(long long int num)
{
    int power = 0;

    while (num >= 10) {
        num /= 10;
        power += 1;
    }
    return power;
}

char *my_put_nbr_printf(long long int num)
{
    int pow = get_power(ABS(num));
    long long int divider = 1;
    char *result = NULL;
    int i = 0;

    result = malloc(sizeof(char) * pow + 2);
    if (num < 0) {
        result[i] = '-';
        num *= -1;
        i++;
    }
    if (num < 10) {
        result[i] = (num + '0');
        result[i + 1] = '\0';
        return result;
    }
    divider = power(divider, pow);
    return get_result(num, divider, i, result);
}
