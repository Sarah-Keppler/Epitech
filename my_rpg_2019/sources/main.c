/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

static char game(rpg_t *rpg, home_t *home, player_t *player)
{
    if (0 == rpg->load && '1' == home_page(rpg, home))
        return ('1');
    if (1 == rpg->load && '1' == dragon_quest(rpg, player))
        return ('1');
    return ('0');
}

static char run(void)
{
    rpg_t *rpg = init_rpg();
    home_t *home = NULL;
    player_t *player = NULL;

    if (NULL == rpg)
        return ('1');
    home = init_home(rpg);
    player = init_player(rpg, "Lucas");
    if (NULL == home || NULL == player)
        return ('1');
    while (sfRenderWindow_isOpen(rpg->window))
        if ('1' == game(rpg, home, player))
            return ('1');
    free_player(player);
    free_rpg(rpg);
    return ('0');
}

int main(void)
{
    if ('1' == run())
        return (84);
    return (0);
}
