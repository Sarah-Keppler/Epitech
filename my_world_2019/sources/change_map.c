/*
** EPITECH PROJECT, 2019
** change_map
** File description:
** Change the size of the map.
*/

#include "world.h"

char increase_map_height(world_t *world)
{
    map_t *maps = world->edit->map;

    if ('1' == update_3d_map(maps, maps->height + 1, maps->width))
        return ('1');
    return ('0');
}

char decrease_map_height(world_t *world)
{
    map_t *maps = world->edit->map;

    if (1 == maps->height)
        return ('0');
    if ('1' == update_3d_map(maps, maps->height - 1, maps->width))
        return ('1');
    return ('0');
}

char increase_map_width(world_t *world)
{
    map_t *maps = world->edit->map;

    if ('1' == update_3d_map(maps, maps->height, maps->width + 1))
        return ('1');
    return ('0');
}

char decrease_map_width(world_t *world)
{
    map_t *maps = world->edit->map;

    if (1 == maps->width)
        return ('0');
    if ('1' == update_3d_map(maps, maps->height, maps->width - 1))
        return ('1');
    return ('0');
}
