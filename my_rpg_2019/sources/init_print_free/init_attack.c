/*
** EPITECH PROJECT, 2019
** init_attack
** File description:
** Init, print and free one attack.
*/

#include "project.h"

void free_an_attack(attack_t *attack)
{
    free(attack->name);
    free(attack->description);
    free(attack);
}

static char set_data_attack(attack_t *attack, char **info)
{
    attack->name = malloc(sizeof(char) * (my_strlen(info[0]) + 1));
    attack->description = malloc(sizeof(char) * (my_strlen(info[1]) + 1));

    if (NULL == attack->name || NULL == attack->description)
        return ('1');
    my_strcpy(attack->name, info[0]);
    my_strcpy(attack->description, info[1]);
    attack->damage = my_getnbr(info[2]);
    return ('0');
}

attack_t *create_an_attack(char *attack_name)
{
    char **info = get_a_file_source(ATTACK_PATH, attack_name);
    attack_t *new = malloc(sizeof(attack_t));

    if (NULL == info)
        return (NULL);
    if ('1' == set_data_attack(new, info))
        return (NULL);
    free_info(info);
    return (new);
}
