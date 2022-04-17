/*
** EPITECH PROJECT, 2019
** menu
** File description:
** all menu function
*/

#include "project.h"

int option(rpg_t *rpg, home_t *menu)
{
    int click = 2;
    sfClock *clock = sfClock_create();
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (menu->scene == NULL || NULL == clock)
        return (-2);
    while (click == 2) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            click = click_scene(click, rpg->event, menu->scene, rpg->window);
        mouse_pos = particle_manage(rpg->window, menu->part, clock, mouse_pos);
        if (click >= 20) {
            option_gestion(click, rpg, menu);
            click = 2;
        }
        draw_scene(rpg, menu, 1);
        sfRenderWindow_display(rpg->window);
    }
    sfClock_destroy(clock);
    return (click);
}

int play_menu(rpg_t *rpg, home_t *menu)
{
    int click = 1;
    sfClock *clock = sfClock_create();
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (menu->scene == NULL || NULL == clock)
        return (-2);
    while (click == 1) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            click = click_scene(click, rpg->event, menu->scene, rpg->window);
        mouse_pos = particle_manage(rpg->window, menu->part, clock, mouse_pos);
        draw_scene(rpg, menu, 1);
        sfRenderWindow_display(rpg->window);
    }
    sfClock_destroy(clock);
    return (click);
}

int main_menu(rpg_t *rpg, home_t *menu)
{
    int click = 0;
    sfClock *clock = sfClock_create();
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (menu->scene == NULL || NULL == clock)
        return (-2);
    while (click == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            click = click_scene(click, rpg->event, menu->scene, rpg->window);
        if (click == -1)
            break;
        mouse_pos = particle_manage(rpg->window, menu->part, clock, mouse_pos);
        draw_scene(rpg, menu, 1);
        sfRenderWindow_display(rpg->window);
    }
    sfClock_destroy(clock);
    return (click);
}
