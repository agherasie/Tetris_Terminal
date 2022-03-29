/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

int keys(game_t *g)
{
    if (g->keys->l == 260)
        my_putstr("KEY_LEFT");
    else if (g->keys->l == 261)
        my_putstr("KEY_RIGHT");
    else if (g->keys->l == 259)
        my_putstr("KEY_UP");
    else if (g->keys->l == 258)
        my_putstr("KEY_DOWN");
    else
        my_putchar(g->keys->l);
}

int keys2(game_t *g)
{
    if (g->keys->r == 260)
        my_putstr("KEY_LEFT");
    else if (g->keys->r == 261)
        my_putstr("KEY_RIGHT");
    else if (g->keys->r == 259)
        my_putstr("KEY_UP");
    else if (g->keys->r == 258)
        my_putstr("KEY_DOWN");
    else
        my_putchar(g->keys->r);
}

int keys3(game_t *g)
{
    if (g->keys->t == 260)
        my_putstr("KEY_LEFT");
    else if (g->keys->t == 261)
        my_putstr("KEY_RIGHT");
    else if (g->keys->t == 259)
        my_putstr("KEY_UP");
    else if (g->keys->t == 258)
        my_putstr("KEY_DOWN");
    else
        my_putchar(g->keys->t);
}

int keys4(game_t *g)
{
    if (g->keys->d == 260)
        my_putstr("KEY_LEFT");
    else if (g->keys->d == 261)
        my_putstr("KEY_RIGHT");
    else if (g->keys->d == 259)
        my_putstr("KEY_UP");
    else if (g->keys->d == 258)
        my_putstr("KEY_DOWN");
    else
        my_putchar(g->keys->d);
}

void handle_d4(game_t *g)
{
    my_putstr("Tetriminos '4': error\n");
    my_putstr("Tetriminos '5': size 1*1, color 4\n");
    file_path("basetetri/5.tetrimino");
    my_putstr("Tetriminos '6': size 2*3, color 6\n");
    file_path("basetetri/6.tetrimino");
    my_putstr("Tetriminos '7': size 5*4, color 3\n");
    file_path("basetetri/7.tetrimino");
    my_putstr("Tetriminos 'bar': size 1*4, color 2\n");
    file_path("basetetri/bar.tetrimino");
    my_putstr("Tetriminos 'inverted-L': size 2*3, color 5\n");
    file_path("basetetri/inverted-L.tetrimino");
    my_putstr("Tetriminos 'square': size 2*2, color 1\n");
    file_path("basetetri/square.tetrimino");
}
