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
    #define MAIN 0
    #define PAUSE 1
    #define SETTINGS 2
    #define SCOREBOARD 3

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
    int amount;
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
    int tetri_count;
    int rotate;
    int time;
    int next;
    int lines;
    int score;
    int hiscore;
    int reserve;
    int current;
    int get1;
    int get2;
    int get3;
    int animation;
    int paused;
    int select;
    int screen;
} game_t;

// PARAMS
char *handle_arg(char *arg, int offset, char sep);
void handle_h(int ac, char **av, game_t *game);
void handle_h_char(char key_code, int *key, char *src, char label);
void handle_h_str(char *src, char *str, int *key);
void handle_d(game_t *g);
int check_file(game_t *g);
char *before_point(char *file);
char *open_map(char *file);
int my_getnbr2(char const *str);
void continue_display(char *inside, game_t *g);
int count_file(game_t *g);

// DRAW
void draw_rectangle(vector2_t size, vector2_t pos, int corner_type);
void draw_tetris(vector2_t pos, tetriminos_t *tetris, int player);
void draw_hint(game_t *g, vector2_t offset, tetriminos_t *tetris);
void draw_ghost(game_t *g, vector2_t offset);
void draw_map(game_t *g, char **map, vector2_t offset);
void draw_ui(game_t *g);

// ANIMATION
void draw_frame(char *filepath, int number, vector2_t pos);
void draw_animation(game_t *g, vector2_t off);
void draw_buffer(char *buffer, vector2_t pos, char *sep);

// TETRI
void land_tetris(game_t *g, tetriminos_t *tetris);
void reset_tetris(game_t *g);
void swap_tetris(game_t *g);
void rotate_shape(tetriminos_t *t);

// INIT
int my_put_nbr(long nb);
void init_map(game_t *g);
void init_colors(void);
keys_t *init_keys(void);
game_t *init_params(void);
tetriminos_t **init_tetri(game_t *g);
tetriminos_t *init_tetriminos(char *filepath);
void skip_to_line(char **data);
game_t *init_game(int ac, char **av);
void ncurses_init(void);
int help(char **av);

// ERROR HANDLING
int is_valid_tetrimino(char *filepath);
int file_error_detection(char *path);
int good_file(char *buff);

// LINES
int line_full(char *line);
int line_empty(char *line);
int line_active(char *line);
void empty_line(char *line);
int full_lines(game_t *g);

// BUTTONS
void draw_button(game_t *g, char *title, int rank);
int select_button(game_t *g, int input, int button_count);
int buttons(game_t *g, int input);
void set_param(game_t *g, int *param, char type, int rank);
void slider(game_t *g, int *param, vector2_t vars, vector2_t range);
int settings_buttons(game_t *g, int input);
int main_buttons(game_t *g, int input);
int pause_buttons(game_t *g, int input);

// MENUS
int settings_menu(game_t *g);
int draw_menu(game_t *g, char **buttons);
int draw_screen(game_t *g, int *button_count);
int pause_game(game_t *g);
int scoreboard(game_t *g);

// GAME
int loop(game_t *g);
int try_move(game_t *g, vector2_t vector);
int read_input(game_t *g);
int valid_pos(game_t *g, vector2_t vector);
void movement(game_t *g);

#endif /* TETRIS_H_ */
