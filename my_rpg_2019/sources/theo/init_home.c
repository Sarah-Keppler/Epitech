/*
** EPITECH PROJECT, 2019
** main
** File description:
** main GUI
*/

#include "project.h"

scene_t *create_scene(sfRenderWindow *window)
{
    scene_t *scene = NULL;

    scene = create_home(window);
    scene->next = create_play_menu(window);
    scene->next->next = create_option(window);
    scene->next->next->next = create_pause(window);
    if (NULL == scene || NULL == scene->next ||
        NULL == scene->next->next || NULL == scene->next->next->next)
        return (NULL);
    scene->next->prev = scene;
    scene->next->next->prev = scene->next;
    scene->next->next->next->prev = scene->next->next;
    scene->next->next->next->next = NULL;
    scene->prev = NULL;
    return (scene);
}

home_t *init_home(rpg_t *rpg)
{
    home_t *new = malloc(sizeof(home_t));

    if (NULL == new)
        return (NULL);
    new->nb = 0;
    new->music = NULL;
    new->scene = create_scene(rpg->window);
    new->part = create_first_particle_point();
    if (NULL == new->scene || NULL == new->part)
        return (NULL);
    return (new);
}
