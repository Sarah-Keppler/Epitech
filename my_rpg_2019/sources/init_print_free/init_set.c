/*
** EPITECH PROJECT, 2019
** init_set
** File description:
** Init, print and free one set.
*/

#include "project.h"

void free_a_set(set_t *set)
{
    free(set->name);
    free(set->description);
    free(set->stat);
    free(set);
}

static char set_type_set(set_t *set, char **info)
{
    char *type_name[7] = {"tete", "epaule", "torse", "jambes", "pieds",
        "cape", "arme"};
    int pos = 0;

    for (int i = 0; 7 > i; ++i)
        if (0 == my_strcmp(type_name[i], info[2]))
            pos = i;
    if (-1 == pos)
        return ('1');
    set->type = pos;
    return ('0');
}

static char set_data_set(set_t *set, char **info)
{
    if (('0' != info[11][0] && '1' != info[11][0]) ||
        '1' == my_str_isnum(info[12])) {
        my_puterror("Set's file : Wrong format\n");
        return ('1');
    }
    set->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    set->description = malloc(sizeof(char) * (my_strlen(info[1]) + 1));
    if (NULL == set->name || NULL == set->description)
        return ('1');
    my_strcpy(set->name, info[0]);
    my_strcpy(set->description, info[1]);
    set->stat = create_a_stat(info);
    if (NULL == set->stat)
        return ('1');
    set->saleable = info[11][0];
    set->cost = my_getnbr(info[12]);
    return ('0');
}

set_t *create_a_set(char *set_name)
{
    char **info = get_a_file_source(SET_PATH, set_name);
    set_t *set = malloc(sizeof(set_t));;
    int nb = 0;

    if (NULL == info || NULL == set)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (13 != nb) {
        my_puterror("Set's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_set(set, info)|| '1' == set_type_set(set, info))
        return (NULL);
    free_info(info);
    return (set);
}
