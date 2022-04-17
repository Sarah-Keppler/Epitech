/*
** EPITECH PROJECT, 2019
** print_quest
** File description:
** Print every structs link to quests.
*/

#include "project.h"

void print_a_quest(quest_t *quest)
{
    my_putstr("#-----Display Quest-----#\n");
    my_putstr("Name: ");
    my_putstr(quest->name);
    my_putchar('\n');
    my_putstr("Description: ");
    my_putstr(quest->description);
    my_putchar('\n');
    print_an_objectif(quest->objectif);
    my_putstr("State: ");
    my_put_nbr(quest->state);
    my_putchar('\n');
    print_a_reward(quest->reward);
}

void print_an_objectif(objectif_t *objectif)
{
    char *type[3] = {"kill", "recolt", "talk"};

    my_putstr("#-----Display Objectif-----#\n");
    my_putstr("Description: ");
    my_putstr(objectif->description);
    my_putchar('\n');
    my_putstr("Type: ");
    my_putstr(type[objectif->type]);
    my_putchar('\n');
    my_putstr("Progression: ");
    my_put_nbr(objectif->current_number);
    my_putstr(" / ");
    my_put_nbr(objectif->number);
    my_putchar('\n');
}

void print_a_reward(reward_t *reward)
{
    my_putstr("#-----Display Reward-----#\n");
    my_putstr("Exp: ");
    my_put_nbr(reward->exp);
    my_putchar('\n');
    my_putstr("Money: ");
    my_put_nbr(reward->money);
    my_putchar('\n');
    if (NULL != reward->set)
        print_a_set(reward->set);
    else
        my_putstr("Set: NULL\n");
    if (NULL != reward->item)
        print_an_item(reward->item);
    else
        my_putstr("Item: NULL\n");
}
