/*
** EPITECH PROJECT, 2019
** create
** File description:
** function that are the same in the scene creation
*/

#include "project.h"

sfIntRect give_value(button_t **but, int i)
{
    sfIntRect value;
    sfFloatRect text = sfText_getGlobalBounds(but[i]->text);

    value.left = (int)(text.left);
    value.top = (int)(text.top);
    value.width = (int)(text.width);
    value.height = (int)(text.height);
    return (value);
}

sfVector2f give_pos(sfVector2f pos)
{
    pos.y += 5.0;
    return (pos);
}
