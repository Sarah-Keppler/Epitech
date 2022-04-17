/*
** EPITECH PROJECT, 2019
** lower.c
** File description:
** Lower the ground.
*/

#include "world.h"

static void lower_tiles(world_t *world, int i)
{
    map_t *maps = world->edit->map;
    sfVector2f points[4];

    for (int y = 0; (maps->width - 1) > y; ++y) {
        points[0] = maps->map_2d[i][y];
        points[1] = maps->map_2d[i][y + 1];
        points[2] = maps->map_2d[i + 1][y + 1];
        points[3] = maps->map_2d[i + 1][y];
        if ('0' == check_if_mouse_tile(world->edit->mouse, points)) {
            --maps->map_3d[i][y];
            --maps->map_3d[i][y + 1];
            --maps->map_3d[i + 1][y + 1];
            --maps->map_3d[i + 1][y];
            update_2d_map(maps, maps->map_2d, maps->map_3d);
            center_the_map(maps, maps->map_2d);
        }
    }
}

static void lower_corners(world_t *world, int i)
{
    map_t *maps = world->edit->map;

    for (int y = 0; maps->width > y; ++y)
        if ('0' == check_corner(world, maps->map_2d[i][y])) {
            --maps->map_3d[i][y];
            update_2d_map(maps, maps->map_2d, maps->map_3d);
            center_the_map(maps, maps->map_2d);
        }
}

void lower_points(world_t *world)
{
    map_t *maps = world->edit->map;

    if ('0' == world->edit->mouse->tiles)
        for (int i = 0; (maps->height - 1) > i; ++i)
            lower_tiles(world, i);
    else
        for (int i = 0; maps->height > i; ++i)
            lower_corners(world, i);
}
