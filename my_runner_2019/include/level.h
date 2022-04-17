/*
** EPITECH PROJECT, 2019
** level.h
** File description:
** Header for one level.
*/

#ifndef LEVEL_H_
#define LEVEL_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "home.h"
#include "picture.h"
#include "player.h"
#include "proto.h"

//typedef struct score {
//    text_t *text;
//    char *txt_score;
//    int score;
//} score_t;

typedef struct level {
    sprite_t *wallpaper;
    picture_t **parsing;
    sfClock *clock;
    sfTime frametime;
    player_t *player;
    int jump;
    int ground;
    int last_ground;
    char **info;
    sfMusic *audio;
    //sfMusic *sound;
    int score;
    
} level_t;

#endif /* LEVEL_H_ */
