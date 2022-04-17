/*
** EPITECH PROJECT, 2019
** Change_state_home
** File description:
** Change the state of the home page buttons.
*/

#include "world.h"

static char redirect_a_button(world_t *world, int i)
{
    if (world->event.type == sfEvtMouseButtonReleased) {
        if (NEWMAP == i)
            world->home->load_map = 0;
        if (LOADMAP == i)
            world->home->load_map = 1;
        if (EXIT == i)
            return ('1');
    }
    return ('0');
}

static char state_pressed(world_t *world, button_t **buttons, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) ||
        world->event.type == sfEvtMouseButtonReleased) {
        buttons[i]->rect.left = 942;
        sfSprite_setTextureRect(buttons[i]->entity->sprite, buttons[i]->rect);
        if ('1' == redirect_a_button(world, i))
            return ('1');
    } else {
        buttons[i]->rect.left = 471;
        sfSprite_setTextureRect(buttons[i]->entity->sprite, buttons[i]->rect);
    }
    return ('0');
}

static char check_each_button_state(world_t *world, button_t **button, int i)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);

    if (sfFloatRect_contains(&button[i]->rectf, mouse_pos.x, mouse_pos.y)) {
        button[i]->rect.left = 471;
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
        if ('1' == state_pressed(world, button, i))
            return ('1');
    } else {
        button[i]->rect.left = 0;
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
    }
    return ('0');
}

char state_hover_home(world_t *world, button_t **button)
{
    for (int i = 0; HOME_BUTTON > i; ++i)
        if ('1' == check_each_button_state(world, button, i))
            return ('1');
    return ('0');
}
