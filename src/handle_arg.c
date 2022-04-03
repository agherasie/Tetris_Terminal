/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void single_chr(game_t *game, char **av, int i)
{
    if (av[i + 1] == NULL || (av[i + 1][0] < '0' || av[i + 1][0] > '9'))
        exit(84);
    handle_h_char('l', &game->keys->l, av[i + 1], av[i][1]);
    handle_h_char('r', &game->keys->r, av[i + 1], av[i][1]);
    handle_h_char('t', &game->keys->t, av[i + 1], av[i][1]);
    handle_h_char('d', &game->keys->d, av[i + 1], av[i][1]);
    handle_h_char('q', &game->keys->q, av[i + 1], av[i][1]);
    handle_h_char('p', &game->keys->p, av[i + 1], av[i][1]);
    handle_h_char('L', &game->level, av[i + 1], av[i][1]);
}

void without_chr(game_t *game, char **av, int i)
{
    if (av[i][1] == 'w')
        game->show_next = FALSE;
    if (av[i][1] == 'D')
        game->debug_mode = TRUE;
    else
        single_chr(game, av, i);
}

void multiple_chr(game_t *game, char **av, int i)
{
    handle_h_str(av[i], "level=", &game->level);
    handle_h_str(av[i], "key-left=", &game->keys->l);
    handle_h_str(av[i], "key-right=", &game->keys->r);
    handle_h_str(av[i], "key-turn=", &game->keys->t);
    handle_h_str(av[i], "key-drop=", &game->keys->d);
    handle_h_str(av[i], "key-quit=", &game->keys->q);
    handle_h_str(av[i], "key-pause=", &game->keys->p);
    if (my_strcmp(av[i] + 2, "without-next") == 0)
            game->show_next = FALSE;
    if (my_strcmp(av[i] + 2, "debug") == 0)
        game->debug_mode = TRUE;
    if (starts_with(av[i] + 2, "map-size=", '=') == TRUE) {
        game->map_size.x = my_getnbr(handle_arg(av[i], 0, ','));
        game->map_size.y = my_getnbr(handle_arg(av[i], 3, '='));
    }
}

void handle_h(int ac, char **av, game_t *game)
{
    int i = 1;
    for (; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] != '-')
            without_chr(game, av, i);
        if (av[i][1] == '-')
            multiple_chr(game, av, i);
    }
}
