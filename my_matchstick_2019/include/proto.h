/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Prototypes of all functions.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my.h"
#include "matchstick.h"

//ai.c
void ai_turn(matchstick_t *);

//display.c
void print_board(matchstick_t *);
void print_player_choice(int, int);
void print_ai_choice(int, int);

//error.c
char check_args(char **);
char check_sdin_line(matchstick_t *, char *);
char check_sdin_match(matchstick_t *, int, char *);
char check_nb_matches(matchstick_t *, int, char *);

//init_match.c
matchstick_t *init_matchstick(char **);
char init_stick_and_space(matchstick_t *);
void create_board(matchstick_t *);
void place_spaces_and_sticks(matchstick_t *, int);

//my_get_line.c
char *my_get_line(char *, size_t *);

//my_rand.c
int my_rand(int, int);
int get_a_random_value(int, int*);

//play.c
void remove_from_board(matchstick_t *, int, int);
void check_end(matchstick_t *, int *);
void free_all(matchstick_t *);

//player.c
char read_player_move(matchstick_t *);
char read_line(matchstick_t *, int *);
char read_match(matchstick_t *, int, int *);

#endif /* PROTO_H_ */
