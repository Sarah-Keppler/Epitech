/*
** EPITECH PROJECT, 2019
** player.h
** File description:
** Header for the player.
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct player {
    game_object_t *entity;
    sprite_t *collision;
} player_t;

#endif /* PLAYER_H_ */
