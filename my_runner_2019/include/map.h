/*
** EPITECH PROJECT, 2019
** map.h
** File description:
** Struct of the map.
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>
#include "picture.h"
#include "game_object.h"

typedef struct map {
    char **src;
    p_obj_t ***sprites;
    float *block;
    int nb_tiles;
} map_t;

#endif /* MAP_H_ */
