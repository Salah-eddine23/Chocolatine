/*
** EPITECH PROJECT, 2024
** num_size
** File description:
** returns the amount of characters in a number
*/

int num_size(int num)
{
    int i = 0;

    while (num >= 1) {
        num /= 10;
        i++;
    }
    return i;
}
