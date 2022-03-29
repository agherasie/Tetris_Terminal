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

void handle_d(game_t *g)
{
    my_putstr("Key left: ");
    keys(g);
    my_putstr(" (");
    my_put_nbr(g->keys->l);
    my_putstr(")\n");
    my_putstr("Key right: ");
    keys2(g);
    my_putstr(" (");
    my_put_nbr(g->keys->r);
    my_putstr(")\n");
    my_putstr("Key turn: ");
    keys3(g);
    my_putstr(" (");
    my_put_nbr(g->keys->t);
    my_putstr(")\n");
    handle_d2(g);
}

void handle_d2(game_t *g)
{
    my_putstr("Key drop: ");
    keys4(g);
    my_putstr(" (");
    my_put_nbr(g->keys->d);
    my_putstr(")\n");
    my_putstr("Key quit: ");
    my_putchar(g->keys->q);
    my_putstr(" (");
    my_put_nbr(g->keys->q);
    my_putstr(")\n");
    my_putstr("Key pause: ");
    my_putchar(g->keys->p);
    my_putstr(" (");
    my_put_nbr(g->keys->p);
    my_putstr(")\n");
    handle_d3(g);
}

void handle_d3(game_t *g)
{
    my_putstr("Next: ");
    if (g->show_next == 1)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    my_putstr("Level: ");
    my_put_nbr(g->level);
    my_putchar('\n');
    my_putstr("Size: ");
    my_put_nbr(g->map_size.y);
    my_putchar('*');
    my_put_nbr(g->map_size.x);
    my_putstr("\n\n");
    my_putstr("Number of tetriminos: 7\n");
    handle_d4(g);
}
