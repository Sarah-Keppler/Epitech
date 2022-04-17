/*
** EPITECH PROJECT, 2019
** data_errors
** File description:
** All functions which 'll get the data for errors management.
*/

#include <ncurses.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "map.h"
#include "sokoban.h"
#include "collision.h"

int get_nb_on_map(char *src, char c)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i) {
        if (c == src[i])
            ++nb;
    }
    return (nb);
}

_Bool get_nb_of_time(map_t *m)
{
    if (1 != get_nb_on_map(m->map, 'P') || 0 == get_nb_on_map(m->map, 'O')) {
        my_putstr("Wrong numbers of P or O -- Error\n");
        return (false);
    } else if (m->nb_storage > m->nb_box) {
        my_putstr("Wrong numbers of boxes of storages -- Error\n");
        return (false);
    }
    return (true);
}
