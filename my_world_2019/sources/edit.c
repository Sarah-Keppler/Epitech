/*
** EPITECH PROJECT, 2019
** home.c
** File description:
** Init and display the home page.
*/

#include "world.h"

void print_edit(sfRenderWindow *window, edit_t *edit)
{
    int i = -1;

    sfRenderWindow_drawSprite(window, edit->background->sprite, NULL);
    while (edit->ref_button[++i])
        sfRenderWindow_drawSprite(window,
            edit->ref_button[i]->entity->sprite, NULL);
}

static button_t **get_ref_button_edit(button_t **template)
{
    button_t **new = malloc(sizeof(button_t *) * (EDIT_BUTTON + 1));

    if (NULL == new)
        return (NULL);
    for (int i = 0; EDIT_BUTTON > i; ++i)
        new[i] = template[i + HOME_BUTTON];
    new[EDIT_BUTTON] = NULL;
    return (new);
}

edit_t *init_edit(world_t *world, home_t *home)
{
    edit_t *edit = malloc(sizeof(edit_t));
    sfVector2f pos = {0, 0};

    if (NULL == edit)
        return (NULL);
    edit->background = create_sprite(BACKGROUND_GUI, pos);
    edit->ref_button = get_ref_button_edit(world->buttons);
    edit->map = home->map;
    center_the_map(edit->map, edit->map->map_2d);
    if (NULL == edit->ref_button || NULL == edit->background)
        return (NULL);
    edit->mouse = init_mouse(world);
    if (NULL == edit->mouse)
        return (NULL);
    return (edit);
}
