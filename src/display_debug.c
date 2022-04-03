/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** file_checks
*/

#include "../include/tetris.h"

char *before_c(char *file, char c)
{
    char *new_file = malloc(sizeof(char) * (my_strlen(file)));
    int i = 0;
    for (; file[i] != c; i++)
        new_file[i] = file[i];
    new_file[i] = '\0';
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
    char **file_names = valid_files();
    sort(file_names, 'a');
    for (int i = 0; file_names[i]; i++) {
        char *path = my_strcat("tetriminos/", file_names[i]);
        if (file_error_detection(path) == TRUE) {
            char *inside = read_to_charstar(path);
            char *name = before_c(file_names[i], '.');
            printf("Tetriminos '");
            printf("%s", name);
            if (good_file(inside) == 1)
                printf("': error\n");
            else
                continue_display(inside, g);
            free(inside);
        }
        free(path);
    }
}
