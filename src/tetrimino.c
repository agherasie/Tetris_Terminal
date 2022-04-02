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
    tetris->amount += 1;
}

void swap_tetris(game_t *g)
{
    g->current = g->next;
    g->tetris = g->tetri[g->current];
    g->next = range(0, g->tetri_count - 1);
}

void reset_tetris(game_t *g)
{
    swap_tetris(g);
    g->animation = 0;
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
    for (int y = 0; y < t->size.y; y++)
        free(t->shape[y]);
    free(t->shape);
    int temp = t->size.x;
    t->size.x = t->size.y;
    t->size.y = temp;
    t->shape = transposed;
    for (int y = 0; y < t->size.y; y++)
        my_revstr(t->shape[y]);
}
