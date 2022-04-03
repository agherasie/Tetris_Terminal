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
    if (label == key_code) {
        if (my_getnbr(src) == 0)
            return;
        else
            *key = my_getnbr(src);
    }
}

void handle_h_str(char *src, char *str, int *key)
{
    if (starts_with(src + 2, str, '=') == TRUE) {
        if (my_getnbr(handle_arg(src, 0, '=')) == 0)
            return;
        else
            *key = my_getnbr(handle_arg(src, 0, '='));
    }
}

void style(game_t *g, char *path, char *file)
{
    char *inside;
    if (file_error_detection(path) == TRUE) {
        inside = read_to_charstar(path);
        printf("Tetriminos '");
        printf("%s", before_point(file));
        if (good_file(inside) == 1)
            printf("': error\n");
        else
            continue_display(inside, g);
    }
}
