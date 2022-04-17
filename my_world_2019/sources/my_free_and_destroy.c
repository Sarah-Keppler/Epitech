/*
** EPITECH PROJECT, 2019
** my_free_and_destroy
** File description:
** Free and destroy the map editor.
*/

#include "world.h"

void my_free_maps(map_t *maps, char which_one)
{
    if ('0' == which_one || '2' == which_one) {
        for (int i = 0; maps->height; ++i)
            free(maps->map_3d[i]);
        free(maps->map_3d);
    }
    if ('1' == which_one || '2' == which_one) {
        for (int i = 0; maps->height; ++i)
            free(maps->map_2d[i]);
        free(maps->map_2d);
    }
}

void my_free_and_destroy(world_t *world)
{
    sfClock_destroy(world->clock);
    sfRenderWindow_destroy(world->window);
    free(world);
}
