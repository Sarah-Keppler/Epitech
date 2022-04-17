/*
** EPITECH PROJECT, 2019
** evil_force.h
** File description:
** Structure of monster.
*/

#ifndef EVIL_FORCE_H_
#define EVIL_FORCE_H_

#include <SFML/Graphics.h>
#include "game_object.h"
#include "picture.h"

typedef struct monster {
    game_object_t *entity;
    sprite_t *collision;
} monster_t;

typedef struct foes {
    char *spawn;
    int number;
    monster_t **villains;
} foes_t;

#endif /* EVIL_FORCE_H_ */
