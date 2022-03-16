/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#ifndef TETRIS_H_
    #define TETRIS_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"

typedef struct vector2 {
    int x;
    int y;
} vector2_t;

typedef struct keys {
    int l;
    int r;
    int t;
    int d;
    int q;
    int p;
} keys_t;

typedef struct game {
    int level;
    keys_t *keys;
    vector2_t map_size;
    int show_next;
    int debug_mode;
} game_t;

char *handle_arg(char *arg);
char *handle_arg2(char *arg);
char *handle_arg3(char *arg);
void handle_h2(int ac, char **av, game_t *game, int i);
void handle_h3(int ac, char **av, game_t *game, int i);
void handle_h4(int ac, char **av, game_t *game, int i);
void handle_h(int ac, char **av, game_t *game);

#endif /* TETRIS_H_ */
