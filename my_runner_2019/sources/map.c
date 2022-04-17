/*
** EPITECH PROJECT, 2019
** map
** File description:
** Get and check the map.
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char *read_file(char *src)
{
    int fd = open(src, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 801);
    int len = 0;

    buffer[0] = '\0';
    if (NULL == buffer || -1 == fd)
        return (NULL);
    len = read(fd, buffer, 800);
    if ('\0' == buffer[0])
        return (NULL);
    buffer[len] = '\0';
    return (buffer);
}

char check_character_allowed(char *map)
{
    char *character = "123567AZERTQSDFG48VM";
    int nb = 0;

    for (int i = 0; map[i]; ++i) {
        for (int y = 0; character[y]; ++y)
            if (map[i] == character[y])
                ++nb;
        if (0 == nb) {
            write(2, "Error :: Map inadaped (character)\n", 35);
            return ('1');
        }
    }
    return ('0');
}

char check_the_map(char *map)
{
    int nb = 0;

    if (153 != my_strlen(map)) {
        write(2, "Error :: Map inadapted (size)\n", 30);
        return ('1');
    }
    for (int i = 0; map[i]; ++i) {
        if ('\n' == map[i])
            ++nb;
    }
    if (6 != nb) {
        write(2, "Error :: Map inadapted (line)\n", 30);
        return ('1');
    } else if ('1' == check_character_allowed(map))
        return ('1');
    return ('0');
}
