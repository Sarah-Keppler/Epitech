/*
** EPITECH PROJECT, 2019
** init_runner
** File description:
** Init the runner.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

sfRenderWindow *createMyWindow(unsigned int w, unsigned int h, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {w, h, 32};

    window = sfRenderWindow_create(video_mode, name, sfClose, NULL);
    return (window);
}

char init_hud(runner_t *runner)
{
    sfVector2f pos = {600, 200};
    
    runner->home = init_home();
    runner->game_over = init_end("GAME OVER");
    if (NULL == runner->home || NULL == runner->game_over)
        return ('1');
    runner->win = init_end("WIN");
    if (NULL ==runner->win)
        return ('1');
    sfText_setPosition(runner->win->text, pos);
    return ('0');
}

runner_t *init_runner(char *map)
{
    runner_t *runner = malloc(sizeof(runner_t));
    sfEvent event = {0};

    if (NULL == runner)
        return (NULL);
    runner->window = createMyWindow(1552, 873, "My_runner");
    runner->event = event;
    runner->scene = 1;
    runner->map = init_map(runner, map);
    runner->level = init_level();
    if (NULL == runner->level || NULL == runner->map)
        return (NULL);
    if ('1' == init_hud(runner))
        return (NULL);
    if ('1' == init_info(runner->level, runner->map->nb_tiles))
        return (NULL);
    get_info(runner->level, runner->map);
    return (runner);
}
