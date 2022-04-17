/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** Manage inventory: Add an item, remove an item.
*/

#include "project.h"

static object_t *create_an_object(rpg_t *rpg, set_t *set, item_t *item)
{
    object_t *object = malloc(sizeof(object_t));
    sfVector2f scale = {0.78, 0.78};

    if (NULL == object)
        return (NULL);
    object->entity = find_ref_sprite(rpg, set, item);
    sfSprite_setScale(object->entity->sprite, scale);
    object->set = NULL;
    object->item = NULL;
    if (NULL != set)
        object->set = set;
    else
        object->item = item;
    return (object);
}

char add_an_item(rpg_t *rpg, inventory_t *invent, set_t *set, item_t *item)
{
    object_t *object = NULL;
    int pos = 0;

    if (invent->places == invent->occupied) {
        return ('1');
    }
    object = create_an_object(rpg, set, item);
    if (NULL == object)
        return ('3');
    for (int i = 0; NULL != invent->items[i]; ++i)
        ++pos;
    invent->items[pos] = object;
    ++invent->occupied;
    return ('0');
}

void remove_an_item(inventory_t *invent, int pos)
{
    free(invent->items[pos]);
    invent->items[pos] = NULL;
    --invent->occupied;
}
