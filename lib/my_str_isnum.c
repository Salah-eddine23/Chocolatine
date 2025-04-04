/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 49 || str[i] > 57){
            return 84;
        }
    }
    return 0;
}
