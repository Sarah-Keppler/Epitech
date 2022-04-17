/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Based on the game matchstick.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/proto.h"

char play(char turn, matchstick_t *m, int *end)
{
    char rtn = '0';

    if ('1' == turn) {
        my_putstr("Your turn:\n");
        rtn = read_player_move(m);
        if ('3' == rtn)
            return ('3');
        else if ('1' == rtn)
            return ('1');
        check_end(m, end);
        print_board(m);
    } else {
        ai_turn(m);
        check_end(m, end);
        if (2 == (*end)) {
            *end -= 1;
            my_putstr("I lost... snif... but I'll get you next time!!\n");
        }
    }
    return ('0');
}

char my_matchstick(matchstick_t *m, int *end)
{
    char rtn = '0';

    while (0 == *end) {
        my_putchar('\n');
        if ('3' == (rtn = play('1', m, end)))
            return ('0');
        else if ('1' == rtn)
            return ('8');
        if (0 == *end) {
            my_putchar('\n');
            play('2', m, end);
        } else
            my_putstr("You lost, too bad...\n");
    }
    return ('0');
}

int launch_the_game(char **av)
{
    matchstick_t *match = init_matchstick(av);
    int end = 0;
    char rtn = '0';

    if (NULL == match)
        return (84);
    print_board(match);
    if ('8' == my_matchstick(match, &end))
        return (84);
    free_all(match);
    return (end);
}

int main(int ac, char **av)
{
    int end = 0;

    if (3 != ac) {
        my_putstr("Wrong nb of arg !\n");
        return (84);
    }
    if ('1' == check_args(av))
        return (84);
    end = launch_the_game(av);
    if (84 == end)
        return (84);
    return (end);
}
