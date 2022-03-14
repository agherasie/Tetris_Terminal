/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

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

void draw_rectangle(vector2_t size, vector2_t pos, int corner_type)
{
    if (corner_type == FALSE) {
        mvprintw(pos.y, pos.x, "+");
        mvprintw(size.y + pos.y, pos.x, "+");
        mvprintw(pos.y, size.x + pos.x, "+");
        mvprintw(size.y + pos.y, size.x + pos.x, "+");
    } else {
        mvprintw(pos.y, pos.x, "/");
        mvprintw(size.y + pos.y, pos.x, "\\");
        mvprintw(pos.y, size.x + pos.x, "\\");
        mvprintw(size.y + pos.y, size.x + pos.x, "/");
    }
    for (int i = 1; i < size.y; i++) {
        mvprintw(i + pos.y, pos.x, "|");
        mvprintw(i + pos.y, size.x + pos.x, "|");
    }
    for (int i = 1; i < size.x; i++) {
        mvprintw(pos.y, i + pos.x, "-");
        mvprintw(size.y + pos.y, i + pos.x, "-");
    }
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
        int x;
        for (x = 0; data[x] != '\n'; x++)
            tetris->shape[y][x] = data[x];
        tetris->shape[y][x] = '\0';
    }
    tetris->shape[tetris->size.y] = NULL;

    return tetris;
}

void draw_tetris(vector2_t pos, tetriminos_t *tetris)
{
    for (int y = 0; tetris->shape[y]; y++)
        for (int x = 0; tetris->shape[x]; x++)
            mvprintw(y + pos.y + tetris->pos.y, x * 2 + pos.x + tetris->pos.x, &tetris->shape[y][x]);
}

int main(int ac, char **av)
{
    for (int i = 1; av[i]; i++)
        if (my_strcmp(av[i], "-h") == 0) {
            printf("%s\n", read_to_charstar("help.txt"));
            return 0;
        }
    tetriminos_t *tetris = init_tetriminos("tetriminos/bar.tetrimino");
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    game_t *game = init_params();
    game->map_size.x *= 2;
    while (1) {
        int offset = COLS / 2 - game->map_size.x;
        refresh();
        clear();
        draw_rectangle(game->map_size, (vector2_t){offset, 0}, FALSE);
        draw_rectangle((vector2_t){10, 4}, (vector2_t){offset + game->map_size.x + 2, 0}, TRUE);
        draw_rectangle((vector2_t){20, 5}, (vector2_t){offset, game->map_size.y + 2}, TRUE);
        draw_tetris((vector2_t){offset + offset / 2, 1}, tetris);
        getch();
        if (tetris->pos.y + tetris->size.y < game->map_size.y - 1)
            tetris->pos.y++;
        erase();
    }
    return 0;
}
