/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

void check_close_window(rpg_t *rpg, sprite_t *close, int event)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)rpg->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(close->sprite);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        rpg->events[event] = -1;
}
