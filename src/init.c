/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** init
*/

#include "../include/tetris.h"

void init_map(game_t *game)
{
    game->map = malloc(sizeof(char *) * game->map_size.y);
    for (int y = 0; y < game->map_size.y; y++) {
        game->map[y] = malloc(sizeof(char) * game->map_size.y);
        for (int x = 0; x < game->map_size.x; x++)
            game->map[y][x] = 0;
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
    game_t *game = malloc(sizeof(game_t));
    game->debug_mode = FALSE;
    game->keys = init_keys();
    game->map_size = (vector2_t) {10, 20};
    game->level = 1;
    game->debug_mode = FALSE;
    game->show_next = FALSE;
    return game;
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
        int x;
        for (x = 0; data[x] != '\n'; x++)
            tetris->shape[y][x] = data[x];
        tetris->shape[y][x] = '\0';
    }
    tetris->shape[tetris->size.y] = NULL;

    return tetris;
}
