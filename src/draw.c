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
            char color = tetris->color;
            if (state == 2)
                color = COLOR_WHITE;
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
    vector2_t draw_pos = {offset.x + g->map_size.x * 2 + 5, offset.y};
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

void draw_status(game_t *g, vector2_t off)
{
    off.x -= 25;
    draw_rectangle((vector2_t){20, 10}, off, TRUE);
    mvprintw(off.y + 2, off.x + 1, "map size %i:%i", g->map_size.x, g->map_size.y);
    mvprintw(off.y + 3, off.x + 1, "tetrimino size %i:%i", g->tetris->size.x, g->tetris->size.y);
    mvprintw(off.y + 5, off.x + 1, "level %i", g->level);
    mvprintw(off.y + 6, off.x + 1, "score %i", g->score);
    mvprintw(off.y + 7, off.x + 1, "hiscore %i", g->hiscore);
    mvprintw(off.y + 8, off.x + 1, "time %i", g->time / 30);
}

void draw_ui(game_t *g)
{
    refresh();
    clear();
    vector2_t rectangle_size = {g->map_size.x * 2, g->map_size.y};
    vector2_t rectangle_pos = {COLS / 2 - g->map_size.x / 2, LINES / 2 - g->map_size.y / 2};
    draw_rectangle(rectangle_size, rectangle_pos, FALSE);
    rectangle_pos.y += 1;
    draw_hint(g, rectangle_pos, g->tetri[g->next]);
    draw_status(g, rectangle_pos);
    draw_ghost(g, rectangle_pos);
    draw_tetris(rectangle_pos, g->tetris, 0);
    draw_map(g, g->map, rectangle_pos);
}
