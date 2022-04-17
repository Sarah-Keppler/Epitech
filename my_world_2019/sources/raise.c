/*
** EPITECH PROJECT, 2019
** raise.c
** File description:
** Raise the ground.
*/

#include "world.h"

static void raise_tiles(world_t *world, int i)
{
    map_t *maps = world->edit->map;
    sfVector2f points[4];

    for (int y = 0; (maps->width - 1) > y; ++y) {
        points[0] = maps->map_2d[i][y];
        points[1] = maps->map_2d[i][y + 1];
        points[2] = maps->map_2d[i + 1][y + 1];
        points[3] = maps->map_2d[i + 1][y];
        if ('0' == check_if_mouse_tile(world->edit->mouse, points)) {
            ++maps->map_3d[i][y];
            ++maps->map_3d[i][y + 1];
            ++maps->map_3d[i + 1][y + 1];
            ++maps->map_3d[i + 1][y];
            update_2d_map(maps, maps->map_2d, maps->map_3d);
            center_the_map(maps, maps->map_2d);
        }
    }
}

static void raise_corners(world_t *world, int i)
{
    map_t *maps = world->edit->map;

    for (int y = 0; maps->width > y; ++y)
        if ('0' == check_corner(world, maps->map_2d[i][y])) {
            ++maps->map_3d[i][y];
            update_2d_map(maps, maps->map_2d, maps->map_3d);
            center_the_map(maps, maps->map_2d);
        }
}

void raise_points(world_t *world)
{
    map_t *maps = world->edit->map;

    if ('0' == world->edit->mouse->tiles)
        for (int i = 0; (maps->height - 1) > i; ++i)
            raise_tiles(world, i);
    else
        for (int i = 0; maps->height > i; ++i)
            raise_corners(world, i);
}
