/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** Init a player.
*/

#include "project.h"

static char set_sprites(player_t *player)
{
    sfVector2f pos_bg = {25, SCREEN_H - (250 + 25)};
    sfVector2f pos_close = {(25 + 400) - 50, SCREEN_H - (250 + 25) + 5};
    sfVector2f scale_bg = {0.66, 0.42};
    sfVector2f scale_close = {0.08, 0.08};

    player->bg = create_sprite(INVENT_I, pos_bg);
    player->close = create_sprite(CLOSE_I, pos_close);
    if (NULL == player->bg || NULL == player->close)
        return ('1');
    sfSprite_setScale(player->bg->sprite, scale_bg);
    sfSprite_setScale(player->close->sprite, scale_close);
    return ('0');
}

static char set_infos(sfText **texts, sfFont *font)
{
    sfVector2f pos = {25 + 10, SCREEN_H - (250 + 25) + 100};
    char *strings[8] = {"Vie:", " 100", "   /", " 100", "Exp:", "   0", "   /",
        "1000"};

    for (int s = 1; 5 > s; ++s) {
        texts[s] = create_text(strings[s - 1], font, 25, pos);
        if (NULL == texts[s])
            return ('1');
        pos.x += 50;
    }
    pos.y += 35;
    pos.x = 35;
    for (int s = 7; 11 > s; ++s) {
        texts[s] = create_text(strings[s - 3], font, 25, pos);
        if (NULL == texts[s])
            return ('1');
        pos.x += 50;
    }
    return ('0');
}

static char set_name_and_level(sfText **texts, sfFont *font, char *name)
{
    sfVector2f pos_name = {100, SCREEN_H - (250 + 25) + 8};
    sfVector2f pos_level = {35, SCREEN_H - (250 + 25) + 65};

    texts[0] = create_text(name, font, 30, pos_name);
    texts[5] = create_text("Level", font, 25, pos_level);
    pos_level.x += 75;
    texts[6] = create_text("1", font, 25, pos_level);
    if (NULL == texts[0] || NULL == texts[5] || NULL == texts[6])
        return ('1');
    return ('0');
}

char set_player_info(player_t *player)
{
    sfFont *font = sfFont_createFromFile(ARIAL_F);

    if (NULL == font)
        return ('1');
    if ('1' == set_name_and_level(player->infos, font, player->name) ||
        '1' == set_infos(player->infos, font) ||
        '1' == set_sprites(player))
        return ('1');
    return ('0');
}
