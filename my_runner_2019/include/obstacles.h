/*
** EPITECH PROJECT, 2019
** obstacles
** File description:
** YOU SHALL NOT PASS ! Create objects to stop the player.
*/

#include <SFML/Graphics.h>

#ifndef OBSTACLES_H_
#define OBSTACLES_H_

//typedef enum obstacles {
//    hole,
//    fences;
//} obsType;

typedef struct obstacles_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int height;
    int width;
    float speed;
} obstacles_t;

#endif /* OBSTACLES_H_ */
