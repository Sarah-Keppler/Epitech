/*
** EPITECH PROJECT, 2019
** armor
** File description:
** Manage armor: Add a set, remove a set.
*/

#include "project.h"

char wear_a_set(rpg_t *rpg, player_t *player, int pos)
{
    set_t **armor = player->armor;
    inventory_t *invent = player->inventory;
    set_t *set = invent->items[pos]->set;
    char rtn = '0';

    if (NULL == armor[set->type]) {
        armor[set->type] = set;
        free(invent->items[pos]);
        invent->items[pos] = NULL;
        --invent->occupied;
    }
    rtn = add_an_item(rpg, invent, armor[set->type], NULL);
    remove_an_item(invent, pos);
    if ('3' == rtn)
        return ('1');
    armor[set->type] = set;
    return ('0');
}

char remove_a_set(rpg_t *rpg, player_t *player, int pos)
{
    char rtn = '0';

    rtn = add_an_item(rpg, player->inventory, player->armor[pos], NULL);
    if ('1' == rtn)
        return ('0');
    if ('3' == rtn)
        return ('1');
    player->armor[pos] = NULL;
    return ('0');
}
