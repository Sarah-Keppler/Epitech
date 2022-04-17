/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"


static char draw_dragon_quest(rpg_t *rpg, player_t *player)
{
    sfRenderWindow_clear(rpg->window, sfCyan);
    if (NULL == rpg->map)
        return ('0');
    sfRenderWindow_drawSprite(rpg->window, rpg->map->bg->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, player->entity->sprite, NULL);
    if ('1' == manage_inventory(rpg, player, player->inventory) ||
        '1' == manage_profil(rpg, player))
        return ('1');
    sfRenderWindow_display(rpg->window);
    return ('0');
}

static char check_end(player_t *player, monster_t *monster)
{
    if (0 >= monster->life[0])
        return ('0');
    if (0 >= player->life[0])
        return ('0');
    return ('1');
}

char dragon_quest(rpg_t *rpg, player_t *player)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (sfKeyboard_isKeyPressed(sfKeyI))
            rpg->events[INVENT_EVENT] = 1;
        if (sfKeyboard_isKeyPressed(sfKeyP))
            rpg->events[PROFIL_EVENT] = 1;
    }
    if ('1' == movement(rpg, player, rpg->map))
        return ('1');
    if ('0' == check_end(player, rpg->monsters[0]))
        sfRenderWindow_close(rpg->window);
    if ('1' == draw_dragon_quest(rpg, player))
        return ('1');
    return ('0');
}
