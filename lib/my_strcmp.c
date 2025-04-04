/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_strcmp.c
*/

static int my_count(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        count = str[i] + count;
        i += 1;
    }
    return count;
}

int my_strcmp(char const *s1, char const *s2)
{
    return my_count(s1) - my_count(s2);
}
