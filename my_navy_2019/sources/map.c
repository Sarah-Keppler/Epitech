/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Recup and check the map.
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char check_size_boat(char *src)
{
    if (src[2] == src[5]) {
        if (((src[0] - 48) - 1) != ((src[6] - 48) - (src[3] - 48))) {
            print_error("Error :: Map -- Size boats1\n");
            return ('1');
        }
    } else {
        if (src[3] != src[6]) {
            print_error("Error :: Map -- Boats positions\n");
            return ('1');
        }
        if (((src[0] - 48) - 1) != (src[5] - 64) - (src[2] - 64)) {
            print_error("Error :: Map -- Size boats2\n");
            return ('1');
        }
    }
    return ('0');
}

char check_line(char *src, int fst)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i)
        if (':' == src[i])
            ++nb;
    if (2 != nb || (fst + 48) != src[0]) {
        write(2, "Error :: Map -- Invalid format\n", 31);
        return ('1');
    }
    if (!('A' <= src[2] && 'H' >= src[2]) ||
        !('A' <= src[5] && 'H' >= src[5])) {
        write(2, "Error :: Map -- Invalid format\n", 31);
        return ('1');
    }
    else if (!('1' <= src[3] && '8' >= src[3]) ||
        !('1' <= src[6] && '8' >= src[6])) {
        write(2, "Error :: Map -- Invalid format\n", 31);
        return ('1');
    }
    return ('0');
}

static char check_map_size(char *src)
{
    int nb_char = 0;
    int nb_line = 0;

    for (int i = 0; src[i]; ++i) {
        if ('\n' != src[i])
            ++nb_char;
        else {
            ++nb_line;
            nb_char = 0;
        }
    }
    if (7 != nb_char || 3 != nb_line) {
        write(2, "Error :: Map -- Invalid Size\n", 28);
        return ('1');
    }
    return ('0');
}

char check_the_map(char *src)
{
    if (31 != my_strlen(src)) {
        write(2, "Error :: Map -- Invalid Size\n", 28);
        return ('1');
    }
    if ('1' == check_map_size(src))
        return ('1');
    return ('0');
}

char *read_the_file(int fd)
{
    char *buffer = malloc(sizeof(char) * 32);

    if (NULL == buffer)
        return (NULL);
    read(fd, buffer, 32);
    buffer[31] = '\0';
    return (buffer);
}
