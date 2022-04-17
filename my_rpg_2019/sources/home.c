/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void draw_home(sfRenderWindow *window, home_t *home)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, home->bg->sprite, NULL);
    for (int i = 0; home->texts[i]; ++i)
        sfRenderWindow_drawText(window, home->texts[i], NULL);
    sfRenderWindow_display(window);
}

char home_page(rpg_t *rpg, home_t *home)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            rpg->load = 1;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(rpg->window);
    }
    draw_home(rpg->window, home);
    return ('0');
}
