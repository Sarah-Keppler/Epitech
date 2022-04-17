/*
** EPITECH PROJECT, 2019
** graphics
** File description:
** Functions of framebuffers.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my_csfml.h"

t_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    t_framebuffer *fb;

    fb = malloc(sizeof(t_framebuffer));
    if (fb == NULL)
        return (NULL);
    fb->pixels = malloc(sizeof(sfUint8) * (4 * width * height));
    if (fb->pixels == NULL)
        return (NULL);
    fb->width = width;
    fb->height = height;
    return (fb);
}

void framebuffer_destroy(t_framebuffer *fb)
{
    free(fb->pixels);
    free(fb);
}
