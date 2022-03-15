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
    char l;
    char r;
    char t;
    char d;
    char q;
    char p;
} keys_t;

typedef struct game {
    int level;
    keys_t *keys;
    vector2_t map_size;
    int show_next;
    int debug_mode;
} game_t;

#endif /* TETRIS_H_ */
