/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** my_strccpy
*/

#include "my.h"

char *before_c(char *file, char c)
{
    char *new_file = malloc(sizeof(char) * (my_strlen(file)));
    int i = 0;
    for (; file[i] != c; i++)
        new_file[i] = file[i];
    new_file[i] = '\0';
    return new_file;
}
