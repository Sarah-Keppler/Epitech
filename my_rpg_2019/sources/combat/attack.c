/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void check_death(battle_t *battle)
{
    if (0 >= battle->monster->life[0])
        battle->end = WIN;
    if (0 >= battle->player->life[0])
        battle->end = LOSE;
}

void attack(battle_t *battle, player_t *player, monster_t *monster)
{
    if (NULL == player)
        battle->player->life[0] -= battle->attack->damage;
    if (NULL == monster)
        battle->monster->life[0] -= battle->attack->damage;
    check_death(battle);
}
