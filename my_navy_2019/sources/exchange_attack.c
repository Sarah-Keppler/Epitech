/*
** EPITECH PROJECT, 2019
** exchange_attack.c
** File description:
** Recup the input from the user, check and use it.
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

static void update_boards(char **board, char *attack, int hit)
{
    int y = attack[1] - 47;
    int x = (attack[0] - 64) * 2;

    if (0 == hit)
        board[y][x] = 'o';
    else
        board[y][x] = 'x';
}

char attack_and_act(navy_t *navy)
{
    int hit = 0;

    if ('1' == send_position(navy->input))
        return ('1');
    hit = receive_touch();
    my_putstr(navy->input);
    my_putstr(": ");
    if (hit)
        my_putstr("hit");
    else
        my_putstr("missed");
    my_putstr("\n\n");
    update_boards(navy->enemy_pos, navy->input, hit);
    return ('0');
}

char receive_attack_and_act(navy_t *navy)
{
    char *attack = receive_position();
    int y = attack[1] - 47;
    int x = (attack[0] - 64) * 2;
    int hit = 0;

    if (NULL == attack)
        return ('1');
    if ('.' == navy->my_pos[y][x]) {
        my_putstr(attack);
        my_putstr(": missed\n\n");
        hit = 0;
    } else {
        my_putstr(attack);
        my_putstr(": hit\n\n");
        hit = 1;
    }
    update_boards(navy->my_pos, attack, hit);
    send_touch(hit);
    free(attack);
    return ('0');
}
