/*
** EPITECH PROJECT, 2019
** check_corners
** File description:
** Check if a corner is selected.
*/

#include "world.h"

static float get_distance_btwn_2points(sfVector2f point1, sfVector2f point2)
{
    float square_x = pow((point2.x - point1.x), 2.0);
    float square_y = pow((point2.y - point1.y), 2.0);
    float distance = sqrt((square_x + square_y));

    return (distance);
}

static void compare_distance_btwn_line_points(world_t *world, int i,
    int *index, float *smaller_distance)
{
    map_t *maps = world->edit->map;
    float distance = 0;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);
    sfVector2f mouse_posf = {(float)mouse_pos.x, (float)mouse_pos.y};

    for (int y = 0; world->edit->map->width > y; ++y) {
        distance = get_distance_btwn_2points(mouse_posf, maps->map_2d[i][y]);
        if (distance < *smaller_distance) {
            *smaller_distance = distance;
            index[0] = i;
            index[1] = y;
        }
    }
}

static void get_the_nearest_point(world_t *world, int *index)
{
    float smaller_distance = (world->edit->mouse->radius);

    for (int i = 0; world->edit->map->height > i; ++i)
        compare_distance_btwn_line_points(world, i, index, &smaller_distance);
}

char check_corner(world_t *world, sfVector2f point)
{
    int index[2] = {-1, -1};
    sfVector2f nearest_point = {0, 0};
    float distance = 0;

    get_the_nearest_point(world, index);
    if (-1 == index[0])
        return ('1');
    nearest_point = world->edit->map->map_2d[index[0]][index[1]];
    distance = get_distance_btwn_2points(nearest_point, point);
    if (distance > (world->edit->mouse->radius))
        return ('1');
    return ('0');
}
