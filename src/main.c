/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

int valid_pos(game_t *g, vector2_t vector)
{
    tetriminos_t *tetris = g->tetris;
    if (tetris->pos.x + vector.x <= 0)
        return 0;
    if (tetris->pos.x + tetris->size.x + vector.x > g->map_size.x)
        return 0;
    if (tetris->pos.y + tetris->size.y + vector.y > g->map_size.y - 1)
        return -1;
    for (int y = 0; y < tetris->size.y; y++)
        for (int x = 0; x < tetris->size.x; x++) {
            char *map_pos = &g->map[y + tetris->pos.y + vector.y][x + tetris->pos.x + vector.x];
            if (*map_pos != ' ' && tetris->shape[y][x] != ' ')
                return -1;
        }
    return TRUE;
}

void apply_vector(game_t *g, vector2_t vector)
{
    game_t *game = malloc(sizeof(game_t));
    game->keys = init_keys();
    game->map_size = (vector2_t) {10, 20};
    game->level = 1;
    game->debug_mode = FALSE;
    game->show_next = FALSE;
    return game;
    if (valid_pos(g, vector) == TRUE) {
        g->tetris->pos.x += vector.x;
        g->tetris->pos.y += vector.y;
    }
}

int try_move(game_t *g, vector2_t vector)
{
    int is_valid = valid_pos(g, vector);
    if (is_valid == TRUE)
        apply_vector(g, vector);
    return is_valid;
}

void read_input(game_t *g)
{
    cbreak();
    timeout(50 - g->level);
    int input = getch();
    tetriminos_t *t = g->tetris;
    vector2_t move_left = {-1, 0};
    vector2_t move_right = {1, 0};
    vector2_t move_down = {0, 1};
    if (g->keys->l == input)
        try_move(g, move_left);
    if (g->keys->r == input)
        try_move(g, move_right);
    if (g->keys->d == input)
        try_move(g, move_down);
    if (g->keys->t == input)
        rotate_shape(t);
}

int loop(game_t *g)
{
    g->time++;
    draw_ui(g);
    if (g->rotate >= 4)
        g->rotate = 0;
    if (g->time % 10 == 0)
        if (try_move(g, (vector2_t){0, 1}) == -1)
            land_tetris(g, g->tetris);
    read_input(g);
    erase();
    return 0;
}

int main(int ac, char **av)
{
    srand(time(NULL));
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "--help") == 0) {
            printf("%s\n", read_to_charstar("help.txt"));
            return 0;
        }
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    game_t *game = init_params();
    handle_h(ac, av, game);

    while (1) {
        game->map_size.x *= 2;
        int offset = COLS / 2 - game->map_size.x;
        refresh();
        clear();
        draw_rectangle(game->map_size, (vector2_t){offset, 0}, FALSE);
        draw_rectangle((vector2_t){10, 4}, (vector2_t){offset + game->map_size.x + 2, 0}, TRUE);
        draw_rectangle((vector2_t){20, 5}, (vector2_t){offset, game->map_size.y + 2}, TRUE);
        getch();
        erase();
    }
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
