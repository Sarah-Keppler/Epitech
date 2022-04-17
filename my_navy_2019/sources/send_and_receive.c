/*
** EPITECH PROJECT, 2019
** send_and_receive.c
** File description:
** Exchange signals.
*/

#include "../include/global_signal.h"
#include "../include/proto.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void send_touch(int i)
{
    usleep(1000);
    if (i) {
        kill(messenger.pid, SIGUSR1);
    } else {
        kill(messenger.pid, SIGUSR2);
    }
}

int receive_touch(void)
{
    pause();
    if (messenger.info == SIGUSR1) {
        return (1);
    } else {
        return (0);
    }
}

char send_position(char *str)
{
    char *binary = position_to_binary((int)str[0] - 64, (int)str[1] - 48);

    if (NULL == binary)
        return ('1');
    for (int i = 0; binary[i]; i++) {
        usleep(1000);
        if (binary[i] == '0') {
            kill(messenger.pid, SIGUSR1);
        } else {
            kill(messenger.pid, SIGUSR2);
        }
    }
    free(binary);
    return ('0');
}

char *receive_position(void)
{
    int j = 0;
    char binary[8];
    char *position = NULL;

    for (int i = 0; i != 8; i++) {
        pause();
        if (messenger.info == SIGUSR1) {
            binary[j++] = '0';
        } else {
            binary[j++] = '1';
        }
    }
    position = binary_to_position(binary);
    if (NULL == position)
        return (NULL);
    return (position);
}
