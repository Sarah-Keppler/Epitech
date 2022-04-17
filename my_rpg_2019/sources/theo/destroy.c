/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** free function
*/

#include "project.h"

int my_butlen(button_t **but)
{
    int i = 0;

    for (i = 0; but[i]; ++i);
    return (i);
}

particle_t *destroy_one(particle_t *particle, particle_t *copy)
{
    particle_t *previous = particle;

    while (previous->next != copy)
        previous = previous->next;
    previous->next = copy->next;
    previous = previous->next;
    if (copy->sprite)
        sfSprite_destroy(copy->sprite);
    if (copy->pixels)
        free(copy->pixels);
    free(copy);
    return (previous);
}
