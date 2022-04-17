/*
** EPITECH PROJECT, 2019
** Shortcut
** File description:
** Define each shortcut and bind it.
*/

#include "world.h"

static void create_a_keycode_list(sfKeyCode *list)
{
    list[0] = sfKeyT;
    list[1] = sfKeyC;
    list[2] = sfKeyX;
    list[3] = sfKeyV;
    list[4] = sfKeyF;
    list[5] = sfKeyG;
    list[6] = sfKeyA;
    list[7] = sfKeyE;
    list[8] = sfKeySpace;
    list[9] = sfKeyEscape;
    list[10] = sfKeyM;
    list[11] = sfKeyL;
    list[12] = sfKeyO;
    list[13] = sfKeyP;
    list[14] = sfKeyU;
    list[15] = sfKeyI;
}

void nothing(world_t *world)
{
    return;
    my_put_nbr(world->edit->mouse->distance);
}

char use_keyboard(world_t *world)
{
    sfKeyCode key_list[16];
    void (*key_function[12])(world_t *) = {active_tiles,
        active_corners, increase_select_area, decrease_select_area,
        active_circles, desactive_circles, nothing, nothing,
        reset_map, nothing, nothing};
    char (*key_spe_function[4])(world_t *) = {increase_map_height,
        increase_map_width, decrease_map_height, decrease_map_width};

    create_a_keycode_list(key_list);
    for (int i = 0; 12 > i; ++i)
        if (sfKeyboard_isKeyPressed(key_list[i]))
            key_function[i](world);
    for (int i = 12; 16 > i; ++i)
        if (sfKeyboard_isKeyPressed(key_list[i]) &&
            '1' == key_spe_function[i - 12](world))
            return ('1');
    return ('0');
}

void use_mouse(world_t *world)
{
    sfMouseButton mouse_list[2] = {sfMouseLeft, sfMouseRight};
    void (*mouse_function[2])(world_t *) = {raise_points, lower_points};

    for (int i = 0; 2 > i; ++i)
        if (sfMouse_isButtonPressed(mouse_list[i]))
            mouse_function[i](world);
}
