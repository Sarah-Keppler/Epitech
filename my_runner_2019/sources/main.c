/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** A video game where you run and run.
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char *get_the_map(char *src)
{
    char *map = read_file(src);

    if (NULL == map)
        return (NULL);
    if ('1' == check_the_map(map)) {
        free(map);
        return (NULL);
    }
    return (map);
}

char my_runner(char *src)
{
    char *map = get_the_map(src);
    runner_t *runner = NULL;
    void (*load_scene[4])(runner_t *) = {home_scene, game,
                                         game_over_scene, win_scene};

    if (NULL == map || '1' == check_the_map(map))
        return ('1');
    if (NULL == (runner = init_runner(map)))
        return ('1');
    while(sfRenderWindow_isOpen(runner->window))
        load_scene[runner->scene - 1](runner);
    return ('0');
}

char check_options(int ac, char **av)
{
    if (3 == ac && 0 == my_strcmp("-h", av[2])) {
        my_putstr("Finite runner created with CSFML.\n\n");
        my_putstr("USAGE\n ./my_runner map.txt\n\n\nOPTIONS\n");
        my_putstr(" -i                 launch the game in infinity mode.\n");
        my_putstr(" -h                 print the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n SPACE_KEY        jump.\n");
        my_putstr("\nIf you want to create a map, please read READ_ME\n");
        return ('1');
    } else if (3 == ac && 0 == my_strcmp("-i", av[2])) {
        my_putstr("Error :: Infinite mode is not implemented.\n");
        return ('1');
    }
    return ('0');
}

int main(int ac, char **av)
{
    if (2 != ac && 3 != ac) {
        write(2, "Error :: The program need only a correct map", 44);
        write(2, " (and its options.)\n", 20);
        return (84);
    }
    if ('1' == check_options(ac, av))
        return (0);
    if ('1' == my_runner(av[1]))
        return (84);
    return (0);
}
