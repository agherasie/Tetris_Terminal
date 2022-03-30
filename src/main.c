/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void ncurses_init(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_colors();
}

int main(int ac, char **av)
{
    srand(time(NULL));
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "--help") == 0 || my_strcmp(av[i], "-h") == 0) {
            printf("%s\n", read_to_charstar("help.txt"));
            return 0;
        }
    game_t *g = init_params();
    handle_h(ac, av, g);
    if (g->debug_mode == 1) {
        handle_d(g);
        return 0;
    }
    ncurses_init();
    g->tetri = init_tetri();
    reset_tetris(g);
    refresh();
    clear();
    init_map(g);
    while (loop(g) == 0);
    refresh();
    clear();
    endwin();
    return 0;
}
