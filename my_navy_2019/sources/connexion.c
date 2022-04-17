/*
** EPITECH PROJECT, 2019
** connexion.c
** File description:
** Connect the server and the client.
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char join_host(navy_t *navy)
{
    my_putstr("my_pid: ");
    my_put_nbr(navy->my_pid);
    my_putchar('\n');
    set_client_signal(navy->other_pid);
    my_putstr("successfully connected\n\n");
    return ('0');
}

void wait_client(navy_t *navy)
{
    my_putstr("my_pid: ");
    my_put_nbr(navy->my_pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connexion...\n");
    while (0 == set_serveur_signal());
    my_putstr("\nenemy connected\n\n");
}
