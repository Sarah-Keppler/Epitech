/*
** EPITECH PROJECT, 2019
** change_base.c
** File description:
** Change from binary to string, and inversely.
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

static char first(char *str)
{
    int k = 0;
    char tmp[5];
    char *bin[10] = {"0000", "0001", "0010", "0011", "0100",
        "0101", "0110", "0111", "1000"};

    for (int i = 0; k < 4; k++) {
        tmp[i++] = str[k];
        tmp[i] = '\0';
    }
    for (int i = 0; bin[i]; i++)
        if (0 == my_strcmp(tmp, bin[i]))
            return (i + 64);
    return (0);
}

static char scnd(char *str)
{
    int k = 4;
    char tmp[5];
    char *bin[10] = {"0000", "0001", "0010", "0011", "0100",
        "0101", "0110", "0111", "1000"};

    for (int i = 0; str[k]; k++) {
        tmp[i++] = str[k];
        tmp[i] = '\0';
    }
    for (int i = 0; bin[i]; i++)
        if (0 == my_strcmp(tmp, bin[i]))
            return (i + 48);
    return (0);
}

char *binary_to_position(char *str)
{
    char *result = malloc(sizeof(char) * 3);

    if (NULL == result)
        return (NULL);
    result[0] = first(str);
    result[1] = scnd(str);
    result[2] = '\0';
    return (result);
}

char *position_to_binary(int first, int scnd)
{
    int j = 0;
    char *result = malloc(sizeof(char) * 11);
    char *bin[10] = {"0000", "0001", "0010", "0011", "0100",
        "0101", "0110", "0111", "1000"};

    if (NULL == result)
        return (NULL);
    for (int k = 0; bin[first][k]; k++)
        result[j++] = bin[first][k];
    for (int k = 0; bin[scnd][k]; k++)
        result[j++] = bin[scnd][k];
    result[j] = '\0';
    return (result);
}
