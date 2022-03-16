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

typedef struct tetriminos {
    char **shape;
    int color;
    int landed;
    vector2_t pos;
    vector2_t size;
} tetriminos_t;

typedef struct g {
    int level;
    keys_t *keys;
    vector2_t map_size;
    int show_next;
    int debug_mode;
    char **map;
    tetriminos_t **tetri;
    tetriminos_t *tetris;
    int rotate;
} game_t;

// DRAW
void draw_rectangle(vector2_t size, vector2_t pos, int corner_type);
void draw_tetris(vector2_t pos, tetriminos_t *tetris);
void draw_map(game_t *g, char **map, vector2_t offset);

// TETRI
void land_tetris(game_t *g, tetriminos_t *tetris);
void reset_tetris(game_t *g);

// INIT
void init_map(game_t *g);
void init_colors();
keys_t *init_keys();
game_t *init_params();
tetriminos_t **init_tetri();
tetriminos_t *init_tetriminos(char *filepath);
void skip_to_line(char **data);

// GAME
int loop(game_t *g);

#endif /* TETRIS_H_ */
