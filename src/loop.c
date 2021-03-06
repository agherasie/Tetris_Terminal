/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** loop
*/

#include "../include/tetris.h"

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

void gravity(game_t *g)
{
    for (int y = g->map_size.y - 1; y > 0; y--)
        if (line_active(g->map[y - 1]) == TRUE
        && line_empty(g->map[y]) == TRUE) {
            my_strcpy(g->map[y], g->map[y - 1]);
            empty_line(g->map[y - 1]);
        }
}

int resize_screen(game_t *g)
{
    if (COLS < g->map_size.x + 55 || LINES < g->map_size.y + 5) {
        printw("PLEASE RESIZE YOUR TERMINAL");
        getch();
        erase();
        return 0;
    }
    return 1;
}

int loop(game_t *g)
{
    if (resize_screen(g) == 0)
        return 0;
    if (g->paused == 1) {
        if (pause_game(g) == 1)
            return 1;
        return 0;
    }
    if (g->map == NULL) {
        init_map(g);
        g->tetris->pos.x += g->map_size.x / 2 - g->tetris->size.x / 2;
    }
    g->time++;
    draw_ui(g);
    movement(g);
    gravity(g);
    if (read_input(g) == 1)
        return 1;
    erase();
    return check_pos(g);
}
