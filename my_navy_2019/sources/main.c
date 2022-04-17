/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Battleship between two terminals.
*/

#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char check_pid(char *src)
{
    for (int i = 0; src[i]; ++i)
        if (!('0' <= src[i] && '9' >= src[i]))
            return ('1');
    return ('0');
}

char recup_the_arguments(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char end = '0';

    if (-1 == fd && 2 == ac) {
        print_error("Error :: Case 1 argument, it needs to be a file\n");
        return ('1');
    }
    if (-1 == fd && 3 == ac) {
        if ('1' == check_pid(av[1])) {
            print_error("Error :: The first argument need to be an integer\n");
            return ('1');
        }
        end = client(av[2], my_getnbr(av[1]));
    } else if (-1 != fd)
        end = host(fd);
    close(fd);
    return (end);
}

void print_help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n\t");
    my_putstr("navy_position: file representing the position of the ships.\n");
}

int main(int ac, char **av)
{
    char endgame = '0';

    if (2 != ac && 3 != ac) {
        print_error("Error :: Bad amouth of argument\n");
        return (84);
    }
    if (2 == ac && 0 == my_strcmp(av[1], "-h")) {
        print_help();
        return (0);
    }
    if ('3' == (endgame = recup_the_arguments(ac, av)))
        return (84);
    return (endgame - 48);
}
