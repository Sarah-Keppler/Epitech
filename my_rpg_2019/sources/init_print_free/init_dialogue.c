/*
** EPITECH PROJECT, 2019
** init_dialogue
** File description:
** Init one dialogue.
*/

#include "project.h"

void free_a_dialogue(dialogue_t *dialogue)
{
    for (int i = 0; dialogue->scripts[i]; ++i)
        free(dialogue->scripts[i]);
    free(dialogue->scripts);
    for (int i = 0; dialogue->selections[i]; ++i)
        free(dialogue->selections[i]);
    free(dialogue->selections);
    free(dialogue);
}

static char set_data_selections(dialogue_t *dialogue, char **info, int *nbr,
    int *nbr_selections)
{
    int len = 0;

    dialogue->selections = malloc(sizeof(char *) * (*nbr_selections + 1));
    if (NULL == dialogue->selections)
        return ('1');
    for (int i = 0; *nbr_selections > i; ++i) {
        len = my_strlen(info[i + *nbr + 1]);
        dialogue->selections[i] = malloc(sizeof(char) * (len + 1));
        if (NULL == dialogue->selections[i])
            return ('1');
        my_strcpy(dialogue->selections[i], info[i + *nbr + 1]);
    }
    dialogue->selections[*nbr_selections] = NULL;
    return ('0');
}

static char set_data_dialogue(dialogue_t *dialogue, char **info, int *nbr,
    int *nbr_selections)
{
    dialogue->scripts = malloc(sizeof(char *) * (*nbr + 1));
    if (NULL == dialogue->scripts)
        return ('1');
    for (int i = 0; *nbr > i; ++i) {
        dialogue->scripts[i] = malloc(sizeof(char) * (my_strlen(info[i]) + 1));
        if (NULL == dialogue->scripts[i])
            return ('1');
        my_strcpy(dialogue->scripts[i], info[i]);
    }
    dialogue->scripts[*nbr] = NULL;
    if ('1' == set_data_selections(dialogue, info, nbr, nbr_selections))
        return ('1');
    return ('0');
}

static char check_dialogue(char **info, int *nbr_scripts, int *nbr_selections)
{
    int nbr = 0;

    while (info[++nbr]);
    for (int s = 0; info[s]; ++s)
        if ('-' == info[s][0]) {
            *nbr_scripts = s;
            break;
        }
    if (0 != my_strcmp("-----", info[*nbr_scripts]))
        return ('1');
    *nbr_selections = nbr - (*nbr_scripts + 1);
    if (1 > *nbr_selections && 3 > *nbr_selections)
        return ('1');
    return ('0');
}

dialogue_t *create_a_dialogue(char *dialogue_name)
{
    char **info = get_a_file_source(DIALOGUE_PATH, dialogue_name);
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));
    int nbr_scripts = 0;
    int nbr_selections = 0;

    if (NULL == info || NULL == dialogue)
        return (NULL);
    if ('1' == check_dialogue(info, &nbr_scripts, &nbr_selections))
        return (NULL);
    if ('1' == set_data_dialogue(dialogue, info, &nbr_scripts,
        &nbr_selections))
        return (NULL);
    free_info(info);
    return (dialogue);
}
