/*
** EPITECH PROJECT, 2019
** free_rpg
** File description:
** Free the models of the rpg.
*/

#include "project.h"

void free_rpg(rpg_t *rpg)
{
    sfClock_destroy(rpg->clock);
    for (int i = 0; NULL != rpg->dialogues[i]; ++i)
        free_a_dialogue(rpg->dialogues[i]);
    for (int i = 0; NULL != rpg->items[i]; ++i)
        free_an_item(rpg->items[i]);
    for (int i = 0; NULL != rpg->pnjs[i]; ++i)
        free_a_pnj(rpg->pnjs[i]);
    for (int i = 0; NULL != rpg->quests[i]; ++i)
        free_a_quest(rpg->quests[i]);
    for (int i = 0; NULL != rpg->objectifs[i]; ++i)
        free_an_objectif(rpg->objectifs[i]);
    for (int i = 0; NULL != rpg->rewards[i]; ++i)
        free_a_reward(rpg->rewards[i]);
    for (int i = 0; NULL != rpg->sets[i]; ++i)
        free_a_set(rpg->sets[i]);
    free(rpg);
}
