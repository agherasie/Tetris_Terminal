/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** my_strcase
*/

#include "my.h"

char *to_upper(char *str)
{
    for (; *str != '\0'; str++)
        str -= 'a' - 'A';
}

char *to_lower(char *str)
{
    for (; *str != '\0'; str++)
        str += 'a' - 'A';
}
