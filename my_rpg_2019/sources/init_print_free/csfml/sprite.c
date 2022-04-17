/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->text);
    free(sprite);
}

char change_sprite_rect(sprite_t *picture, char *path,
    sfIntRect rect, sfVector2f pos)
{
    if (0 != my_strcmp("NONE", path)) {
        sfTexture_destroy(picture->text);
        picture->text = sfTexture_createFromFile(path, NULL);
        if (NULL == picture->text)
            return ('1');
    }
    sfSprite_setTexture(picture->sprite, picture->text, sfTrue);
    sfSprite_setTextureRect(picture->sprite, rect);
    sfSprite_setPosition(picture->sprite, pos);
    return ('0');
}

sprite_t *create_sprite_rect(char *path, sfIntRect rect, sfVector2f pos)
{
    sprite_t *picture = malloc(sizeof(sprite_t));

    if (NULL == picture)
        return (NULL);
    picture->sprite = sfSprite_create();
    picture->text = sfTexture_createFromFile(path, NULL);
    if (NULL == picture->sprite || NULL == picture->text)
        return (NULL);
    sfSprite_setTexture(picture->sprite, picture->text, sfTrue);
    sfSprite_setTextureRect(picture->sprite, rect);
    sfSprite_setPosition(picture->sprite, pos);
    return (picture);
}

sprite_t *create_sprite(char *path, sfVector2f pos)
{
    sprite_t *picture = malloc(sizeof(sprite_t));

    if (NULL == picture)
        return (NULL);
    picture->sprite = sfSprite_create();
    picture->text = sfTexture_createFromFile(path, NULL);
    if (NULL == picture->sprite || NULL == picture->text)
        return (NULL);
    sfSprite_setTexture(picture->sprite, picture->text, sfTrue);
    sfSprite_setPosition(picture->sprite, pos);
    return (picture);
}
