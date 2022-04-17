/*
** EPITECH PROJECT, 2019
** evil
** File description:
** Do opponents.
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void set_pos_foes(foes_t *foes)
{
    int foe = 0;
    sfVector2f pos = {0, 360};

    for (int i = 0; foes->spawn[i]; ++i) {
        if ('M' == foes->spawn[i]) {
            foes->villains[foe]->entity->position = pos;
            sfSprite_setPosition(foes->villains[foe]->entity->sprite, pos);
            ++foe;
        }
        pos.x += 128;
        if ('\n' == foes->spawn[i])
            pos.x = 0;
    }
}

monster_t *init_monster(void)
{
    monster_t *monster = malloc(sizeof(monster_t));
    sfVector2f size = {0.5, 0.5};
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 521, 576};
    sfIntRect hitbox = {0, 0, 248, 432};

    if (NULL == monster)
        return (NULL);
    monster->entity = create_object("Assets/Monster.png", pos, rect);
    monster->collision = init_collision("Assets/19.png", hitbox);
    if (NULL == monster->entity || NULL == monster->collision)
        return (NULL);
    sfSprite_setScale(monster->entity->sprite, size);
    sfSprite_setScale(monster->collision->sprite, size);
    monster->entity->speed = 2;
    return (monster);
}

int get_nb_ennemies(char *src)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i)
        if ('M' == src[i])
            ++nb;
    return (nb);
}

foes_t *init_foes(char *src, int nb_tiles)
{
    foes_t *foes = malloc(sizeof(foes_t));
    int y = 0;

    if (NULL == foes)
        return (NULL);
    if (NULL == (foes->spawn = malloc(sizeof(char *) * (nb_tiles + 1))))
        return (NULL);
    foes->spawn = my_strcpy(foes->spawn, src);
    foes->number = get_nb_ennemies(foes->spawn);
    if (NULL == (foes->villains = malloc(sizeof(monster_t *) * foes->number)))
        return (NULL);
    for (int i = 0; foes->spawn[i]; ++i)
        if ('M' == foes->spawn[i]) {
            foes->villains[y] = init_monster();
            if (NULL == foes->villains[y])
                return (NULL);
            ++y;
        }
    set_pos_foes(foes);
    return (foes);
}
