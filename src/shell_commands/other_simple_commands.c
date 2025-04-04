/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** other_simple_commands.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include "../../include/protos_shell.h"

void handle_vim_command(info_t info)
{
    pid_t pid = fork();

    if (info.args[1] == NULL) {
        return;
    }
    if (pid == -1) {
        return;
    }
    if (pid == 0) {
        if (execve("/usr/bin/vim", info.args, info.env) == -1) {
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

static int is_directory(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) == -1) {
        perror("stat");
        return -1;
    }
    if (S_ISDIR(path_stat.st_mode)) {
        errno = EISDIR;
        perror(path);
        return 1;
    }
    return 0;
}

void handle_exec_command(info_t info)
{
    pid_t pid = fork();

    if (!info.args || !info.args[0]) {
        perror("Invalid arguments");
        return;
    }
    if (is_directory(info.args[0]) != 0)
        return;
    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) {
        if (execve(info.args[0], info.args, info.env) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else
        waitpid(pid, NULL, 0);
}

void handle_cp_command(info_t info)
{
    pid_t pid = fork();

    if (info.args[1] == NULL || info.args[2] == NULL) {
        return;
    }
    if (pid == -1) {
        return;
    }
    if (pid == 0) {
        if (execve("/bin/cp", info.args, info.env) == -1) {
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_rm_command(info_t info)
{
    pid_t pid = fork();

    if (info.args[1] == NULL) {
        return;
    }
    if (pid == -1) {
        return;
    }
    if (pid == 0) {
        if (execve("/bin/rm", info.args, info.env) == -1) {
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void handle_touch_command(info_t info)
{
    pid_t pid = fork();

    if (info.args[1] == NULL) {
        return;
    }
    if (pid == -1) {
        return;
    }
    if (pid == 0) {
        if (execve("/bin/touch", info.args, info.env) == -1) {
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}
