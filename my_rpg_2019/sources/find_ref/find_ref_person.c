/*
** EPITECH PROJECT, 2019
** find_ref_person
** File description:
** Find the ref of the struct link to persons.
*/

#include "project.h"

pnj_t *find_ref_pnj(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 3);
    pnj_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "name");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("pnj", type)) {
        my_puterror("Wrong pnj name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->pnjs[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find pnj file\n");
        return (NULL);
    }
    ref = rpg->pnjs[number - 1];
    free(type);
    return (ref);
}

dialogue_t *find_ref_dialogue(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 8);
    dialogue_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "dialogue");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("dialogue", type)) {
        my_puterror("Wrong dialogue name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->dialogues[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find dialogue file\n");
        return (NULL);
    }
    ref = rpg->dialogues[number - 1];
    free(type);
    return (ref);
}

monster_t *find_ref_monster(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 7);
    monster_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "monster");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("monster", type)) {
        my_puterror("Wrong monster name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->monsters[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find monster file\n");
        return (NULL);
    }
    ref = rpg->monsters[number - 1];
    free(type);
    return (ref);
}

attack_t *find_ref_attack(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 6);
    attack_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "attack");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("attack", type)) {
        my_puterror("Wrong attack name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->attacks[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find attack file\n");
        return (NULL);
    }
    ref = rpg->attacks[number - 1];
    free(type);
    return (ref);
}
