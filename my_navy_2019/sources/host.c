/*
** EPITECH PROJECT, 2019
** host.c
** File description:
** The program of the host.
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

void display_boards(navy_t *navy)
{
    my_putstr("my positions:\n");
    for (int i = 0; 10 > i; ++i)
        my_putstr(navy->my_pos[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; 10 > i; ++i)
        my_putstr(navy->enemy_pos[i]);
    my_putchar('\n');
}

char host(int fd)
{
    navy_t *navy = init_navy(fd);
    char endgame = '0';

    if (NULL == navy)
        return ('3');
    wait_client(navy);
    while (victory_and_defeat(navy)) {
        display_boards(navy);
        if ('1' == recup_player_attack(navy) || '1' == attack_and_act(navy))
            return ('3');
        my_putstr("waiting for enemy's attack...\n");
        if ('1' == receive_attack_and_act(navy))
            return ('3');
        free(navy->input);
    }
    endgame = navy->endgame + 48;
    return (endgame);
}
