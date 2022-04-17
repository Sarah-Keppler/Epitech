/*
** EPITECH PROJECT, 2019
** winning
** File description:
** Functions which tell you if you win or not.
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

int check_victory(map_t *map)
{
    int placed = 0;

    for	(int s = 0; map->nb_storage > s; ++s) {
	for (int b = 0; map->nb_box > b; ++b) {
            if (map->box_pos[b] == map->storage_pos[s])
                ++placed;
	}
    }
    if (placed != map->nb_storage)
        return (0);
    map->end = 0;
    return (1);
}

int get_line_pos(map_t *src, int pos)
{
    int line = 0;

    for (int i = 0; pos != i; ++i) {
        if ('\n' == src->map[i])
            ++line;
    }
    ++line;
    return (line);
}

int check_defeat(map_t *map)
{
    int side[4];
    int block_box[map->nb_box];
    int block = 0;

    for (int i = 0; map->nb_box > i; ++i) {
        side[0] = -(map->line_len[get_line_pos(map, map->box_pos[i])]);
        side[1] = 1;
        side[2] = map->line_len[get_line_pos(map, map->box_pos[i])];
        side[3] = -1;
        for (int c = 0; 3 > c; ++c) {
            map->map[map->box_pos[i] + side[c + 1]];
            if (map->map[map->box_pos[i] + side[c]] ==
                '#' && map->map[map->box_pos[i] + side[c + 1]] == '#')
                block_box[i] = 1;
        }
    }
    for (int i = 0; map->nb_box > i; ++i) {
        if (block_box[i] == 1)
            ++block;
    }
    if (block == map->nb_box) {
        map->end = 1;
        return (1);
    }
    return (0);
}
