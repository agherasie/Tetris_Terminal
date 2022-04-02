/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#ifndef TETRIS_H_
    #define TETRIS_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <curses.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include "my.h"
    #define FULL '#'
    #define EMPTY ' '

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
    int lines;
    int score;
    int hiscore;
    int get1;
    int get2;
    int get3;
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
int check_file(game_t *g);
char *before_point(char *file);
char *open_map(char *file);
int my_getnbr2(char const *str);
void continue_display(char *inside, game_t *g);
int count_file(game_t *g);

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

// LINES
int line_full(char *line);
int line_empty(char *line);
int line_active(char *line);
void empty_line(char *line);
int full_lines(game_t *g);

// GAME
int loop(game_t *g);
int try_move(game_t *g, vector2_t vector);
void read_input(game_t *g);
int valid_pos(game_t *g, vector2_t vector);
void movement(game_t *g);

#endif /* TETRIS_H_ */
