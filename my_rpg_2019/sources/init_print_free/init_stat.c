/*
** EPITECH PROJECT, 2019
** init_stat
** File description:
** Init and print one stat.
*/

#include "project.h"

static char set_data_stat(stat_t *stat, char **info, int start)
{
    stat->attack = my_getnbr(info[start + 1]);
    stat->def = my_getnbr(info[start + 2]);
    stat->critical = my_getnbr(info[start + 3]);
    stat->strengh = my_getnbr(info[start + 4]);
    stat->intelligent = my_getnbr(info[start + 5]);
    stat->agility = my_getnbr(info[start + 6]);
    if (0 > stat->attack || 0 > stat->def || 0 > stat->critical ||
        0 > stat->strengh || 0 > stat->intelligent || 0 > stat->agility)
        return ('1');
    return ('0');
}

static char check_content(char **info, int start, int end)
{
    int nb = 0;

    for (int i = start + 1; end > i; ++i) {
        if ('1' == my_str_isnum(info[i]))
            return ('1');
        ++nb;
    }
    if (6 != nb)
        return ('1');
    return ('0');
}

static char check_positions(char **info, int *start, int *end)
{
    for (int i = 0; NULL != info[i]; ++i)
        if (0 == my_strcmp("-----", info[i])) {
            *start = i;
            break;
        }
    if (-1 == *start)
        return ('1');
    for (int i = *start + 1; NULL != info[i]; ++i)
        if (0 == my_strcmp("-----", info[i]))
            *end = i;
    if (-1 == *end)
        return ('1');
    if ('1' == check_content(info, *start, *end))
        return ('1');
    return ('0');
}

stat_t *create_a_stat(char **info)
{
    stat_t *stat = malloc(sizeof(stat_t));
    int start = -1;
    int end = -1;

    if (NULL == stat)
        return (NULL);
    if ('1' == check_positions(info, &start, &end)) {
        my_puterror("Stat's file: Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_stat(stat, info, start))
        return (NULL);
    return (stat);
}
