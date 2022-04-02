/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** input
*/

#include "../include/tetris.h"

void level_in_range(game_t *g)
{
    if (g->level < 1)
        g->level = 1;
    if (g->level > MAX_LVL)
        g->level = MAX_LVL;
}

void movement_input(game_t *g, int input)
{
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
}

int read_input(game_t *g)
{
    cbreak();
    level_in_range(g);
    timeout(40);
    int input = getch();
    movement_input(g, input);
    if (g->keys->p == input) {
        g->paused *= -1;
        g->screen = PAUSE;
    }
    if (g->keys->q == input)
        return 1;
    return 0;
}
