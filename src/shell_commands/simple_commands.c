/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** simple_commands.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../include/protos_shell.h"
#include "../../include/struct_shell.h"
#include "../../include/protos_lib.h"

static void execute_command_top(char *command, info_t info)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1)
        return;
    if (pid == 0) {
        if (execve(command, info.args, info.env) == -1) {
            exit(EXIT_FAILURE);
        }
    } else
        waitpid(pid, &status, 0);
}

static void execute_cat_command(info_t info)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return;
    }
    if (pid == 0) {
        if (execve("/bin/cat", info.args, info.env) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_cat_command(info_t info)
{
    if (info.args == NULL || info.args[1] == NULL) {
        write(2, "Error: No file provided for cat command\n", 41);
        return;
    }
    execute_cat_command(info);
}

void handle_top_command(info_t info)
{
    char *args[] = {"top", NULL };

    info.args = args;
    execute_command_top("/usr/bin/top", info);
}

void handle_emacs_command(info_t info)
{
    pid_t pid = fork();

    if (info.args[1] == NULL) {
        return;
    }
    if (pid == -1) {
        return;
    }
    if (pid == 0) {
        if (execve("/usr/bin/emacs", info.args, info.env) == -1) {
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_pwd_command(info_t info)
{
    char *cwd = (char *)malloc(1024 * sizeof(char));

    if (cwd == NULL) {
        perror("malloc failed");
        return;
    }
    if (getcwd(cwd, 1024) != NULL) {
        my_putstr(cwd);
        my_putstr("\n");
    } else {
        my_putstr("getcwd failed\n");
    }
    free(cwd);
}
