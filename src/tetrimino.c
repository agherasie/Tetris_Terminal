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
        for (int x = 0; x < tetris->size.x; x++)
            if (tetris->shape[y][x] == '*')
                g->map[y + tetris->pos.y][x + tetris->pos.x] = tetris->color;
}

void reset_tetris(game_t *g)
{
    g->tetris = g->tetri[range(0, 6)];
    g->tetris->pos.x = g->map_size.x / 2;
    g->tetris->pos.y = 0;
}
