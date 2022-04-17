/*
** EPITECH PROJECT, 2019
** init
** File description:
** Init everything
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_csfml.h"

void init_bird2(bird_t *bird)
{
    bird->position = sfSprite_getPosition(bird->sprite);
    bird->position.y = rand() % (810);
    sfSprite_setPosition(bird->sprite, bird->position);
    bird->size = sfSprite_getScale(bird->sprite);
    bird->size.x = 0.33;
    bird->size.y = 0.33;
    bird->rect.top = 0;
    bird->rect.left = 0;
    bird->rect.width = 360;
    bird->rect.height = 316;
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    sfSprite_setScale(bird->sprite, bird->size);
}

bird_t *init_bird(void)
{
    bird_t *bird = malloc(sizeof(bird_t));

    if (bird == NULL)
        return (NULL);
    bird->sprite = sfSprite_create();
    if (bird->sprite == NULL)
        return (NULL);
    bird->texture = sfTexture_createFromFile("Triforce_sheet.png", NULL);
    if (bird->texture == NULL)
        return (NULL);
    init_bird2(bird);
    return (bird);
}

picture_t *init_background(void)
{
    picture_t *bg = malloc(sizeof(picture_t));
    sfVector2f size;

    if (bg == NULL)
        return (NULL);
    bg->sprite = sfSprite_create();
    if (bg->sprite == NULL)
        return (NULL);
    bg->texture = sfTexture_createFromFile("background.jpg", NULL);
    if (bg->texture == NULL)
        return (NULL);
    size = sfSprite_getScale(bg->sprite);
    size.x = 0.75;
    size.y = 0.75;
    sfSprite_setScale(bg->sprite, size);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    return (bg);
}

game_t *init_game_s(void)
{
    game_t *hunter = malloc(sizeof(game_t));
    sfEvent event;
    picture_t *bg = init_background();

    if (hunter == NULL)
        return (NULL);
    hunter->window = create_my_window(1440, 810, "My Hunter");
    hunter->event = event;
    hunter->bg = *bg;
    hunter->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    hunter->score = 0;
    hunter->life = 3;
    return (hunter);
}
