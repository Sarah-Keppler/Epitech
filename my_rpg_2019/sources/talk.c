/*
** EPITECH PROJECT, 2019
** My_RPG
** File description:
** My_RPG inspired from Dragon Quest.
*/

#include "project.h"

static void print_a_box(char **boxes, int current)
{
    int max = 0;

    for (int i = current; boxes[i]; ++i) {
        my_putstr(boxes[i]);
        my_putstr("\n\n");
        ++max;
        if (3 == max)
            break;
    }
}

static void talk(dialogue_t *dialogue, char **boxes)
{
    int current = 0;

    for (int i = 0; boxes[i]; ++i) {
        print_a_box(boxes, current);
        current += 3;
        my_putstr("-----\n");
    }
    for (int i = 0; dialogue->selection[i]; ++i) {
        my_putstr(dialogue->selections[i]);
        my_putchar('\n');
    }
}
