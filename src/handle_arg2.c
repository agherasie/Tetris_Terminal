/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void handle_h3(int ac, char **av, game_t *game, int i)
{
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 'r' && av[i][7] == 'i' && av[i][8] == 'g')
        game->keys->r = my_getnbr(handle_arg3(av[i]));
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 't' && av[i][7] == 'u' && av[i][8] == 'r')
        game->keys->t = my_getnbr(handle_arg3(av[i]));
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 'd' && av[i][7] == 'r' && av[i][8] == 'o')
        game->keys->d = my_getnbr(handle_arg3(av[i]));
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 'q' && av[i][7] == 'u' && av[i][8] == 'i')
        game->keys->q = my_getnbr(handle_arg3(av[i]));
    handle_h4(ac, av, game, i);
}

void handle_h4(int ac, char **av, game_t *game, int i)
{
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'd' &&
            av[i][3] == 'e' && av[i][4] == 'b' && av[i][5] == 'u' &&
            av[i][6] == 'g')
            game->debug_mode = TRUE;
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 'p' && av[i][7] == 'a' && av[i][8] == 'u')
        game->keys->p = my_getnbr(handle_arg3(av[i]));
}
