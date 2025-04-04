/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strncmp.c
*/

static int strcount_nb(char const *str, int n)
{
    int index = 0;
    int count = 0;

    while (str[index] != '\0' && index < n){
        count += str[index];
        index++;
    }
    return count;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    return strcount_nb(s1, n) - strcount_nb(s2, n);
}
