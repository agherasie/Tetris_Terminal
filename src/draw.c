/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw
*/

#include "../include/tetris.h"

void draw_statistics(game_t *g, vector2_t off)
{
    mvprintw(off.y, off.x - 20, "STATISTICS");
    int y_offset = 2 + off.y;
    for (int i = 0; i < g->tetri_count; i++) {
        vector2_t pos = {off.x - 20, y_offset + i};
        draw_tetris(pos, g->tetri[i], 1);
        mvprintw(y_offset + i, off.x - 10, "%.3i", g->tetri[i]->amount);
        y_offset += g->tetri[i]->size.y;
    }
}

void draw_stats(game_t *g, vector2_t off)
{
    int xoffset = off.x + g->map_size.x / 2 + 2;
    mvprintw(off.y - 2, xoffset, "LINES %i", g->lines - 10);
    xoffset = off.x + g->map_size.x * 2 + 4;
    mvprintw(off.y + 2, xoffset, "TOP");
    mvprintw(off.y + 3, xoffset, "%.7i", g->hiscore);
    mvprintw(off.y + 4, xoffset, "SCORE");
    mvprintw(off.y + 5, xoffset, "%.7i", g->score);
    draw_hint(g, off, g->tetri[g->next]);
    mvprintw(off.y + 16, xoffset, "LEVEL");
    mvprintw(off.y + 17, xoffset, "% 5i", g->level);
    draw_statistics(g, off);
}

void draw_ui(game_t *g)
{
    erase();
    refresh();
    vector2_t size = {g->map_size.x * 2, g->map_size.y + 1};
    vector2_t off;
    off.x = COLS / 2 - g->map_size.x / 2;
    off.y = LINES / 2 - g->map_size.y / 2;
    draw_rectangle(size, off, FALSE);
    off.y += 1;
    off.x += 1;
    draw_ghost(g, off);
    draw_tetris(off, g->tetris, 0);
    draw_map(g, g->map, off);
    draw_stats(g, off);
    draw_animation(g, off);
}
