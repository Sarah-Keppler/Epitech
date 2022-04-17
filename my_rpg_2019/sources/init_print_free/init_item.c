/*
** EPITECH PROJECT, 2019
** init_item
** File description:
** Init one item.
*/

#include "project.h"

void free_an_item(item_t *item)
{
    free(item->name);
    free(item->description);
    free(item);
}

static char set_type_and_effect(item_t *item, char **info)
{
    char *type[3] = {"combat", "standart", "quest_object"};
    char *effect[5] = {"nothing", "heal_e", "healing_e", "attack_e", "def_e"};
    int pos = -1;

    for (int i = 0; 3 > i; ++i)
        if (0 == my_strcmp(type[i], info[2]))
            pos = i;
    if (-1 == pos)
        return ('1');
    item->type = pos;
    pos = -1;
    for (int i = 0; 5 > i; ++i)
        if (0 == my_strcmp(effect[i], info[3]))
            pos = i;
    if (-1 == pos)
        return ('1');
    item->effect = pos;
    return ('0');
}

static char set_data_item(item_t *item, char **info)
{
    item->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    item->description = malloc(sizeof(char) * (my_strlen(info[1]) + 1));
    if (NULL == item->name || NULL == item->description)
        return ('1');
    my_strcpy(item->name, info[0]);
    my_strcpy(item->description, info[1]);
    item->saleable = info[4][0];
    item->cost = my_getnbr(info[5]);
    if ('1' == set_type_and_effect(item, info))
        return ('1');
    return ('0');
}

item_t *create_an_item(char *item_name)
{
    char **info = get_a_file_source(ITEM_PATH, item_name);
    item_t *item = malloc(sizeof(item_t));
    int nb = 0;

    if (NULL == info || NULL == item)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (6 != nb) {
        my_puterror("Item's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_item(item, info))
        return (NULL);
    free_info(info);
    return (item);
}
