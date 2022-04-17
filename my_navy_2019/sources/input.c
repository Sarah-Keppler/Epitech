/*
** EPITECH PROJECT, 2019
** input.c
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

static char check_already_hitten(navy_t *navy, char *buffer)
{
    int y = buffer[1] - 47;
    int x = (buffer[0] - 64) * 2;

    if ('o' == navy->enemy_pos[y][x])
        return ('1');
    return ('0');
}

static int check_valid_input(navy_t *navy, char *buffer)
{
    if (2 != my_strlen(buffer))
        return (1);
    if (!('A' <= buffer[0] && 'H' >= buffer[0])
        || !('1' <= buffer[1] && '8' >= buffer[1])) {
        my_putstr("wrong position\n");
        return (1);
    } else if ('1' == check_already_hitten(navy, buffer)) {
        my_putstr("wrong attack\n");
        return (1);
    }
    return (0);
}

char recup_player_attack(navy_t *navy)
{
    char *buffer = NULL;
    size_t n = 0;
    int rtn = 0;

    do {
        my_putstr("attack: ");
        rtn = getline(&buffer, &n, stdin);
        if (EOF == rtn || -1 == rtn)
            return ('1');
        buffer[2] = '\0';
        rtn = check_valid_input(navy, buffer);
    } while (0 != rtn);
    navy->input = buffer;
    return ('0');
}
