/*
** EPITECH PROJECT, 2019
** init_rpg_part1
** File description:
** Init the part 1 of the rpg's models.
*/

#include "project.h"

static char init_rewards(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("reward", i);
        if (NULL == path)
            return ('1');
        rpg->rewards[i - 1] = create_a_reward(rpg, path);
        if (NULL == rpg->rewards[i - 1])
            return ('1');
        free(path);
    }
    rpg->rewards[number] = NULL;
    return ('0');
}

static char init_sets(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("set", i);
        if (NULL == path)
            return ('1');
        rpg->sets[i - 1] = create_a_set(path);
        if (NULL == rpg->sets[i - 1])
            return ('1');
        free(path);
    }
    rpg->sets[number] = NULL;
    return ('0');
}

static char init_items(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("item", i);
        if (NULL == path)
            return ('1');
        rpg->items[i - 1] = create_an_item(path);
        if (NULL == rpg->items[i - 1])
            return ('1');
        free(path);
    }
    rpg->items[number] = NULL;
    return ('0');
}

static char init_dialogues(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("dialogue", i);
        if (NULL == path)
            return ('1');
        rpg->dialogues[i - 1] = create_a_dialogue(path);
        if (NULL == rpg->dialogues[i - 1])
            return ('1');
        free(path);
    }
    rpg->dialogues[number] = NULL;
    return ('0');
}

char init_rpg_part1(rpg_t *rpg, int *numbers)
{
    if ('1' == init_dialogues(rpg, numbers[0]) ||
        '1' == init_items(rpg, numbers[1]) ||
        '1' == init_sets(rpg, numbers[2]) ||
        '1' == init_rewards(rpg, numbers[3]))
        return ('1');
    return ('0');
}
