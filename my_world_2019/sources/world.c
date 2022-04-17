/*
** EPITECH PROJECT, 2019
** Init_world
** File description:
** Init the map editor.
*/

#include "world.h"

static sfRenderWindow *create_a_window(unsigned int w, unsigned int h, char *n)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = {w, h, 32};

    window = sfRenderWindow_create(video_mode, n, sfResize | sfClose, NULL);
    return (window);
}

world_t *init_world(char **av)
{
    world_t *world = malloc(sizeof(world_t));
    sfEvent event = {0};

    if (NULL == world)
        return (NULL);
    world->window = create_a_window(1920, 1080, "My_World");
    sfRenderWindow_setFramerateLimit(world->window, 120);
    world->event = event;
    world->load_scene = 0;
    world->clock = sfClock_create();
    if (NULL == world->clock)
        return (NULL);
    world->buttons = init_template_buttons();
    world->home = init_home(world, av);
    world->ref_color = init_color();
    world->edit = NULL;
    if (NULL == world->buttons || NULL == world->home ||
        NULL == world->ref_color)
        return (NULL);
    return (world);
}
