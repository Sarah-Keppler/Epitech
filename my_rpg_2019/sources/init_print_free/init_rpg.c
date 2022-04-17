 /*
** EPITECH PROJECT, 2019
** init_rpg
** File description:
** Init the the rpg's models.
*/

#include "project.h"

char *create_a_path(char *type, int i)
{
    int len = my_strlen(type) + get_nb_of_digits(i);
    char *path = malloc(sizeof(char) * (len + 1));
    char *number = malloc(sizeof(char) * (get_nb_of_digits(i) + 1));

    if (NULL == path || NULL == number)
        return (NULL);
    my_strcpy(path, type);
    my_int_to_str(i, number);
    my_strcat(path, number);
    free(number);
    return (path);
}

static sfRenderWindow *create_a_window(unsigned int w, unsigned int h, char *n)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = {w, h, 32};

    window = sfRenderWindow_create(video_mode, n, sfClose, NULL);
    return (window);
}

static char init_part(rpg_t *rpg)
{
    int numbers[11] = {1, 1, 5, 1, 1, 1, 4, 1, 2, 1, 6};
    char (*inits[4])(rpg_t *, int *) = {init_rpg_part1, init_rpg_part2,
        init_rpg_part3, init_rpg_part4};

    for (int i = 0; 4 > i; ++i)
        if ('1' == inits[i](rpg, numbers))
            return ('1');
    return ('0');
}

rpg_t *init_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfEvent event = {0};

    if (NULL == rpg)
        return (NULL);
    rpg->window = create_a_window(SCREEN_W, SCREEN_H, "my_rpg");
    rpg->event = event;
    rpg->events[0] = -1;
    rpg->events[1] = -1;
    rpg->events[2] = -1;
    rpg->load = 0;
    rpg->clock = sfClock_create();
    if (NULL == rpg->clock || '1' == init_part(rpg))
        return (NULL);
    rpg->map = find_ref_map(rpg, "map1");
    sfRenderWindow_setFramerateLimit(rpg->window, 120);
    return (rpg);
}
