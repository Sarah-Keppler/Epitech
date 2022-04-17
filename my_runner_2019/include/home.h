/*
** EPITECH PROJECT, 2019
** home.h
** File description:
** Struct of the home.
*/

#ifndef HOME_H_
#define HOME_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct text {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct {
    sfFont *font;
    sfText **text;
    sfSprite *bg_s;
    sfTexture *bg_t;
} home_t;

#endif /* HOME_H_ */
