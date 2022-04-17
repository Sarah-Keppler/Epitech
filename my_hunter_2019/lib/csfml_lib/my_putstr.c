/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display a string.
*/

#include <SFML/Graphics.h>
#include "my_csfml.h"

void my_putstr(char const *str)
{
    while ('\0' != *str) {
        my_putchar(*str);
        ++str;
    }
}
