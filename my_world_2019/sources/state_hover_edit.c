/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** change_state
*/

#include "world.h"

static void nothing(world_t *world)
{
    return;
    my_put_nbr(world->edit->mouse->distance);
}

static char redirect_button(world_t *world, int index)
{
    void (*redirect[22])(world_t *) = {move_to_the_top, move_to_the_bottom,
        move_to_the_right, move_to_the_left, active_corners, active_circles,
        active_tiles, nothing, nothing, increase_select_area,
        decrease_select_area, nothing, nothing, nothing, nothing, nothing,
        nothing, nothing, nothing, nothing, nothing};

    if (IN_MAP == (index + 3) && ('1' == increase_map_height(world) ||
        '1' == increase_map_width(world)))
        return ('1');
    if (DE_MAP == (index + 3) && ('1' == decrease_map_height(world) ||
        '1' == decrease_map_width(world)))
        return ('1');
    redirect[index](world);
    return ('0');
}

static char state_pressed(world_t *world, button_t **button, int i, int *left)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) ||
        world->event.type == sfEvtMouseButtonReleased) {
        button[i]->rect.left = left[2];
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
        if ('1' == redirect_button(world, i))
            return ('1');
    } else {
        button[i]->rect.left = left[3];
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
    }
    return ('0');
}

static char check_each_button_state(world_t *world, button_t **button, int i,
    int *left)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)world->window);

    if (sfFloatRect_contains(&button[i]->rectf, mouse_pos.x, mouse_pos.y)) {
        button[i]->rect.left = left[0];
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
        if ('1' == state_pressed(world, button, i, left))
            return ('1');
    } else {
        button[i]->rect.left = left[1];
        sfSprite_setTextureRect(button[i]->entity->sprite, button[i]->rect);
    }
    return ('0');
}

char state_hover_edit(world_t *world, button_t **button)
{
    int left[4] = {63, 0, 126, 63};

    for (int i = 0; (EDIT_BUTTON - 3) > i; ++i)
        if ('1' == check_each_button_state(world, button, i, left))
            return ('1');
    left[0] = 47;
    left[2] = 94;
    left[3] = 47;
    for (int i = EDIT_BUTTON - 4; EDIT_BUTTON > i; ++i)
        if ('1' == check_each_button_state(world, button, i, left))
            return ('1');
    return ('0');
}
