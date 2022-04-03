/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** file_checks
*/

#include "../include/tetris.h"

char *before_point(char *file)
{
    char *new_file = malloc(sizeof(char) * (30));
    for (int i = 0; file[i] != '.'; i++)
        new_file[i] = file[i];
    return new_file;
}

int good_file(char *buff)
{
    for (int i = 0; buff[i]; i++) {
        if (buff[i] >= 'A' && buff[i] <= 'Z')
            return 1;
        if (buff[i] >= 'a' && buff[i] <= 'z')
            return 1;
    }
    return 0;
}

void display_tetri(char *buff)
{
    int i = 0;
    for (; buff[i] != '\n'; i++);
    for (; buff[i] != '\0'; i++)
        printf("%c", buff[i]);
}

void continue_display(char *inside, game_t *g)
{
    printf("': size ");
    g->get1 = my_getnbr2(inside);
    inside += 2;
    g->get2 = my_getnbr2(inside);
    inside += 2;
    g->get3 = my_getnbr2(inside);
    printf("%i", g->get1);
    printf("*");
    printf("%i", g->get2);
    printf(", color ");
    printf("%i", g->get3);
    display_tetri(inside);
}

int check_file(game_t *g)
{
    struct dirent *dirent;
    DIR *file_name;
    char *file;
    char *path;
    file_name = opendir("tetriminos");
    while ((dirent = readdir(file_name)) != NULL) {
        file = dirent->d_name;
        path = my_strcat("tetriminos/", file);
        style(g, path, file);
    }
    free(path);
}
