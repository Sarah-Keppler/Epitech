/*
** EPITECH PROJECT, 2019
** draw_world.c
** File description:
** Draw the map editor with framerate.
*/

#include "world.h"

static char draw_selection_tool(world_t *world, mouse_t *mouse)
{
    if ('1' == mouse->draw_circles && '1' == mouse->tiles)
        sfRenderWindow_drawCircleShape(world->window, mouse->circle, NULL);
    if ('0' == mouse->draw_circles && '1' == mouse->tiles)
        if ('1' == color_points_in_select_area(world))
            return ('1');
    if ('0' == mouse->draw_circles && '0' == mouse->tiles)
        if ('1' == color_points_of_a_tile(world))
            return ('1');
    return ('0');
}

static char draw_world(world_t *world, mouse_t *mouse)
{
    sfRenderWindow_clear(world->window, get_color(world->ref_color, "lBlack"));
    if ('1' == draw_2d_map(world))
        return ('1');
    print_edit(world->window, world->edit);
    if ('1' == draw_selection_tool(world, mouse))
        return ('1');
    sfRenderWindow_display(world->window);
    return ('0');
}

char draw_under_framerate(world_t *world, int load)
{
    float seconds = 0;

    world->frametime = sfClock_getElapsedTime(world->clock);
    seconds = world->frametime.microseconds;
    seconds /= 1000000;
    if (0.01 < seconds) {
        if (0 == load) {
            print_home(world->window, world->home);
            sfClock_restart(world->clock);
            return ('0');
        }
        if ('1' == draw_world(world, world->edit->mouse))
            return ('1');
        sfClock_restart(world->clock);
    }
    return ('0');
}
