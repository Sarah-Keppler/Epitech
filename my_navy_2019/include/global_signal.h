/*
** EPITECH PROJECT, 2020
** global_signal.h
** File description:
** Global struct for the signals.
*/

#ifndef GLOBAL_SIGNAL_H
#define GLOBAL_SIGNAL_H

#include <signal.h>

typedef struct msg
{
    pid_t pid;
    int info;
} msg;

extern msg messenger;

#endif /*GLOBAL_SIGNAL_H*/