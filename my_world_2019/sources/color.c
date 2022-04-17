/*
** EPITECH PROJECT, 2019
** color
** File description:
** Init and create colors.
*/

#include "world.h"

sfColor get_color(color_t *color, char *chosen_color)
{
    for (int i = 0; COLOR_MAX > i; ++i) {
        if (0 == my_strcmp(color->color_names[i], chosen_color))
            return (color->colors[i]);
    }
    return (sfBlack);
}

static char init_colors(color_t *color)
{
    color->colors = malloc(sizeof(sfColor) * COLOR_MAX);
    if (NULL == color->colors)
        return ('1');
    color->colors[0] = sfColor_fromRGB(46, 46, 46);
    color->colors[1] = sfColor_fromRGB(255, 243, 141);
    color->colors[2] = sfColor_fromRGB(182, 255, 141);
    color->colors[3] = sfColor_fromRGB(0, 255, 251);
    color->colors[4] = sfColor_fromRGBA(0, 255, 251, 100);
    color->colors[5] = sfColor_fromRGB(255, 100, 100);
    return ('0');
}

static void init_color_name(color_t *color)
{
    color->color_names[0] = "lBlack";
    color->color_names[1] = "lYellow";
    color->color_names[2] = "llGreen";
    color->color_names[3] = "Turquoise";
    color->color_names[4] = "ATurquoise";
    color->color_names[5] = "lRed";
}

color_t *init_color(void)
{
    color_t *color = malloc(sizeof(color_t));

    if (NULL == color)
        return (NULL);
    init_color_name(color);
    if ('1' == init_colors(color))
        return (NULL);
    return (color);
}
