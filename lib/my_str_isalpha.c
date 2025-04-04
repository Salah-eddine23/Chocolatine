/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'){
            return 84;
        }
    }
    return 0;
}
