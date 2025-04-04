/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strncat.c
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    while (dest[i] != '\0'){
        i++;
    }
    for (int a = i; a <= nb + i; a++){
        dest[a] = src[a - i];
    }
    return dest;
}
