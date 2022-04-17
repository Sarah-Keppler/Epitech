/*
** EPITECH PROJECT, 2019
** game_object.h
** File description:
** Create game objects.
*/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <SFML/Graphics.h>

typedef enum object {
    background
} objType;

typedef struct s_game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    objType type;
    float speed;
    void (*ptr_move)(struct s_game_object *);
} game_object_t;

typedef struct picture_obj {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int collision;
    float speed;
    void (*ptr_move)(struct picture_obj *);
} p_obj_t;

#endif /* GAME_OBJECT_H_ */
