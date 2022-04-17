/*
** EPITECH PROJECT, 2019
** My_RPG
** File description:
** My_RPG inspired from Dragon Quest.
*/

#include "project.h"

void set_start_position(rpg_t *rpg, player_t *player)
{
    if (find_ref_map(rpg, "map1") == rpg->map) {
        player->pos[0] = 78;
        player->pos[1] = 14;
    } if (find_ref_map(rpg, "map2") == rpg->map) {
        player->pos[0] = 56;
        player->pos[1] = 46;
    }
}

static void set_position(rpg_t *rpg, player_t *player)
{
    if (find_ref_map(rpg, "map1") == rpg->map) {
        player->pos[0] = 61;
        player->pos[1] = 4;
    } if (find_ref_map(rpg, "map2") == rpg->map) {
        player->pos[0] = 56;
        player->pos[1] = 46;
    }
}

static void set_start_data_map(map_t **maps)
{
    sfIntRect rect1 = {320, 16, SCREEN_W, SCREEN_H};
    sfIntRect rect2 = {224, 752, SCREEN_W, SCREEN_H};

    sfSprite_setTextureRect(maps[0]->bg->sprite, rect1);
    sfSprite_setTextureRect(maps[1]->bg->sprite, rect2);
}

void update_map(rpg_t *rpg, player_t *player, char map)
{
    char path[5] = "map";

    path[3] = map;
    path[4] = '\0';
    set_start_data_map(rpg->maps);
    rpg->map = find_ref_map(rpg, path);
    set_position(rpg, player);
}
