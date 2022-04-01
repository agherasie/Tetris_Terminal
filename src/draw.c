/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw
*/

#include "../include/tetris.h"

void draw_tetris(vector2_t pos, tetriminos_t *tetris, int state)
{
    vector2_t disp_pos = {pos.x, pos.y};
    if (state != 1) {
        disp_pos.x += tetris->pos.x * 2;
        disp_pos.y += tetris->pos.y;
    }
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            char color = state != 2 ? tetris->color : 0;
            attron(COLOR_PAIR(color));
            char c = tetris->shape[y][x];
            mvaddch(disp_pos.y + y, disp_pos.x + x * 2, c);
            attroff(COLOR_PAIR(color));
        }
}

void draw_hint(game_t *g, vector2_t offset, tetriminos_t *tetris)
{
    if (g->show_next == FALSE)
        return;
    vector2_t draw_size = {tetris->size.x + 4, tetris->size.y + 2};
    offset.y += 8;
    offset.x += g->map_size.x * 2 + 4;
    mvprintw(offset.y - 1, offset.x, "NEXT");
    vector2_t draw_pos = {offset.x, offset.y};
    draw_rectangle(draw_size, draw_pos, TRUE);
    draw_pos.x += 1;
    draw_pos.y += 1;
    draw_tetris(draw_pos, tetris, 1);
}

void draw_ghost(game_t *g, vector2_t offset)
{
    if (g->time % 20 > 10)
        return;
    int i = 0;
    while (valid_pos(g, (vector2_t){0, i}) == TRUE)
        i++;
    draw_tetris((vector2_t){offset.x, i + offset.y - 1}, g->tetris, 2);
}

void draw_ui(game_t *g)
{
    refresh();
    clear();
    vector2_t size = {g->map_size.x * 2, g->map_size.y};
    vector2_t off;
    off.x = COLS / 2 - g->map_size.x / 2;
    off.y = LINES / 2 - g->map_size.y / 2;
    draw_rectangle(size, off, FALSE);
    off.y += 1;
    draw_ghost(g, off);
    draw_tetris(off, g->tetris, 0);
    draw_map(g, g->map, off);
    mvprintw(off.y - 2, off.x + g->map_size.x / 2 + 2, "LINES %i", g->lines - 10);
    mvprintw(off.y + 2, off.x + g->map_size.x * 2 + 4, "TOP");
    mvprintw(off.y + 3, off.x + g->map_size.x * 2 + 4, "%.7i", g->hiscore);
    mvprintw(off.y + 4, off.x + g->map_size.x * 2 + 4, "SCORE");
    mvprintw(off.y + 5, off.x + g->map_size.x * 2 + 4, "%.7i", g->score);
    draw_hint(g, off, g->tetri[g->next]);
    mvprintw(off.y + 16, off.x + g->map_size.x * 2 + 4, "LEVEL");
    mvprintw(off.y + 17, off.x + g->map_size.x * 2 + 4, "% 5i", g->level);
    mvprintw(off.y, 3, "STATISTICS");
    int y_offset = 2;
    for (int i = 0; i < 6; i++) {
        draw_tetris((vector2_t){0, y_offset + i + off.y}, g->tetri[i], 1);
        mvprintw(y_offset + i + off.y, 5, "%.3i", g->tetri[i]->amount);
        y_offset += g->tetri[i]->size.y;
    }
}
