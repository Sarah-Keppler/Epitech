/*
** EPITECH PROJECT, 2019
** init_reward
** File description:
** Init one reward.
*/

#include "project.h"

void free_a_reward(reward_t *reward)
{
    free(reward);
}

static char set_data_reward(rpg_t *rpg, reward_t *reward, char **info)
{
    if ('1' == my_str_isnum(info[0]) || '1' == my_str_isnum(info[1]))
        return ('1');
    reward->exp = my_getnbr(info[0]);
    reward->money = my_getnbr(info[1]);
    reward->set = NULL;
    reward->item = NULL;
    if (0 != my_strcmp(info[2], "NULL")) {
        reward->set = find_ref_set(rpg, info[2]);
        if (NULL == reward->set)
            return ('1');
    }
    if (0 != my_strcmp(info[3], "NULL")) {
        reward->item = find_ref_item(rpg, info[3]);
        if (NULL == reward->item)
            return ('1');
    }
    return ('0');
}

reward_t *create_a_reward(rpg_t *rpg, char *reward_name)
{
    char **info = get_a_file_source(REWARD_PATH, reward_name);
    reward_t *reward = malloc(sizeof(reward_t));;
    int nb = 0;

    if (NULL == info || NULL == reward)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (4 != nb) {
        my_puterror("Reward's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_reward(rpg, reward, info))
        return (NULL);
    free_info(info);
    return (reward);
}
