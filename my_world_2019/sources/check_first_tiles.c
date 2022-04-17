/*
** EPITECH PROJECT, 2019
** first_check_tile
** File description:
** First check of the slected tile. Check the positions.
*/

#include "world.h"

static void check_y_position(world_t *world, int *position, sfVector2f point)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);
    sfVector2f mouse_posf = {(float)mouse_pos.x, (float)mouse_pos.y};

    if (point.y > mouse_posf.y)
        ++position[3];
    if (point.y < mouse_posf.y)
        ++position[2];
}

static void check_x_position(world_t *world, int *position, sfVector2f point)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);
    sfVector2f mouse_posf = {(float)mouse_pos.x, (float)mouse_pos.y};

    if (point.x > mouse_posf.x)
        ++position[1];
    if (point.x < mouse_posf.x)
        ++position[0];
}

char first_check_tile(world_t *world, sfVector2f *points)
{
    int pos[4] = {0, 0, 0, 0};

    for (int i = 0; 4 > i; ++i) {
        check_x_position(world, pos, points[i]);
        check_y_position(world, pos, points[i]);
    }
    for (int i = 0; 4 > i; ++i)
        if (0 == pos[i])
            return ('1');
    return ('0');
}
