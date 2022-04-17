/*
** EPITECH PROJECT, 2019
** collisions.c
** File description:
** Handle all collisions.
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

char collision_with_monsters(player_t *player, foes_t *f)
{
    sfFloatRect ply_rect = sfSprite_getGlobalBounds(player->collision->sprite);
    sfFloatRect mob_rect = {0, 0, 0, 0};

    for (int i = 0; f->number > i; ++i) {
        mob_rect = sfSprite_getGlobalBounds(f->villains[i]->collision->sprite);
        if (sfFloatRect_intersects(&ply_rect, &mob_rect, NULL))
            return ('1');
    }
    return ('0');
}

char collision_with_tiles(player_t *player, map_t *map)
{
    sfFloatRect ply_rect = sfSprite_getGlobalBounds(player->collision->sprite);
    sfFloatRect tile_rect = {0, 0, 0, 0};

    for (int i = 0; 7 > i; ++i) {
        for (int y = 0; map->nb_tiles > y; ++y) {
            tile_rect = sfSprite_getGlobalBounds(map->sprites[i][y]->sprite);
            if (sfFloatRect_intersects(&ply_rect, &tile_rect, NULL) &&
                map->sprites[i][y]->collision)
                return ('1');
        }
    }
    return ('0');
}

void move_hitbox(player_t *player, foes_t *foes)
{
    sfVector2f pos;

    pos.x = player->entity->position.x + (136 * 0.5);
    pos.y = player->entity->position.y + (34 * 0.5);
    sfSprite_setPosition(player->collision->sprite, pos);
    for (int i = 0; foes->number > i; ++i) {
        pos.x = foes->villains[i]->entity->position.x + (111 * 0.5);
        pos.y = foes->villains[i]->entity->position.y + (129 * 0.5);
        sfSprite_setPosition(foes->villains[i]->collision->sprite, pos);
    }
}

void check_collisions(runner_t *runner, level_t *level)
{
    if ('1' == collision_with_monsters(level->player, runner->foes))
        runner->scene = 3;
    if ('1' == collision_with_tiles(level->player, runner->map))
        runner->scene = 3;
}
