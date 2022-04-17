/*
** EPITECH PROJECT, 2020
** particle_gest
** File description:
** particle gestion
*/

#include "project.h"

void particle_gestion(particle_t *particle, sfRenderWindow *window)
{
    particle_t *copy = particle;

    while (copy->next != particle)
        copy = copy->next;
    create_particle(window, copy);
}

sfVector2i particle_manage(sfRenderWindow *window, particle_t *particle,
    sfClock *clock, sfVector2i mouse_pos_save)
{
    sfTime time;
    float compare;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    time = sfClock_getElapsedTime(clock);
    mouse_pos = sfMouse_getPositionRenderWindow(window);
    compare = sfTime_asSeconds(time) * 1000.0;
    if ((int)(compare) % 2 == 0) {
        modif_particle(particle);
    }
    if ((int)(compare) % 3 == 0 && (mouse_pos.x != mouse_pos_save.x ||
        mouse_pos.y != mouse_pos_save.y)) {
        particle_gestion(particle, window);
    }
    return (mouse_pos);
}
