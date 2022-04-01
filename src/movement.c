/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** movement
*/

#include "../include/tetris.h"

int valid_pos(game_t *g, vector2_t vector)
{
    tetriminos_t *tetris = g->tetris;
    if (tetris->pos.x + vector.x < 0)
        return 0;
    if (tetris->pos.x + tetris->size.x + vector.x > g->map_size.x)
        return 0;
    if (tetris->pos.y + tetris->size.y + vector.y > g->map_size.y)
        return -1;
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            vector2_t pos;
            pos.x = x + tetris->pos.x + vector.x;
            pos.y = y + tetris->pos.y + vector.y;
            if (pos.x >= g->map_size.x || pos.y >= g->map_size.y)
                return 0;
            char *map_pos = &g->map[pos.y][pos.x];
            if (*map_pos != EMPTY && tetris->shape[y][x] != EMPTY)
                return -1;
        }
    return TRUE;
}

void apply_vector(game_t *g, vector2_t vector)
{
    if (valid_pos(g, vector) == TRUE) {
        g->tetris->pos.x += vector.x;
        g->tetris->pos.y += vector.y;
    }
}

int try_move(game_t *g, vector2_t vector)
{
    int is_valid = valid_pos(g, vector);
    if (is_valid == TRUE)
        apply_vector(g, vector);
    return is_valid;
}

void reserve_shape(game_t *g)
{
    if (g->reserve != -1)
        g->next = g->reserve;
    g->reserve = g->current;
    reset_tetris(g);
}

void read_input(game_t *g)
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
    if (input == 'r' && g->show_next == TRUE)
        reserve_shape(g);
}

void movement(game_t *g)
{
    if (g->rotate >= 4)
        g->rotate = 0;
    if (g->time % (11 - g->level) == 0) {
        if (try_move(g, (vector2_t){0, 1}) == -1)
            land_tetris(g, g->tetris);
    }
}
