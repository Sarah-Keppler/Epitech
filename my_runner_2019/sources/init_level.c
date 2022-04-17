/*
** EPITECH PROJECT, 2019
** level
** File description:
** Init one level.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

char init_info(level_t *lvl, int nb_tiles)
{
    lvl->info = malloc(sizeof(char *) * 7);
    if (NULL == lvl->info)
        return ('1' );
    for (int i = 0; 7 > i; ++i) {
        lvl->info[i] = malloc(sizeof(char) * (nb_tiles + 1));
        if (NULL == lvl->info[i])
            return ('1');
        lvl->info[i][nb_tiles] = '\0';
    }
    return ('0');
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f size = {0.5, 0.5};
    sfVector2f pos = {128 / 2, 415};
    sfIntRect rect = {0, 0, 416, 454};
    sfIntRect collision = {0, 0, 208, 412};

    if (NULL == player)
        return (NULL);
    player->entity = create_object("Assets/Run.png", pos, rect);
    player->collision = init_collision("Assets/19.png", collision);
    if (NULL == player->entity || NULL == player->collision)
        return (NULL);
    sfSprite_setScale(player->entity->sprite, size);
    sfSprite_setScale(player->collision->sprite, size);
    return (player);
}

level_t *init_level(void)
{
    level_t *lvl = malloc(sizeof(level_t));

    if (lvl == NULL)
        return (NULL);
    lvl->wallpaper = init_wallpaper_level("Assets/background.png");
    lvl->parsing = init_parsing();
    lvl->clock = sfClock_create();
    if (NULL == lvl->wallpaper || NULL == lvl->parsing || NULL == lvl->clock)
        return (NULL);
    lvl->player = init_player();
    if (NULL == lvl->player)
        return (NULL);
    lvl->score = 0;
    lvl->jump = 0;
    lvl->ground = 640;
    lvl->last_ground = lvl->ground;
    return (lvl);
}
