/*
** EPITECH PROJECT, 2019
** map
** File description:
** Init the map.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void set_tiles_pos(map_t *map, p_obj_t ***t)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; 7 > i; ++i) {
        for (int y = 0; map->nb_tiles > y; ++y) {
            t[i][y]->pos = pos;
            sfSprite_setPosition(t[i][y]->sprite, pos);
            pos.x += 128;
        }
        pos.y += 128;
        pos.x = 0;
    }
}

char init_t(map_t *map)
{
    map->sprites = malloc(sizeof(p_obj_t **) * 7);
    if (NULL == map->src)
        return ('1');
    for (int y = 0; 7 > y; ++y) {
        map->sprites[y] = malloc(sizeof(p_obj_t *) * (map->nb_tiles + 1));
        if (NULL == map->src[y])
            return ('1');
    }
    return ('0');
}

void save_block(map_t *map, float *src)
{
    for (int i = 0; map->nb_tiles > i; ++i) {
        src[i] = i * 128;
    }
}

void set_ressources(char **src)
{
    src[0] = "Assets/1.png";
    src[1] = "Assets/2.png";
    src[2] = "Assets/3.png";
    src[3] = "Assets/.png";
    src[4] = "Assets/5.png";
    src[5] = "Assets/6.png";
    src[6] = "Assets/7.png";
    src[7] = "Assets/8.png";
    src[8] = "Assets/9.png";
    src[9] = "Assets/10.png";
    src[10] = "Assets/11.png";
    src[11] = "Assets/12.png";
    src[12] = "Assets/13.png";
    src[13] = "Assets/14.png";
    src[14] = "Assets/15.png";
    src[15] = "Assets/16.png";
    src[16] = "Assets/17.png";
    src[17] = "Assets/18.png";
    src[18] = "Assets/19.png";
}

map_t *init_map(runner_t *runner, char *src)
{
    map_t *map = malloc(sizeof(map_t));

    if (NULL == map || NULL == (map->src = malloc(sizeof(char *) * 19)))
        return (NULL);
    for (int i = 0; 18 > i; ++i)
        if (NULL == (map->src[i] = malloc(sizeof(char) * 7)))
            return (NULL);
    map->nb_tiles = 20;
    if (NULL == (map->block = malloc(sizeof(float) * (map->nb_tiles))))
        return (NULL);
    set_ressources(map->src);
    save_block(map, map->block);
    if ('1' == init_t(map))
        return (NULL);
    make_map(map, src);
    set_tiles_pos(map, map->sprites);
    if (NULL == (runner->foes = init_foes(src, map->nb_tiles)))
        return (NULL);
    return (map);
}
