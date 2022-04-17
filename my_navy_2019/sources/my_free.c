/*
** EPITECH PROJECT, 2019
** my_free.c
** File description:
** Free the program.
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

void my_free(navy_t *navy)
{
    for (int i = 0; 8 > i; ++i) {
        free(navy->map[i]);
        free(navy->my_pos[i]);
        free(navy->enemy_pos[i]);
    }
    free(navy->map);
    free(navy->my_pos);
    free(navy->enemy_pos);
    free(navy);
}
