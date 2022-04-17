/*
** EPITECH PROJECT, 2019
** init_navy.c
** File description:
** Init the struct navy.
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

static char create_map(navy_t *navy, int fd)
{
    char *buffer = read_the_file(fd);

    if (NULL == buffer || '1' == check_the_map(buffer))
        return ('1');
    navy->map = my_str_to_word_array(buffer, '\n');
    if (NULL == navy->map)
        return ('1');
    for (int i = 0; 4 > i; ++i) {
        if ('1' == check_line(navy->map[i], i + 2))
            return ('1');
        if ('1' == check_size_boat(navy->map[i]))
            return ('1');
    }
    return ('0');
}

navy_t *init_navy(int fd)
{
    navy_t *navy = malloc(sizeof(navy_t));

    if (NULL == navy || '1' == create_map(navy, fd))
        return (NULL);
    if ('1' == create_boards(navy, navy->map))
        return (NULL);
    navy->my_pid = getpid();
    return (navy);
}
