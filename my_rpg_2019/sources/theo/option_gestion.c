/*
** EPITECH PROJECT, 2019
** option_gestion
** File description:
** fonction to modify screen size & sound
*/

#include "project.h"

static void rescreen(rpg_t *rpg, home_t *menu)
{
    sfVideoMode video;
    sfVector2u size = sfRenderWindow_getSize(rpg->window);

    if (size.x == 1320 && size.y == 840) {
        video = sfVideoMode_getDesktopMode();
        sfRenderWindow_close(rpg->window);
        sfRenderWindow_destroy(rpg->window);
        rpg->window = sfRenderWindow_create(video, "RPG", sfNone, NULL);
    } else {
        video = (sfVideoMode){1320, 840, 32};
        sfRenderWindow_close(rpg->window);
        sfRenderWindow_destroy(rpg->window);
        rpg->window = sfRenderWindow_create(video, "RPG", sfClose, NULL);
    }
    menu->scene = create_scene(rpg->window);
    menu->scene = menu->scene->next->next;
}

static void resound(home_t *menu)
{
    float sound = sfMusic_getVolume(menu->music);

    if (sound == 100.0)
        sfMusic_setVolume(menu->music, 0.0);
    else
        sfMusic_setVolume(menu->music, sound + 25.0);
}

void option_gestion(int click, rpg_t *rpg, home_t *menu)
{
    if (click == 21)
        rescreen(rpg, menu);
    return;
    if (click == 22)
        resound(menu);
}
