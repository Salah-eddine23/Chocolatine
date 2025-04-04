/*
** EPITECH PROJECT, 2024
** knoupi
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int is_charac(char c, int i)
{
    if (c < '!' || c > '~')
        return 0;
    if (i == 2 && c == ':')
        return 0;
    return 1;
}

int count(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (is_charac(str[i], 1) && (!str[i + 1] || !is_charac(str[i + 1], 1)))
            count++;
        i++;
    }
    return count;
}

int is_word(char *str, int i)
{
    while (str[i] && is_charac(str[i], 1))
        i++;
    return i;
}

void free_word_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

static char *extract_word(char *str, int *index)
{
    int start = *index;
    int len = 0;
    char *word;

    while (str[*index] && !is_charac(str[*index], 1))
        (*index)++;
    start = *index;
    while (str[*index] && is_charac(str[*index], 1)) {
        (*index)++;
        len++;
    }
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < len; i++)
        word[i] = str[start + i];
    word[len] = '\0';
    return word;
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int words = count(str);
    char **result = malloc(sizeof(char *) * (words + 1));

    if (!result)
        return NULL;
    for (int a = 0; a < words; a++) {
        result[a] = extract_word(str, &i);
        if (!result[a]) {
            free_word_array(result);
            return NULL;
        }
    }
    result[words] = NULL;
    return result;
}
