/*
** EPITECH PROJECT, 2019
** init_map
** File description:
** Init, print and free one map.
*/

#include "project.h"

void free_a_map(map_t *map)
{
    destroy_sprite(map->bg);
    for (int i = 0; map->collisions[i]; ++i)
        free(map->collisions[i]);
    free(map->collisions);
    free(map);
}

static char set_data_map(map_t *map, char **info)
{
    int nbr = -1;
    int len = 0;

    while (info[++nbr]);
    map->collisions = malloc(sizeof(char *) * (nbr + 1));
    if (NULL == map->collisions)
        return ('1');
    for (int i = 0; info[i]; ++i) {
        len = my_strlen(info[i]);
        map->collisions[i] = malloc(sizeof(char) * (len + 1));
        if (NULL == map->collisions[i])
            return ('1');
        my_strcpy(map->collisions[i], info[i]);
    }
    map->collisions[nbr] = NULL;
    return ('0');
}

map_t *create_a_map(char *map_name)
{
    char **info = get_a_file_source(MAP_PATH, map_name);
    map_t *new = malloc(sizeof(map_t));

    if (NULL == info)
        return (NULL);
    if ('1' == set_data_map(new, info))
        return (NULL);
    free_info(info);
    return (new);
}
