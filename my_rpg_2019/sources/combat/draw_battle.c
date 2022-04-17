/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void anim_the_king(rpg_t *rpg, monster_t *monster)
{
    float seconds = 0;
    sfIntRect rect = sfSprite_getTextureRect(monster->entity->sprite);

    rpg->frame = sfClock_getElapsedTime(rpg->clock);
    seconds = rpg->frame.microseconds;
    seconds /= 1000000;
    if (0.3 > seconds)
        return;
    rect.left += MONSTER_S;
    if ((MONSTER_S * 3) == rect.left)
        rect.left = 0;
    sfSprite_setTextureRect(monster->entity->sprite, rect);
    sfClock_restart(rpg->clock);
}

static void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->bg->sprite, NULL);
    for (int i = 0; menu->texts[i]; ++i)
        sfRenderWindow_drawText(window, menu->texts[i], NULL);
    sfRenderWindow_drawSprite(window, menu->cache->sprite, NULL);
}

void draw_battle(rpg_t *rpg, battle_t *battle)
{
    monster_t *monster = battle->monster;

    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, battle->bg->sprite, NULL);
    anim_the_king(rpg, monster);
    sfRenderWindow_drawSprite(rpg->window, monster->entity->sprite, NULL);
    draw_menu(rpg->window, battle->menu[battle->display]);
    sfRenderWindow_display(rpg->window);
}
