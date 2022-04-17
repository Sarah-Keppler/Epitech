/*
** EPITECH PROJECT, 2019
** display_level
** File description:
** Display one level.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "../include/my.h"
#include "../include/proto.h"

void display_parsing(runner_t *rnr, level_t *lvl)
{
    for (int i = 0; 3 > i; ++i) {
        sfRenderWindow_drawSprite(rnr->window,
                                  lvl->parsing[i]->bgp1->sprite, NULL);
        sfRenderWindow_drawSprite(rnr->window,
                                  lvl->parsing[i]->bgp2->sprite, NULL);
    }
}

void display_map(runner_t *rnr, map_t *map)
{
    for (int i = 0; 7 > i; ++i)
        for (int y = 0; map->nb_tiles > y; ++y)
            sfRenderWindow_drawSprite(rnr->window,
                                      map->sprites[i][y]->sprite, NULL);
}

void display_mob(runner_t *rnr)
{
    for (int i = 0; rnr->foes->number > i; ++i) {
        sfRenderWindow_drawSprite(
            rnr->window,
            rnr->foes->villains[i]->entity->sprite, NULL);
        sfRenderWindow_drawSprite(
            rnr->window,
            rnr->foes->villains[i]->collision->sprite, NULL);
    }
}

void display_game(runner_t *rnr, level_t *lvl)
{
    sfRenderWindow_clear(rnr->window, sfBlack);
    sfRenderWindow_drawSprite(rnr->window, lvl->wallpaper->sprite, NULL);
    display_parsing(rnr, lvl);
    display_map(rnr, rnr->map);
    display_mob(rnr);
    sfRenderWindow_drawSprite(rnr->window, lvl->player->entity->sprite, NULL);
    sfRenderWindow_display(rnr->window);
}
