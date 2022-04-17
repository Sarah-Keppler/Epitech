/*
** EPITECH PROJECT, 2019
** init_rpg_part2
** File description:
** Init the part 2 of rpg's models.
*/

#include "project.h"

static char init_pnjs(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("pnj", i);
        if (NULL == path)
            return ('1');
        rpg->pnjs[i - 1] = create_a_pnj(rpg, path);
        if (NULL == rpg->pnjs[i - 1])
            return ('1');
        free(path);
    }
    rpg->pnjs[number] = NULL;
    return ('0');
}

static char init_attacks(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("attack", i);
        if (NULL == path)
            return ('1');
        rpg->attacks[i - 1] = create_an_attack(path);
        if (NULL == rpg->attacks[i - 1])
            return ('1');
        free(path);
    }
    rpg->attacks[number] = NULL;
    return ('0');
}

static char init_quests(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("quest", i);
        if (NULL == path)
            return ('1');
        rpg->quests[i - 1] = create_a_quest(rpg, path);
        if (NULL == rpg->quests[i - 1])
            return ('1');
        free(path);
    }
    rpg->quests[number] = NULL;
    return ('0');
}

static char init_objectifs(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("objectif", i);
        if (NULL == path)
            return ('1');
        rpg->objectifs[i - 1] = create_an_objectif(path);
        if (NULL == rpg->objectifs[i - 1])
            return ('1');
        free(path);
    }
    rpg->objectifs[number] = NULL;
    return ('0');
}

char init_rpg_part2(rpg_t *rpg, int *numbers)
{
    if ('1' == init_objectifs(rpg, numbers[4]) ||
        '1' == init_quests(rpg, numbers[5]) ||
        '1' == init_attacks(rpg, numbers[6]) ||
        '1' == init_pnjs(rpg, numbers[7]))
        return ('1');
    return ('0');
}
