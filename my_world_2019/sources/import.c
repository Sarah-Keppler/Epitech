/*
** EPITECH PROJECT, 2019
** Import
** File description:
** Create a map by import.
*/

#include "world.h"

int **create_default_3d_map(void)
{
    int **map = malloc(sizeof(int *) * 6);

    for (int i = 0; 6 > i; ++i) {
        map[i] = malloc(sizeof(int) * 6);
        if (NULL == map[i])
            return (NULL);
        for (int y = 0; 6 > y; ++y)
            map[i][y] = 0;
    }
    return (map);
}

char create_the_map(map_t *maps, char *map, int w, int h)
{
    char **value = my_str_to_word_array(map, '\n');

    if (NULL == value)
        return ('1');
    maps->map_3d = create_3d_map(w, h, value);
    if (NULL == maps->map_3d)
        return ('1');
    maps->map_2d = create_2d_map(maps, maps->map_3d);
    if (NULL == maps->map_2d)
        return ('1');
    for (int i = 0; h > i; ++i)
        free(value[i]);
    free(value);
    return ('0');
}

char *import_a_map(char *src)
{
    int fd = open(src, O_RDONLY);
    char *map = NULL;

    if (-1 == fd) {
        write(2, "Error :: The second argument need to be a file\n", 48);
        return (NULL);
    }
    map = read_a_file(fd, 10);
    if (NULL == map)
        return (NULL);
    return (map);
}
