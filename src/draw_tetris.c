/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw_tetris
*/

#include "../include/tetris.h"

void draw_tetris(vector2_t pos, tetriminos_t *tetris, int state)
{
    char **shape_to_draw = state != 1 ? tetris->shape : tetris->initial_shape;
    vector2_t disp_pos = {pos.x, pos.y};
    if (state != 1) {
        disp_pos.x += tetris->pos.x * 2;
        disp_pos.y += tetris->pos.y;
    }
    for (int y = 0; shape_to_draw[y]; y++)
        for (int x = 0; shape_to_draw[y][x] != '\0'; x++) {
            char color = state != 2 ? tetris->color : 0;
            attron(COLOR_PAIR(color));
            char c = shape_to_draw[y][x];
            mvaddch(disp_pos.y + y, disp_pos.x + x * 2, c);
            attroff(COLOR_PAIR(color));
        }
}

void draw_hint(game_t *g, vector2_t offset, tetriminos_t *tetris)
{
    if (g->show_next == FALSE)
        return;
    vector2_t draw_size = {0, 0};
    for (; tetris->initial_shape[draw_size.y]; draw_size.y++) {
        int x = 0;
        for (; tetris->initial_shape[draw_size.y][x] != '\0'; x++);
        if (x > draw_size.x)
            draw_size.x = x;
    }
    draw_size.y += 1;
    draw_size.x *= 2;
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
