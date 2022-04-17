/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** Header for the pretty game in your terminal !
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

void move_player(int, map_t *);
int move_box(int, map_t *);
void go_left(map_t *);
void go_right(map_t *);
void go_up(map_t *);
void go_down(map_t *);

int check_victory(map_t *);
int check_defeat(map_t *);
void disp_storage(map_t *);
char **my_str_to_word_array(map_t *);
void print_map(map_t *);
void disp_map(map_t *, int, int);

_Bool deal_arg(int);
_Bool is_valid_map(char *, char *, int);
_Bool get_nb_of_time(map_t *);
int get_nb_on_map(char *, char);
_Bool verif_extrem(map_t *);

#endif /* SOKOBAN_H_ */
