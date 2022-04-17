/*
** EPITECH PROJECT, 2019
** get_data
** File description:
** All functions who can get you some interesing data about the map.
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

int *get_storages(map_t *map)
{
    int *storage;
    int y = 0;

    map->nb_storage = 0;
    for (int i = 0; map->map[i]; ++i) {
        if ('O' == map->map[i])
            ++(map->nb_storage);
    }
    storage = malloc(sizeof(int) * map->nb_storage);
    if (storage == NULL)
        return (NULL);
    for (int i = 0; '\0' != map->map[i]; ++i) {
        if ('O' == map->map[i]) {
            storage[y] = i;
            ++y;
        }
    }
    return (storage);
}

int *get_boxes(map_t *map)
{
    int *box;
    int y = 0;

    map->nb_box = 0;
    for (int i = 0; '\0' != map->map[i]; ++i) {
        if ('X' == map->map[i])
            ++(map->nb_box);
    }
    box = malloc(sizeof(int) * (2 * map->nb_box));
    if (box == NULL)
        return (NULL);
    for (int i = 0; '\0' != map->map[i]; ++i) {
        if ('X' == map->map[i]) {
            box[y] = i;
            box[y + map->nb_box] = i;
            ++y;
        }
    }
    return (box);
}

int get_position_on_map(char c, char *map)
{
    for (int i = 0; '\0' != map[i]; ++i) {
        if (c == map[i])
            return (i);
    }
}

int get_line_player(map_t *src)
{
    int line = 0;

    for (int i = 0; 'P' != src->map[i]; ++i) {
        if ('\n' == src->map[i])
            ++line;
    }
    return (line);
}

int *get_len_per_line(map_t *src)
{
    int nb_n = 0;
    int size = 0;
    int y = 0;
    int *len;

    for (int i = 0; '\0' != src->map[i]; ++i)
        if ('\n' == src->map[i])
            ++nb_n;
    len = malloc(sizeof(int) * (nb_n + 1));
    if (len == NULL)
        return (NULL);
    for (int i = 0; '\0' != src->map[i]; ++i) {
        ++size;
        if ('\n' == src->map[i] || '\0' == src->map[i + 1]) {
            len[y] = size;
            size = 0;
            ++y;
        }
    }
    len[nb_n] += 1;
    return (len);
}
