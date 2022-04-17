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

int get_nb_lines_left(matchstick_t *m)
{
    int nb = 0;

    for (int i = 0; m->lines > i; ++i) {
        if (0 != m->stick[i])
            ++nb;
    }
    return (nb);
}

void situation_last_line(matchstick_t *m, int *line, int *matches)
{
    for (int i = 0; m->lines > i; ++i) {
        if (0 != m->stick[i])
            *line = i + 1;
    }
    if (m->stick[*line - 1] == ((m->max_out * 2) - 1))
        *matches = m->max_out - 1;
    else if (m->stick[*line - 1] < ((m->max_out * 2) - 1))
        *matches = m->stick[*line - 1] - 1;
    else
        *matches = -1;
}

void play_under_situations(matchstick_t *m, int *line, int *matches)
{
    int valid_choice = '0';

    while ('0' == valid_choice) {
        *line = my_rand(1, m->lines);
        *matches = my_rand(1, m->max_out);
        if (*matches <= m->stick[*line - 1])
            valid_choice = '1';
    }
}

void ai_turn(matchstick_t *m)
{
    int line = 0;
    int matches = 0;

    my_putstr("AI's turn...\n");
    play_under_situations(m, &line, &matches);
    remove_from_board(m, line, matches);
    print_ai_choice(line, matches);
    print_board(m);
}
