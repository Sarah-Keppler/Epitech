/*
** EPITECH PROJECT, 2019
** click_gestion
** File description:
** all function relative to click
*/

#include "project.h"

int click_scene_gestion(sfRenderWindow *window, scene_t *scene)
{
    int nb = -1;
    sfVector2i posm = sfMouse_getPositionRenderWindow(window);

    nb = check_pos(scene->but[0], posm, 0);
    for (int i = 1; scene->but[i] && nb == -1; ++i)
        nb = check_pos(scene->but[i], posm, i);
    return (nb);
}

void change_color(scene_t *scene, sfRenderWindow *window)
{
    int button = click_scene_gestion(window, scene);

    for (int i = 0; scene->but[i]; ++i)
        sfText_setColor(scene->but[i]->text, sfWhite);
    if (scene->button_pressed == 1 && button != -1) {
        sfText_setColor(scene->but[button]->text, sfBlue);
    }
}

int click_scene(int clic, sfEvent event, scene_t *scene,
    sfRenderWindow *window)
{
    int button = -2;

    if (event.type == sfEvtMouseButtonPressed) {
        button = click_scene_gestion(window, scene);
        if (button != -2)
            scene->button_pressed = 1;
    }
    if (event.type == sfEvtMouseButtonReleased &&
        scene->button_pressed == 1) {
        button = click_scene_gestion(window, scene);
        scene->button_pressed = 0;
        if (button >= 0)
            clic = scene->but[button]->ret;
    }
    change_color(scene, window);
    if (event.type == sfEvtClosed || clic == -1) {
        clic = -1;
        sfRenderWindow_close(window);
    }
    return (clic);
}
