/*
** EPITECH PROJECT, 2019
** level
** File description:
** Play at one level.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void event_level(runner_t *runner, level_t *level)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) && 1 != (level->jump)) {
            level->jump = 1;
            level->last_ground = runner->level->ground;
        }
    }
}

void game(runner_t *runner)
{
    level_t *lvl = runner->level;
    char gravity = '0';

    event_level(runner, lvl);
    move(runner, runner->level);
    if (runner->level->jump && '0' == gravity)
        jump(runner->level, runner->level->player->entity, &gravity);
    else if (0 == runner->level->jump)
        apply_gravity(runner->map, lvl, lvl->player->entity, &gravity);
    check_collisions(runner, runner->level);
    anim_level(runner, runner->level);
    display_game(runner, runner->level);
}
