/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetrimino
*/

#include "../include/tetris.h"

void land_tetris(game_t *game, tetriminos_t *tetris)
{
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++)
            if (tetris->shape[y][x] == '*')
                game->map[y + tetris->pos.y][x + tetris->pos.x] = '*';
}

tetriminos_t *reset_tetris(tetriminos_t **tetri)
{
    tetriminos_t *tetris = tetri[range(0, 6)];
    tetris->pos.x = 0;
    tetris->pos.y = 0;
    return tetris;
}

tetriminos_t **init_tetri()
{
    tetriminos_t **tetri = malloc(sizeof(tetriminos_t *) * 7);
    for (int i = 0; i < 7; i++)
        tetri[i] = init_tetriminos(my_strcat(my_strcat("tetriminos/", my_itoa(i)), ".tetrimino"));
    return tetri;
}
