/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void draw_profil(sfRenderWindow *window, player_t *player,
    sprite_t **list)
{
    sfVector2f pos = {35, SCREEN_H - (250 + 25) + 185};
    sfVector2f scale = {0.78, 0.78};

    sfRenderWindow_drawSprite(window, player->bg->sprite, NULL);
    sfRenderWindow_drawSprite(window, player->close->sprite, NULL);
    for (int i = 0; 11 > i; ++i)
        sfRenderWindow_drawText(window, player->infos[i], NULL);
    for (int i = 0; 7 > i; ++i) {
        if (NULL != list[i]) {
            sfSprite_setScale(list[i]->sprite, scale);
            sfSprite_setPosition(list[i]->sprite, pos);
            sfRenderWindow_drawSprite(window, list[i]->sprite, NULL);
        }
        pos.x += 55;
        if (i == 6)
            pos.x += 60;
    }
}

static char event_profil(rpg_t *rpg, player_t *player, sprite_t **list)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)rpg->window);
    char rtn = '0';

    for (int i = 0; 7 > i; ++i) {
        if (NULL == list[i])
            continue;
        rect = sfSprite_getGlobalBounds(list[i]->sprite);
        if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) &&
            sfMouse_isButtonPressed(sfMouseRight) &&
            rpg->event.type == sfEvtMouseButtonReleased) {
            rtn = remove_a_set(rpg, player, i);
            list[i] = NULL;
            break;
        }
    }
    return (rtn);
}

static void init_set_sprites(rpg_t *rpg, sprite_t **list, set_t **armor)
{
    for (int i = 0; 7 > i; ++i) {
        if (NULL == armor[i])
            list[i] = NULL;
        else
            list[i] = find_ref_sprite(rpg, armor[i], NULL);
    }
}

char manage_profil(rpg_t *rpg, player_t *player)
{
    sprite_t *sprites[7];

    if (-1 == rpg->events[PROFIL_EVENT] || 1 == rpg->events[COMBAT_EVENT])
        return ('0');
    init_set_sprites(rpg, sprites, player->armor);
    check_close_window(rpg, player->close, PROFIL_EVENT);
    draw_profil(rpg->window, player, sprites);
    if ('1' == event_profil(rpg, player, sprites))
        return ('1');
    return ('0');
}
