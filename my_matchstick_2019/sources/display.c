/*
** EPITECH PROJECT, 2019
** AI
** File description:
** AI features.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/proto.h"

void print_board(matchstick_t *m)
{
    for (int i = 0; m->lines + 2 > i; ++i) {
        my_putstr(m->game[i]);
        my_putchar('\n');
    }
}

void print_player_choice(int line, int matches)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void print_ai_choice(int line, int matches)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}
