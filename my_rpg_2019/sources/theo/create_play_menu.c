/*
** EPITECH PROJECT, 2019
** create_menu
** File description:
** create the scene play menu
*/

#include "project.h"

static char give_sprite(scene_t *menu, sfVector2f size)
{
    sfVector2f pos = {0.0, 0.0};
    sfVector2f scale = {size.x / 1280.0, size.y / 720.0};

    menu->background = create_sprite(MENU2_I, pos);
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
    sfVector2f pos = {size.x / 100 * 50, size.y / 100 * 40};
    sfFont *font = sfFont_createFromFile(PIXEL_F);
    char *strings[5] = {"NEW GAME", "<EMPTY>", "<EMPTY>", "<EMPTY>", "BACK"};

    if (NULL == font)
        return ('1');
    for (int i = 0; i < 5; ++i) {
        but[i]->text = create_text(strings[i], font, 30, pos);
        if (NULL == but[i]->text)
            return ('1');
    }
    for (int i = 0; i < 4; ++i) {
        sfText_setPosition(but[i]->text, pos);
        pos.y += ((size.y / 100) * 10);
    }
    pos.x += ((size.x / 100) * 40);
    pos.y += ((size.y / 100) * 10);
    sfText_setPosition(but[4]->text, pos);
    return ('0');
}

static void get_ret(button_t **but)
{
    but[0]->ret = 3;
    but[1]->ret = 10;
    but[2]->ret = 11;
    but[3]->ret = 12;
    but[4]->ret = 0;
}

static button_t **make_but(sfVector2f size, sfVector2f scale)
{
    button_t **but = malloc(sizeof(button_t *) * 6);

    if (NULL == but)
        return (NULL);
    for (int i = 0; i < 5; ++i) {
        but[i] = malloc(sizeof(button_t));
        if (but[i] == NULL)
            return (NULL);
    }
    if ('1' == set_text(but, size))
        return (NULL);
    for (int i = 0; i < 5; ++i) {
        but[i]->value = give_value(but, i);
        but[i]->pos = give_pos(sfText_getPosition(but[i]->text));
        but[i]->scale = scale;
        but[i]->but = NULL;
    }
    but[5] = NULL;
    get_ret(but);
    return (but);
}

scene_t *create_play_menu(sfRenderWindow *window)
{
    scene_t *menu = malloc(sizeof(scene_t));
    sfVector2u size_u = sfRenderWindow_getSize(window);
    sfVector2f size = {(float)(size_u.x), (float)(size_u.y)};
    sfVector2f scale = {1.0, 1.0};

    if (menu == NULL)
        return (NULL);
    menu->button_pressed = 0;
    if ('1' == give_sprite(menu, size))
        return (NULL);
    menu->but = make_but(size, scale);
    if (NULL == menu->but)
        return (NULL);
    return (menu);
}
