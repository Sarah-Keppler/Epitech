/*
** EPITECH PROJECT, 2019
** map
** File description:
** Create the map.
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void get_info(level_t *lvl, map_t *mp)
{
    for (int i = 0; 7 > i; ++i) {
        for (int y = 0; mp->nb_tiles > y; ++y) {
            if (1 == mp->sprites[i][y]->collision)
                lvl->info[i][y] = 'B';
            else
                lvl->info[i][y] = '0';
        }
    }
}

void set_collisions(map_t *map, char flag, int m, int h)
{
    if ('V' == flag)
        map->sprites[h][m]->collision = 0;
}

void set_up_sprites(map_t *mp, char src, int *m, int h)
{
    char *map_flags = "123567AZERTQSDFG48V";
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 128, 128};

    if ('M' == src) {
        mp->sprites[h][*m] = create_sprite_obj(mp->src[18], pos, rect, 0.7);
        set_collisions(mp, 'V', *m, h);
        *m += 1;
        return;
    }
    for (int y = 0; map_flags[y]; ++y) {
        if (src == map_flags[y]) {
            mp->sprites[h][*m] = create_sprite_obj(mp->src[y], pos, rect, 0.7);
            set_collisions(mp, map_flags[y], *m, h);
            *m += 1;
        }
    }
}

void make_map(map_t *map, char *src)
{
    int h = 0;
    int m = 0;

    for (int i = 0; src[i]; ++i) {
        if ('\n' == src[i]) {
            ++h;
            m = 0;
        }
        set_up_sprites(map, src[i], &m, h);
    }
}
