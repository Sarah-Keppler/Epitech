/*
** EPITECH PROJECT, 2019
** fhunter
** File description:
** functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_csfml.h"

int check_flag(int ac, char **av)
{
    if (ac == 2) {
        if ('-' == av[1][0] && 'h' == av[1][1]) {
            my_putstr("Welcome to My Hunter !\n");
            my_putstr("The goal is to catch as many as triforce you can !\n");
            my_putstr("Use your amazing mouse to catch them !\n");
            my_putstr("----------------\n");
            my_putstr("Sarah KEPPLER\n");
            return (0);
        } else
            return (84);
    } else if (ac > 2)
        return (84);
    return (1);
}

void destroy_all(game_t *h, bird_t *t)
{
    sfRenderWindow_destroy(h->window);
    sfSprite_destroy(h->bg.sprite);
    sfTexture_destroy(h->bg.texture);
    sfSprite_destroy(t->sprite);
    sfTexture_destroy(t->texture);
    free(t);
    free(h);
}

void chrono(sfClock *clock, sfTime *frametime, bird_t *triforce)
{
    float seconds = 0;

    seconds = frametime->microseconds;
    seconds /= 1000000;
    if (seconds > 0.075) {
        triforce->rect.left += 360;
        sfSprite_setTextureRect(triforce->sprite, triforce->rect);
        if (triforce->rect.left > 1440 - 360)
            triforce->rect.left = 0;
        sfClock_restart(clock);
    }
}
