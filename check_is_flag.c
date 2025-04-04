/*
** EPITECH PROJECT, 2024
** check_if_flag
** File description:
** checks if the current char is a flag
*/

int check_is_flag(char flag)
{
    char *flag_str = "#0-.'+";

    if (!flag)
        return 0;
    for (int i = 0; flag_str[i]; i++) {
        if (flag == flag_str[i])
            return 1;
    }
    return 0;
}
