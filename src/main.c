/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void read_input(game_t *g, int input)
{
    tetriminos_t *t = g->tetris;
    if (g->keys->l == input && 1 < t->pos.x)
        t->pos.x--;
    if (g->keys->r == input && t->pos.x < g->map_size.x - t->size.x)
        t->pos.x++;
    if (g->keys->t == input)
        rotate_shape(t);
}

int loop(game_t *g)
{
    draw_ui(g);
    read_input(g, getch());
    if (g->rotate >= 4)
        g->rotate = 0;
    int tip = g->tetris->pos.y + g->tetris->size.y;
    if (g->map[tip][g->tetris->pos.x] != ' ' || tip >= g->map_size.y - 1) {
        land_tetris(g, g->tetris);
        reset_tetris(g);
    } else
        g->tetris->pos.y++;
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
    g->map_size.x *= 2;
    g->tetri = init_tetri();
    reset_tetris(g);
    refresh();
    clear();
    init_map(g);
    while (loop(g) == 0);
    return 0;
}
