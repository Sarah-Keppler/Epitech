/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Fucntions prototype.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "struct.h"

                    /*###############*/
                    /*     PAGES     */
                    /*###############*/

char home_page(rpg_t *, home_t *);
char dragon_quest(rpg_t *, player_t *);

                    /*################*/
                    /*     COMBAT     */
                    /*################*/

char engage_combat(rpg_t *, player_t *, monster_t *);
void event_battle(rpg_t *, battle_t *);
void choose(rpg_t *, battle_t *);
void attack(battle_t *, player_t *, monster_t *);
void draw_battle(rpg_t *, battle_t *);

                    /*##########################*/
                    /*     MAP AND MOVEMENT     */
                    /*##########################*/

void set_start_position(rpg_t *, player_t *);
void get_player_position(map_t *, player_t *);
char movement(rpg_t *, player_t *, map_t *);
char events(rpg_t *, player_t *, int);
void update_map(rpg_t *, player_t *, char);
void move_up(player_t *, map_t *);
void move_down(player_t *, map_t *);
void move_right(player_t *, map_t *);
void move_left(player_t *, map_t *);
void anim_movement(player_t *, int);

                    /*####################*/
                    /*     GET_&_FIND     */
                    /*####################*/

char **get_a_file_source(char *, char *);
char *copy_the_name(char const *, char const *);
item_t *find_ref_item(rpg_t *, char *);
set_t *find_ref_set(rpg_t *, char *);
pnj_t *find_ref_pnj(rpg_t *, char *);
dialogue_t *find_ref_dialogue(rpg_t *, char *);
quest_t *find_ref_quest(rpg_t *, char *);
objectif_t *find_ref_objectif(rpg_t *, char *);
reward_t *find_ref_reward(rpg_t *, char *);
map_t *find_ref_map(rpg_t *, char *);
monster_t *find_ref_monster(rpg_t *, char *);
attack_t *find_ref_attack(rpg_t *, char *);
sprite_t *find_ref_sprite(rpg_t *, set_t *, item_t *);

                    /*###############################*/
                    /*     INVENTAIRE AND PROFIL     */
                    /*###############################*/

char manage_inventory(rpg_t *, player_t *, inventory_t *);
char manage_profil(rpg_t *, player_t *);
void check_close_window(rpg_t *, sprite_t *, int);
char add_an_item(rpg_t *, inventory_t *, set_t *, item_t *);
void remove_an_item(inventory_t *, int);
char wear_a_set(rpg_t *, player_t *, int);
char remove_a_set(rpg_t *, player_t *, int);

                    /*#############################*/
                    /*     INIT PRINT AND FREE     */
                    /*#############################*/

/*##############*/
/*     INIT     */
/*##############*/

rpg_t *init_rpg(void);
home_t *init_home(rpg_t *);
battle_t *init_battle(player_t *, monster_t *);
char *create_a_path(char *, int);
char init_rpg_part1(rpg_t *, int *);
char init_rpg_part2(rpg_t *, int *);
char init_rpg_part3(rpg_t *, int *);
char init_rpg_part4(rpg_t *, int *);
player_t *init_player(rpg_t *, char *);
char set_player_info(player_t *);
dialogue_t *create_a_dialogue(char *);
objectif_t *create_an_objectif(char *);
pnj_t *create_a_pnj(rpg_t *, char *);
quest_t *create_a_quest(rpg_t *, char *);
reward_t *create_a_reward(rpg_t *, char *);
item_t *create_an_item(char *);
set_t *create_a_set(char *);
stat_t *create_a_stat(char **);
map_t *create_a_map(char *);
attack_t *create_an_attack(char *);
monster_t *create_a_monster(rpg_t *, char *);
inventory_t *create_an_empty_inventory(int);
sprite_t *create_sprite(char *, sfVector2f);
sprite_t *create_sprite_rect(char *, sfIntRect, sfVector2f);
char change_sprite_rect(sprite_t *, char *, sfIntRect, sfVector2f);
sfText *create_text(char *, sfFont *, int, sfVector2f);

/*###############*/
/*     PRINT     */
/*###############*/

void print_rpg(rpg_t *);
void print_player(player_t *);
void print_an_inventory(inventory_t *);
void print_a_dialogue(dialogue_t *);
void print_an_objectif(objectif_t *);
void print_a_pnj(pnj_t *);
void print_a_quest(quest_t *);
void print_a_reward(reward_t *);
void print_an_item(item_t *);
void print_a_set(set_t *);
void print_a_stat(stat_t *);
void print_a_map(map_t *);
void print_an_attack(attack_t *);
void print_a_monster(monster_t *);

/*##############*/
/*     FREE     */
/*##############*/

void free_rpg(rpg_t *);
void free_player(player_t *);
void free_an_inventory(inventory_t *);
void free_a_dialogue(dialogue_t *);
void free_an_item(item_t *);
void free_an_objectif(objectif_t *);
void free_a_pnj(pnj_t *);
void free_a_quest(quest_t *);
void free_a_reward(reward_t *);
void free_a_set(set_t *);
void free_a_map(map_t *);
void free_an_attack(attack_t *);
void free_a_monster(monster_t *);
void free_home(home_t *);
void free_info(char **);
void destroy_sprite(sprite_t *);
void destroy_text(sfText *);

                    /*##############*/
                    /*     THEO     */
                    /*##############*/

sfIntRect give_value(button_t **, int);
sfVector2f give_pos(sfVector2f);
scene_t *create_home(sfRenderWindow *);
scene_t *create_play_menu(sfRenderWindow *);
scene_t *create_option(sfRenderWindow *);
scene_t *create_pause(sfRenderWindow *);
scene_t *create_scene(sfRenderWindow *);
int click_scene_gestion(sfRenderWindow *, scene_t *);
void change_color(scene_t *, sfRenderWindow *);
int click_scene(int, sfEvent, scene_t *, sfRenderWindow *);
void check_if(sfRenderWindow *, scene_t *);
int check_pos(button_t *, sfVector2i, int);
int option(rpg_t *, home_t *);
int play_menu(rpg_t *, home_t *);
int main_menu(rpg_t *, home_t *);
int pause_scene(rpg_t *);
int my_butlen(button_t **);
void free_scene(scene_t *);
int loop(rpg_t *);
void draw_scene(rpg_t *, home_t *, int);
particle_t *create_first_particle_point(void);
void create_particle(sfRenderWindow *, particle_t *);
void modif_particle(particle_t *);
particle_t *destroy_one(particle_t *, particle_t *);
void free_particle(particle_t *);
void particle_gestion(particle_t *, sfRenderWindow *);
void print_particle(particle_t *, sfRenderWindow *);
sfVector2i particle_manage(sfRenderWindow *, particle_t *, sfClock *,
    sfVector2i);
void option_gestion(int, rpg_t *, home_t *);
void free_all(rpg_t *);

#endif /* PROTO_H_ */
