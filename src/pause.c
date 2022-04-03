/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** pause
*/

#include "../include/tetris.h"

int draw_screen(game_t *g, int *button_count)
{
    char *buttons1[] = {"START GAME", "SETTINGS", "SCOREBOARD", "EXIT", NULL};
    char *buttons2[] = {"RESUME GAME", "EXIT", NULL};
    if (g->screen == MAIN) {
        *button_count = 4;
        return draw_menu(g, buttons1);
    }
    if (g->screen == PAUSE) {
        *button_count = 2;
        return draw_menu(g, buttons2);
    }
    if (g->screen == SETTINGS) {
        *button_count = 10;
        settings_menu(g);
    }
    if (g->screen == SCOREBOARD) {
        *button_count = 2;
        scoreboard(g);
    }
    return 0;
}

int pause_game(game_t *g)
{
    int button_count;
    refresh();
    clear();
    if (draw_screen(g, &button_count) == 1)
        return 1;
    int input = getch();
    select_button(g, input, button_count);
    return buttons(g, input);
}
