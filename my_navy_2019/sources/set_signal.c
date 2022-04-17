/*
** EPITECH PROJECT, 2019
** set_serveur_signal.c
** File description:
** Set the serveur signal.
*/

#include <signal.h>
#include <unistd.h>
#include "../include/proto.h"

msg messenger = {0};

int set_serveur_signal(void)
{
    set_sigaction();
    pause();
    if (0 == kill(messenger.pid, SIGUSR2))
        return (1);
    return (0);
}

int set_client_signal(pid_t host_pid)
{
    set_sigaction();
    kill(host_pid, SIGUSR1);
    pause();
    if (messenger.pid == host_pid)
    {
        return (1);
    }
    return (0);
}
