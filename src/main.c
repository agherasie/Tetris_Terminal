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

game_t *init_game(int ac, char **av)
{
    srand(time(NULL));
    if (help(av) == 0)
        return NULL;
    game_t *g = init_params();
    handle_h(ac, av, g);
    if (g->debug_mode == 1) {
        handle_d(g);
        return NULL;
    }
    ncurses_init();
    g->tetri = init_tetri(g);
    refresh();
    clear();
    init_map(g);
    g->next = range(0, g->tetri_count - 1);
    swap_tetris(g);
    g->tetris->pos.x += g->map_size.x / 2 - g->tetris->size.x / 2;
    g->lines = g->level * 10;
    return g;
}

void free_all(game_t *g)
{
    for (int i = 0; g->map[i]; i++)
        free(g->map[i]);
    free(g->map);
    for (int i = 0; i < g->tetri_count - 1; i++) {
        for (int j = 0; j < g->tetri[i]->size.y; j++)
            free(g->tetri[i]->shape[j]);
        free(g->tetri[i]->shape);
        free(g->tetri[i]);
    }
    free(g->tetri);
    free(g->keys);
    free(g);
}

int main(int ac, char **av)
{
    game_t *g = init_game(ac, av);
    if (g == NULL)
        return 0;
    while (loop(g) == 0);
    refresh();
    clear();
    endwin();
    if (g->score > g->hiscore)
        set_score(&g->score);
    free_all(g);
    return 0;
}
