/*
** EPITECH PROJECT, 2019
** My_RPG
** File description:
** My_RPG inspired from Dragon Quest.
*/

#include "project.h"

void anim_movement(player_t *player, int type)
{
    sfIntRect rect = sfSprite_getTextureRect(player->entity->sprite);

    rect.top = (type * PLAYER_H);
    rect.left += PLAYER_W;
    if ((PLAYER_W * 3) == rect.left)
        rect.left = 0;
    sfSprite_setTextureRect(player->entity->sprite, rect);
}
