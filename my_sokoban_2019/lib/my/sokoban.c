/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** All functions linked to sokoban.h
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

void disp_storage(map_t *map)
{
    for (int i = 0; map->nb_storage > i; ++i) {
        if (' ' == map->map[map->storage_pos[i]])
            map->map[map->storage_pos[i]] = 'O';
    }
}

char **my_str_to_word_array(map_t *map)
{
    for (int i = 0; map->map[i]; ++i) {
        map->print_map[i][0] = map->map[i];
        map->print_map[i][1] = '\0';
    }
    map->print_map[map->len] = '\0';
}

void print_map(map_t *map)
{
    int nb_line = 0;
    int moy_colum = map->line_len[0];

    for (int i = 0; '\0' != map->map[i]; ++i)
        if ('\n' == map->map[i])
            ++nb_line;
    ++nb_line;
    if (LINES < nb_line || COLS < moy_colum) {
        move (LINES / 2, COLS / 2 - (27 / 2));
	printw("Please enlarge the terminal.");
    } else
        disp_map(map, nb_line / 2, moy_colum / 2);
}

void disp_map(map_t *map, int nb_line, int moy_colum)
{
    int line = 1;

    move(LINES / 2 - nb_line, COLS / 2 - moy_colum);
    for (int i = 0; my_strlen(map->map) > i; ++i) {
        if ('\n' != map->print_map[i][0])
            printw(map->print_map[i]);
        else {
            printw("\n");
            move(LINES / 2 + line - nb_line, COLS / 2 - moy_colum);
            ++line;
        }
    }
}
