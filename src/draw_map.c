/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw_map
*/

#include "../include/tetris.h"

void draw_map_tile(int y, int x, vector2_t offset, game_t *g)
{
    attron(COLOR_PAIR(g->map[y][x]));
    if (g->map[y][x] != EMPTY)
        mvaddch(y + offset.y, x + x + offset.x, FULL);
    attroff(COLOR_PAIR(g->map[y][x]));
}

void draw_map(game_t *g, char **map, vector2_t offset)
{
    for (int y = 0; y < g->map_size.y; y++)
        for (int x = 0; x < g->map_size.x; x++)
            draw_map_tile(y, x, offset, g);
}
