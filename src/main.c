/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** main.c
*/

#include "../include/protos_shell.h"
#include "../include/protos_lib.h"
#include "../include/struct_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void handle_ls_command(info_t info)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) {
        if (execve("/bin/ls", info.args, info.env) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

pair_t *populate_dict(void)
{
    static pair_t pairs[] = {
        {"cd", &handle_cd_command},
        {"env", &print_env},
        {"ls", &handle_ls_command},
        {"cat", &handle_cat_command},
        {"top", &handle_top_command},
        {"pwd", &handle_pwd_command},
        {"vim", &handle_vim_command},
        {"cp", &handle_cp_command},
        {"rm", &handle_rm_command},
        {"touch", &handle_touch_command},
        {"setenv", &setenv_custom},
        {"segfault", &handle_exit_segfault_command},
        {NULL, NULL}
    };

    return pairs;
}

void execute_pair_command(char *args[], info_t info)
{
    pair_t *pairs = populate_dict();
    int found = 0;

    info.args = args;
    for (int i = 0; pairs[i].key != NULL; i++) {
        if (my_strcmp(args[0], pairs[i].key) == 0) {
            pairs[i].function_ptr(info);
            found = 1;
            return;
        }
    }
    if (!found) {
        if (execute_command(args, info.env) == -1) {
            my_putstr(args[0]);
            my_putstr(" : Command not found.\n");
            exit(127);
        }
    }
}

void handle_input(char *input, info_t info)
{
    char **args = parse_input(input);

    if (args[0] != NULL) {
        if (my_strcmp(args[0], "exit") == 0) {
            free(args);
            free(input);
            exit(0);
        }
        if (access(args[0], X_OK) == 0) {
            handle_exec_command(info);
        } else {
            execute_pair_command(args, info);
        }
    }
    free(args);
}

int minishell(char **env)
{
    char *input;
    info_t info = {env, NULL, NULL, NULL, 0, 0};

    handle_signals();
    info.env_list = store_env(env);
    while (1) {
        display_prompt();
        input = read_input();
        info.input = input;
        if (my_strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
        handle_input(input, info);
        free(input);
    }
    return 0;
}

int main(int argc, char *argv[], char *env[])
{
    if (argc == 1)
        minishell(env);
    return 0;
}
