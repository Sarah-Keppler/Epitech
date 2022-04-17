/*
** EPITECH PROJECT, 2019
** end.h
** File description:
** Struct of the end.
*/

#ifndef END_H_
#define END_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct {
    sfFont *font;
    sfText *text;
    sfSprite *bg_s;
    sfTexture *bg_t;
} end_t;

#endif /* END_H_ */
