/*
** EPITECH PROJECT, 2019
** play
** File description:
** Main functions of the matchstick game.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/proto.h"

void remove_from_board(matchstick_t *m, int line, int matches)
{
    int nb = 0;
    int remove = m->stick[line - 1] - matches;

    for (int i = 0; m->game[line][i]; ++i) {
        if (nb == remove && '|' == m->game[line][i]) {
            for (int y = 0; matches > y; ++y)
                m->game[line][i + y] = ' ';
        }
        if ('|' == m->game[line][i])
            ++nb;
    }
    m->stick[line - 1] -= matches;
}

void check_end(matchstick_t *m, int *end)
{
    int nb = 0;

    for (int i = 0; m->lines > i; ++i) {
        if (0 != m->stick[i])
            ++nb;
    }
    if (0 == nb)
        *end = 2;
}

void free_all(matchstick_t *m)
{
    for (int i = 0; (m->lines + 2) > i; ++i) {
        free(m->game[i]);
    }
    free(m->stick);
    free(m->space);
    free(m->game);
    free(m);
}
