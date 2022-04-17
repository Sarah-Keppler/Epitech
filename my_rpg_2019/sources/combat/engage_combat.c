/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

void event_battle(rpg_t *rpg, battle_t *battle)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg->window);
            battle->end = CLOSE;
        }
}

static char monster_turn(battle_t *battle)
{
    int i = 0;

    if ('1' == my_rand(&i, 0, 1))
        return ('1');
    battle->attack = battle->monster->attacks[i];
    attack(battle, NULL, battle->monster);
    return ('0');
}

static char fight(battle_t *battle)
{
    attack(battle, battle->player, NULL);
    if ('1' == monster_turn(battle))
        return ('1');
    battle->display = 0;
    battle->attack = NULL;
    return ('0');
}

char engage_combat(rpg_t *rpg, player_t *player, monster_t *monster)
{
    battle_t *battle = init_battle(player, monster);

    if (NULL == battle)
        return ('1');
    while (1 == battle->end) {
        event_battle(rpg, battle);
        choose(rpg, battle);
        if (CLOSE == battle->end)
            return ('0');
        if ('1' == fight(battle))
            return ('1');
        draw_battle(rpg, battle);
    }
    return ('0');
}
