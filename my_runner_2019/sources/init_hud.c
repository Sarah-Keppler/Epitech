/*
** EPITECH PROJECT, 2019
** init_hud
** File description:
** Init hud scenes.
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

char init_wallpaper(home_t *menu)
{
    menu->bg_s = sfSprite_create();
    menu->bg_t = sfTexture_createFromFile("Assets/wallpaper_menu.jpg", NULL);
    if (NULL == menu->bg_s || NULL == menu->bg_t)
        return (false);
    sfSprite_setTexture(menu->bg_s, menu->bg_t, sfTrue);
    return (true);
}

char init_wallpaper_end(end_t *menu)
{
    menu->bg_s = sfSprite_create();
    menu->bg_t = sfTexture_createFromFile("Assets/wallpaper_menu.jpg", NULL);
    if (NULL == menu->bg_s || NULL == menu->bg_t)
        return (false);
    sfSprite_setTexture(menu->bg_s, menu->bg_t, sfTrue);
    return (true);
}

end_t *init_end(char *text)
{
    end_t *menu = malloc(sizeof(end_t));
    sfVector2f pos = {400, 200};

    menu->font = sfFont_createFromFile("Polices/Ravenna.ttf");
    if (NULL == menu || NULL == menu->font)
        return (NULL);
    menu->text = sfText_create();
    if (NULL == menu->text)
        return (NULL);
    sfText_setFont(menu->text, menu->font);
    sfText_setString(menu->text, text);
    sfText_setCharacterSize(menu->text, 100);
    sfText_setPosition(menu->text, pos);
    if (false == init_wallpaper_end(menu))
        return (NULL);
    return (menu);
}

void set_pos_home(sfText **text)
{
    sfVector2f pos;

    pos.x = 100;
    pos.y = 150;
    sfText_setPosition(text[0], pos);
    pos.x = 425;
    pos.y = 350;
    sfText_setPosition(text[1], pos);
}

home_t *init_home(void)
{
    home_t *home = malloc(sizeof(home_t));

    home->text = malloc(sizeof(sfText *) * 2);
    home->font = sfFont_createFromFile("Polices/Ravenna.ttf");
    if (NULL == home || NULL == home->text || NULL == home->font)
        return (NULL);
    for (int i = 0; 2 > i; ++i) {
        home->text[i] = sfText_create();
        if (NULL == home->text[i])
            return (NULL);
        sfText_setFont(home->text[i], home->font);
    }
    sfText_setString(home->text[0], "Let s go on an adventure");
    sfText_setCharacterSize(home->text[0], 100);
    sfText_setString(home->text[1], "Appuyer sur Z pour jouer");
    sfText_setCharacterSize(home->text[1], 40);
    set_pos_home(home->text);
    if (false == init_wallpaper(home))
        return (NULL);
    return (home);
}
