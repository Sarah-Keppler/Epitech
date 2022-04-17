/*
** EPITECH PROJECT, 2019
** home_page.c
** File description:
** Init and display the home page.
*/

#include "world.h"

static char new_map(map_t *maps)
{
    maps->height = 6;
    maps->width = 6;
    maps->map_3d = create_default_3d_map();
    if (NULL == maps->map_3d)
        return ('1');
    maps->map_2d = create_2d_map(maps, maps->map_3d);
    if (NULL == maps->map_2d)
        return ('1');
    return ('0');
}

static char load_a_map(map_t *maps, char **av)
{
    char *map = import_a_map(av[1]);

    if (NULL == map || '1' == check_the_map(maps, map) ||
        '1' == create_the_map(maps, map, maps->width, maps->height))
        return ('1');
    return ('0');
}

static void home_event(world_t *world)
{
    while (sfRenderWindow_pollEvent(world->window, &world->event))
        if (world->event.type == sfEvtClosed)
            sfRenderWindow_close(world->window);
}

char home_page(world_t *world)
{
    home_t *home = world->home;
    int i = -1;

    home_event(world);
    if ('1' == state_hover_home(world, home->ref_button))
        return ('3');
    if (-1 != home->load_map) {
        while (home->av[++i]);
        if (2 == i && '1' == load_a_map(home->map, home->av))
            return ('1');
        else if (1 == i && '1' == new_map(home->map))
            return ('1');
        ++world->load_scene;
        return ('0');
    }
    if ('1' == draw_under_framerate(world, 0))
        return ('1');
    return ('0');
}
