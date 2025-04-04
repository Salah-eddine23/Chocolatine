/*
** EPITECH PROJECT, 2024
** printf_struct
** File description:
** makes a structure that holds the data after the percent in printf
*/

#ifndef PRINTF_STRUCT
    #define PRINTF_STRUCT
typedef struct printf_s {
    char flags;
    int precision;
    int length_mod;
    char precision_mod;
}printf_t;

#endif
