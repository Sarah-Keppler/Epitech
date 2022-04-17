/*
** EPITECH PROJECT, 2019
** create_menu
** File description:
** create the scene menu
*/

#include "project.h"

static char give_sprite(scene_t *menu, sfVector2f size)
{
    sfVector2f pos = {0.0, 0.0};
    sfVector2f scale = {size.x / 1280.0, size.y / 720.0};

    menu->background = create_sprite(MENU_I, pos);
    pos.x = -((size.x / 100.0) * 3);
    menu->cache = create_sprite(PASSED_ON_B, pos);
    if (NULL == menu->background || NULL == menu->cache)
        return ('1');
    sfSprite_setScale(menu->background->sprite, scale);
    menu->cache_pos = pos;
    return ('0');
}

static char set_text(button_t **but, sfVector2f size)
{
    sfVector2f pos = {size.x / 100 * 40, size.x / 100 * 40};
    sfFont *font = sfFont_createFromFile(PIXEL_F);
    char *strings[3] = {"PLAY GAME", "OPTION", "QUIT GAME"};

    if (NULL == font)
        return ('1');
    for (int i = 0; i < 3; ++i) {
        but[i]->text = create_text(strings[i], font, 30, pos);
        if (NULL == but[i]->text)
            return ('1');
    }
    for (int i = 0; i < 3; ++i) {
        sfText_setPosition(but[i]->text, pos);
        pos.y += ((size.y / 100) * 10);
    }
    return ('0');
}

static void set_data_but(button_t **but)
{
    sfVector2f scale = {1.0, 1.0};

    for (int i = 0; i <= 2; ++i) {
        but[i]->value = give_value(but, i);
        but[i]->pos = give_pos(sfText_getPosition(but[i]->text));
        but[i]->scale = scale;
        but[i]->but = NULL;
    }
    but[0]->ret = 1;
    but[1]->ret = 2;
    but[2]->ret = -1;
    but[3] = NULL;
}

static button_t **give_but(sfVector2f size)
{
    button_t **but = malloc(sizeof(button_t *) * 4);

    if (NULL == but)
        return (NULL);
    for (int i = 0; i < 3; ++i) {
        but[i] = malloc(sizeof(button_t));
        if (NULL == but[i])
            return (NULL);
    }
    if ('1' == set_text(but, size))
        return (NULL);
    set_data_but(but);
    return (but);
}

scene_t *create_home(sfRenderWindow *window)
{
    scene_t *menu = malloc(sizeof(scene_t));
    sfVector2u size_u = sfRenderWindow_getSize(window);
    sfVector2f size = {(float)(size_u.x), (float)(size_u.y)};

    if (NULL == menu)
        return (NULL);
    menu->button_pressed = 0;
    if ('1' == give_sprite(menu, size))
        return (NULL);
    menu->but = give_but(size);
    if (NULL == menu->but)
        return (NULL);
    return (menu);
}
