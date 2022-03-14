/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void skip_to_line(char **data)
{
    for (; **data != '\n'; *data += 1)
        if (**data == '\0')
            return;
    *data += 1;
}

int loop(game_t *game, tetriminos_t *tetris, tetriminos_t **tetri)
{
    int offset = COLS / 2 - game->map_size.x;
    refresh();
    clear();
    draw_rectangle(game->map_size, (vector2_t){offset, 0}, FALSE);
    draw_rectangle((vector2_t){10, 4}, (vector2_t){offset + game->map_size.x + 2, 0}, TRUE);
    draw_rectangle((vector2_t){20, 5}, (vector2_t){offset, game->map_size.y + 2}, TRUE);
    draw_tetris((vector2_t){offset + offset / 2, 1}, tetris);
    draw_map(game, game->map, (vector2_t){offset + offset / 2, 1});
    getch();
    if (tetris->pos.y + tetris->size.y < game->map_size.y - 1)
        tetris->pos.y++;
    else {
        land_tetris(game, tetris);
        tetris = reset_tetris(tetri);
    }
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
    tetriminos_t **tetri = init_tetri();
    tetriminos_t *tetris = reset_tetris(tetri);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_colors();
    game_t *game = init_params();
    game->map_size.x *= 2;
    init_map(game);
    while (loop(game, tetris, tetri) == 0);
    return 0;
}
