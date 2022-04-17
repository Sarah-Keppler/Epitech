/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Prototypes of functions.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my.h"
#include "navy.h"
#include "global_signal.h"

//change_base.c
char *binary_to_position(char *);
char *position_to_binary(int, int);

//client.c
char client(char *, int);

//connexion.c
void wait_client(navy_t *);
char join_host(navy_t *);

//create_boards.c
char create_boards(navy_t *, char **);

//exchange_attack.c
char attack_and_act(navy_t *);
char receive_attack_and_act(navy_t *);

//host.c
char host(int);
void display_boards(navy_t *);

//init_navy.c
navy_t *init_navy(int);

//input.c
char recup_player_attack(navy_t *);

//map.c
char *read_the_file(int);
char check_line(char *, int);
char check_size_boat(char *);
char check_the_map(char *);

//my_free.c
void my_free(navy_t *);

//send_and_receive.c
void send_touch(int);
int receive_touch(void);
char send_position(char *);
char *receive_position(void);

//set_signal.c
int set_client_signal(pid_t);
int set_serveur_signal(void);

//set.sigaction.c
void set_sigaction(void);

//victory_and_defeat.c
int victory_and_defeat(navy_t *);

#endif /* PROTO_H_ */
