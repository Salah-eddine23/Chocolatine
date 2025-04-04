/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** handle_signal.c
*/

#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig)
{
    (void)sig;
    write(1, "\nmysh> ", 7);
}

void handle_signals(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, SIG_IGN);
}
