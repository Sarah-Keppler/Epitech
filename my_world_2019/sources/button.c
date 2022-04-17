/*
** EPITECH PROJECT, 2019
** button
** File description:
** world
*/

#include "world.h"

static button_t *create_button(char *picture, sfVector2f pos, sfIntRect rect)
{
    button_t *button = malloc(sizeof(button_t));
    sfFloatRect rectf = {0, 0, 0, 0};

    if (NULL == button)
        return (NULL);
    button->entity = create_sprite_rect(picture, rect, pos);
    if (NULL == button->entity)
        return (NULL);
    button->state = 0;
    button->rect = rect;
    rectf = sfSprite_getGlobalBounds(button->entity->sprite);
    button->rectf = rectf;
    return (button);
}

static void init_buttons_part1(button_t **new)
{
    new[UP] = create_button(BUTTON_UP,
        (sfVector2f){1727, 870}, (sfIntRect){0, 0, 63, 63});
    new[DOWN] = create_button(BUTTON_DOWN,
        (sfVector2f){1727, 933}, (sfIntRect){0, 0, 63, 63});
    new[RIGHT] = create_button(BUTTON_RIGHT,
        (sfVector2f){1793, 933}, (sfIntRect){0, 0, 63, 63});
    new[LEFT] = create_button(BUTTON_LEFT,
        (sfVector2f){1660, 933}, (sfIntRect){0, 0, 63, 63});
    new[CIRCLE] = create_button(BUTTON_CIRCLE,
        (sfVector2f){300, 855}, (sfIntRect){0, 0, 63, 63});
    new[POINT] = create_button(BUTTON_POINT,
        (sfVector2f){400, 855}, (sfIntRect){0, 0, 63, 63});
    new[SQUARE] = create_button(BUTTON_SQUARE,
        (sfVector2f){500, 855}, (sfIntRect){0, 0, 63, 63});
    new[AMP_UP] = create_button(BUTTON_AMP_UP,
        (sfVector2f){1315, 855}, (sfIntRect){0, 0, 63, 63});
    new[AMP_DOWN] = create_button(BUTTON_AMP_DOWN,
        (sfVector2f){1383, 855}, (sfIntRect){0, 0, 63, 63});
    new[IN_AREA] = create_button(BUTTON_IN_AREA,
        (sfVector2f){1463, 855}, (sfIntRect){0, 0, 63, 63});
}

static void init_buttons_part2(button_t **new)
{
    new[DE_AREA] = create_button(BUTTON_DE_AREA,
        (sfVector2f){1531, 855}, (sfIntRect){0, 0, 63, 63});
    new[IN_MAP] = create_button(BUTTON_IN_MAP,
        (sfVector2f){1450, 945}, (sfIntRect){0, 0, 63, 63});
    new[DE_MAP] = create_button(BUTTON_DE_MAP,
        (sfVector2f){1525, 945}, (sfIntRect){0, 0, 63, 63});
    new[MENU] = create_button(BUTTON_MENU,
        (sfVector2f){30, 825}, (sfIntRect){0, 0, 63, 63});
    new[IMPORT] = create_button(BUTTON_IMPORT,
        (sfVector2f){310, 942}, (sfIntRect){0, 0, 63, 63});
    new[EXPORT] = create_button(BUTTON_EXPORT,
        (sfVector2f){395, 942}, (sfIntRect){0, 0, 63, 63});
    new[SAVE] = create_button(BUTTON_SAVE,
        (sfVector2f){480, 942}, (sfIntRect){0, 0, 63, 63});
    new[ROTATE_R] = create_button(BUTTON_ROTATE_R,
        (sfVector2f){165, 914}, (sfIntRect){0, 0, 47,47});
    new[ROTATE_L] = create_button(BUTTON_ROTATE_L,
        (sfVector2f){78, 914}, (sfIntRect){0, 0, 47, 47});
    new[IN_ZOOM] = create_button(BUTTON_IN_ZOOM,
        (sfVector2f){122, 873}, (sfIntRect){0, 0, 47, 47});
}

static void init_buttons_part3(button_t **new)
{
    new[DE_ZOOM] = create_button(BUTTON_DE_ZOOM,
        (sfVector2f){122, 958}, (sfIntRect){0, 0, 47, 47});
    new[NEWMAP] = create_button(BUTTON_NEWMAP,
        (sfVector2f){730, 400}, (sfIntRect){0, 0, 471, 126});
    new[LOADMAP] = create_button(BUTTON_LOADMAP,
        (sfVector2f){730, 550}, (sfIntRect){0, 0, 471, 126});
    new[EXIT] = create_button(BUTTON_EXIT,
        (sfVector2f){730, 700}, (sfIntRect){0, 0, 471, 126});
}

button_t **init_template_buttons(void)
{
    button_t **new = malloc(sizeof(button_t *) * (BUTTON_MAX + 1));

    if (NULL == new)
        return (NULL);
    init_buttons_part1(new);
    init_buttons_part2(new);
    init_buttons_part3(new);
    for (int i = 0; BUTTON_MAX > i; ++i)
        if (NULL == new[i])
            return (NULL);
    new[BUTTON_MAX] = NULL;
    return (new);
}
