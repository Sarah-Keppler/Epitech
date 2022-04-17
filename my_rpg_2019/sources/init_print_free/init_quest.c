/*
** EPITECH PROJECT, 2019
** init_quest
** File description:
** Inia one pnj.
*/

#include "project.h"

void free_a_quest(quest_t *quest)
{
    free(quest->name);
    free(quest->description);
    free(quest);
}

static char set_data_quest(rpg_t *rpg, quest_t *quest, char **info)
{
    quest->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    quest->description = malloc(sizeof(char) * (my_strlen(info[1]) + 1));
    if (NULL == quest->name || NULL == quest->description)
        return ('1');
    my_strcpy(quest->name, info[0]);
    my_strcpy(quest->description, info[1]);
    quest->objectif = find_ref_objectif(rpg, info[2]);
    quest->state = not_begin;
    quest->reward = find_ref_reward(rpg, info[3]);
    if (NULL == quest->objectif || NULL == quest->reward)
        return ('1');
    return ('0');
}

quest_t *create_a_quest(rpg_t *rpg, char *quest_name)
{
    char **info = get_a_file_source(QUEST_PATH, quest_name);
    quest_t *quest = malloc(sizeof(quest_t));
    int nb = 0;

    if (NULL == info || NULL == quest)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (4 != nb) {
        my_puterror("Quest's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_quest(rpg, quest, info))
        return (NULL);
    free_info(info);
    return (quest);
}
