/*
** EPITECH PROJECT, 2019
** print_person
** File description:
** Print every structs link to characters of the game.
*/

#include "project.h"

void print_a_monster(monster_t *monster)
{
    my_putstr("#-----Display Attaque-----#\n");
    my_putstr("Name: ");
    my_putstr(monster->name);
    my_putstr("\nLife: ");
    my_put_nbr(monster->life[0]);
    my_putstr(" - ");
    my_put_nbr(monster->life[1]);
    my_putchar('\n');
    for (int i = 0; monster->attacks[i]; ++i)
        print_an_attack(monster->attacks[i]);
    my_putstr("Reward XP: ");
    my_put_nbr(monster->reward_xp);
    my_putchar('\n');

}

void print_an_attack(attack_t *attack)
{
    my_putstr("#-----Display Attaque-----#\n");
    my_putstr("Name: ");
    my_putstr(attack->name);
    my_putstr("\nDescription :");
    my_putstr(attack->description);
    my_putstr("\nDamage: ");
    my_put_nbr(attack->damage);
    my_putchar('\n');

}

void print_a_dialogue(dialogue_t *dialogue)
{
    my_putstr("#-----Display Dialogues-----#\n");
    my_putstr("Scripts:\n");
    for (int i = 0; NULL != dialogue->scripts[i]; ++i) {
        my_putstr(dialogue->scripts[i]);
        my_putchar('\n');
    }
    my_putstr("Selections:\n");
    for (int i = 0; NULL != dialogue->selections[i]; ++i) {
        my_putstr(dialogue->selections[i]);
        my_putchar('\n');
    }
}

void print_a_pnj(pnj_t *pnj)
{
    char *type[3] = {"hero", "merchant", "citizen"};

    my_putstr("#-----Display PNJ-----#\n");
    my_putstr("Name: ");
    my_putstr(pnj->name);
    my_putchar('\n');
    my_putstr("Type: ");
    my_putstr(type[pnj->type]);
    my_putchar('\n');
    my_putstr("Level: ");
    my_put_nbr(pnj->level);
    my_putchar('\n');
    my_putstr("Exp: ");
    my_put_nbr(pnj->exp);
    my_putstr(" / ");
    my_put_nbr(pnj->exp_max);
    my_putchar('\n');
    for (int i = 0; NULL != pnj->quest[i]; ++i)
        print_a_quest(pnj->quest[i]);
    print_a_dialogue(pnj->dialogues);
}
