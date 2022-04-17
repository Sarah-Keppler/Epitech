/*
** EPITECH PROJECT, 2019
** Check_map
** File description:
** Check the import map.
*/

#include "world.h"

static char check_number_of_characters(char *src, int i, int w, int *nb)
{
    if ('\n' == src[i] || '\0' == src[i + 1]) {
        if (*nb != w) {
            write(2, "Error :: Wrong number of characters per line\n", 45);
            return ('1');
        }
        *nb = 0;
    }
    return ('0');
}

static char check_width_per_line(char *src, int w)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i) {
        if (',' == src[i])
            ++nb;
        if ('\0' == src[i + 1])
            ++nb;
        if ('1' == check_number_of_characters(src, i, w, &nb))
            return ('1');
    }
    return ('0');
}

static char check_map_content(map_t *maps, char *src)
{
    int width = 0;
    int height = 0;
    int tmp = 0;

    for (int i = 0; src[i]; ++i) {
        if (!('0' <= src[i] && '9' >= src[i]) &&
            '\n' != src[i] && ',' != src[i])
            return ('1');
        if (',' == src[i])
            ++width;
        if ('\n' == src[i] || '\0' == src[i + 1]) {
            tmp = width;
            width = 0;
            ++height;
        }
    }
    maps->width = tmp + 1;
    maps->height = height;
    return ('0');
}

char check_the_map(map_t *maps, char *src)
{
    if ('1' == check_map_content(maps, src) ||
        '1' == check_width_per_line(src, maps->width))
        return ('1');
    return ('0');
}
