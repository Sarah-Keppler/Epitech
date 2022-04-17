/*
** EPITECH PROJECT, 2019
** print_error.c
** File description:
** Print a error message error on output 2.
*/

#include <unistd.h>
#include "../../include/my.h"

void print_error(char *str)
{
    write(2, str, my_strlen(str));
}
