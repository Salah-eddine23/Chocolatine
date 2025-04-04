/*
** EPITECH PROJECT, 2024
** check_isflag
** File description:
** check if a character is a flag
*/

int check_is_specifier(char flag)
{
    char *flag_str = "diuoxXeEfFgGcspn%";

    if (!flag)
        return 0;
    for (int i = 0; flag_str[i]; i++) {
        if (flag == flag_str[i])
            return 1;
    }
    return 0;
}
