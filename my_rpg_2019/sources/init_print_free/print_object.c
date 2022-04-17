/*
** EPITECH PROJECT, 2019
** print_object
** File description:
** Print every structs link to objects.
*/

#include "project.h"

static void print_item_type_and_effect(item_t *item)
{
    char *type[3] = {"combat", "standart", "quest_object"};
    char *effect[5] = {"nothing", "heal", "healing", "attack", "def"};

    my_putstr("Type: ");
    my_putstr(type[item->type]);
    my_putchar('\n');
    my_putstr("Effect: ");
    my_putstr(effect[item->effect]);
    my_putchar('\n');
}

void print_an_item(item_t *item)
{
    my_putstr("#-----Print Item-----#\n");
    my_putstr("Name: ");
    my_putstr(item->name);
    my_putchar('\n');
    my_putstr("Description: ");
    my_putstr(item->description);
    my_putchar('\n');
    print_item_type_and_effect(item);
    my_putstr("Saleable: ");
    my_put_nbr(item->saleable);
    my_putchar('\n');
    my_putstr("Cost: ");
    my_put_nbr(item->cost);
    my_putchar('\n');
}

void print_a_set(set_t *set)
{
    char *type_name[7] = {"tete", "epaule", "torse", "jambes", "pieds",
        "cape", "arme"};

    my_putstr("#-----Print Set-----#\n");
    my_putstr("Name: ");
    my_putstr(set->name);
    my_putchar('\n');
    my_putstr("Description: ");
    my_putstr(set->description);
    my_putstr("\nType: ");
    my_putstr(type_name[set->type]);
    my_putchar('\n');
    print_a_stat(set->stat);
    my_putstr("Saleable: ");
    my_put_nbr(set->saleable);
    my_putchar('\n');
    my_putstr("Cost: ");
    my_put_nbr(set->cost);
    my_putchar('\n');
}

void print_a_stat(stat_t *stat)
{
    my_putstr("#-----Print Stat-----#\n");
    my_putstr("Attack: ");
    my_put_nbr(stat->attack);
    my_putstr("; Def: ");
    my_put_nbr(stat->def);
    my_putstr("; Crit: ");
    my_put_nbr(stat->critical);
    my_putchar('\n');
    my_putstr("Strengh: ");
    my_put_nbr(stat->strengh);
    my_putstr("; Intelligent: ");
    my_put_nbr(stat->intelligent);
    my_putstr("; Agility: ");
    my_put_nbr(stat->agility);
    my_putchar('\n');
}
