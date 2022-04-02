/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** input
*/

#include "../include/tetris.h"

int read_input(game_t *g)
{
    cbreak();
    if (g->level > 10)
        g->level = 10;
    timeout(30);
    int input = getch();
    tetriminos_t *t = g->tetris;
    vector2_t move_left = {-1, 0};
    vector2_t move_right = {1, 0};
    vector2_t move_down = {0, 1};
    if (g->keys->l == input)
        try_move(g, move_left);
    if (g->keys->r == input)
        try_move(g, move_right);
    if (g->keys->d == input)
        try_move(g, move_down);
    if (g->keys->t == input)
        rotate_shape(t);
    if (g->keys->p == input)
        g->paused *= -1;
    if (g->keys->q == input)
        return 1;
    return 0;
}
