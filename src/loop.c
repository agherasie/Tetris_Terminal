/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** loop
*/

#include "../include/tetris.h"

int loop(game_t *g)
{
    g->time++;
    draw_ui(g);
    if (g->rotate >= 4)
        g->rotate = 0;
    if (g->time % 10 == 0)
        if (try_move(g, (vector2_t){0, 1}) == -1)
            land_tetris(g, g->tetris);
    read_input(g);
    erase();
    return 0;
}
