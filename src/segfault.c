/*
** EPITECH PROJECT, 2024
** salah-eddine
** File description:
** segfault.c
*/

#include "../include/struct_shell.h"
#include <signal.h>
#include "../include/protos_lib.h"
#include <sys/wait.h>
#include <stdio.h>

static void handle_segfault_command(info_t info)
{
    int signal = WTERMSIG(info.signal);

    if (signal == SIGSEGV)
        my_putstr("Segmentation fault (core dumped)\n");
    info.last_sig = 128 + signal;
}

void handle_exit_segfault_command(info_t info)
{
    int signal = 0;

    info.signal = signal;
    if (WIFSIGNALED(info.signal)) {
        info.signal = signal;
        handle_segfault_command(info);
    }
}
