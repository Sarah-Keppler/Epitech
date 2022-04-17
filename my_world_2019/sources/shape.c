/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** Create shapes.
*/

#include "world.h"

sfCircleShape *create_a_circle_with_color(world_t *world, float radius,
    char *color, sfVector2f position)
{
    sfCircleShape *circle = sfCircleShape_create();

    if (NULL == circle)
        return (NULL);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setFillColor(circle, get_color(world->ref_color, color));
    return (circle);
}
