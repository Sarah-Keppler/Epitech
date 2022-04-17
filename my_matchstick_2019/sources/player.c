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

char read_line(matchstick_t *m, int *line)
{
    char *buffer = NULL;
    size_t n = 0;
    int rtn = 0;

    my_putstr("Line: ");
    rtn = getline(&buffer, &n, stdin);
    if (-1 == rtn || EOF == rtn)
        return ('3');
    if ('1' == check_sdin_line(m, buffer))
        return ('1');
    *line = my_getnbr(buffer);
    free(buffer);
    return ('0');
}

char read_match(matchstick_t *m, int line, int *matches)
{
    char *buffer = NULL;
    size_t n = 0;
    int rtn = 0;

    my_putstr("Matches: ");
    rtn = getline(&buffer, &n, stdin);
    if (-1 == rtn || EOF == rtn)
        return ('3');
    if ('1' == check_sdin_match(m, line, buffer))
        return ('1');
    *matches = my_getnbr(buffer);
    free(buffer);
    return ('0');
}

char read_player_move(matchstick_t *m)
{
    int line = 0;
    int matches = 0;
    char valid_choice = '0';
    char rtn = '0';

    while ('0' == valid_choice) {
        if ('3' == (rtn = read_line(m, &line)))
            return ('3');
        else if ('1' == rtn)
            continue;
        if ('3' == (rtn = read_match(m, line, &matches)))
            return ('3');
        if ('1' == rtn)
            continue;
        valid_choice = '1';
    }
    remove_from_board(m, line, matches);
    print_player_choice(line, matches);
    return ('0');
}
