/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** draw
*/

#include "../include/tetris.h"

void draw_rectangle(vector2_t size, vector2_t pos, int corner_type)
{
    if (corner_type == FALSE) {
        mvprintw(pos.y, pos.x, "+");
        mvprintw(size.y + pos.y, pos.x, "+");
        mvprintw(pos.y, size.x + pos.x, "+");
        mvprintw(size.y + pos.y, size.x + pos.x, "+");
    } else {
        mvprintw(pos.y, pos.x, "/");
        mvprintw(size.y + pos.y, pos.x, "\\");
        mvprintw(pos.y, size.x + pos.x, "\\");
        mvprintw(size.y + pos.y, size.x + pos.x, "/");
    }
    for (int i = 1; i < size.y; i++) {
        mvprintw(i + pos.y, pos.x, "|");
        mvprintw(i + pos.y, size.x + pos.x, "|");
    }
    for (int i = 1; i < size.x; i++) {
        mvprintw(pos.y, i + pos.x, "-");
        mvprintw(size.y + pos.y, i + pos.x, "-");
    }
}

void draw_tetris(vector2_t pos, tetriminos_t *tetris)
{
    for (int y = 0; tetris->shape[y]; y++)
        for (int x = 0; tetris->shape[x]; x++) {
            attron(COLOR_PAIR(tetris->color));
            mvprintw(y + pos.y + tetris->pos.y, x + pos.x + tetris->pos.x, &tetris->shape[y][x]);
            attroff(COLOR_PAIR(tetris->color));
        }
}

void draw_map(game_t *game, char **map, vector2_t offset)
{
    for (int y = 0; y < game->map_size.y; y++)
        for (int x = 0; x < game->map_size.x; x++)
            mvprintw(y + offset.y, x + offset.x, &map[y][x]);
}