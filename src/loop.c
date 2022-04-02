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

void set_stats(game_t *g)
{
    int lines = full_lines(g);
    g->score += lines * 100 * g->level;
    if (lines >= 4) {
        g->animation = 1;
        g->score += lines * 100 * g->level;
    }
    g->lines += lines;
    g->level = g->lines / 10;
}

void pause_game(game_t *g)
{
    refresh();
    clear();
    char *logo = read_to_charstar("data/tetris.txt");
    draw_buffer(logo, (vector2_t){5, LINES / 2 - 10}, "!");
    free(logo);
    const char *key = keyname(g->keys->p);
    mvprintw(LINES / 2, COLS / 2 - 10, "PRESS '%s' to PLAY\n", key);
    if (getch() == g->keys->p)
        g->paused = -1;
}

int loop(game_t *g)
{
    if (g->paused == 1) {
        pause_game(g);
        return 0;
    }
    if (resize_screen(g) == 0)
        return 0;
    g->time++;
    draw_ui(g);
    movement(g);
    set_stats(g);
    gravity(g);
    if (read_input(g) == 1)
        return 1;
    erase();
    return check_pos(g);
}
