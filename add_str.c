/*
** EPITECH PROJECT, 2024
** add str
** File description:
** adds a sting at the start of another
*/

#include "include/protos.h"

char *loop(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *final_str = malloc(sizeof(char) * (len1 + len2) + 1);

    for (int i = 0; i < (len1 + len2); i++) {
        if (i < len1)
            final_str[i] = str1[i];
        if (i >= len1)
            final_str[i] = str2[i - len1];
    }
    final_str[len1 + len2] = '\0';
    free(str1);
    free(str2);
    return final_str;
}

char *add_string(char *str1, char *str2)
{
    char *result_str = NULL;

    result_str = loop(str1, str2);
    return result_str;
}
