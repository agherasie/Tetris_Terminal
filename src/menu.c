/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** menu
*/

#include "../include/tetris.h"

int draw_menu(game_t *g, char **buttons)
{
    char *logo = read_to_charstar("data/tetris.txt");
    attron(COLOR_PAIR(1));
    draw_buffer(logo, (vector2_t){COLS / 2 - 31, LINES / 2 - 10}, "!");
    attroff(COLOR_PAIR(1));
    free(logo);
    for (int i = 0; buttons[i]; i++)
        draw_button(g, buttons[i], i);
    return 0;
}

int main_buttons(game_t *g, int input)
{
    if (input == g->keys->p) {
        if (g->select == 0)
            g->paused = -1;
        if (g->select == 1) {
            g->screen = SETTINGS;
            g->select = 0;
        }
        if (g->select == 2) {
            g->screen = SCOREBOARD;
            g->select = 0;
        }
        if (g->select == 3)
            return 1;
    }
    return 0;
}

int pause_buttons(game_t *g, int input)
{
    if (input == g->keys->p) {
        if (g->select == 0)
            g->paused = -1;
        if (g->select == 1)
            return 1;
    }
    return 0;
}
