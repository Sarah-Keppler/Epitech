/*
** EPITECH PROJECT, 2019
** HUD_scene.c
** File description:
** Load HUD Scenes.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void game_over_scene(runner_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->event))
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
    sfRenderWindow_clear(runner->window, sfBlack);
    sfRenderWindow_drawSprite(runner->window, runner->game_over->bg_s, NULL);
    sfRenderWindow_drawText(runner->window, runner->game_over->text, NULL);
    sfRenderWindow_display(runner->window);
}

void win_scene(runner_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->event))
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
    sfRenderWindow_clear(runner->window, sfBlack);
    sfRenderWindow_drawSprite(runner->window, runner->win->bg_s, NULL);
    sfRenderWindow_drawText(runner->window, runner->win->text, NULL);
    sfRenderWindow_display(runner->window);
}

void home_scene(runner_t *runner)
{
    while (sfRenderWindow_pollEvent(runner->window, &runner->event)) {
        if (runner->event.type == sfEvtClosed)
            sfRenderWindow_close(runner->window);
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            runner->scene = 2;
    }
    sfRenderWindow_clear(runner->window, sfBlack);
    sfRenderWindow_drawSprite(runner->window, runner->home->bg_s, NULL);
    sfRenderWindow_drawText(runner->window, runner->home->text[0], NULL);
    sfRenderWindow_drawText(runner->window, runner->home->text[1], NULL);
    sfRenderWindow_display(runner->window);
}
