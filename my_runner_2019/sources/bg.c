/*
** EPITECH PROJECT, 2019
** bg
** File description:
** Create a parsing background.
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

sprite_t *init_collision(char *path_to_folder, sfIntRect hitbox)
{
    sprite_t *collision = malloc(sizeof(sprite_t));

    if (NULL == collision)
        return (NULL);
    collision->sprite = sfSprite_create();
    collision->texture = sfTexture_createFromFile(path_to_folder, NULL);
    if (NULL == collision->sprite || NULL == collision->texture)
        return (NULL);
    sfSprite_setTexture(collision->sprite, collision->texture, sfTrue);
    sfSprite_setTextureRect(collision->sprite, hitbox);
    return (collision);
}

sprite_t *init_wallpaper_level(char *path_to_folder)
{
    sprite_t *wallpaper = malloc(sizeof(sprite_t));

    if (NULL == wallpaper)
        return (NULL);
    wallpaper->sprite = sfSprite_create();
    wallpaper->texture = sfTexture_createFromFile(path_to_folder, NULL);
    if (NULL == wallpaper->sprite || NULL == wallpaper->texture)
        return (NULL);
    sfSprite_setTexture(wallpaper->sprite, wallpaper->texture, sfTrue);
    return (wallpaper);
}

picture_t *init_bg(char *path_to_folder, int x2)
{
    picture_t *bg = malloc(sizeof(picture_t));
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 2048, 1546};

    if (NULL == bg)
        return (NULL);
    bg->bgp1 = create_object(path_to_folder, pos, rect);
    pos.x = x2;
    bg->bgp2 = create_object(path_to_folder, pos, rect);
    if (NULL == bg->bgp1 || NULL == bg->bgp2)
        return (NULL);
    return (bg);
}

picture_t **init_parsing(void)
{
    picture_t **pars = malloc(sizeof(picture_t) * 3);
    float speed = 0.5;
    sfVector2f scale = {0.7578, 0.5646};

    if (NULL == pars)
        return (NULL);
    pars[0] = init_bg("Assets/huge_clouds.png", 1552);
    pars[1] = init_bg("Assets/hill.png", 1552);
    pars[2] = init_bg("Assets/distant_trees.png", 1552);
    for (int i = 0; 3 > i; ++i) {
        pars[i]->bgp1->speed += speed;
        pars[i]->bgp2->speed += speed;
        speed += 0.25;
        sfSprite_setScale(pars[i]->bgp1->sprite, scale);
        sfSprite_setScale(pars[i]->bgp2->sprite, scale);
    }
    return (pars);
}

sprite_t *init_sprite(char *path)
{
    sprite_t *picture = malloc(sizeof(sprite_t));

    if (NULL == picture)
        return (NULL);
    picture->sprite = sfSprite_create();
    picture->texture = sfTexture_createFromFile(path, NULL);
    if (NULL == picture->sprite || NULL == picture->texture)
        return (NULL);
    sfSprite_setTexture(picture->sprite, picture->texture, sfTrue);
    return (picture);
}
