/*
** EPITECH PROJECT, 2019
** create_window
** File description:
** Create a window.
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_my_window(unsigned int w, unsigned int h, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {w, h, 32};

    window = sfRenderWindow_create(video_mode, name, sfClose, NULL);
    return (window);
}
