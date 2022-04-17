/*
** EPITECH PROJECT, 2019
** update_maps
** File description:
** Update the 2dmap and 3dmap.
*/

#include "world.h"

void update_2d_map(map_t *maps, sfVector2f **map_2d, int **map_3d)
{
    for (int i = 0; maps->height > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            map_2d[i][y] = project_iso_point(i * 64, y * 64, map_3d[i][y]);
}

static char update_maps_data(map_t *maps, int **new_map)
{
    maps->map_3d = new_map;
    maps->map_2d = create_2d_map(maps, maps->map_3d);
    if (NULL == maps->map_2d)
        return ('1');
    center_the_map(maps, maps->map_2d);
    return ('0');
}

char update_3d_map(map_t *maps, int new_height, int new_width)
{
    int **new_map = malloc(sizeof(int *) * new_height);

    if (NULL == new_map)
        return ('1');
    for (int i = 0; new_height > i; ++i) {
        new_map[i] = malloc(sizeof(int) * (new_width + 1));
        if (NULL == new_map[i])
            return ('1');
        for (int y = 0; new_width > y; ++y)
            new_map[i][y] = 0;
    }
    for (int i = 0; maps->height > i && new_height > i; ++i)
        for (int y = 0; maps->width > y && new_width > y; ++y)
            new_map[i][y] = maps->map_3d[i][y];
    maps->height = new_height;
    maps->width = new_width;
    if ('1' == update_maps_data(maps, new_map))
        return ('1');
    return ('0');
}
