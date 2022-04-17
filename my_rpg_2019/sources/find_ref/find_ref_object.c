/*
** EPITECH PROJECT, 2019
** find_ref_object
** File description:
** Find the ref of the struct link to objects.
*/

#include "project.h"

char *copy_the_name(char const *name, char const *type)
{
    char *copy = malloc(sizeof(char) * (my_strlen(name) + 1));

    if (NULL == copy)
        return (NULL);
    my_strcpy(copy, name);
    copy[my_strlen(type)] = '\0';
    return (copy);
}

set_t *find_ref_set(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 3);
    set_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "set");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("set", type)) {
        my_puterror("Wrong set name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->sets[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find set file\n");
        return (NULL);
    }
    ref = rpg->sets[number - 1];
    free(type);
    return (ref);
}

item_t *find_ref_item(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 3);
    item_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "item");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("item", type)) {
        my_puterror("Wrong item name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->items[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find item file\n");
        return (NULL);
    }
    ref = rpg->items[number - 1];
    free(type);
    return (ref);
}
