/*
** EPITECH PROJECT, 2019
** My_RPG
** File description:
** My_RPG inspired from Dragon Quest.
*/

#include "project.h"

static char check_collisions(player_t *player, map_t *map, int type)
{
    char **col = map->collisions;
    int pos[2] = {player->pos[0], player->pos[1]};
    int next[4][2] = {{pos[0], pos[1] - 1}, {pos[0] + 1, pos[1]},
        {pos[0], pos[1] + 1}, {pos[0] - 1, pos[1]}};

    for (int i = 0; DENIED[i]; ++i)
        if (DENIED[i] == col[next[type][1]][next[type][0]])
            return ('0');
    return ('1');
}

static char check_events(player_t *player, map_t *map, int type)
{
    char **col = map->collisions;
    int pos[2] = {player->pos[0], player->pos[1]};
    int next[4][2] = {{pos[0], pos[1] - 1}, {pos[0] + 1, pos[1]},
        {pos[0], pos[1] + 1}, {pos[0] - 1, pos[1]}};

    for (int i = 0; NOTSPE[i]; ++i)
        if (NOTSPE[i] == col[next[type][1]][next[type][0]])
            return ('1');
    return ('0');
}

static char engage_movement(rpg_t *rpg, player_t *player, map_t *map, int i)
{
    int type[4] = {UP_M, DOWN_M, RIGHT_M, LEFT_M};
    void (*movement[4])(player_t *, map_t *) = {move_up, move_down, move_right,
        move_left};

    if ('0' == check_collisions(player, map, type[i]))
        return ('0');
    if ('0' == check_events(player, map, type[i])) {
        if ('1' == events(rpg, player, i))
            return ('1');
        return ('0');
    }
    movement[i](player, map);
    return ('0');
}

char movement(rpg_t *rpg, player_t *player, map_t *map)
{
    sfKeyCode key_list[4] = {sfKeyUp, sfKeyDown, sfKeyRight, sfKeyLeft};
    float seconds = 0;
    char rtn = '0';

    rpg->frame = sfClock_getElapsedTime(rpg->clock);
    seconds = rpg->frame.microseconds;
    seconds /= 1000000;
    if (0.07 > seconds)
        return ('0');
    for (int i = 0; 4 > i; ++i)
        if (sfKeyboard_isKeyPressed(key_list[i]))
            rtn = engage_movement(rpg, player, map, i);
    sfClock_restart(rpg->clock);
    return (rtn);
}
