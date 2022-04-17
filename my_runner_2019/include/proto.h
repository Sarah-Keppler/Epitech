/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Proto of all functions.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "end.h"
#include "evil_force.h"
#include "game_object.h"
#include "level.h"
#include "map.h"
#include "home.h"
#include "obstacles.h"
#include "runner.h"
#include "picture.h"

//animation.c
void anim_level(runner_t *,level_t *);
void anim_player(game_object_t *);
void anim_monster(monster_t **, int);

//bg.c
sprite_t *init_collision(char *, sfIntRect);
sprite_t *init_wallpaper_level(char *);
picture_t *init_bg(char *, int);
picture_t **init_parsing(void);
sprite_t *init_sprite(char *);

//collisions.c
void check_collisions(runner_t *, level_t *);
void move_hitbox(player_t *, foes_t *);
char collision_with_monsters(player_t *, foes_t *);
char collision_with_tiles(player_t *, map_t *);

//create_map.c
void make_map(map_t *, char *);
void set_collisions(map_t *, char, int, int);
void get_info(level_t *, map_t *);

//display_level.c
void display_game(runner_t *, level_t *);
void display_parsing(runner_t *, level_t *);
void display_mob(runner_t *);

//evil.c
foes_t *init_foes(char *, int);
monster_t *init_monster(void);
int get_nb_ennemies(char *);
void set_pos_foes(foes_t *);

//hud_scene.c
void home_scene(runner_t *);
void win_scene(runner_t *);
void game_over_scene(runner_t *);

//init_end.c
end_t *init_end(char *);
char init_wallpaper_end(end_t *);

//init_map.c
map_t *init_map(runner_t *, char *);
char init_t(map_t *);
void get_ressources(p_obj_t **);
void save_block(map_t *, float *);
void set_tiles_pos(map_t *, p_obj_t ***);

//init_hud.c
home_t *init_home(void);
void set_pos_home(sfText **);
char init_wallpaper(home_t *);
end_t *init_end(char *);
char init_wallpaper_end(end_t *);

//init_level.c
level_t *init_level(void);
player_t *init_player(void);
char init_info(level_t *, int);

//init_runner.c
runner_t *init_runner(char *);
sfRenderWindow *createMyWindow(unsigned int, unsigned int, char *);

//jump_and_gravity.c
void jump(level_t *, game_object_t *, char *);
void apply_gravity(map_t *, level_t *, game_object_t *, char *);

//level_scene.c
void game(runner_t *);
void event_level(runner_t *, level_t *);

//map.c
char *read_file(char *);
char check_the_map(char *);
char check_character_allowed(char *);

//mouvement.c
void move(runner_t *, level_t *);
void move_object(game_object_t *);
void move_tiles(p_obj_t *);

//my.c
int my_strln(char const *);
void my_rstr(char *);
void my_swp_c(char *, char *);
void my_strct(char *, char const *);
char *my_strcy(char *, char const *);

//my_free.c
void destroy_and_free_runner(runner_t *);

//object.c
game_object_t *create_object(const char *,
                                    sfVector2f, sfIntRect);
void destroy_object(game_object_t *);
p_obj_t *create_sprite_obj(char *, sfVector2f, sfIntRect, float);

//player_mouvement.c
void move_player(runner_t *,level_t *, map_t *);
void set_the_ground(level_t *, map_t *, int, int);
void mouvement_events(runner_t *, level_t *, map_t *, int);

#endif /* PROTO_H_ */
