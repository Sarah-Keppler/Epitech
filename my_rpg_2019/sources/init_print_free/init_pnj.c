/*
** EPITECH PROJECT, 2019
** init_pnj
** File description:
** Init one pnj.
*/

#include "project.h"

void free_a_pnj(pnj_t *pnj)
{
    free(pnj->name);
    free(pnj->quest);
    free(pnj);
}

static char set_quests(rpg_t *rpg, pnj_t *pnj, char *info)
{
    char **quest_file = my_str_to_word_array(info, ';');
    int len = 0;

    if (NULL == quest_file)
        return ('1');
    for (int i = 0; NULL != quest_file[i]; ++i)
        ++len;
    pnj->quest = malloc(sizeof(quest_t *) * (len + 1));
    if (NULL == pnj->quest)
        return ('1');
    for (int i = 0; NULL != quest_file[i]; ++i) {
        pnj->quest[i] = find_ref_quest(rpg, quest_file[i]);
        if (NULL == pnj->quest[i])
            return ('1');
    }
    pnj->quest[len] = NULL;
    for (int i = 0; NULL != quest_file[i]; ++i)
        free(quest_file[i]);
    free(quest_file);
    return ('0');
}

static char set_name_quest_and_dialogue(rpg_t *rpg, pnj_t *pnj, char **info)
{
    pnj->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    pnj->quest = NULL;
    pnj->dialogues = find_ref_dialogue(rpg, info[6]);
    if (NULL == pnj->dialogues || NULL == pnj->name)
        return ('1');
    my_strcpy(pnj->name, info[0]);
    if (0 == my_strcmp("NULL", info[5]))
        return ('0');
    if ('1' == set_quests(rpg, pnj, info[5]))
        return ('1');
    return ('0');
}

static char set_data_pnj(pnj_t *pnj, char **info)
{
    char *type[3] = {"hero", "merchant", "citizen"};
    int pos = -1;

    if ('1' == my_str_isnum(info[2]) || '1' == my_str_isnum(info[3]) ||
        '1' == my_str_isnum(info[4]))
        return ('1');
    pnj->level = my_getnbr(info[2]);
    pnj->exp = my_getnbr(info[3]);
    pnj->exp_max = my_getnbr(info[4]);
    for (int i = 0; 3 > i; ++i)
        if (0 == my_strcmp(type[i], info[1]))
            pos = i;
    if (-1 == pos || 1 > pnj->level || 0 > pnj->exp_max || 0 > pnj->exp_max ||
        pnj->exp >= pnj->exp_max) {
        my_puterror("PNJ's file : Wrong format\n");
        return ('1');
    }
    pnj->type = pos;
    return ('0');
}

pnj_t *create_a_pnj(rpg_t *rpg, char *pnj_name)
{
    char **info = get_a_file_source(PNJ_PATH, pnj_name);
    pnj_t *pnj = malloc(sizeof(pnj_t));
    int nb = 0;

    if (NULL == info || NULL == pnj)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (7 != nb) {
        my_puterror("PNJ's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_pnj(pnj, info) ||
        '1' == set_name_quest_and_dialogue(rpg, pnj, info))
        return (NULL);
    free_info(info);
    return (pnj);
}
