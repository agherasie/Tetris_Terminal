/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetrimino
*/

#include "../include/tetris.h"

void land_tetris(game_t *g, tetriminos_t *tetris)
{
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            char *map_pos = &g->map[y + tetris->pos.y][x + tetris->pos.x];
            *map_pos = tetris->shape[y][x] == FULL ? tetris->color : *map_pos;
        }
    reset_tetris(g);
}

void reset_tetris(game_t *g)
{
    g->tetris = g->tetri[g->next];
    g->next = range(0, 6);
    g->tetris->pos.x = g->map_size.x / 2;
    g->tetris->pos.y = 0;
}

void rotate_shape(tetriminos_t *t)
{
    char **transposed = malloc(sizeof(char *) * (t->size.x + 1));
    for (int y = 0; y < t->size.x; y++) {
        transposed[y] = malloc(sizeof(char) * (t->size.y + 1));
        for (int x = 0; x < t->size.y; x++)
            transposed[y][x] = t->shape[x][y];
        transposed[y][t->size.y] = '\0';
    }
    transposed[t->size.x] = NULL;
    int temp = t->size.x;
    t->size.x = t->size.y;
    t->size.y = temp;
    char **shape_to_free = t->shape;
    t->shape = transposed;
    for (int y = 0; y < t->size.y; y++) {
        my_revstr(t->shape[y]);
        free(shape_to_free[y]);
    }
    free(shape_to_free);
}

void file_path(char *file)
{
    struct stat sb;
    stat(file, &sb);
    char *buff = malloc(sizeof(char *) * (sb.st_size));
    int fd = open(file, O_RDONLY);
    read(fd, buff, sb.st_size);
    char **tab = my_str_to_word_array(buff);
    for (int y = 1; tab[y] != NULL; y++) {
        for (int x = 0; tab[y][x] != '\0'; x++)
            my_putchar(tab[y][x]);
        my_putchar('\n');
    }
}
