/*
** EPITECH PROJECT, 2019
** move_key
** File description:
** All functions linked to the arrow key.
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

void go_left(map_t *map)
{
    map->move = -1;
    if (deal_collision(map->player_pos + map->move, map)) {
        map->map[map->player_pos] = ' ';
        --(map->player_pos);
        map->map[map->player_pos] = 'P';
    }
}

void go_right(map_t *map)
{
    map->move = 1;
    if (deal_collision(map->player_pos + map->move, map)) {
        map->map[map->player_pos] = ' ';
        ++(map->player_pos);
        map->map[map->player_pos] = 'P';
    }
}

void go_up(map_t *map)
{
    map->move = -(map->line_len[get_line_player(map) - 1]);
    if (deal_collision(map->player_pos + map->move, map)) {
        map->map[map->player_pos] = ' ';
        map->player_pos += map->move;
        map->map[map->player_pos] = 'P';
    }
}

void go_down(map_t *map)
{
    map->move = map->line_len[get_line_player(map)];
    if (deal_collision(map->player_pos + map->move, map)) {
        map->map[map->player_pos] = ' ';
        map->player_pos += map->move;
        map->map[map->player_pos] = 'P';
    }
}
