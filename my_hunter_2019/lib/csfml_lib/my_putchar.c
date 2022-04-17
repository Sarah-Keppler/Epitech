/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Display a char.
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "my_csfml.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
