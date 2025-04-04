/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** set_env.c
*/

#include "../../include/struct_shell.h"
#include "../../include/protos_shell.h"
#include "../../include/protos_lib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static bool is_valid_key(const char *key)
{
    if (!(key[0] >= 'A' && key[0] <= 'Z') &&
    !(key[0] >= 'a' && key[0] <= 'z'))
        return false;
    for (int i = 1; key[i] != '\0'; i++) {
        if (!my_str_isalpha(&key[i]) && !my_str_isnum(&key[i]))
            return false;
    }
    return true;
}

static char *update_existing_var(env_node_t *current, char *value)
{
    free(current->value);
    current->value = my_strdup(value);
    free(current->env_var);
    current->env_var = malloc(my_strlen(current->key) + my_strlen(value) + 2);
    if (!current->env_var) {
        perror("malloc failed !");
        return NULL;
    }
    my_strcpy(current->env_var, current->key);
    my_strcat(current->env_var, "=");
    my_strcat(current->env_var, value);
    return current->value;
}

static env_node_t *allocate_new_var(char *name, char *value)
{
    env_node_t *new_var = malloc(sizeof(env_node_t));

    if (!new_var) {
        perror("malloc failed !");
        return NULL;
    }
    new_var->key = my_strdup(name);
    new_var->value = my_strdup(value);
    new_var->env_var = malloc(my_strlen(name) + my_strlen(value) + 2);
    if (!new_var->env_var) {
        free(new_var->key);
        free(new_var->value);
        free(new_var);
        perror("malloc");
        return NULL;
    }
    new_var->next = NULL;
    return new_var;
}

static env_node_t *create_new_var(char *name, char *value)
{
    env_node_t *new_var = allocate_new_var(name, value);

    if (!new_var) {
        perror("malloc failed !");
        return NULL;
    }
    my_strcpy(new_var->env_var, name);
    my_strcat(new_var->env_var, "=");
    my_strcat(new_var->env_var, value);
    return new_var;
}

void add_var_to_list(env_node_t **head, env_node_t *new_var)
{
    env_node_t *current = *head;

    if (*head == NULL)
        *head = new_var;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = new_var;
    }
}

char *add_new_var(env_node_t **head, char *name, char *value)
{
    env_node_t *current = *head;
    env_node_t *new_var = create_new_var(name, value);

    if (!is_valid_key(name))
        return NULL;
    while (current) {
        if (my_strcmp(current->key, name) == 0)
            return update_existing_var(current, value);
        if (current->next == NULL)
            break;
        current = current->next;
    }
    if (!new_var)
        return NULL;
    add_var_to_list(head, new_var);
    return new_var->value;
}

void setenv_custom(info_t info)
{
    if (!info.args[1]) {
        print_env(info);
        return;
    }
    if (!info.args[2]) {
        my_putstr("Usage: setenv VAR VALUE\n");
        return;
    }
    if (!add_new_var(&info.env_list, info.args[1], info.args[2])) {
        my_putstr("Failed to set environment variable.\n");
        return;
    }
}
