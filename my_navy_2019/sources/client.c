/*
** EPITECH PROJECT, 2019
** client.c
** File description:
** The program of the client.
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "proto.h"

static char play_battleship_as_client(navy_t *navy)
{
    while (victory_and_defeat(navy)) {
        display_boards(navy);
        my_putstr("waiting for enemy's attack...\n");
        if ('1' == receive_attack_and_act(navy))
            return ('1');
        if ('1' == recup_player_attack(navy) || '1' == attack_and_act(navy))
            return ('1');
        free(navy->input);
    }
    return ('0');
}

char client(char *src, int host_pid)
{
    int fd = open(src, O_RDONLY);
    navy_t *navy = NULL;

    if (-1 == fd) {
        print_error("Error :: In this case, the second argument is a file\n");
        return ('3');
    }
    navy = init_navy(fd);
    if (NULL == navy)
        return ('3');
    navy->other_pid = host_pid;
    if ('1' == join_host(navy) || '1' == play_battleship_as_client(navy))
        return ('3');
    return (navy->endgame + 48);
}
