/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** Struct of navy.
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "proto.h"

typedef struct navy {
    pid_t my_pid;
    pid_t other_pid;
    char **map;
    char **my_pos;
    char **enemy_pos;
    char *input;
    int endgame;
} navy_t;

#endif /* NAVY_H_ */
