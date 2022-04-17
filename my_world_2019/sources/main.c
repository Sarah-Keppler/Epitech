/*
** EPITECH PROJECT, 2019
** World
** File description:
** First Year Project Epitech: Make a map editor.
*/

#include "world.h"

static char run(char **av)
{
    world_t *world = init_world(av);
    char (*my_scenes[2])(world_t *) = {home_page, edit_page};
    char rtn = '1';

    if (NULL == world)
        return ('1');
    while (sfRenderWindow_isOpen(world->window)) {
        rtn = my_scenes[world->load_scene](world);
        if ('1' == rtn)
            return ('1');
        else if ('3' == rtn)
            return ('0');
    }
    return ('0');
}

static void print_help(char **av)
{
    my_putstr("Usage: ");
    my_putstr(av[0]);
    my_putstr(" [options]\n"
        "Options:\n"
        " -h\tDisplay this help\n"
        " {map}.txt\tLoad a map\n");
}

int main(int ac, char **av)
{
    if (ac > 2) {
        my_puterror("Error: Too much arguments\n");
        print_help(av);
        return (84);
    }
    if (2 == ac && 0 == my_strcmp("-h", av[1])) {
        print_help(av);
        return (0);
    }
    if ('1' == run(av))
        return (84);
    return (0);
}
