/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

char *handle_arg(char *arg)
{
    char *new_arg = arg;
    for (; *new_arg != ','; new_arg++);
    new_arg++;
    new_arg[my_strlen(new_arg)] = '\0';
    return new_arg;
}

char *handle_arg2(char *arg)
{
    char *new_arg = arg;
    for (; *new_arg != '='; new_arg++);
    new_arg++;
    new_arg[my_strlen(new_arg) - 3] = '\0';
    return new_arg;
}

char *handle_arg3(char *arg)
{
    char *new_arg = arg;
    for (; *new_arg != '='; new_arg++);
    new_arg++;
    new_arg[my_strlen(new_arg)] = '\0';
    return new_arg;
}

void handle_h2(int ac, char **av, game_t *game, int i)
{
    if (av[i][0] == '-' && av[i][1] == 'L')
        game->level = my_getnbr(av[i + 1]);
    if (av[i][0] == '-' && av[i][2] == 'm') {
        game->map_size.x = my_getnbr(handle_arg(av[i]));
        game->map_size.y = my_getnbr(handle_arg2(av[i]));
    }
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'l' &&
            av[i][3] == 'e' && av[i][4] == 'v' && av[i][5] == 'e' &&
            av[i][6] == 'l' && av[i][7] == '=')
        game->level = my_getnbr(handle_arg3(av[i]));
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'w' &&
            av[i][3] == 'i' && av[i][4] == 't' && av[i][5] == 'h' &&
            av[i][6] == 'o' && av[i][7] == 'u' && av[i][8] == 't')
            game->show_next = TRUE;
    if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == 'k' &&
            av[i][3] == 'e' && av[i][4] == 'y' && av[i][5] == '-' &&
            av[i][6] == 'l' && av[i][7] == 'e' && av[i][8] == 'f')
        game->keys->l = my_getnbr(handle_arg3(av[i]));
    handle_h3(ac, av, game, i);
}

void handle_h(int ac, char **av, game_t *game)
{
    int i = 1;
    for (; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'l')
            game->keys->l = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'r')
            game->keys->r = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 't')
            game->keys->t = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'd')
            game->keys->d = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'q')
            game->keys->q = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'p')
            game->keys->p = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'w')
            game->show_next = TRUE;
        if (av[i][0] == '-' && av[i][1] == 'D')
            game->debug_mode = TRUE;
        handle_h2(ac, av, game, i);
    }
}
