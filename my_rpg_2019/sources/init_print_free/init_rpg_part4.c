/*
** EPITECH PROJECT, 2019
** init_rpg_part2
** File description:
** Init the part 3 of rpg's models.
*/

#include "project.h"

static char init_sprites(rpg_t *rpg, int number)
{
    sfVector2f pos = {0, 0};

    rpg->sprites[0] = create_sprite(SPRITE1, pos);
    rpg->sprites[1] = create_sprite(SPRITE2, pos);
    rpg->sprites[2] = create_sprite(SPRITE3, pos);
    rpg->sprites[3] = create_sprite(SPRITE4, pos);
    rpg->sprites[4] = create_sprite(SPRITE5, pos);
    rpg->sprites[5] = create_sprite(SPRITE6, pos);
    rpg->sprites[6] = NULL;
    for (int i = 0; number > i; ++i)
        if (NULL == rpg->sprites[i])
            return ('1');
    return ('0');
}

char init_rpg_part4(rpg_t *rpg, int *numbers)
{
    if ('1' == init_sprites(rpg, numbers[10]))
        return ('1');
    return ('0');
}
