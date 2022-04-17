/*
** EPITECH PROJECT, 2019
** player_mouvement
** File description:
** Move the player in the board.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void mouvement_events(runner_t *rnnr, level_t *lvl, map_t *mp, int x)
{
    if (x == (mp->nb_tiles - 1))
        rnnr->scene = 4;
    if (lvl->score != (x * 100) - 200) {
        lvl->score = (x * 100) - 200;
        my_put_nbr(lvl->score);
        my_putchar('\n');
    }
}

void set_the_ground(level_t *lvl, map_t *mp, int x, int y)
{
    int floor = y + 1;
    int i = 1;

    while ('B' != lvl->info[y + i][x - 1]) {
        ++floor;
        ++i;
    }
    lvl->ground = mp->block[floor];
    floor = y + 1;
    i = 1;
    while ('B' != lvl->info[y + i][x]) {
        ++floor;
        ++i;
    }
    if (lvl->ground > mp->block[floor])
        lvl->ground = mp->block[floor];
}

void move_player(runner_t *rnnr, level_t *lvl, map_t *mp)
{
    sfVector2f pos = sfSprite_getPosition(lvl->player->collision->sprite);
    static int index[3] = {1, 3, 4};

    for (int i = 0; mp->block[i] < lvl->player->entity->position.y; ++i) {
        index[1] = i;
        index[2] = i + 1;
    }
    if ((mp->sprites[index[1]][index[0]]->pos.x) < pos.x)
        index[0] += 1;
    set_the_ground(lvl, mp, index[0], index[2]);
    mouvement_events(rnnr, lvl, mp, index[0]);
}
