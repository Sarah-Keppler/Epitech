/*
** EPITECH PROJECT, 2019
** mouse
** File description:
** Init and execute the mouse struct.
*/

#include "world.h"

void active_circles(world_t *world)
{
    world->edit->mouse->draw_circles = '0';
}

void desactive_circles(world_t *world)
{
    world->edit->mouse->draw_circles = '1';
}

void circle_follow_mouse(sfCircleShape *circle, world_t *world,
    int offsetting_x, int offsetting_y)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);
    sfVector2f new_pos = {(float)mouse_pos.x, (float)mouse_pos.y};

    new_pos.x += offsetting_x;
    new_pos.y += offsetting_y;
    sfCircleShape_setPosition(circle, new_pos);
}

char check_if_mouse_tile(mouse_t *mouse, sfVector2f *points)
{
    for (int i = 0; 4 > i; ++i)
        if (points[i].x != mouse->points[i].x ||
            points[i].y != mouse->points[i].y)
            return ('1');
    return ('0');
}

mouse_t *init_mouse(world_t *world)
{
    mouse_t *mouse = malloc(sizeof(mouse_t));
    sfVector2f pos = {0, 0};

    if (NULL == mouse)
        return (NULL);
    mouse->radius = 50;
    mouse->draw_circles = '1';
    mouse->tiles = '1';
    for (int i = 0; 4 > i; ++i)
        mouse->points[i] = pos;
    mouse->distance = 2000;
    mouse->circle = create_a_circle_with_color(world, mouse->radius,
        "ATurquoise", pos);
    if (NULL == mouse->circle)
        return (NULL);
    return (mouse);
}
