/*
** EPITECH PROJECT, 2019
** movement
** File description:
** All functions to move through the game.
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

int move_box(int pos, map_t *map)
{
    if (deal_box_collision(pos, map)) {
	map->map[pos + map->move] = 'X';
        for (int i = 0; map->nb_box > i; ++i) {
            if (map->box_pos[i] == pos)
                map->box_pos[i] += map->move;
        }
        return (1);
    }
    return (0);
}

void move_player(int ch, map_t *map)
{
    switch (ch) {
        case (KEY_LEFT):
            go_left(map);
            break;
        case (KEY_RIGHT):
            go_right(map);
            break;
        case (KEY_UP):
            go_up(map);
            break;
        case (KEY_DOWN):
            go_down(map);
            break;
    }
}
