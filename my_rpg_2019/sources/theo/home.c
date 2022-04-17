/*
** EPITECH PROJECT, 2019
** main
** File description:
** main GUI
*/

#include "project.h"

void draw_scene(rpg_t *rpg, home_t *menu, int draw_part)
{
    sprite_t *bg = menu->scene->background;

    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, bg->sprite, NULL);
    if (draw_part == 1)
        print_particle(menu->part, rpg->window);
    for (int i = 0; menu->scene->but[i]; ++i)
        sfRenderWindow_drawText(rpg->window, menu->scene->but[i]->text, NULL);
    check_if(rpg->window, menu->scene);
}

static scene_t *change_copy(scene_t *scene, int nb)
{
    while (scene->prev != NULL)
        scene = scene->prev;
    for (int i = 0; i < nb; ++i)
        scene = scene->next;
    return (scene);
}

static int play(rpg_t *rpg, home_t *home)
{
    rpg->load = 1;
    return (home->nb);
}

char home_page(rpg_t *rpg, home_t *home)
{
    int (*ptr[4])(rpg_t *, home_t *) = {main_menu, play_menu, option,
        play};

    if (home->nb >= 0 && home->nb < 4) {
        home->scene = change_copy(home->scene, home->nb);
        home->nb = ptr[home->nb](rpg, home);
    } else
        sfRenderWindow_close(rpg->window);
    if (-2 == home->nb)
        return ('1');
    return ('0');
}
