/*
** EPITECH PROJECT, 2019
** Project
** File description:
** First Year Project Epitech
*/

#include "project.h"

void destroy_text(sfText *text)
{
    sfText_destroy(text);
}

sfText *create_text(char *string, sfFont *font, int size, sfVector2f pos)
{
    sfText *new = sfText_create();

    if (NULL == new)
        return (NULL);
    sfText_setString(new, string);
    sfText_setFont(new, font);
    sfText_setCharacterSize(new, size);
    sfText_setPosition(new, pos);
    return (new);
}
