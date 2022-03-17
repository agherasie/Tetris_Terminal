/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** init
*/

#include "../include/tetris.h"

void init_map(game_t *g)
{
    g->map = malloc(sizeof(char *) * g->map_size.y);
    for (int y = 0; y < g->map_size.y; y++) {
        g->map[y] = malloc(sizeof(char) * g->map_size.y);
        for (int x = 0; x < g->map_size.x; x++)
            g->map[y][x] = ' ';
    }
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
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
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
    g->debug_mode = FALSE;
    g->keys = init_keys();
    g->map_size = (vector2_t){10, 20};
    g->level = 1;
    g->debug_mode = FALSE;
    g->show_next = FALSE;
    g->rotate = 0;
    g->time = 0;
    g->next = range(0, 6);
    return g;
}
