/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Return the size of a string.
*/

#include <SFML/Graphics.h>
#include "my_csfml.h"

int my_strlen(char const *str)
{
    int number = 0;

    while ('\0' != *str) {
        ++str;
        ++number;
    }
    return (number);
}
