/*
** EPITECH PROJECT, 2019
** init_rpg
** File description:
** Init the models of the rpg.
*/

#include "project.h"

static void print_part3_rpg(rpg_t *rpg)
{
    my_putstr("\n################\n");
    my_putstr("#     SETS     #\n");
    my_putstr("################\n");
    for (int i = 0; NULL != rpg->sets[i]; ++i)
        print_a_set(rpg->sets[i]);
    my_putstr("\n################\n");
    my_putstr("#     MAPS     #\n");
    my_putstr("################\n");
    for (int i = 0; NULL != rpg->maps[i]; ++i)
        print_a_map(rpg->maps[i]);
}

static void print_part2_rpg(rpg_t *rpg)
{
    my_putstr("\n##################\n");
    my_putstr("#     QUESTS     #\n");
    my_putstr("##################\n\n");
    for (int i = 0; NULL != rpg->quests[i]; ++i)
        print_a_quest(rpg->quests[i]);
    my_putstr("\n/#####################\n");
    my_putstr("#     OBJECTIFS     #\n");
    my_putstr("#####################\n\n");
    for (int i = 0; NULL != rpg->objectifs[i]; ++i)
        print_an_objectif(rpg->objectifs[i]);
    my_putstr("\n###################\n");
    my_putstr("#     REWARDS     #\n");
    my_putstr("###################\n");
    for (int i = 0; NULL != rpg->rewards[i]; ++i)
        print_a_reward(rpg->rewards[i]);
    print_part3_rpg(rpg);
}

void print_rpg(rpg_t *rpg)
{
    my_putstr("#     Display RPG     #\n\n");
    my_putstr("#####################\n");
    my_putstr("#     DIALOGUES     #\n");
    my_putstr("#####################\n\n");
    for (int i = 0; NULL != rpg->dialogues[i]; ++i)
        print_a_dialogue(rpg->dialogues[i]);
    my_putstr("\n#################\n");
    my_putstr("#     ITEMS     #\n");
    my_putstr("#################\n\n");
    for (int i = 0; NULL != rpg->items[i]; ++i)
        print_an_item(rpg->items[i]);
    my_putstr("\n################\n");
    my_putstr("#     PNJS     #\n");
    my_putstr("################\n\n");
    for (int i = 0; NULL != rpg->pnjs[i]; ++i)
        print_a_pnj(rpg->pnjs[i]);
    print_part2_rpg(rpg);
}
