/*
** EPITECH PROJECT, 2019
** object
** File description:
** Create game object.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

game_object_t *create_object(const char *path_spritesheet,
                             sfVector2f pos, sfIntRect rect)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    if (obj == NULL)
        return (NULL);
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path_spritesheet, NULL);
    if (NULL == obj->sprite || obj->texture == NULL)
        return (NULL);
    obj->position.x = pos.x;
    obj->position.y = pos.y;
    obj->rect = rect;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->position);
    obj->speed = 0.5;
    return (obj);
}

void destroy_object(game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

p_obj_t *create_sprite_obj(char *path, sfVector2f pos,
                           sfIntRect rect, float speed)
{
    p_obj_t *obj = malloc(sizeof(p_obj_t));

    if (NULL == obj)
        return (NULL);
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    if (NULL == obj->sprite)
        return (NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, rect);
    obj->pos = pos;
    obj->speed = speed;
    obj->ptr_move = &move_tiles;
    obj->collision = 1;
    return (obj);
}
