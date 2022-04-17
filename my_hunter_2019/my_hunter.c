/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** Need to put my great ideas.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my_csfml.h"

void event_clicked(game_t *h, bird_t *b)
{
    h->mouse = sfMouse_getPositionRenderWindow(h-> window);
    if (h->mouse.x >= b->position.x && h->mouse.x <= (b->position.x + 80))
        if (h->mouse.y >= b->position.y && h->mouse.y <= b->position.y + 70) {
            b->position.x = 0;
            b->position.y = rand() % (810);
        }
}

void event(game_t *hunter, bird_t *triforce)
{
    while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
        if (hunter->event.type == sfEvtClosed)
            sfRenderWindow_close(hunter->window);
        if (hunter->event.type == sfEvtMouseButtonPressed) {
            event_clicked(hunter, triforce);
        }
    }
}

void mouvement(bird_t *triforce)
{
    if (triforce->position.x <= 1440) {
        triforce->position.x += 5;
        triforce->position.y += 0;
    } else {
        triforce->position.x = 0;
        triforce->position.y = rand() % (810 - 87);
    }
    sfSprite_setPosition(triforce->sprite, triforce->position);
}

void game(game_t *hunter, bird_t *triforce)
{
    sfClock *clock = sfClock_create();
    sfTime frametime;

    while (sfRenderWindow_isOpen(hunter->window)) {
        event(hunter, triforce);
        frametime = sfClock_getElapsedTime(clock);
        chrono(clock, &frametime, triforce);
        sfRenderWindow_setFramerateLimit(hunter->window, 60);
        mouvement(triforce);
        sfRenderWindow_display(hunter->window);
        sfRenderWindow_drawSprite(hunter->window, hunter->bg.sprite, NULL);
        sfRenderWindow_drawSprite(hunter->window, triforce->sprite, NULL);
    }
}

int main(int ac, char **av)
{
    game_t *hunter = init_game_s();
    bird_t *triforce = init_bird();
    int check = check_flag(ac, av);

    if (84 == check)
        return (84);
    else if (0 == check)
        return (0);
    game(hunter, triforce);
    return (0);
}
