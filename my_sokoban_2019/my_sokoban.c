/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Our hand-made sokoban ! (with bugs). Don't check valgrind ! Please !
*/

#include <ncurses.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/map.h"
#include "include/sokoban.h"

void disp_hflag(char **av)
{
    my_putstr("USAGE\n     ");
    my_putstr(av[0]);
    my_putstr(" map\n");
    my_putstr("DESCRIPTION\n     map  file representing the warehouse map,");
    my_putstr("containing '#' for walls,\n          'P' for the player,");
    my_putstr("'X' for boxes and '0' for storage locations.\n");
}

void game(map_t *map)
{
    int ch = 0;

    while (ch != 27) {
        print_map(map);
        ch = getch();
        move_player(ch, map);
        disp_storage(map);
        reset(ch, map);
        if (1 == check_victory(map) || 1 == check_defeat(map))
            break;
        my_str_to_word_array(map);
        refresh();
        clear();
    }
    if (ch == 27)
        map->end = 0;
    print_map(map);
}

void start_ncurses(map_t *map)
{
    initscr();
    keypad(stdscr, TRUE);
    game(map);
    endwin();
}

_Bool deal_errors(map_t *map)
{
    char *flag =  "#XO P\n";

    for (int i = 0; '\0' != map->map[i]; ++i) {
        if (false == is_valid_map(map->map, flag, i)) {
            my_putstr("Wrong characters in the map -- Error");
            return (false);
        }
    }
    if (false == get_nb_of_time(map))
        return (false);
    return (true);
}

int main(int ac, char **av)
{
    int end = 0;
    map_t *map;

    if (false == deal_arg(ac))
        return (84);
    if ('-' == av[1][0] && 'h' == av[1][1]) {
        disp_hflag(av);
        return (0);
    }
    map = init_map(av);
    if (map == NULL)
        return (84);
    if (false == deal_errors(map))
        return (84);
    start_ncurses(map);
    end = map->end;
    lets_free(map);
    return (end);
}
