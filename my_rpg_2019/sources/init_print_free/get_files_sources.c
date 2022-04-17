/*
** EPITECH PROJECT, 2019
** get_file_sources
** File description:
** Get the file source to init a structure.
*/

#include <dirent.h>
#include "project.h"

void free_info(char **info)
{
    for (int i = 0; NULL != info[i]; ++i)
        free(info[i]);
    free(info);
}

static char **read_a_file_source(char *path)
{
    char *buffer = NULL;
    char **info = NULL;
    int fd = open(path, O_RDONLY);

    if (-1 == fd) {
        my_puterror("No such file\n");
        return (NULL);
    }
    buffer = read_a_file(fd, 100);
    if (NULL == buffer)
        return (NULL);
    info = my_str_to_word_array(buffer, '\n');
    if (NULL == info)
        return (NULL);
    free(buffer);
    close(fd);
    return (info);
}

static char *construct_path(char *path, char *file_name)
{
    int len = my_strlen(path) + my_strlen(file_name);
    char *file_path = malloc(sizeof(char) * (len + 1));

    if (NULL == file_path)
        return (NULL);
    my_strcpy(file_path, path);
    my_strcat(file_path, file_name);
    return (file_path);
}

char **get_a_file_source(char *path, char *file_name)
{
    char *file_path = construct_path(path, file_name);
    char **info = NULL;

    if (NULL == file_path)
        return (NULL);
    info = read_a_file_source(file_path);
    if (NULL == info)
        return (NULL);
    free(file_path);
    return (info);
}
