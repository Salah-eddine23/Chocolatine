/*
** EPITECH PROJECT, 2024
** my_put_double
** File description:
** displays a double
*/

#include "include/protos.h"

static int add_part(char *str, int index, int size, long int part)
{
    int i = index;
    int n = 0;
    char *num_str = NULL;

    if (part <= 9 && index < 2) {
        str[i] = part + '0';
        return i + 1;
    }
    num_str = my_put_nbr(part);
    while (num_str[n]) {
        str[i] = num_str[n];
        i++;
        n++;
    }
    free(num_str);
    return i;
}

long double round_up(int precision)
{
    long double num = 4.0;

    for (int i = 0; i <= precision; i++) {
        num /= 10.0;
    }
    return num;
}

char *add_to_str(int index, long double num, int precision, char *str)
{
    long int whole_part = 0;

    if (precision <= 17)
        num += round_up(precision);
    for (int i = 0; i < precision; i++) {
        num *= 10;
        whole_part = (int)num;
        str[index] = whole_part + '0';
        num -= whole_part;
        index += 1;
    }
    str[index] = '\0';
    return str;
}

char *my_put_double(long double num, int precision)
{
    long int whole_part = (int)ABS(num);
    int num_len = num_size(whole_part) + 1;
    char *str = malloc(sizeof(char) * (precision + num_len + 3));
    int index = 0;

    if (num < 0) {
        str[index] = '-';
        num *= -1;
        index += 1;
    }
    index = add_part(str, index, num_len, whole_part);
    num -= (int)num;
    if (precision != 0) {
        str[index] = '.';
        index += 1;
    }
    return add_to_str(index, num, precision, str);
}
