/*
** EPITECH PROJECT, 2019
** init_objectif
** File description:
** Init, print and free one objectif.
*/

#include "project.h"

void free_an_objectif(objectif_t *objectif)
{
    free(objectif->description);
    free(objectif);
}

static char set_data_objectif(objectif_t *objectif, char **info)
{
    char *type[3] = {"kill", "recolt", "talk"};
    int pos = -1;

    if ('1' == my_str_isnum(info[2]))
        return ('1');
    for (int i = 0; 3 > i; ++i)
        if (0 == my_strcmp(type[i], info[1]))
            pos = i;
    objectif->number = my_getnbr(info[2]);
    objectif->description = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    if (-1 == pos || 0 >= objectif->number || NULL == objectif->description)
        return ('1');
    my_strcpy(objectif->description, info[0]);
    objectif->type = pos;
    objectif->current_number = 0;
    return ('0');
}

objectif_t *create_an_objectif(char *objectif_name)
{
    char **info = get_a_file_source(OBJECTIF_PATH, objectif_name);
    objectif_t *objectif = malloc(sizeof(objectif_t));;
    int nb = 0;

    if (NULL == info || NULL == objectif)
        return (NULL);
    for (int i = 0; NULL != info[i]; ++i)
        ++nb;
    if (3 != nb) {
        my_puterror("Objectif's file : Wrong format\n");
        return (NULL);
    }
    if ('1' == set_data_objectif(objectif, info)) {
        my_puterror("Objectif's file : Wrong format\n");
        return (NULL);
    }
    free_info(info);
    return (objectif);
}
