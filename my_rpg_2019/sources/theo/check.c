/*
** EPITECH PROJECT, 2019
** check
** File description:
** all check function
*/

#include "project.h"

int check_pos(button_t *but, sfVector2i posm, int i)
{
    int here = 0;

    if ((float)(posm.x) >= but->pos.x &&
        (float)(posm.x) <= (but->pos.x) + (but->value.width * but->scale.x))
        ++here;
    if ((float)(posm.y) >= (but->pos.y) &&
        (float)(posm.y) <= (but->pos.y + (but->value.height * but->scale.y))
        && here)
        return (i);
    return (-1);
}

void check_if(sfRenderWindow *window, scene_t *scene)
{
    sfVector2i posm = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos;
    int nb = -1;

    nb = check_pos(scene->but[0], posm, 0);
    for (int i = 1; scene->but[i] && nb == -1; ++i)
        nb = check_pos(scene->but[i], posm, i);
    if (nb != -1) {
        pos = scene->cache_pos;
        pos.x += scene->but[nb]->pos.x;
        pos.y += scene->but[nb]->pos.y;
        sfSprite_setPosition(scene->cache->sprite, pos);
        sfRenderWindow_drawSprite(window, scene->cache->sprite, NULL);
    }
}
