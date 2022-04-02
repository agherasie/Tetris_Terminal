/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** loop
*/

#include "../include/tetris.h"

int check_pos(game_t *g)
{
    int check = valid_pos(g, (vector2_t){0, 0});
    for (int i = 0; i < 4; i++) {
        check = valid_pos(g, (vector2_t){0, 0});
        if (check != TRUE)
            rotate_shape(g->tetris);
    }
    if (check != TRUE)
        return 1;
    return 0;
}

void gravity(game_t *g)
{
    for (int y = g->map_size.y - 1; y > 0; y--)
        if (line_active(g->map[y - 1]) == TRUE
        && line_empty(g->map[y]) == TRUE) {
            my_strcpy(g->map[y], g->map[y - 1]);
            empty_line(g->map[y - 1]);
        }
}

int resize_screen(game_t *g)
{
    if (COLS < g->map_size.x + 55 || LINES < g->map_size.y + 5) {
        printw("PLEASE RESIZE YOUR TERMINAL");
        getch();
        erase();
        return 0;
    }
    return 1;
}

void set_stats(game_t *g)
{
    int lines = full_lines(g);
    g->score += lines * 100 * g->level;
    if (lines >= 4) {
        g->animation = 1;
        g->score += lines * 100 * g->level;
    }
    g->lines += lines;
    if (g->lines >= g->level * 10 && g->lines - lines < g->level * 10)
        g->level++;
}

void draw_button(game_t *g, char *title, int rank)
{
    vector2_t pos = {COLS / 2, LINES / 2};
    attron(COLOR_PAIR(3));
    if (g->select == rank) {
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(4));
        mvaddch(pos.y + rank, pos.x - my_strlen(title) / 2 - 2, '>');
        mvaddch(pos.y + rank, pos.x + my_strlen(title) / 2 + 1, '<');
    }
    mvprintw(pos.y + rank, pos.x - my_strlen(title) / 2, "%s", title);
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
}

char *key_button_title(game_t *g, char *title, int key)
{
    char *key_name = malloc(sizeof(char) * my_strlen(keyname(key)));
    my_strcpy(key_name, keyname(key));
    char *button_title = my_strcat(title, key_name);
    free(key_name);
    return button_title;
}

int settings_menu(game_t *g)
{
    draw_button(g, my_strcat("LEVEL: ", my_itoa(g->level)), 0);
    draw_button(g, key_button_title(g, "LEVEL: ", g->keys->l), 1);
    draw_button(g, key_button_title(g, "RIGHT: ", g->keys->r), 2);
    draw_button(g, key_button_title(g, "TURN: ", g->keys->t), 3);
    draw_button(g, key_button_title(g, "DROP: ", g->keys->d), 4);
    draw_button(g, key_button_title(g, "QUIT: ", g->keys->q), 5);
    draw_button(g, my_strcat("MAP HEIGHT: ", my_itoa(g->map_size.y)), 6);
    draw_button(g, my_strcat("MAP WIDTH: ", my_itoa(g->map_size.x)), 7);
    draw_button(g, g->show_next == TRUE ? "HINT" : "NO HINT", 8);
    draw_button(g, "BACK", 9);
}

int draw_menu(game_t *g, char **buttons)
{
    char *logo = read_to_charstar("data/tetris.txt");
    attron(COLOR_PAIR(1));
    draw_buffer(logo, (vector2_t){COLS / 2 - 31, LINES / 2 - 10}, "!");
    attroff(COLOR_PAIR(1));
    free(logo);
    for (int i = 0; buttons[i]; i++)
        draw_button(g, buttons[i], i);
}

int select_button(game_t *g, int input, int button_count)
{
    if (input == KEY_UP)
        g->select--;
    if (input == KEY_DOWN)
        g->select++;
    if (g->select < 0)
        g->select = button_count - 1;
    if (g->select >= button_count)
        g->select = 0;
}

int scoreboard(game_t *g)
{
    draw_button(g, "BACK", 0);
}

int draw_screen(game_t *g, int *button_count)
{
    char *buttons1[] = {"START GAME", "SETTINGS", "SCOREBOARD", "EXIT", NULL};
    char *buttons2[] = {"RESUME GAME", "EXIT", NULL};
    switch (g->screen) {
        case MAIN:
            *button_count = 4;
            if (draw_menu(g, buttons1) == 1)
                return 1;
            break;
        case PAUSE:
            *button_count = 2;
            if (draw_menu(g, buttons2) == 1)
                return 1;
            break;
        case SETTINGS:
            *button_count = 10;
            settings_menu(g);
            break;
        case SCOREBOARD:
            *button_count = 1;
            scoreboard(g);
            break;
    }
    return 0;
}

void set_param(game_t *g, int *param, char type, int rank)
{
    if (rank != g->select)
        return;
    if (type == 'c')
        *param = getch();
    if (type != 'b')
        return;
    if (*param == TRUE)
        *param = FALSE;
    else
        *param = TRUE;
}

void slider(game_t *g, int *param, vector2_t vars, vector2_t range)
{
    int input = vars.y;
    int rank = vars.x;
    if (rank != g->select)
        return;
    if (input == g->keys->l)
        *param -= 1;
    if (input == g->keys->r)
        *param += 1;
    if (*param < range.x)
        *param = range.x;
    if (*param > range.y)
        *param = range.y;
}

int settings_buttons(game_t *g, int input)
{
    slider(g, &g->level, (vector2_t){0, input}, (vector2_t){1, 9});
    slider(g, &g->map_size.y, (vector2_t){6, input}, (vector2_t){5, 30});
    slider(g, &g->map_size.x, (vector2_t){7, input}, (vector2_t){5, 30});
    if (input != g->keys->p)
        return 0;
    set_param(g, &g->keys->l, 'c', 1);
    set_param(g, &g->keys->r, 'c', 2);
    set_param(g, &g->keys->t, 'c', 3);
    set_param(g, &g->keys->d, 'c', 4);
    set_param(g, &g->keys->q, 'c', 5);
    set_param(g, &g->show_next, 'b', 8);
    if (g->select == 9) {
        g->screen = MAIN;
        g->select = 0;
    }
}

int main_buttons(game_t *g, int input)
{
    if (input == g->keys->p) {
        if (g->select == 0)
            g->paused = -1;
        if (g->select == 1) {
            g->screen = SETTINGS;
            g->select = 0;
        }
        if (g->select == 2) {
            g->screen = SCOREBOARD;
            g->select = 0;
        }
        if (g->select == 3)
            return 1;
    }
    return 0;
}

int pause_buttons(game_t *g, int input)
{
    if (input == g->keys->p) {
        if (g->select == 0)
            g->paused = -1;
        if (g->select == 1)
            return 1;
    }
    return 0;
}

int buttons(game_t *g, int input)
{
    if (g->screen == SETTINGS) {
        settings_buttons(g, input);
        return 0;
    }
    if (g->screen == SCOREBOARD) {
        if (input == g->keys->p && g->select == 0)
            g->screen = MAIN;
        return 0;
    }
    if (g->screen == MAIN)
        if (main_buttons(g, input) == 1)
            return 1;
    if (g->screen == PAUSE)
        if (pause_buttons(g, input) == 1)
            return 1;
    return 0;
}

int pause_game(game_t *g)
{
    int button_count;
    refresh();
    clear();
    if (draw_screen(g, &button_count) == 1)
        return 1;
    int input = getch();
    select_button(g, input, button_count);
    return buttons(g, input);
}

int loop(game_t *g)
{
    if (resize_screen(g) == 0)
        return 0;
    if (g->paused == 1) {
        if (pause_game(g) == 1)
            return 1;
        return 0;
    }
    g->time++;
    draw_ui(g);
    movement(g);
    set_stats(g);
    gravity(g);
    if (read_input(g) == 1)
        return 1;
    erase();
    return check_pos(g);
}
