/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** init
*/

#include "../include/tetris.h"

game_t *init_game(int ac, char **av)
{
    srand(time(NULL));
    if (help(av) == 0)
        return NULL;
    game_t *g = init_params();
    g->map = NULL;
    g->tetri = NULL;
    handle_h(ac, av, g);
    if (g->debug_mode == 1) {
        handle_d(g);
        free_all(g);
        return NULL;
    }
    ncurses_init();
    g->tetri = init_tetri(g);
    refresh();
    clear();
    g->next = range(0, g->tetri_count - 1);
    swap_tetris(g);
    return g;
}

void init_map(game_t *g)
{
    g->map = malloc(sizeof(char *) * (g->map_size.y + 1));
    for (int y = 0; y < g->map_size.y; y++) {
        g->map[y] = malloc(sizeof(char) * (g->map_size.x + 1));
        for (int x = 0; x < g->map_size.x; x++)
            g->map[y][x] = EMPTY;
        g->map[y][g->map_size.x] = '\0';
    }
    g->map[g->map_size.y] = NULL;
}

void init_colors(void)
{
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
}

keys_t *init_keys(void)
{
    keys_t *keys = malloc(sizeof(keys_t));
    keys->l = KEY_LEFT;
    keys->r = KEY_RIGHT;
    keys->t = KEY_UP;
    keys->d = KEY_DOWN;
    keys->q = 'q';
    keys->p = ' ';
    return keys;
}

game_t *init_params(void)
{
    game_t *g = malloc(sizeof(game_t));
    g->keys = init_keys();
    g->map_size.x = 10;
    g->map_size.y = 20;
    g->level = 1;
    g->debug_mode = FALSE;
    g->show_next = TRUE;
    g->rotate = 0;
    g->time = 0;
    g->lines = 0;
    g->streak = 0;
    g->score = 0;
    g->hiscore = get_hiscore();
    g->current = 0;
    g->reserve = -1;
    g->animation = 0;
    g->paused = 1;
    g->select = 0;
    g->screen = MAIN;
    return g;
}
