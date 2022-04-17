/*
** EPITECH PROJECT, 2019
** draw_the_ground
** File description:
** Draw quadrangles.
*/

#include "world.h"

static void change_the_color(world_t *world, sfVertexArray *vertex_array,
    char *color)
{
    int nb_vertex = (int)sfVertexArray_getVertexCount(vertex_array);
    sfVertex *vertex = NULL;

    for (int i = 0; nb_vertex > i; ++i) {
        vertex = sfVertexArray_getVertex(vertex_array, i);
        vertex->color = get_color(world->ref_color, color);
    }
}

static void get_the_quad_color(world_t *world, sfVertexArray *my_quad,
    int i, int y)
{
    edit_t *edit = world->edit;
    char rtn = '0';
    sfVector2f points[4] = {edit->map->map_2d[i][y],
        edit->map->map_2d[i][y + 1],
        edit->map->map_2d[i + 1][y + 1],
        edit->map->map_2d[i + 1][y]};

    rtn = check_if_mouse_tile(edit->mouse, points);
    if ('1' == rtn || '1' == edit->mouse->tiles ||
        '0' == edit->mouse->draw_circles)
        change_the_color(world, my_quad, "llGreen");
    else
        change_the_color(world, my_quad, "lRed");
}

static char draw_a_line_of_quadrangles(world_t *world, int i)
{
    edit_t *edit = world->edit;
    sfVertexArray *my_quad = NULL;

    for (int y = 0; (edit->map->width - 1) > y; ++y) {
        my_quad = create_quadrangle(&edit->map->map_2d[i][y],
            &edit->map->map_2d[i][y + 1],
            &edit->map->map_2d[i + 1][y + 1],
            &edit->map->map_2d[i + 1][y]);
        if (NULL == my_quad)
            return ('1');
        get_the_quad_color(world, my_quad, i, y);
        sfRenderWindow_drawVertexArray(world->window, my_quad, NULL);
        sfVertexArray_destroy(my_quad);
    }
    return ('0');
}

char draw_quadrangles(world_t *world)
{
    for (int i = 0; (world->edit->map->height - 1) > i; ++i)
        if ('1' == draw_a_line_of_quadrangles(world, i))
            return ('1');
    return ('0');
}
