/*
** EPITECH PROJECT, 2019
** error
** File description:
** Check if an error occur.
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/proto.h"

char check_sdin_line(matchstick_t *m, char *line)
{
    for (int i = 0; '\0' != line[i + 1]; ++i)
        if (!('0' <= line[i] && '9' >= line[i])) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return ('1');
        }
    if (!(0 < my_getnbr(line) &&  m->lines >= my_getnbr(line))) {
        my_putstr("Error: this line is out of range\n");
        return ('1');
    }
    if (0 == m->stick[my_getnbr(line) -1]) {
        my_putstr("Error: No stick on this line\n");
        return ('1');
    }
    return ('0');
}

char check_nb_matches(matchstick_t *m, int line, char *matches)
{
    if (m->stick[line - 1] < my_getnbr(matches)) {
        my_putstr("Error: not enough matches on this line\n");
        return ('1');
    }
    else if (0 >= my_getnbr(matches)) {
        my_putstr("Error: you have to remove at least one match\n");
        return ('1');
    }
}

char check_sdin_match(matchstick_t *m, int line, char *matches)
{
    for (int i = 0; '\0' != matches[i + 1]; ++i)
        if (!('0' <= matches[i] && '9' >= matches[i])) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return ('1');
        }
    if ('1' == check_nb_matches(m, line, matches))
        return ('1');
    else if (m->max_out < my_getnbr(matches)) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(m->max_out);
        my_putstr(" matches per turn\n");
        return ('1');
    }
    return ('0');
}

char check_args(char **av)
{
    if (!(1 < my_getnbr(av[1]) && 100 > my_getnbr(av[1]))) {
        my_putstr("Wrong first arg !\n");
        return ('1');
    }
    if (1 > my_getnbr(av[2])) {
        my_putstr("Wrong second arg !\n");
        return ('1');
    }
    return ('0');
}
