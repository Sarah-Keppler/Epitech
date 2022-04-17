/*
** EPITECH PROJECT, 2019
** create_boards.c
** File description:
** Create the two board for the navy.
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

static char filled_boards(char **board, char **map, int line, int i)
{
    int y = map[line][3] - 47;
    int x = (map[line][2] - 64) * 2;

    if (map[line][2] == map[line][5]) {
        if ('.' != board[y + i][x])
            return ('1');
        board[y + i][x] = (line + 48) + 2;
    } else {
        if ('.' != board[y][x + (i * 2)])
            return ('1');
        board[y][x + (i * 2)] = (line + 48) + 2;
    }
    return ('0');
}

static char draw_boats(char **board, char **map, int line)
{
    for (int i = 0; (map[line][0] - 48) > i; ++i)
        if ('1' == filled_boards(board, map, line, i))
            return ('1');
    return ('0');
}

static void filled_empty_board(char **board)
{
    my_strcpy(board[0], " |A B C D E F G H\n");
    my_strcpy(board[1], "-+---------------\n");
    for (int i = 0; 8 > i; ++i) {
        my_strcpy(board[i + 2], "1|. . . . . . . .\n");
        board[i + 2][0] = (i + 1) + 48;
        board[i][18] = '\0';
    }
}

char create_boards(navy_t *navy, char **map)
{
    char **my_pos = malloc(sizeof(char *) * 10);
    char **enemy_pos = malloc(sizeof(char *) * 10);

    if (NULL == my_pos || NULL == enemy_pos)
        return ('1');
    for (int i = 0; 10 > i; ++i) {
        my_pos[i] = malloc(sizeof(char) * (18 + 1));
        enemy_pos[i] = malloc(sizeof(char) * (18 + 1));
        if (NULL == my_pos[i] || NULL == enemy_pos[i])
            return ('1');
    }
    filled_empty_board(my_pos);
    filled_empty_board(enemy_pos);
    for (int i = 0; 4 > i; ++i)
        if ('1' == draw_boats(my_pos, map, i))
            return ('1');
    navy->my_pos = my_pos;
    navy->enemy_pos = enemy_pos;
    return ('0');
}
