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
    #include <dirent.h>
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
    int time;
    int next;
} game_t;

// PARAMS
char *handle_arg(char *arg);
char *handle_arg2(char *arg);
char *handle_arg3(char *arg);
void handle_h2(int ac, char **av, game_t *game, int i);
void handle_h3(int ac, char **av, game_t *game, int i);
void handle_h4(int ac, char **av, game_t *game, int i);
void handle_h(int ac, char **av, game_t *game);
void handle_d(game_t *g);
void handle_d2(game_t *g);
void handle_d3(game_t *g);
void handle_d4(game_t *g);
int keys(game_t *g);
int keys2(game_t *g);
int keys3(game_t *g);
int keys4(game_t *g);
void file_path(char *file);
char *cpy_word(char *str, int i);
char **my_str_to_word_array(char *str);
int nb_words(char const *str);
int word_len(char const *str, int i);

// DRAW
void draw_rectangle(vector2_t size, vector2_t pos, int corner_type);
void draw_tetris(vector2_t pos, tetriminos_t *tetris, int player);
void draw_map(game_t *g, char **map, vector2_t offset);
void draw_ui(game_t *g);

// TETRI
void land_tetris(game_t *g, tetriminos_t *tetris);
void reset_tetris(game_t *g);
void rotate_shape(tetriminos_t *t);

// INIT
int my_put_nbr(long nb);
void init_map(game_t *g);
void init_colors(void);
keys_t *init_keys(void);
game_t *init_params(void);
tetriminos_t **init_tetri(void);
tetriminos_t *init_tetriminos(char *filepath);
void skip_to_line(char **data);

// ERROR HANDLING
int ends_with(char *str, char *ending);
int is_valid_tetrimino(char *filepath);
int file_error_detection(char *path);

// GAME
int loop(game_t *g);
int try_move(game_t *g, vector2_t vector);
void read_input(game_t *g);
int valid_pos(game_t *g, vector2_t vector);

#endif /* TETRIS_H_ */
