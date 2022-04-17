/*
** EPITECH PROJECT, 2020
** particle
** File description:
** the particle of menu
*/

#include "project.h"

static void set_data(sfTexture *text, particle_t **copy)
{
    sfTexture_updateFromPixels(text, (*copy)->pixels, 8, 1, 1, 0);
    sfTexture_updateFromPixels(text, (*copy)->pixels, 10, 8, 0, 1);
    sfTexture_updateFromPixels(text, (*copy)->pixels, 8, 1, 1, 9);
    sfSprite_setTexture((*copy)->sprite, text, true);
    sfSprite_setPosition((*copy)->sprite, (*copy)->position);
    *copy = (*copy)->next;
}

void modif_particle(particle_t *particle)
{
    particle_t *copy = particle->next;
    sfTexture *text;

    while (copy != copy->first) {
        text = (sfTexture*)(sfSprite_getTexture(copy->sprite));
        if (copy->pixels[3] >= 250)
            copy->inc = 1;
        if (copy->inc == 0)
            copy->pixels[3] += 5;
        else if ((copy->inc = 1) && copy->pixels[3] != 0)
            copy->pixels[3] -= 5;
        else {
            copy = destroy_one(particle, copy);
            continue;
        }
        set_data(text, &copy);
    }
}
