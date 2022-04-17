/*
** EPITECH PROJECT, 2019
** home.c
** File description:
** Init and display the home page.
*/

#include "world.h"

void print_home(sfRenderWindow *window, home_t *home)
{
    int i = -1;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, home->background->sprite, NULL);
    while (home->ref_button[++i])
        sfRenderWindow_drawSprite(window,
            home->ref_button[i]->entity->sprite, NULL);
    sfRenderWindow_display(window);
}

static button_t **get_ref_button_home(button_t **template)
{
    button_t **new = malloc(sizeof(button_t *) * (HOME_BUTTON + 1));

    if (NULL == new)
        return (NULL);
    for (int i = 0; HOME_BUTTON > i; ++i)
        new[i] = template[i];
    new[HOME_BUTTON] = NULL;
    return (new);
}

home_t *init_home(world_t *world, char **av)
{
    home_t *home = malloc(sizeof(home_t));
    sfVector2f position = {0, 0};

    if (NULL == home)
        return (NULL);
    home->background = create_sprite(BACKGROUND, position);
    home->ref_button = get_ref_button_home(world->buttons);
    if (NULL == home->background || NULL == home->ref_button)
        return (NULL);
    home->load_map = -1;
    home->map = malloc(sizeof(map_t));
    if (NULL == home->map)
        return (NULL);
    home->av = av;
    return (home);
}
