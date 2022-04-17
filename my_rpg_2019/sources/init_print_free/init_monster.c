/*
** EPITECH PROJECT, 2019
** init_map
** File description:
** Init, print and free one map.
*/

#include "project.h"

void free_a_monster(monster_t *monster)
{
    free(monster->name);
    free(monster->attacks);
    free(monster);
}

static char set_sprite_monster(monster_t *monster)
{
    sfVector2f pos = {(SCREEN_W / 2) - 123, (SCREEN_H / 2) - 123};
    sfIntRect rect = {0, 0, MONSTER_S, MONSTER_S};

    monster->entity = create_sprite_rect(MONSTER_I, rect, pos);
    if (NULL == monster->entity)
        return ('1');
    return ('0');
}

static char set_data_monster(rpg_t *rpg, monster_t *monster, char **info)
{
    int i = -1;

    while (info[++i]);
    monster->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    monster->life[0] = my_getnbr(info[1]);
    monster->life[1] = my_getnbr(info[2]);
    monster->attacks = malloc(sizeof(attack_t *) * (i - 2));
    if (NULL == monster->name || NULL == monster->attacks)
        return ('1');
    my_strcpy(monster->name, info[0]);
    for (int s = 0; 2 > s; ++s)
        monster->attacks[s] = find_ref_attack(rpg, info[s + 3]);
    monster->attacks[i - 4] = NULL;
    monster->reward_xp = my_getnbr(info[i - 1]);
    if ('1' == set_sprite_monster(monster))
        return ('1');
    return ('0');
}

monster_t *create_a_monster(rpg_t *rpg, char *monster_name)
{
    char **info = get_a_file_source(MONSTER_PATH, monster_name);
    monster_t *new = malloc(sizeof(monster_t));

    if (NULL == info)
        return (NULL);
    if ('1' == set_data_monster(rpg, new, info))
        return (NULL);
    free(info);
    return (new);
}
