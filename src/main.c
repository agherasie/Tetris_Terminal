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
    /*keys->l = KEY_LEFT;
    keys->r = KEY_RIGHT;
    keys->t = KEY_UP;
    keys->d = KEY_DOWN;
    keys->q = 'q';
    keys->p = ' ';*/

    keys->l = 'q';
    keys->r = 'd';
    keys->t = 'z';
    keys->d = 's';
    keys->q = 'q';
    keys->p = ' ';
    return keys;
}

game_t *init_params()
{
    game_t *game = malloc(sizeof(game_t));
    //game->debug_mode = FALSE;
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

char *handle_arg(char *arg)
{
    char *new_arg = arg;
    for (; *new_arg != '{'; new_arg++);
    new_arg++;
    new_arg[my_strlen(new_arg)] = '\0';
    return new_arg;
}

void handle_h2(int ac, char **av, game_t *game, int i)
{
    if (av[i][0] == '-' && av[i][1] == 'L')
        game->level = my_getnbr(handle_arg(av[i + 1]));
    else if (my_strcmp(av[i], "--map-size") == 0) {
        game->map_size.y = my_getnbr(av[i + 1]);
        game->map_size.x = my_getnbr(av[i + 2]);
    }
}

void handle_h(int ac, char **av, game_t *game)
{
    int i = 1;
    for (; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l')
            game->keys->l = av[i + 1][1];
        else if(av[i][0] == '-' && av[i][1] == 'r')
            game->keys->r = av[i + 1][1];
        else if (av[i][0] == '-' && av[i][1] == 't')
            game->keys->t = av[i + 1][1];
        else if (av[i][0] == '-' && av[i][1] == 'd')
            game->keys->d = av[i + 1][1];
        else if (av[i][0] == '-' && av[i][1] == 'q')
            game->keys->q = av[i + 1][1];
        else if (av[i][0] == '-' && av[i][1] == 'p')
            game->keys->p = av[i + 1][1];
        else if (av[i][0] == '-' && av[i][1] == 'w')
            game->show_next = TRUE;
        else if (av[i][0] == '-' && av[i][1] == 'D')
            game->debug_mode = TRUE;
        handle_h2(ac, av, game, i);
    }
}

int main(int ac, char **av)
{
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
    return 0;
}
