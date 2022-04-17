/*
** EPITECH PROJECT, 2019
** set_sigaction.c
** File description:
** Set the sigaction.
*/

#include <signal.h>
#include <unistd.h>
#include "../include/global_signal.h"

static void sig_connection(int signum, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)signum;
    messenger.pid = siginfo->si_pid;
    messenger.info = siginfo->si_signo;
}

void set_sigaction(void)
{
    struct sigaction info;

    info.sa_sigaction = &sig_connection;
    info.sa_flags = SA_SIGINFO;
    sigemptyset(&info.sa_mask);
    sigaction(SIGUSR1, &info, NULL);
    sigaction(SIGUSR2, &info, NULL);
}
