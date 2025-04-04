/*
** EPITECH PROJECT, 2024
** Protos.h
** File description:
** protos of the minishell1 project
*/

#ifndef STRUCT_SHELL_H
    #define STRUCT_SHELL_H
typedef struct command_s {
    char **params;
    char **env;
    int signal;
} command_t;

typedef struct env_node_s {
    char *key;
    char *value;
    char *env_var;
    struct env_node_s *next;
} env_node_t;

typedef struct info_s {
    char **env;
    char *input;
    env_node_t *env_list;
    char **args;
    int signal;
    int last_sig;
} info_t;

typedef struct cd_result_s {
    int status;
    char *new_prev_dir;
} cd_result_t;

typedef struct pair_s {
    char *key;
    void ((*function_ptr)(info_t info));
} pair_t;

#endif /*STRUCT_SHELL_H */
