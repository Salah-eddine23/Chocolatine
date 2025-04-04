/*
** EPITECH PROJECT, 2024
** flag_g
** File description:
** replicates the g flag in printf
*/

#include "include/protos.h"

static char *add_science_end(char *str_result, char *str_science, int index)
{
    char *new_str = NULL;
    int i = index;

    while (str_science[i]) {
        i++;
    }
    new_str = malloc(sizeof(char) * i + 2);
    new_str[i] = '\0';
    i = index;
    while (str_science[i]) {
        new_str[i - index] = str_science[i];
        i++;
    }
    new_str[i - index] = '\0';
    return add_string(str_result, new_str);
}

static char *delete_zeros(int i, char *str)
{
    if (!str)
        return NULL;
    while (str[i] == '0' || str[i] == '.') {
        str[i] = '\0';
        i -= 1;
    }
    return str;
}

static int get_science_pow(char *str_science, int *index)
{
    int len = my_strlen(str_science) - 1;
    int i = len;
    int pow = 0;

    while (str_science[i] != '-' && str_science[i] != '+') {
        pow *= 10;
        pow += str_science[i] - '0';
        i -= 1;
    }
    if (str_science[len - 1] == '0')
        pow = str_science[len] - '0';
    if (str_science[i] == '-')
        pow *= -1;
    *index = i - 1;
    return pow;
}

char *flag_g(long double num, int precision, char cap)
{
    char *str_science = my_to_science(num, precision, cap);
    int index = 0;
    char *str_double = NULL;
    char *result_str = NULL;
    int science_pow = get_science_pow(str_science, &index);
    int d = 0;

    str_double = my_put_double(num, precision);
    d = my_strlen(str_double) - 1;
    if (science_pow < -4) {
        result_str = delete_zeros(index - 1, str_science);
        result_str[my_strlen(result_str)] = '\0';
        free(str_double);
        return add_science_end(result_str, str_science, index);
    } else {
        free(str_science);
        result_str = delete_zeros(d, str_double);
        return result_str;
    }
}
