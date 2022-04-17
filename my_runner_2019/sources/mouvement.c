/*
** EPITECH PROJECT, 2019
** mouvement.c
** File description:
** Make move.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void move_object(game_object_t *obj)
{
    obj->position.x -= obj->speed;
    sfSprite_setPosition(obj->sprite, obj->position);
    if (obj->position.x < -1552.0) {
        obj->position.x = 1552;
        sfSprite_setPosition(obj->sprite, obj->position);
    }
}

void move_tiles(p_obj_t *obj)
{
    obj->pos.x -= obj->speed;
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void move_monster(game_object_t *obj)
{
    obj->position.x -= obj->speed;
    sfSprite_setPosition(obj->sprite, obj->position);
}

void move(runner_t *runner, level_t *level)
{
    move_hitbox(level->player, runner->foes);
    for (int i = 0; 3 > i; ++i) {
        level->parsing[i]->bgp1->ptr_move = &move_object;
        level->parsing[i]->bgp2->ptr_move = &move_object;
        level->parsing[i]->bgp1->ptr_move(level->parsing[i]->bgp1);
        level->parsing[i]->bgp2->ptr_move(level->parsing[i]->bgp2);
    }
    for (int i = 0; runner->foes->number > i; ++i) {
        runner->foes->villains[i]->entity->ptr_move = &move_monster;
        runner->foes->villains[i]->entity->ptr_move(
            runner->foes->villains[i]->entity);
    }
    for (int i = 0; 7 > i; ++i)
        for (int y = 0; runner->map->nb_tiles > y; ++y)
            runner->map->sprites[i][y]->ptr_move(runner->map->sprites[i][y]);
    move_player(runner, level, runner->map);
}
