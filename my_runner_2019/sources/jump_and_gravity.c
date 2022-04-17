/*
** EPITECH PROJECT, 2019
** jump
** File description:
** Jump.
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void jump(level_t *lvl, game_object_t *player, char *gravity)
{
    int static push = 1.5;

    if ((lvl->last_ground - (300 + (454 * 0.5))) >= player->position.y) {
        *gravity = '1';
        lvl->jump = 0;
    }
    player->position.y += -push;
    sfSprite_setPosition(player->sprite, player->position);
}

void apply_gravity(map_t *map, level_t *lvl, game_object_t *ply, char *gravity)
{
    int floor = 0;

    for (int i = 0; map->block[i] < (ply->position.y + (454 / 2)); ++i)
        floor = i;
    if (lvl->ground != map->block[floor] && 0 == lvl->jump) {
        *gravity = '1';
    } else
        *gravity = '0';
    if ('1' == *gravity) {
        ply->position.y += 1.10;
        sfSprite_setPosition(ply->sprite, ply->position);
    }
}
