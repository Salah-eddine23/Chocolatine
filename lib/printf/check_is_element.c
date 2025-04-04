/*
** EPITECH PROJECT, 2024
** check_is_element
** File description:
** if the character after the percent is a stopper or not
*/

#include "../../include/protos_printf.h"

int check_is_element(char element)
{
    if (!element)
        return 0;
    if ((!check_is_flag(element)) ||
        (check_is_len(element)) ||
        (element == 32))
        return 1;
    return 0;
}
