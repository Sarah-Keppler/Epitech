/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void select_attacks(rpg_t *rpg, battle_t *battle, menu_t *attack,
    int *current)
{
    sfVector2f pos = sfSprite_getPosition(attack->cache->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        rpg->event.type == sfEvtKeyReleased)
        battle->attack = battle->player->attacks[*current];
    if (sfKeyboard_isKeyPressed(sfKeyRight) && 0 == *current) {
        *current = 1;
        pos.x += 300;
        sfSprite_setPosition(attack->cache->sprite, pos);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft) && 1 == *current) {
        *current = 0;
        pos.x -= 300;
        sfSprite_setPosition(attack->cache->sprite, pos);
    }
}

static int select_options(rpg_t *rpg, battle_t *battle, menu_t *options,
    int *current)
{
    int option = -1;
    sfVector2f pos = sfSprite_getPosition(options->cache->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        rpg->event.type == sfEvtKeyReleased) {
        option = *current;
        *current = 0;
        battle->display = 1;
    } if (sfKeyboard_isKeyPressed(sfKeyDown) && 0 == *current) {
        *current = 1;
        pos.y += 50;
        sfSprite_setPosition(options->cache->sprite, pos);
    } if (sfKeyboard_isKeyPressed(sfKeyUp) && 1 == *current) {
        *current = 0;
        pos.y -= 50;
        sfSprite_setPosition(options->cache->sprite, pos);
    }
    return (option);
}

void choose(rpg_t *rpg, battle_t *battle)
{
    int option = -1;
    int current = 0;

    while (NULL == battle->attack && CLOSE != battle->end) {
        event_battle(rpg, battle);
        draw_battle(rpg, battle);
        if (-1 != option) {
            select_attacks(rpg, battle, battle->menu[1], &current);
            continue;
        }
        option = select_options(rpg, battle, battle->menu[0], &current);
        if (1 == option)
            battle->end = CLOSE;
    }
}
