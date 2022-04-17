/*
** EPITECH PROJECT, 2019
** picture.h
** File description:
** Struct for image.
*/

#ifndef PICTURE_H_
#define PICTURE_H_

#include "game_object.h"

typedef struct s_picture {
    game_object_t *bgp1;
    game_object_t *bgp2;
    sfVector2f vect;
} picture_t;

typedef struct sprite {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

#endif /* PICTURE_H_ */
