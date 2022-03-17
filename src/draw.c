/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw
*/

#include "../include/tetris.h"

void draw_tetris(vector2_t pos, tetriminos_t *tetris)
{
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            attron(COLOR_PAIR(tetris->color));
            char color = tetris->shape[y][x];
            pos.x += x + tetris->pos.x * 2;
            pos.y += y + tetris->pos.y;
            mvaddch(pos.y, pos.x + x, color);
            pos.x -= x + tetris->pos.x * 2;
            pos.y -= y + tetris->pos.y;
            attroff(COLOR_PAIR(tetris->color));
        }
}

void draw_ui(game_t *g)
{
    int offset = COLS / 2 - g->map_size.x;
    refresh();
    clear();
    mvprintw(0, 0, "%i:%i", g->map_size.x, g->map_size.y);
    draw_rectangle((vector2_t){g->map_size.x * 2, g->map_size.y}, (vector2_t){offset, 0}, FALSE);
    vector2_t draw_pos = {offset + g->map_size.x * 2 + 2, 0};
    vector2_t draw_pos2 = {offset, g->map_size.y + 2};
    draw_rectangle((vector2_t){10, 4}, draw_pos, TRUE);
    draw_rectangle((vector2_t){20, 5}, draw_pos2, TRUE);
    draw_tetris((vector2_t){offset, 1}, g->tetris);
    draw_map(g, g->map, (vector2_t){offset, 1});
}
