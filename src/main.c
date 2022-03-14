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

void handle_h(int ac, char **av, game_t *game)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l')
            game->keys->l = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 'r')
            game->keys->r = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 't')
            game->keys->t = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 'd')
            game->keys->d = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 'q')
            game->keys->q = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 'p')
            game->keys->p = my_getnbr(av[i + 1]);
        else if (av[i][0] == '-' && av[i][1] == 'w')
            game->show_next = TRUE;
        else if (av[i][0] == '-' && av[i][1] == 'D')
            game->debug_mode = TRUE;
    }
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
    return 0;
}
