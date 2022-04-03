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

int help(char **av)
{
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "--help") == 0 || my_strcmp(av[i], "-h") == 0) {
            printf("Usage: %s [options]\n", av[0]);
            printf("%s\n", read_to_charstar("help.txt"));
            return 0;
        }
    return 1;
}

int emergency_exit(game_t *g, int exitcode)
{
    refresh();
    clear();
    endwin();
    if (g->score > g->hiscore)
        set_score(&g->score);
    free_all(g);
    exit(exitcode);
}

int main(int ac, char **av)
{
    DIR *dir = opendir("tetriminos/");
    if (dir == NULL)
        return 84;
    closedir(dir);
    game_t *g = init_game(ac, av);
    if (g == NULL)
        return 0;
    while (loop(g) == 0);
    emergency_exit(g, 0);
}
