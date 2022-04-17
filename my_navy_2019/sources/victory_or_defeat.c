/*
** EPITECH PROJECT, 2019
** victory_and_defeat.c
** File description:
** Check victory or defeat.
*/

#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

static void check_who_wins(char *board_line, int *infos)
{
    for (int i = 0; board_line[i]; ++i)
        if ('x' == board_line[i])
            ++(*infos);
}

int victory_and_defeat(navy_t *navy)
{
    int my_infos = 0;
    int enemy_infos = 0;

    for (int i = 0; 10 > i; ++i) {
        check_who_wins(navy->my_pos[i], &my_infos);
        check_who_wins(navy->enemy_pos[i], &enemy_infos);
    }
    if (14 == my_infos) {
        display_boards(navy);
        my_putstr("Enemy won\n");
        navy->endgame = 1;
        return (0);
    } else if (14 == enemy_infos) {
        display_boards(navy);
        my_putstr("I won\n");
        navy->endgame = 0;
        return (0);
    }
    return (1);
}
