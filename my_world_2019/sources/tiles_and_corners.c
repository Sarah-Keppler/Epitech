/*
** EPITECH PROJECT, 2019
** tiles_and_corners
** File description:
** Switch between selection tool tile or corner.
*/

#include "world.h"

void active_tiles(world_t *world)
{
    world->edit->mouse->tiles = '0';
}

void active_corners(world_t *world)
{
    world->edit->mouse->tiles = '1';
}

void increase_select_area(world_t *world)
{
    mouse_t *mouse = world->edit->mouse;

    if ('1' == mouse->tiles) {
        if (500 <= mouse->radius)
            return;
        ++mouse->radius;
        sfCircleShape_setRadius(mouse->circle, mouse->radius);
    }
}

void decrease_select_area(world_t *world)
{
    mouse_t *mouse = world->edit->mouse;

    if ('1' == mouse->tiles) {
        if (25 >= mouse->radius)
            return;
        --mouse->radius;
        sfCircleShape_setRadius(mouse->circle, mouse->radius);
    }
}
