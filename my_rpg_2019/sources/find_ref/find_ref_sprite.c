/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

sprite_t *find_ref_sprite(rpg_t *rpg, set_t *set, item_t *item)
{
    int index = 0;
    sprite_t *ref = NULL;

    for (int i = 0; rpg->sets[i]; ++i)
        if (set == rpg->sets[i])
            index = i;
    for (int i = 0; rpg->sets[i]; ++i)
        if (set == rpg->sets[i])
            index = i;
    if (NULL == item)
        ref = rpg->sprites[index + SET_INDEX];
    if (NULL == set)
        ref = rpg->sprites[index];
    return (ref);
}
