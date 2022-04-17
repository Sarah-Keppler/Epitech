/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** Init a player.
*/

#include "project.h"

void free_player(player_t *player)
{
    destroy_sprite(player->entity);
    free_an_inventory(player->inventory);
    free(player->attacks);
    free(player);
}

static char set_player_attacks(rpg_t *rpg, player_t *player)
{
    player->attacks = malloc(sizeof(attack_t *) * (2 + 1));

    if (NULL == player->attacks)
        return ('1');
    player->attacks[0] = find_ref_attack(rpg, "attack1");
    player->attacks[1] = find_ref_attack(rpg, "attack2");
    player->attacks[2] = NULL;
    return ('0');
}

static void set_player_armor(rpg_t *rpg, player_t *player)
{
    player->armor[0] = NULL;
    player->armor[1] = NULL;
    player->armor[2] = find_ref_set(rpg, "set2");
    player->armor[3] = find_ref_set(rpg, "set3");
    player->armor[4] = find_ref_set(rpg, "set4");
    player->armor[5] = NULL;
    player->armor[6] = find_ref_set(rpg, "set1");
}

static char set_player_sprite(player_t *player)
{
    sfVector2f position = {0, 0};
    sfIntRect rect = {0, 0, PLAYER_W, PLAYER_H};
    sfVector2f scale = {0.51, 0.5};

    position.x = (SCREEN_W / 2);
    position.y = (SCREEN_H / 2);
    player->entity = create_sprite_rect(PLAYER_I, rect, position);
    if (NULL == player->entity)
        return ('1');
    sfSprite_setScale(player->entity->sprite, scale);
    return ('0');
}

player_t *init_player(rpg_t *rpg, char *name)
{
    player_t *player = malloc(sizeof(player_t));

    if (NULL == player)
        return (NULL);
    player->name = name;
    player->level = 1;
    player->life[0] = 100;
    player->life[1] = 100;
    player->exp[0] = 1;
    player->exp[1] = 100;
    player->money = 0;
    set_player_armor(rpg, player);
    set_start_position(rpg, player);
    player->inventory = create_an_empty_inventory(10);
    if (NULL == player->inventory)
        return (NULL);
    if ('1' == set_player_sprite(player) || '1' == set_player_info(player) ||
        '1' == set_player_attacks(rpg, player))
        return (NULL);
    return (player);
}
