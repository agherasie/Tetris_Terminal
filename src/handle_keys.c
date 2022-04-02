/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

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

void handle_d(game_t *g)
{
    printf("Key left: %s (%i)\n", keyname(g->keys->l), g->keys->l);
    printf("Key right: %s (%i)\n", keyname(g->keys->r), g->keys->r);
    printf("Key turn: %s (%i)\n", keyname(g->keys->t), g->keys->t);
    printf("Key drop: %s (%i)\n", keyname(g->keys->d), g->keys->d);
    printf("Key quit: %s (%i)\n", keyname(g->keys->q), g->keys->q);
    printf("Key pause: %s (%i)\n", keyname(g->keys->p), g->keys->p);
    printf("Next: ");
    printf(g->show_next == 1 ? "Yes\n" : "No\n");
    printf("Level: %i\n", g->level);
    printf("Size: %i*%i\n\n", g->map_size.y, g->map_size.x);
    printf("Number of tetriminos: %i\n", count_file(g));
    check_file(g);
}
