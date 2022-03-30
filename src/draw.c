/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw
*/

#include "../include/tetris.h"

void draw_tetris(vector2_t pos, tetriminos_t *tetris, int player)
{
    vector2_t disp_pos = {pos.x, pos.y};
    if (player == TRUE) {
        disp_pos.x += tetris->pos.x * 2;
        disp_pos.y += tetris->pos.y;
    }
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            attron(COLOR_PAIR(tetris->color));
            char color = tetris->shape[y][x];
            mvaddch(disp_pos.y + y, disp_pos.x + x * 2, color);
            attroff(COLOR_PAIR(tetris->color));
        }
}

void draw_hint(game_t *g, int offset, tetriminos_t *tetris)
{
    if (g->show_next == FALSE)
        return;
    vector2_t draw_size = {tetris->size.x + 4, tetris->size.y + 2};
    vector2_t draw_pos = {offset + g->map_size.x * 2 + 2, 0};
    draw_rectangle(draw_size, draw_pos, TRUE);
    draw_pos.x += 1;
    draw_pos.y += 1;
    draw_tetris(draw_pos, tetris, FALSE);
}

void draw_ui(game_t *g)
{
    int offset = COLS / 2 - g->map_size.x;
    refresh();
    clear();
    mvprintw(0, 0, "%i:%i", g->map_size.x, g->map_size.y);
    mvprintw(1, 0, "%i:%i", g->tetris->size.x, g->tetris->size.y);
    mvprintw(2, 0, "deleted lines: %i", g->lines);
    mvprintw(3, 0, "level %i", g->level);
    mvprintw(4, 0, "score: %i", g->score);
    vector2_t rectangle_size = {g->map_size.x * 2, g->map_size.y};
    vector2_t rectangle_pos = {offset, 0};
    draw_rectangle(rectangle_size, rectangle_pos, FALSE);
    draw_hint(g, offset, g->tetri[g->next]);
    vector2_t draw_pos2 = {offset, g->map_size.y + 2};
    draw_rectangle((vector2_t){20, 5}, draw_pos2, TRUE);
    draw_tetris((vector2_t){offset, 1}, g->tetris, TRUE);
    draw_map(g, g->map, (vector2_t){offset, 1});
}
