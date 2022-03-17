/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

int valid_pos(game_t *g, int plus)
{
    tetriminos_t *tetris = g->tetris;
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            char *map_pos = &g->map[y + tetris->pos.y][x + tetris->pos.x];
            if (*map_pos != ' ' && tetris->shape[y][x] != ' ')
                return FALSE;
        }
    return TRUE;
}

void read_input(game_t *g, int input)
{
    tetriminos_t *t = g->tetris;
    if (g->keys->l == input && 1 < t->pos.x && valid_pos(g, 0) == TRUE)
        t->pos.x--;
    if (g->keys->r == input && t->pos.x < g->map_size.x - t->size.x && valid_pos(g, 0) == TRUE)
        t->pos.x++;
    if (g->keys->t == input)
        rotate_shape(t);
}

int loop(game_t *g)
{
    draw_ui(g);
    if (g->rotate >= 4)
        g->rotate = 0;
    int tip = g->tetris->pos.y + g->tetris->size.y;
    if (tip >= g->map_size.y - 1) {
        land_tetris(g, g->tetris);
        reset_tetris(g);
    } else if (valid_pos(g, 1) == TRUE)
        g->tetris->pos.y++;
    read_input(g, getch());
    erase();
    return 0;
}

int main(int ac, char **av)
{
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "-h") == 0) {
            printf("%s\n", read_to_charstar("help.txt"));
            return 0;
        }
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_colors();
    game_t *g = init_params();
    g->tetri = init_tetri();
    reset_tetris(g);
    refresh();
    clear();
    init_map(g);
    while (loop(g) == 0);
    return 0;
}
