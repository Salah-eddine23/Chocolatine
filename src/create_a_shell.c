/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** create_a_shell.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/protos_shell.h"
#include "../include/protos_lib.h"
#include <sys/wait.h>

void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "mysh> ", 6);
}

int execute_command(char **args, char **env)
{
    pid_t pid = fork();
    int status;

    if (pid < 0)
        return -1;
    if (pid == 0) {
        if (execve(args[0], args, env) == -1) {
            my_putstr(args[0]);
            my_putstr(": Command not found\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        return (WIFEXITED(status)) ? WEXITSTATUS(status) : -1;
    }
    return 0;
}
