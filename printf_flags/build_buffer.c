/*
** EPITECH PROJECT, 2024
** build_elements
** File description:
** builds a malloc using the elements outputed by the get_elements function
*/

#include "../include/protos.h"

int add_buffer(char *result_str, printf_t *elements, int i, int len)
{
    while (i < elements->precision - len) {
        if (elements->flags == '0') {
            result_str[i] = '0';
        } else
            result_str[i] = 32;
        i += 1;
    }
    return i;
}

char *build_buffer(printf_t *elements, int len)
{
    char *result_str = NULL;
    int i = 0;

    result_str = malloc(sizeof(char) * (elements->precision) + 1);
    if (elements->precision == 0)
        return NULL;
    if (elements->flags == '-')
        elements->precision -= 1;
    if (elements->precision_mod == '\0')
        i = add_buffer(result_str, elements, i, len);
    result_str[i] = '\0';
    return result_str;
}
