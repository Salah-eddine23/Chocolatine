/*
** EPITECH PROJECT, 2024
** Protos.h
** File description:
** protos of the minishell1 project
*/

#ifndef PROTOS_MINISHELL_H
    #define PROTOS_MINISHELL_H
    #define SUCCESS 0
    #define FAILURE 84
    #include "struct_shell.h"
void print_env(info_t info);
void print_list(env_node_t *head);
void display_prompt(void);
void execute_pair_command(char **args, info_t info);
int execute_command(char **args, char **env);
void handle_input(char *input, info_t info);
void handle_cat_command(info_t info);
void handle_top_command(info_t info);
void handle_grep_command(info_t info);
void handle_pwd_command(info_t info);
void handle_vim_command(info_t info);
void handle_cp_command(info_t info);
void handle_rm_command(info_t info);
void handle_exec_command(info_t info);
void handle_touch_command(info_t info);
void handle_signals(void);
void handle_cd_command(info_t info);
void handle_exit_segfault_command(info_t info);
void handle_setenv_command(info_t info);
void sigint_handler(int sig);
char *read_input(void);
void cd_command(info_t info);
env_node_t *add(env_node_t *head, char *env);
void setenv_custom(info_t info);
char **parse_input(char *input);
char **get_paths(char **env);
env_node_t *store_env(char *env[]);
void parse_key_value(env_node_t *head, char *env);
int minishell(char **env);
int main(int argc, char *argv[], char *env[]);
char *add_new_var(env_node_t **head, char *name, char *value);
#endif /* PROTOS_SHELL_H */
