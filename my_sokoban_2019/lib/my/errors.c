/*
** EPITECH PROJECT, 2019
** errors
** File description:
** All functions which 'll make sure your code works.
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

_Bool deal_arg(int ac)
{
    if (ac != 2) {
        my_putstr("Wrong numbers of arguments -- Error\n");
        return (false);
    }
    return (true);
}

_Bool is_valid_map(char *src, char *flag, int i)
{
    int verif = 0;

    for (int f = 0; '\0' != flag[f]; ++f) {
        if (src[i] == flag[f])
            ++verif;
    }
    if (1 == verif)
        return (true);
    else
        return (false);
}

_Bool verif_extrem(map_t *map)
{
    for (int i = 0; '\0' != map->map[i]; ++i) {
        if ('\n' == map->map[i] && '#' != map->map[i - 1])
            return (false);
        else if ('\n' == map->map[i] && '#' != map->map[i + 1])
            return (false);
    }
    for (int i = 0; '\n' != map->map[i]; ++i) {
        if ('#' != map->map[i])
            return (false);
    }
    return (true);
}
