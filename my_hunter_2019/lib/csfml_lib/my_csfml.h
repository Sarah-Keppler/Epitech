/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Header for the hunter !!!
*/

#ifndef MY_CSFML_H_
#define MY_CSFML_H

typedef struct text_s
{
    sfFont *font;
    sfText *text;
} text_t;

typedef struct picture_s
{
    sfTexture *texture;
    sfSprite *sprite;
} picture_t;

typedef struct text_game_s
{
    text_t life;
    text_t score;
} text_game_t;

typedef struct bird_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f size;
    sfIntRect rect;
} bird_t;

typedef struct game_s
{
    sfRenderWindow *window;
    sfEvent event;
    picture_t bg;
    sfVector2i mouse;
    int life;
    int score;
} game_t;

sfRenderWindow *create_my_window(unsigned int, unsigned int, char *);

typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;
t_framebuffer *framebuffer_create(unsigned int, unsigned int);
void framebuffer_destroy(t_framebuffer *);

//My_Lib
void my_putchar(char);
void my_putstr(char const *);
int my_strlen(char const *);

bird_t *init_bird();
game_t *init_game_s();
int check_flag(int, char **);
void destroy_all(game_t *, bird_t *);
void chrono(sfClock *, sfTime *, bird_t *);

#endif /* MY_CSFML_H */
