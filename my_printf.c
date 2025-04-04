/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include "include/protos.h"
#include "include/flag_protos.h"

static char *(*const fptr[])(va_list list, printf_t *elements) = {
    ['o'] = &flag_o,
    ['X'] = &flag_cap_x,
    ['x'] = &flag_x,
    ['u'] = &flag_u,
    ['e'] = &flag_e,
    ['E'] = &flag_cap_e,
    ['g'] = &flag_g1,
    ['G'] = &flag_cap_g,
    ['s'] = &flag_s,
    ['c'] = &flag_c,
    ['%'] = &flag_percent,
    ['d'] = &flag_d,
    ['f'] = &flag_f,
    ['i'] = &flag_i,
    ['F'] = &flag_cap_f,
    ['p'] = &flag_p
};

static void my_put_char(char c)
{
    write(1, &c, 1);
}

char *check_specifier(char c, va_list list, int n, printf_t *elements)
{
    if (c == 'n') {
        *va_arg(list, int *) = n;
        return NULL;
    }
    return fptr[c](list, elements);
}

static int after_percent(char const *format, int index, int n, va_list list)
{
    int i = index;
    char *str = NULL;
    printf_t *elements = {0};

    while (format[i]) {
        if (!check_is_element(format[i]))
            return i;
        if (check_is_specifier(format[i])) {
            elements = get_elements(format, i);
            str = check_specifier(format[i], list, n, elements);
            n += my_strlen(str);
            my_putstr(str);
            free(elements);
            free(str);
            return n;
        }
        i += 1;
    }
    return n;
}

static int loop_through(char const *format, va_list list)
{
    int i = 0;
    int n = 0;

    while (format[i]) {
        if (format[i] == '%') {
            n = after_percent(format, (i + 1), n, list);
            i = skip_over(i + 1, format);
            continue;
        }
        n += 1;
        if (!format[i])
            return n;
        my_put_char(format[i]);
        i += 1;
    }
    return n;
}

int my_printf(char const *format, ...)
{
    va_list list;
    int n = 0;

    va_start(list, format);
    if (!initial_check(format))
        return -1;
    n = loop_through(format, list);
    va_end(list);
    return n;
}
