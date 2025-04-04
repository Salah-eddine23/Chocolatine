/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_getnbr.c
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}

static int intlen(int nb)
{
    int count = 0;

    for (nb; nb > 10; count++){
        nb = nb / 10;
    }
    return count + 1;
}

static int my_put_nbr(int nb)
{
    int result = nb;
    int len = intlen(result);

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    for (int i = 1; i <= len; i++){
        for (int a = len - i; a > 0; a = a - 1){
            result = result / 10;
        }
        for (int j = i - 1; j > 0; j = j - 1){
            result = result % 10;
        }
        my_putchar(result + 48);
        result = nb;
    }
    return result;
}

int my_getnbr(char *str)
{
    int i = 0;
    int result = 0;

    if (!str || *str == '\0')
        return 84;
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
