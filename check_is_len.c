/*
** EPITECH PROJECT, 2024
** check_is_len
** File description:
** checks if a character after the percent is a len modifier
*/

int check_is_len(char flag)
{
    char *flag_str = "hlL";

    for (int i = 0; flag_str[i]; i++) {
        if (flag == flag_str[i])
            return 1;
    }
    return 1;
}
