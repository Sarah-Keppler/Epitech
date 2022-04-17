/*
** EPITECH PROJECT, 2019
** map_editor
** File description:
** Edit maps.
*/

#include "world.h"

static void edit_event(world_t *world)
{
    while (sfRenderWindow_pollEvent(world->window, &world->event))
        if (world->event.type == sfEvtClosed)
            sfRenderWindow_close(world->window);
}

char edit_page(world_t *world)
{
    edit_t *edit = world->edit;

    if (NULL == world->edit) {
        world->edit = init_edit(world, world->home);
        if (NULL == world->edit)
            return ('1');
        return ('0');
    }
    edit_event(world);
    if ('1' == use_keyboard(world))
        return ('1');
    use_mouse(world);
    circle_follow_mouse(edit->mouse->circle, world, -edit->mouse->radius,
        -edit->mouse->radius);
    state_hover_edit(world, edit->ref_button);
    check_tiles(world);
    if ('1' == draw_under_framerate(world, 1))
        return ('1');
    return ('0');
}
