/*
** EPITECH PROJECT, 2019
** find_ref_quest
** File description:
** Find the ref of the struct link to quests.
*/

#include "project.h"

quest_t *find_ref_quest(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 5);
    quest_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "quest");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("quest", type)) {
        my_puterror("Wrong quest name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->quests[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find quest file\n");
        return (NULL);
    }
    ref = rpg->quests[number - 1];
    free(type);
    return (ref);
}

objectif_t *find_ref_objectif(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 8);
    objectif_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "objectif");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("objectif", type)) {
        my_puterror("Wrong objectif name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->objectifs[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find objectif file\n");
        return (NULL);
    }
    ref = rpg->objectifs[number - 1];
    free(type);
    return (ref);
}

reward_t *find_ref_reward(rpg_t *rpg, char *name)
{
    int number = my_getnbr(name + 6);
    reward_t *ref = NULL;
    int pos = 0;
    char *type = copy_the_name(name, "reward");

    if (NULL == type)
        return (NULL);
    if (0 != my_strcmp("reward", type)) {
        my_puterror("Wrong reward name\n");
        return (NULL);
    }
    for (int i = 0; NULL != rpg->rewards[i]; ++i)
        ++pos;
    if (pos < (number - 1)) {
        my_puterror("Wrong number to find reward file\n");
        return (NULL);
    }
    ref = rpg->rewards[number - 1];
    free(type);
    return (ref);
}
