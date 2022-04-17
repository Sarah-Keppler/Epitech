/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

char events(rpg_t *rpg, player_t *player, int i)
{
    void (*movement[4])(player_t *, map_t *) = {move_up, move_down, move_right,
        move_left};
    int pos[2] = {player->pos[0], player->pos[1]};

    movement[i](player, rpg->map);
    pos[0] = player->pos[0];
    pos[1] = player->pos[1];
    if ('G' == rpg->map->collisions[pos[1]][pos[0]]) {
        rpg->events[COMBAT_EVENT] = 1;
        if ('1' == engage_combat(rpg, player, rpg->monsters[0]))
            return ('1');
        rpg->events[COMBAT_EVENT] = -1;
        return ('0');
    }
    update_map(rpg, player, rpg->map->collisions[pos[1]][pos[0]]);
    return ('0');
}
