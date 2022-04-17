/*
** EPITECH PROJECT, 2019
** 2d_wireframe_and_arrays
** File description:
** Display a 2d_wireframe.
*/

#include "world.h"

static sfVertexArray ***create_an_empty_array(int lines, int characters)
{
    sfVertexArray ***arrays = malloc(sizeof(sfVertexArray **) * (lines - 1));

    if (NULL == arrays)
        return (NULL);
    for (int i = 0; (lines - 1) > i; ++i) {
        arrays[i] = malloc(sizeof(sfVertexArray *) * (characters));
        if (NULL == arrays[i])
            return (NULL);
    }
    return (arrays);
}

static char draw_vertical_lines(world_t *world, map_t *maps)
{
    sfVertexArray ***arrays = create_an_empty_array(maps->height, maps->width);

    if (NULL == arrays)
        return ('1');
    for (int i = 0; (maps->height - 1) > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            arrays[i][y] = create_line(&maps->map_2d[i][y],
                &maps->map_2d[i + 1][y]);
    for (int i = 0; (maps->height - 1) > i; ++i)
        for (int y = 0; maps->width > y; ++y)
            sfRenderWindow_drawVertexArray(world->window, arrays[i][y], NULL);
    for (int i = 0; (maps->height - 1) > i; ++i) {
        for (int y = 0; maps->width > y; ++y)
            sfVertexArray_destroy(arrays[i][y]);
        free(arrays[i]);
    }
    free(arrays);
    return ('0');
}

static char draw_horizontal_lines(world_t *world, map_t *maps)
{
    sfVertexArray ***arrays = create_an_empty_array(maps->width, maps->height);

    if (NULL == arrays)
        return ('1');
    for (int i = 0; (maps->width - 1) > i; ++i)
        for (int y = 0; maps->height > y; ++y)
            arrays[i][y] = create_line(&maps->map_2d[y][i],
                &maps->map_2d[y][i + 1]);
    for (int i = 0; (maps->width - 1) > i; ++i)
        for (int y = 0; maps->height > y; ++y)
            sfRenderWindow_drawVertexArray(world->window, arrays[i][y], NULL);
    for (int i = 0; (maps->width - 1) > i; ++i) {
        for (int y = 0; maps->height > y; ++y)
            sfVertexArray_destroy(arrays[i][y]);
        free(arrays[i]);
    }
    return ('0');
}

char draw_2d_map(world_t *world)
{
    map_t *maps = world->edit->map;

    if ('1' == draw_quadrangles(world))
        return ('1');
    if ('1' == draw_horizontal_lines(world, maps))
        return ('1');
    if ('1' == draw_vertical_lines(world, maps))
        return ('1');
    return ('0');
}
