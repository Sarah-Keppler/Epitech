/*
** EPITECH PROJECT, 2019
** find_ref_object
** File description:
** Find the ref of the struct link to objects.
*/

#include "project.h"

map_t *find_ref_map(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 3);
    map_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "map");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("map", type)) {
        my_puterror("Wrong map name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->maps[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find map file\n");
        return (NULL);
    }
    ref = rpg->maps[number - 1];
    free(type);
    return (ref);
}
