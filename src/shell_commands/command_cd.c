/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** command_cd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/protos_lib.h"
#include "../../include/protos_shell.h"
#include "../../include/struct_shell.h"

static char *get_env_var(char *env[], const char *var_name)
{
    int i = 0;

    for (i; env[i]; i++) {
        if (my_strncmp(env[i], var_name, my_strlen(var_name)) == 0) {
            return env[i] + my_strlen(var_name);
        }
    }
    return NULL;
}

static void alloc_setenv_var(char **var, const char *name, const char *value)
{
    *var = malloc(my_strlen(name) + my_strlen(value) + 1);
    if (*var) {
        my_strcpy(*var, name);
        my_strcat(*var, value);
    }
}

void set_env_var(char *env[], const char *name, const char *value)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            alloc_setenv_var(&env[i], name, value);
            return;
        }
    }
}

static void update_env_vars(info_t info)
{
    char *cwd = malloc(1024 * sizeof(char));
    char *old_pwd = get_env_var(info.env, "PWD=");

    if (!cwd) {
        perror("malloc");
        return;
    }
    if (getcwd(cwd, 1024) == NULL) {
        perror("getcwd");
        free(cwd);
        return;
    }
    set_env_var(info.env, "OLDPWD=", get_env_var(info.env, "PWD="));
    set_env_var(info.env, "PWD=", cwd);
    add_new_var(&info.env_list, "OLDPWD", old_pwd);
    add_new_var(&info.env_list, "PWD", cwd);
    free(cwd);
}

static int handle_cd_home(info_t info)
{
    char *home = get_env_var(info.env, "HOME=");

    if (!home) {
        my_putstr("cd: HOME not set\n");
        return -1;
    }
    if (chdir(home) == -1) {
        perror("cd");
        return -1;
    }
    update_env_vars(info);
    return 0;
}

static int handle_cd_previous(info_t info)
{
    char *oldpwd = get_env_var(info.env, "OLDPWD=");

    if (!oldpwd) {
        my_putstr("cd: OLDPWD not set\n");
        return -1;
    }
    my_putstr(oldpwd);
    my_putchar('\n');
    if (chdir(oldpwd) == -1) {
        perror("cd");
        return -1;
    }
    update_env_vars(info);
    return 0;
}

void handle_cd_valid(info_t info)
{
    if (info.args[1] == NULL || my_strcmp(info.args[1], "~") == 0) {
        handle_cd_home(info);
        return;
    }
    if (my_strcmp(info.args[1], "-") == 0) {
        handle_cd_previous(info);
        return;
    }
    if (chdir(info.args[1]) == -1) {
        perror("cd");
        return;
    }
    update_env_vars(info);
}

void handle_cd_command(info_t info)
{
    handle_cd_valid(info);
}

char *get_path(char **args, char *home_dir)
{
    if (args == NULL || args[0] == NULL) {
        my_putstr("cd: invalid arguments\n");
        return NULL;
    }
    if (args[1] == NULL) {
        if (home_dir == NULL) {
            my_putstr("cd: HOME not set\n");
            return NULL;
        }
        return home_dir;
    }
    return args[1];
}
