/*
** EPITECH PROJECT, 2019
** color_tiles_and_corners
** File description:
** Color the tiles or the corners.
*/

#include "world.h"

char color_points_of_a_tile(world_t *world)
{
    mouse_t *mouse = world->edit->mouse;
    sfCircleShape *circle = NULL;
    int rad = 10;
    sfVector2f pos = {0, 0};

    for (int i = 0; 4 > i; ++i) {
        pos.x = mouse->points[i].x - rad;
        pos.y = mouse->points[i].y - rad;
        circle = create_a_circle_with_color(world, rad, "Turquoise", pos);
        if (NULL == circle)
            return ('1');
        sfRenderWindow_drawCircleShape(world->window, circle, NULL);
        sfCircleShape_destroy(circle);
    }
    return ('0');
}

static char color_the_points(world_t *world, int i)
{
    map_t *maps = world->edit->map;
    sfVector2f pos = {0, 0};
    sfCircleShape *circle = NULL;
    int rad = 10;

    for (int y = 0; maps->width > y; ++y)
        if ('0' == check_corner(world, maps->map_2d[i][y])) {
            pos.x = maps->map_2d[i][y].x - rad;
            pos.y = maps->map_2d[i][y].y - rad;
            circle = create_a_circle_with_color(world, rad, "Turquoise", pos);
            if (NULL == circle)
                return ('1');
            sfRenderWindow_drawCircleShape(world->window, circle, NULL);
            sfCircleShape_destroy(circle);
        }
    return ('0');
}

char color_points_in_select_area(world_t *world)
{
    map_t *maps = world->edit->map;

    for (int i = 0; maps->height > i; ++i)
        if ('1' == color_the_points(world, i))
            return ('1');
    return ('0');
}
