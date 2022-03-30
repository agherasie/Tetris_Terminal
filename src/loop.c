/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** loop
*/

#include "../include/tetris.h"

int line_full(char *line, int y)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ' ')
            count++;
    if (count == 1)
        return TRUE;
    return FALSE;
}

void empty_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        line[i] = ' ';
}

void full_lines(game_t *g)
{
    for (int y = 0; g->map[y]; y++) {
        if (line_full(g->map[y], y) == TRUE)
            empty_line(g->map[y]);
    }
}

int check_pos(game_t *g)
{
    int check = valid_pos(g, (vector2_t){0, 0});
    for (int i = 0; i < 4; i++) {
        check = valid_pos(g, (vector2_t){0, 0});
        if (check != TRUE)
            rotate_shape(g->tetris);
    }
    if (check != TRUE)
        return 1;
    return 0;
}

int loop(game_t *g)
{
    g->time++;
    draw_ui(g);
    if (g->rotate >= 4)
        g->rotate = 0;
    if (g->time % 10 == 0) {
        if (try_move(g, (vector2_t){0, 1}) == -1)
            land_tetris(g, g->tetris);
    }
    full_lines(g);
    read_input(g);
    erase();
    return check_pos(g);
}
