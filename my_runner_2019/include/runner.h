/*
** EPITECH PROJECT, 2019
** runner.h
** File description:
** Struct of a runner.
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "level.h"
#include "home.h"
#include "end.h"

typedef struct runner {
    sfRenderWindow *window;
    sfEvent event;
    int scene;
    map_t *map;
    level_t *level;
    home_t *home;
    foes_t *foes;
    end_t *game_over;
    end_t *win;
} runner_t;

#endif /* RUNNER_H_ */
