/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** settings
*/

#include "../include/tetris.h"

char *key_button_title(game_t *g, char *title, int key)
{
    char *key_name = malloc(sizeof(char) * my_strlen(keyname(key)));
    my_strcpy(key_name, keyname(key));
    char *button_title = my_strcat(title, key_name);
    free(key_name);
    return button_title;
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
