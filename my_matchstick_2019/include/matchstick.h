/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** Struct of the matchstick.
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct matchstick {
    char **game;
    int lines;
    int max_out;
    int *stick;
    int *space;
} matchstick_t;

#endif /* MATCHSTICK_H_ */
