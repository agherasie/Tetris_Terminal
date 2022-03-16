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

void init_colors()
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

keys_t *init_keys()
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

game_t *init_params()
{
    game_t *g = malloc(sizeof(game_t));
    g->debug_mode = FALSE;
    g->keys = init_keys();
    g->map_size = (vector2_t) {10, 20};
    g->level = 1;
    g->debug_mode = FALSE;
    g->show_next = FALSE;
    g->rotate = 0;
    return g;
}

void skip_to_line(char **data)
{
    for (; **data != '\n'; *data += 1)
        if (**data == '\0')
            return;
    *data += 1;
}

tetriminos_t *init_tetriminos(char *filepath)
{
    tetriminos_t *tetris = malloc(sizeof(tetris));
    char *data = read_to_charstar(filepath);
    tetris->size = (vector2_t){data[0] - '0', data[2] - '0'};
    tetris->color = data[4] - '0';
    tetris->landed = FALSE;
    tetris->shape = malloc(sizeof(char *) * (tetris->size.y + 1));
    for (int y = 0; y < tetris->size.y; y++) {
        skip_to_line(&data);
        tetris->shape[y] = malloc(sizeof(char) * (tetris->size.x + 1));
        int x = 0;
        for (; data[x] != '\n'; x++)
            tetris->shape[y][x] = data[x];
        for (; x < tetris->size.x; x++)
            tetris->shape[y][x] = ' ';
        tetris->shape[y][tetris->size.x] = '\0';
    }
    tetris->shape[tetris->size.y] = NULL;

    return tetris;
}

tetriminos_t **init_tetri()
{
    tetriminos_t **tetri = malloc(sizeof(tetriminos_t *) * 7);
    for (int i = 0; i < 7; i++)
        tetri[i] = init_tetriminos(my_strcat(my_strcat("tetriminos/", my_itoa(i)), ".tetrimino"));
    return tetri;
}
