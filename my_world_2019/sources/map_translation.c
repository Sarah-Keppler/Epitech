/*
** EPITECH PROJECT, 2019
** map_rotation
** File description:
** Rotate the map.
*/

#include "world.h"

void move_to_the_top(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            ++maps->map_2d[i][y].y;
}

void move_to_the_right(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            --maps->map_2d[i][y].x;
}

void move_to_the_bottom(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            --maps->map_2d[i][y].y;
}

void move_to_the_left(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            ++maps->map_2d[i][y].x;
}
