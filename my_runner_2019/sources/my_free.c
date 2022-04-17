/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** Free the program.
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

void destroy_and_free_runner(runner_t *runner)
{
    sfRenderWindow_destroy(runner->window);
    free(runner);
}
