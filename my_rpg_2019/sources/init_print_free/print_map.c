/*
** EPITECH PROJECT, 2019
** print_object
** File description:
** Print every structs link to objects.
*/

#include "project.h"

void print_a_map(map_t *map)
{
    my_putstr("#-----Print Map-----#\n");
    my_putstr("Map:\n");
    for (int i = 0; map->collisions[i]; ++i) {
        my_putstr(map->collisions[i]);
        my_putchar('\n');
    }
}
