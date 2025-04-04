/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** parse_cmd.c
*/

#include "../include/protos_shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *read_input(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    if (getline(&buffer, &bufsize, stdin) == -1) {
        free(buffer);
        write(STDOUT_FILENO, "\n", 1);
        exit(0);
    }
    return buffer;
}

char **parse_input(char *input)
{
    int max_args = 64;
    char **args = malloc(max_args * sizeof(char *));
    int i = 0;
    char *token = strtok(input, " \t\n");

    if (!args) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    while (token != NULL) {
        if (i >= max_args - 1) {
            write(STDERR_FILENO, "Too many arguments\n", 19);
            break;
        }
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}
