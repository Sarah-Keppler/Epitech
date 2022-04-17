/*
** EPITECH PROJECT, 2019
** animation
** File description:
** Anim the game.
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void anim_player(game_object_t *player)
{
    player->rect.left += 416;
    sfSprite_setTextureRect(player->sprite, player->rect);
    if (player->rect.left > (8320 - (3 * 416)))
        player->rect.left = 0;
}

void anim_monster(monster_t **vil, int nb_mob)
{
    for (int i = 0; nb_mob > i; ++i) {
        vil[i]->entity->rect.left += 521;
        sfSprite_setTextureRect(vil[i]->entity->sprite, vil[i]->entity->rect);
        if (vil[i]->entity->rect.left > (5210 - 521 - 521))
            vil[i]->entity->rect.left = 0;
    }
}

void anim_level(runner_t *rnnr, level_t *lvl)
{
    float seconds = 0;

    lvl->frametime = sfClock_getElapsedTime(lvl->clock);
    seconds = lvl->frametime.microseconds;
    seconds /= 1000000;
    if (0.05 < seconds) {
        anim_player(lvl->player->entity);
        anim_monster(rnnr->foes->villains, rnnr->foes->number);
        sfClock_restart(lvl->clock);
    }
}
