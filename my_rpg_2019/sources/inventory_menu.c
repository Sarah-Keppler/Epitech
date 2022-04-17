/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static void draw_inventory(sfRenderWindow *window, inventory_t *invent)
{
    sfVector2f pos = {SCREEN_W - (300 + 25) + 15, SCREEN_H - (200 + 25) + 75};
    sprite_t *entity = NULL;

    sfRenderWindow_drawSprite(window, invent->bg->sprite, NULL);
    sfRenderWindow_drawSprite(window, invent->close->sprite, NULL);
    for (int i = 0; invent->texts[i]; ++i)
        sfRenderWindow_drawText(window, invent->texts[i], NULL);
    for (int i = 0; invent->items[i]; ++i) {
        entity = invent->items[i]->entity;
        sfSprite_setPosition(entity->sprite, pos);
        sfRenderWindow_drawSprite(window, entity->sprite, NULL);
        pos.x += 55;
        if (0 == ((i + 1) % 5) && 0 != i) {
            pos.y += 55;
            pos.x = SCREEN_W - (300 + 25) + 15;
        }
    }
}

static char event_inventory(rpg_t *rpg, player_t *player, inventory_t *invent)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)rpg->window);
    char rtn = '0';

    for (int i = 0; invent->items[i]; ++i) {
        rect = sfSprite_getGlobalBounds(invent->items[i]->entity->sprite);
        if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) &&
            sfMouse_isButtonPressed(sfMouseRight) &&
            rpg->event.type == sfEvtMouseButtonReleased) {
            rtn = wear_a_set(rpg, player, i);
            break;
        }
    }
    return (rtn);
}

char manage_inventory(rpg_t *rpg, player_t *player, inventory_t *invent)
{
    if (-1 == rpg->events[INVENT_EVENT] || 1 == rpg->events[COMBAT_EVENT])
        return ('0');
    check_close_window(rpg, invent->close, INVENT_EVENT);
    if ('1' == event_inventory(rpg, player, invent))
        return ('1');
    draw_inventory(rpg->window, invent);
    return ('0');
}
