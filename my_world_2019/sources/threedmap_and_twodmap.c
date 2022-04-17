/*
** EPITECH PROJECT, 2019
** 3dmap_and_2dmap
** File description:
** Create a 3D-Map and a 2D-Map.
*/

#include "world.h"

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector3f thrd_point = {x, y, z};
    sfVector2f twod_point = {0, 0};
    float angle[2] = {55 * (180 / M_PI), 35 * (180 / M_PI)};

    twod_point.x = (cos(angle[0]) * thrd_point.x) -
        (cos(angle[0]) * thrd_point.y);
    twod_point.y = (sin(angle[1]) * thrd_point.y) +
        (sin(angle[1]) * thrd_point.x) - thrd_point.z;
    return (twod_point);
}

sfVector2f **create_2d_map(map_t *maps, int **md_map)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (maps->height));

    if (NULL == map_2d)
        return (NULL);
    for (int i = 0; maps->height > i; ++i) {
        map_2d[i] = malloc(sizeof(sfVector2f) * maps->width);
        if (NULL == map_2d[i])
            return (NULL);
        for (int y = 0; maps->width > y; ++y)
            map_2d[i][y] = project_iso_point(i * 64, y * 64, md_map[i][y]);
    }
    return (map_2d);
}

static void string_into_positions(char *str, int *line, int width)
{
    int pos = 0;

    for (int i = 0; width > i; ++i) {
        line[i] = my_getnbr(str + pos);
        pos += (get_nb_of_digits(line[i]) + 1);
    }
}

int **create_3d_map(int width, int height, char **value)
{
    int **map_3d = malloc(sizeof(int *) * height);

    if (NULL == map_3d)
        return (NULL);
    for (int i = 0; height > i; ++i) {
        map_3d[i] = malloc(sizeof(int) * width);
        if (NULL == map_3d[i])
            return (NULL);
        string_into_positions(value[i], map_3d[i], width);
    }
    return (map_3d);
}
