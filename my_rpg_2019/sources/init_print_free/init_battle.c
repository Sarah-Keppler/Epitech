/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static char set_text_attack(sfFont *font, sfText **texts, player_t *player)
{
    sfVector2f tmp = {360 + 40 + 60, SCREEN_H - (200 + 25) + 55};
    int nbr = -1;

    while (player->attacks[++nbr]);
    for (int i = 0; nbr > i; ++i) {
        texts[i] = create_text(player->attacks[i]->name, font, 15, tmp);
        if (NULL == texts[i])
            return ('1');
        tmp.x += 300;
    }
    texts[nbr] = NULL;
    return ('0');
}

static char set_text_option(sfFont *font, sfText **texts)
{
    char *options[OPTION_MAX] = {"Attaquer", "Fuir"};
    sfVector2f tmp = {360 + 40 + 60, SCREEN_H - (200 + 25) + 50};

    for (int i = 0; OPTION_MAX > i; ++i) {
        texts[i] = create_text(options[i], font, 30, tmp);
        if (NULL == texts[i])
            return ('1');
        tmp.y += 50;
    }
    texts[OPTION_MAX] = NULL;
    return ('0');
}

static menu_t *create_menu(int nb_text)
{
    menu_t *new = malloc(sizeof(menu_t));
    sfVector2f menu_pos = {360, SCREEN_H - (200 + 25)};
    sfVector2f cache_pos = {360 + 40, SCREEN_H - (200 + 25) + 50};
    sfVector2f scale = {1, 0.3};

    if (NULL == new)
        return (NULL);
    new->bg = create_sprite(MENU_I, menu_pos);
    new->texts = malloc(sizeof(sfText *) * (nb_text + 1));
    new->font = sfFont_createFromFile(RAVENNA_F);
    new->cache = create_sprite(CACHE_I, cache_pos);
    if (NULL == new->bg || NULL == new->texts || NULL == new->font ||
        NULL == new->cache)
        return (NULL);
    sfSprite_setScale(new->bg->sprite , scale);
    return (new);
}

static char set_menu(battle_t *battle, player_t *player)
{
    int nbr[2] = {OPTION_MAX, -1};

    while (player->attacks[++nbr[1]]);
    for (int i = 0; 2 > i; ++i) {
        battle->menu[i] = create_menu(nbr[i]);
        if (NULL == battle->menu[i])
            return ('1');
    }
    battle->menu[2] = NULL;
    if ('1' == set_text_option(battle->font, battle->menu[0]->texts) ||
        '1' == set_text_attack(battle->font, battle->menu[1]->texts, player))
        return ('1');
    return ('0');
}

battle_t *init_battle(player_t *player, monster_t *monster)
{
    battle_t *new = malloc(sizeof(battle_t));
    sfVector2f pos = {0, 0};
    sfVector2f scale = {0.69, 0.78};

    if (NULL == new)
        return (NULL);
    new->bg = create_sprite(BATTLE_I, pos);
    new->font = sfFont_createFromFile(RAVENNA_F);
    if (NULL == new->bg || NULL == new->font)
        return (NULL);
    sfSprite_setScale(new->bg->sprite, scale);
    if ('1' == set_menu(new, player))
        return (NULL);
    new->attack = NULL;
    new->display = 0;
    new->end = 1;
    new->player = player;
    new->monster = monster;
    return (new);
}
