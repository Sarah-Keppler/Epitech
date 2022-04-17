/*
** EPITECH PROJECT, 2019
** map
** File description:
** All functions linked to the map.h.
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

char *read_map(char **av, map_t *src)
{
    int fd = open(av[1], O_RDONLY);
    struct stat stats;

    if (-1 == fd) {
        my_putstr("The file didn't open -- Error\n");
        return (NULL);
    }
    if (0 == stat(av[1], &stats)) {
        src->map = malloc(sizeof(char) * (stats.st_size + 1));
        if (src->map == NULL)
            return (NULL);
        read(fd, src->map, stats.st_size);
    } else
        return (NULL);
    src->map[stats.st_size] = '\0';
    src->len = stats.st_size;
    close(fd);
    return (src->map);
}

void init_map2(map_t *map)
{
    map->player_pos = get_position_on_map('P', map->map);
    map->line_len = get_len_per_line(map);
    map->storage_pos = get_storages(map);
    map->box_pos = get_boxes(map);
}

map_t *init_map(char **av)
{
    map_t *map = malloc(sizeof(map_t));

    map->map = read_map(av, map);
    map->map_src = malloc(sizeof(char) * (map->len + 1));
    map->print_map = malloc(sizeof(char *) * (map->len + 1));
    if (map->print_map == NULL || map->map_src == NULL
        || map->map == NULL || map == NULL)
        return (NULL);
    for (int i = 0; map->map[i]; ++i) {
        map->print_map[i] = malloc(sizeof(char) * 2);
        if (map->print_map[i] == NULL)
            return (NULL);
    }
    map->map_src = my_strcpy(map->map_src, map->map);
    my_str_to_word_array(map);
    init_map2(map);
    if (map->box_pos == NULL || map->storage_pos == NULL
        || map->line_len == NULL)
        return (NULL);
    return (map);
}

void reset(int ch, map_t *map)
{
    if (ch == 32) {
        map->map = my_strcpy(map->map, map->map_src);
        map->player_pos = get_position_on_map('P', map->map);
        for (int i = 0; map->nb_box > i; ++i) {
            map->box_pos[i] = map->box_pos[i + map->nb_box];
        }
    }
}

void lets_free(map_t *map)
{
    free(map->map);
    free(map->map_src);
    for (int i = 0; map->len > i; ++i)
        free(map->print_map[i]);
    free(map->print_map);
    free(map->line_len);
    free(map->storage_pos);
    free(map->box_pos);
    free(map);
}
