/*
** EPITECH PROJECT, 2019
** world.h
** File description:
** Prototypes of My_world
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

/*-----INIT-----*/
world_t *init_world(char **);
button_t **init_template_buttons(void);
color_t *init_color(void);
home_t *init_home(world_t *, char **);
edit_t *init_edit(world_t *, home_t *);
mouse_t *init_mouse(world_t *);
sprite_t *create_sprite_rect(char *, sfIntRect, sfVector2f);
sprite_t *create_sprite(char *, sfVector2f);

/*-----USEFUL-----*/
char change_sprite_rect(sprite_t *, char *, sfIntRect, sfVector2f);
char create_the_map(map_t *, char *, int, int);
char *import_a_map(char *);
sfVector2f **create_2d_map(map_t *, int **);
int **create_3d_map(int, int, char **);
int **create_default_3d_map(void);
char check_the_map(map_t *, char *);
sfColor get_color(color_t *, char *);
char check_if_mouse_tile(mouse_t *, sfVector2f *);
void check_tiles(world_t *);
void circle_follow_mouse(sfCircleShape *, world_t *, int, int);
void active_circles(world_t *);
void desactive_circles(world_t *);
char first_check_tile(world_t *, sfVector2f *);
sfCircleShape *create_a_circle_with_color(world_t *, float, char *,
    sfVector2f);
sfVertexArray *create_line(sfVector2f *, sfVector2f *);
sfVertexArray *create_quadrangle(sfVector2f *, sfVector2f *, sfVector2f *,
    sfVector2f *);
char check_corner(world_t *, sfVector2f);
void center_the_map(map_t *, sfVector2f **);
void reset_map(world_t *);
char reset_map_completely(world_t *);
void update_2d_map(map_t *, sfVector2f **, int **);
char update_3d_map(map_t *, int, int);
sfVector2f project_iso_point(int, int, int);
void lower_points(world_t *);
void raise_points(world_t *);
void move_to_the_top(world_t *);
void move_to_the_right(world_t *);
void move_to_the_bottom(world_t *);
void move_to_the_left(world_t *);
char increase_map_height(world_t *);
char increase_map_width(world_t *);
char decrease_map_height(world_t *);
char decrease_map_width(world_t *);
void active_tiles(world_t *);
void active_corners(world_t *);
void increase_select_area(world_t *);
void decrease_select_area(world_t *);

/*-----MAIN-----*/
char home_page(world_t *);
char state_hover_home(world_t *, button_t **);
char edit_page(world_t *);
char state_hover_edit(world_t *, button_t **);
char use_keyboard(world_t *);
void use_mouse(world_t *);

/*-----PRINT-----*/
void print_home(sfRenderWindow *, home_t *);
void print_edit(sfRenderWindow *, edit_t *);
char draw_under_framerate(world_t *, int);
char draw_quadrangles(world_t *);
char draw_2d_map(world_t *);
char color_points_in_select_area(world_t *);
char color_points_of_a_tile(world_t *);

/*-----FREE AND DESTROY-----*/
void my_free_and_destroy(world_t *);
void my_free_maps(map_t *, char);

#endif /* WORLD_H_ */
