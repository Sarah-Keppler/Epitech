/*
** EPITECH PROJECT, 2019
** Init_world
** File description:
** Init the map editor.
*/

#include "world.h"

void center_the_map(map_t *maps, sfVector2f **map_2d)
{
    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y) {
            map_2d[i][y].x += (1920 / 2);
            map_2d[i][y].y += ((1080 / 2) - (64 * (maps->height / 2)));
        }
}

void reset_map(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            maps->map_3d[i][y] = 0;
    update_2d_map(maps, maps->map_2d, maps->map_3d);
    center_the_map(maps, maps->map_2d);
}

char reset_map_completely(world_t *world)
{
    edit_t *edit = world->edit;
    int **new_map = create_default_3d_map();

    if (NULL == new_map)
        return ('1');
    my_free_maps(edit->map, '2');
    edit->map->map_3d = new_map;
    edit->map->height = 6;
    edit->map->width = 6;
    edit->map->map_2d = create_2d_map(edit->map, edit->map->map_3d);
    if (NULL == edit->map->map_2d)
        return ('1');
    return ('0');
}
