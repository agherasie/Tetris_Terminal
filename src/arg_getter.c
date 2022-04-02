/*
** EPITECH PROJECT, 2022
** tetris
** File description:
**
*/

#include "../include/tetris.h"

char *handle_arg(char *arg, int offset, char sep)
{
    char *new_arg = arg;
    for (; *new_arg != sep; new_arg++);
    new_arg++;
    new_arg[my_strlen(new_arg) - offset] = '\0';
    return new_arg;
}

void handle_h_char(char key_code, int *key, char *src, char label)
{
    if (label == key_code)
        *key = my_getnbr(src);
}

void handle_h_str(char *src, char *str, int *key)
{
    if (starts_with(src + 2, str, '=') == TRUE)
        *key = my_getnbr(handle_arg(src, 0, '='));
}
