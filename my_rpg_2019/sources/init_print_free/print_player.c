/*
** EPITECH PROJECT, 2019
** init_player
** File description:
** Init a player.
*/

#include "project.h"

static void print_armor(player_t *player)
{
    char *set_name[7] = {"Tête", "Epaule", "Torse", "Jambes", "Pieds",
        "Cape", "Arme"};

    for (int i = 0; 7 > i; ++i) {
        my_putstr("#---");
        my_putstr(set_name[i]);
        my_putstr("---#\n");
        if (NULL != player->armor[i])
            print_a_set(player->armor[i]);
        else
            my_putstr("NULL\n");
    }
}

void print_player(player_t *player)
{
    my_putstr("#     Print Player     #\n");
    my_putstr("Name: ");
    my_putstr(player->name);
    my_putstr("\nLife: ");
    my_put_nbr(player->life[0]);
    my_putstr(" / ");
    my_put_nbr(player->life[1]);
    my_putstr("\nLevel: ");
    my_put_nbr(player->level);
    my_putstr("\nExp: ");
    my_put_nbr(player->exp[0]);
    my_putstr(" / ");
    my_put_nbr(player->exp[1]);
    my_putchar('\n');
    print_armor(player);
    my_putstr("Money: ");
    my_put_nbr(player->money);
    my_putstr("\n\n");
    print_an_inventory(player->inventory);
}
