/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void draw_ui(game_t *g)
{
    int offset = COLS / 2 - g->map_size.x;
    refresh();
    clear();
    draw_rectangle(g->map_size, (vector2_t){offset, 0}, FALSE);
    draw_rectangle((vector2_t){10, 4}, (vector2_t){offset + g->map_size.x + 2, 0}, TRUE);
    draw_rectangle((vector2_t){20, 5}, (vector2_t){offset, g->map_size.y + 2}, TRUE);
    draw_tetris((vector2_t){offset, 1}, g->tetris);
    draw_map(g, g->map, (vector2_t){offset, 1});
}

void read_input(game_t *g, int input)
{
    if (g->keys->l == input && 1 < g->tetris->pos.x)
        g->tetris->pos.x--;
    if (g->keys->r == input && g->tetris->pos.x < g->map_size.x - g->tetris->size.x)
        g->tetris->pos.x++;
    if (g->keys->t == input)
        g->rotate++;
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
    init_map(g);
    while (loop(g) == 0);
    return 0;
}
