/*
** EPITECH PROJECT, 2019
** check_tiles
** File description:
** Check with tile is selected.
*/

#include "world.h"

static void change_mouse_quad(mouse_t *mouse, float new_distance,
    sfVector2f *points)
{
    mouse->points[0] = points[0];
    mouse->points[1] = points[1];
    mouse->points[2] = points[2];
    mouse->points[3] = points[3];
    mouse->distance = new_distance;
}

static float get_distance_btwn_point_mouse(world_t *world, sfVector2f point)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);
    sfVector2f mouse_posf = {(float)mouse_pos.x, (float)mouse_pos.y};
    float square_x = pow((mouse_posf.x - point.x), 2.0);
    float square_y = pow((mouse_posf.y - point.y), 2.0);
    float distance = sqrt((square_x + square_y));

    return (distance);
}

static void second_check(world_t *world, sfVector2f *points)
{
    edit_t *edit = world->edit;
    float middle_x = (points[0].x + points[1].x) / 2;
    float middle_y = (points[0].y + points[1].y) / 2;
    sfVector2f middle_point = {middle_x, middle_y};
    float distance = get_distance_btwn_point_mouse(world, middle_point);

    if (distance < edit->mouse->distance)
        change_mouse_quad(edit->mouse, distance, points);
}

static void first_check(world_t *world, int i)
{
    edit_t *edit = world->edit;
    sfVector2f points[4];

    for (int y = 0; (edit->map->width - 1) > y; ++y) {
        points[0] = edit->map->map_2d[i][y];
        points[1] = edit->map->map_2d[i][y + 1];
        points[2] = edit->map->map_2d[i + 1][y + 1];
        points[3] = edit->map->map_2d[i + 1][y];
        if ('0' == first_check_tile(world, points))
            second_check(world, points);
    }
}

void check_tiles(world_t *world)
{
    edit_t *edit = world->edit;

    for (int i = 0; (edit->map->height - 1) > i; ++i)
        first_check(world, i);
    edit->mouse->distance = 2000;
}
