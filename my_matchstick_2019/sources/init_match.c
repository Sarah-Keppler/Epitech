/*
** EPITECH PROJECT, 2019
** init_match
** File description:
** Init the matchstick struct.
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/proto.h"

void place_spaces_and_sticks(matchstick_t *m, int i)
{
    int y = 1;

    for (int n = 0; m->space[i - 1] > n; ++n) {
        m->game[i][y] = ' ';
        ++y;
    }
    for (int n = 0; m->stick[i - 1] > n; ++n) {
        m->game[i][y] = '|';
        ++y;
    }
    for (int n = 0; m->space[i - 1] > n; ++n) {
        m->game[i][y] = ' ';
        ++y;
    }
}

void create_board(matchstick_t *match)
{
    for (int i = 1; (match->lines + 1) > i; ++i) {
        match->game[i][0] = '*';
        match->game[i][(match->lines * 2)] = '*';
        match->game[i][(match->lines * 2) + 1] = '\0';
        place_spaces_and_sticks(match, i);
    }
    for (int i = 0; ((match->lines * 2) + 1) > i; ++i) {
        match->game[0][i] = '*';
        match->game[0][i + 1] = '\0';
    }
    for (int i = 0; ((match->lines * 2) + 1) > i; ++i) {
        match->game[match->lines + 1][i] = '*';
        match->game[match->lines + 1][i + 1] = '\0';
    }
}

char init_stick_and_space(matchstick_t *m)
{
    m->stick = malloc(sizeof(int) * m->lines);
    m->space = malloc(sizeof(int) * m->lines);
    if (NULL == m->stick || NULL == m->space)
        return ('1');
    m->stick[0] = 1;
    m->space[0] = m->lines - 1;
    for (int i = 1; m->lines > i; ++i) {
        m->stick[i] = m->stick[i - 1] + 2;
        m->space[i] = m->space[i - 1] - 1;
    }
    return ('0');
}

matchstick_t *init_matchstick(char **av)
{
    matchstick_t *match = malloc(sizeof(matchstick_t));

    if (NULL == match)
        return (NULL);
    match->lines = my_getnbr(av[1]);
    match->max_out = my_getnbr(av[2]);
    match->game = malloc(sizeof(char *) * (match->lines + 2));
    if (NULL == match->game)
        return (NULL);
    for (int i = 0; (match->lines + 2) > i; ++i) {
        match->game[i] = malloc(sizeof(char) * ((match->lines * 2) + 2));
        if (NULL == match->game[i])
            return (NULL);
    }
    if ('1' == init_stick_and_space(match))
        return (NULL);
    create_board(match);
    return (match);
}
