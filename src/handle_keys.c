/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void handle_d4(game_t *g)
{
    my_putstr("Number of tetriminos: ");
    my_put_nbr(count_file(g));
    my_putchar('\n');
    check_file(g);
}

int count_file(game_t *g)
{
    struct dirent *dirent;
    DIR *file_name;
    int count = 0;
    char *path;
    char *file;

    file_name = opendir("tetriminos");

    while ((dirent = readdir(file_name)) != NULL) {
        file = dirent->d_name;
        path = my_strcat("tetriminos/", file);
        if (file_error_detection(path) == TRUE)
            count++;
    }
    return count;
}
