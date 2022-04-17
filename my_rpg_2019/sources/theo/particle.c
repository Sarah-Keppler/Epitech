/*
** EPITECH PROJECT, 2020
** particle
** File description:
** the particle of menu
*/

#include "project.h"

static sfUint8 *define_pixel(void)
{
    sfUint8 *pixels = malloc(128);

    pixels[0] = 0;
    pixels[1] = 0;
    pixels[2] = 0;
    pixels[3] = 5;
    return (pixels);
}

void print_particle(particle_t *particle, sfRenderWindow *window)
{
    particle_t *copy = particle->next;

    while (copy != copy->first) {
        sfRenderWindow_drawSprite(window, copy->sprite, NULL);
        copy = copy->next;
    }
}

void create_particle(sfRenderWindow *window, particle_t *particle)
{
    particle_t *new = malloc(sizeof(particle_t));
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfTexture *texture = sfTexture_copy((sfTexture *)
        sfSprite_getTexture(particle->sprite));

    new->inc = 0;
    new->position.x = (float)(pos.x) + (float)((rand() - 10) % 20);
    new->position.y = (float)(pos.y) + (float)((rand() - 10) % 20);
    new->sprite = sfSprite_copy(particle->sprite);
    new->pixels = define_pixel();
    new->first = particle->first;
    sfTexture_updateFromPixels(texture, new->pixels, 8, 1, 1, 0);
    sfTexture_updateFromPixels(texture, new->pixels, 10, 8, 0, 1);
    sfTexture_updateFromPixels(texture, new->pixels, 8, 1, 1, 9);
    particle->next = new;
    new->next = new->first;
}

particle_t *create_first_particle_point(void)
{
    particle_t *particule = malloc(sizeof(particle_t));
    sfTexture *texture = sfTexture_create(10, 10);

    particule->position.x = -1.0;
    particule->position.y = -1.0;
    particule->sprite = sfSprite_create();
    particule->pixels = define_pixel();
    particule->first = particule;
    particule->next = particule->first;
    sfTexture_updateFromPixels(texture, particule->pixels, 8, 1, 1, 0);
    sfTexture_updateFromPixels(texture, particule->pixels, 10, 8, 0, 1);
    sfTexture_updateFromPixels(texture, particule->pixels, 8, 1, 1, 9);
    sfSprite_setTexture(particule->sprite, texture, true);
    return (particule);
}
