/*
** EPITECH PROJECT, 2019
** collision
** File description:
** All functions linked to collisions.
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

int deal_collision(int pos, map_t *src)
{
    if (src->map[pos] == '#')
        return (0);
    else if (src->map[pos] == 'X') {
        if (move_box(pos, src))
            return (1);
        else
            return (0);
    }
    return (1);
}

int deal_box_collision(int pos, map_t *src)
{
    if (src->map[pos + src->move] == 'X') {
        return (0);
    }
    else if (src->map[pos + src->move] == '#') {
        return (0);
    }
    return (1);
}
