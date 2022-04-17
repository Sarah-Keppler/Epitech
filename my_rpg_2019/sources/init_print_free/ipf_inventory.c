/*
** EPITECH PROJECT, 2019
** create_inventory
** File description:
** Create an empty inventory or/and an object, or print and free.
*/

#include "project.h"

void free_an_inventory(inventory_t *invent)
{
    for (int i = 0; invent->places > i; ++i)
        if (NULL != invent->items[i])
            free(invent->items[i]);
    free(invent->items);
    free(invent);
}

void print_an_inventory(inventory_t *inventory)
{
    my_putstr("###########################\n");
    my_putstr("#     Print Inventory     #\n");
    my_putstr("###########################\n\n");
    for (int i = 0; inventory->places > i; ++i) {
        my_put_nbr(i + 1);
        my_putstr(" : ");
        if (NULL == inventory->items[i]) {
            my_putstr("NULL\n");
            continue;
        }
        if (NULL != inventory->items[i]->set)
            print_a_set(inventory->items[i]->set);
        else
            print_an_item(inventory->items[i]->item);
    }
}

static char set_text_inventory(inventory_t *invent)
{
    char *string = "Taille : 10";
    sfFont *font = sfFont_createFromFile(ARIAL_F);
    sfVector2f pos = {SCREEN_W - (300 + 25) + 90, SCREEN_H - (200 + 10) + 10};

    invent->texts = malloc(sizeof(sfText *) * (3 + 1));
    if (NULL == invent->texts || NULL == font)
        return ('1');
    for (int i = 0; 1 > i; ++i) {
        invent->texts[i] = create_text(string, font, 25, pos);
        if (NULL == invent->texts[i])
            return ('1');
        pos.x += 50;
    }
    invent->texts[1] = NULL;
    return ('0');
}

static char create_sprite_inventory(inventory_t *invent)
{
    sfVector2f pos_bg = {SCREEN_W - (300 + 25), SCREEN_H - (200 + 25)};
    sfVector2f pos_close = {SCREEN_W - (55 + 5), SCREEN_H - (200 + 25) + 5};
    sfVector2f scale_bg = {0.5, 0.33};
    sfVector2f scale_close = {0.06, 0.06};

    invent->bg = create_sprite(INVENT_I, pos_bg);
    invent->close = create_sprite(CLOSE_I, pos_close);
    if (NULL == invent->bg || NULL == invent->close)
        return ('1');
    sfSprite_setScale(invent->bg->sprite, scale_bg);
    sfSprite_setScale(invent->close->sprite, scale_close);
    return ('0');
}

inventory_t *create_an_empty_inventory(int places)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (NULL == inventory)
        return (NULL);
    inventory->places = places;
    inventory->occupied = 0;
    inventory->items = malloc(sizeof(object_t *) * (inventory->places + 1));
    if (NULL == inventory->items || '1' == set_text_inventory(inventory) ||
        '1' == create_sprite_inventory(inventory))
        return (NULL);
    for (int i = 0; inventory->places > i; ++i)
        inventory->items[i] = NULL;
    inventory->items[places] = NULL;
    return (inventory);
}
