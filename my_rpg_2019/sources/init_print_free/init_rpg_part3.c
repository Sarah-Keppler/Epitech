/*
** EPITECH PROJECT, 2019
** init_rpg_part2
** File description:
** Init the part 3 of rpg's models.
*/

#include "project.h"

static char set_map_position(map_t **maps)
{
    sfVector2f position = {0, 0};
    sfIntRect rect1 = {588, 172, SCREEN_W, SCREEN_H};
    sfIntRect rect2 = {224, 752, SCREEN_W, SCREEN_H};

    maps[0]->bg = create_sprite_rect(MAP1, rect1, position);
    maps[1]->bg = create_sprite_rect(MAP2, rect2, position);
    for (int i = 0; 2 > i; ++i)
        if (NULL == maps[i])
            return ('1');
    return ('0');
}

static char init_maps(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("map", i);
        if (NULL == path)
            return ('1');
        rpg->maps[i - 1] = create_a_map(path);
        if (NULL == rpg->maps[i - 1])
            return ('1');
        free(path);
    }
    rpg->maps[number] = NULL;
    if ('1' == set_map_position(rpg->maps))
        return ('0');
    return ('0');
}

static char init_monsters(rpg_t *rpg, int number)
{
    char *path = NULL;

    for (int i = 1; number >= i; ++i) {
        path = create_a_path("monster", i);
        if (NULL == path)
            return ('1');
        rpg->monsters[i - 1] = create_a_monster(rpg, path);
        if (NULL == rpg->monsters[i - 1])
            return ('1');
        free(path);
    }
    rpg->monsters[number] = NULL;
    return ('0');
}

char init_rpg_part3(rpg_t *rpg, int *numbers)
{
    if ('1' == init_maps(rpg, numbers[8]) ||
        '1' == init_monsters(rpg, numbers[9]))
        return ('1');
    return ('0');
}
