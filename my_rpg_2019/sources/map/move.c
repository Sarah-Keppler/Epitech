/*
** EPITECH PROJECT, 2019
** My_RPG
** File description:
** My_RPG inspired from Dragon Quest.
*/

#include "project.h"

void move_up(player_t *player, map_t *map)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(map->bg->sprite);
    rect.top -= BLOCK;
    rect.height = SCREEN_H;
    rect.width = SCREEN_W;
    player->pos[1] -= 1;
    sfSprite_setTextureRect(map->bg->sprite, rect);
    anim_movement(player, UP_M);
}

void move_down(player_t *player, map_t *map)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(map->bg->sprite);
    rect.top += BLOCK;
    rect.height = SCREEN_H;
    rect.width = SCREEN_W;
    player->pos[1] += 1;
    sfSprite_setTextureRect(map->bg->sprite, rect);
    anim_movement(player, DOWN_M);
}

void move_right(player_t *player, map_t *map)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(map->bg->sprite);
    rect.left += BLOCK;
    rect.height = SCREEN_H;
    rect.width = SCREEN_W;
    player->pos[0] += 1;
    sfSprite_setTextureRect(map->bg->sprite, rect);
    anim_movement(player, RIGHT_M);
}

void move_left(player_t *player, map_t *map)
{
    sfIntRect rect = {0, 0, 0, 0};

    rect = sfSprite_getTextureRect(map->bg->sprite);
    rect.left -= BLOCK;
    rect.height = SCREEN_H;
    rect.width = SCREEN_W;
    player->pos[0] -= 1;
    sfSprite_setTextureRect(map->bg->sprite, rect);
    anim_movement(player, LEFT_M);
}
