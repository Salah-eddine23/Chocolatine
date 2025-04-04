/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** my_revstr
*/

#include <stdlib.h>

static int rev_length(char *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i]) {
        i++;
    }
    return i;
}

static void rev_swap(char *a, char *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int left = 0;
    int right = rev_length(str)-1;

    while (left <= right) {
        rev_swap(&str[left], &str[right]);
        right--;
        left++;
    }
    return str;
}
