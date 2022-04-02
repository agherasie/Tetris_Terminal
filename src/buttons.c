/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** buttons
*/

#include "../include/tetris.h"

void draw_button(game_t *g, char *title, int rank)
{
    vector2_t pos = {COLS / 2, LINES / 2};
    attron(COLOR_PAIR(3));
    if (g->select == rank) {
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(4));
        mvaddch(pos.y + rank, pos.x - my_strlen(title) / 2 - 2, '>');
        mvaddch(pos.y + rank, pos.x + my_strlen(title) / 2 + 1, '<');
    }
    mvprintw(pos.y + rank, pos.x - my_strlen(title) / 2, "%s", title);
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
}

int select_button(game_t *g, int input, int button_count)
{
    if (input == KEY_UP)
        g->select--;
    if (input == KEY_DOWN)
        g->select++;
    if (g->select < 0)
        g->select = button_count - 1;
    if (g->select >= button_count)
        g->select = 0;
}

int buttons(game_t *g, int input)
{
    if (g->screen == SETTINGS) {
        settings_buttons(g, input);
        return 0;
    }
    if (g->screen == SCOREBOARD) {
        if (input == g->keys->p && g->select == 0)
            g->screen = MAIN;
        return 0;
    }
    if (g->screen == MAIN)
        if (main_buttons(g, input) == 1)
            return 1;
    if (g->screen == PAUSE)
        if (pause_buttons(g, input) == 1)
            return 1;
    return 0;
}

void set_param(game_t *g, int *param, char type, int rank)
{
    if (rank != g->select)
        return;
    if (type == 'c')
        *param = getch();
    if (type != 'b')
        return;
    if (*param == TRUE)
        *param = FALSE;
    else
        *param = TRUE;
}

void slider(game_t *g, int *param, vector2_t vars, vector2_t range)
{
    int input = vars.y;
    int rank = vars.x;
    if (rank != g->select)
        return;
    if (input == g->keys->l)
        *param -= 1;
    if (input == g->keys->r)
        *param += 1;
    if (*param < range.x)
        *param = range.x;
    if (*param > range.y)
        *param = range.y;
}
