/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strcat.c
*/

static int len_bis(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    for (int a = i; a <= len_bis(src) + i; a++){
        dest[a] = src[a - i];
    }
    return dest;
}
