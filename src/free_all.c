/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** free_all
*/

#include "../include/tetris.h"

void free_tetri(game_t *g)
{
    if (g->tetri == NULL)
        return;
    for (int i = 0; i < g->tetri_count - 1; i++) {
        for (int j = 0; j < g->tetri[i]->size.y; j++)
            free(g->tetri[i]->shape[j]);
        free(g->tetri[i]->shape);
        free(g->tetri[i]->initial_shape);
        free(g->tetri[i]);
    }
    free(g->tetri);
}

void free_all(game_t *g)
{
    if (g->map != NULL) {
        for (int i = 0; g->map[i]; i++)
            free(g->map[i]);
        free(g->map);
    }
    free_tetri(g);
    free(g->keys);
    free(g);
}
