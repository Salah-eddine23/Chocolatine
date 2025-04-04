/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** env.c
*/

#include "../../include/protos_lib.h"
#include "../../include/struct_shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *extract_key(char *env)
{
    int i = 0;
    char *key = (char *)malloc(sizeof(char) * (i + 1));

    while (env[i] && env[i] != '=')
        i++;
    if (!env[i])
        return NULL;
    if (!key)
        return NULL;
    for (int j = 0; j < i; j++)
        key[j] = env[j];
    key[i] = '\0';
    return key;
}

static char *extract_value(char *env)
{
    int i = 0;
    int len = my_strlen(env + i + 1);
    char *value = (char *)malloc(sizeof(char) * (len + 1));

    while (env[i] && env[i] != '=')
        i++;
    if (!env[i])
        return NULL;
    if (!value)
        return NULL;
    for (int j = 0; j < len; j++)
        value[j] = env[i + 1 + j];
    value[len] = '\0';
    return value;
}

static void parse_key_value(env_node_t *node, char *env)
{
    node->key = extract_key(env);
    if (!node->key) {
        node->value = NULL;
        return;
    }
    node->value = extract_value(env);
    if (!node->value) {
        free(node->key);
        node->key = NULL;
    }
}

static env_node_t *add(env_node_t *head, char *env)
{
    env_node_t *new_node = (env_node_t *)malloc(sizeof(env_node_t));

    if (!new_node)
        return head;
    parse_key_value(new_node, env);
    if (!new_node->key || !new_node->value) {
        free(new_node);
        return head;
    }
    new_node->env_var = my_strdup(env);
    if (!new_node->env_var) {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return head;
    }
    new_node->next = head;
    return new_node;
}

env_node_t *store_env(char *env[])
{
    env_node_t *head = NULL;

    for (int i = 0; env[i]; i++) {
        head = add(head, env[i]);
        if (!head)
            break;
    }
    return head;
}

void print_list(env_node_t *head)
{
    env_node_t *current = head;

    while (current) {
        my_putstr(current->key);
        my_putstr("=");
        my_putstr(current->value);
        my_putstr("\n");
        current = current->next;
    }
}

void free_env_list(env_node_t *head)
{
    env_node_t *temp = NULL;

    while (head) {
        temp = head;
        head = head->next;
        free(temp->key);
        free(temp->value);
        free(temp->env_var);
        free(temp);
    }
}

void print_env(info_t info)
{
    if (info.env_list) {
        print_list(info.env_list);
    }
}
