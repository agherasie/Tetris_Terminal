/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main.c
*/

#include "../include/tetris.h"

void handle_d(game_t *g)
{
    my_putstr("Key left: ");
    my_putstr(keyname(g->keys->l));
    my_putstr(" (");
    my_put_nbr(g->keys->l);
    my_putstr(")\n");
    my_putstr("Key right: ");
    my_putstr(keyname(g->keys->r));
    my_putstr(" (");
    my_put_nbr(g->keys->r);
    my_putstr(")\n");
    my_putstr("Key turn: ");
    my_putstr(keyname(g->keys->t));
    my_putstr(" (");
    my_put_nbr(g->keys->t);
    my_putstr(")\n");
    handle_d2(g);
}

void handle_d2(game_t *g)
{
    my_putstr("Key drop: ");
    my_putstr(keyname(g->keys->d));
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
    handle_d4(g);
}
