/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** animations
*/

#include "../include/tetris.h"

void draw_frame(char *filepath, int number, vector2_t pos)
{
    char *frame = read_to_charstar(filepath);
    vector2_t off = {0, 0};
    int start = 0;
    for (; frame[start] != number + '0' && frame[start] != '\0'; start++);
    if (frame[start] == '\0') {
        free(frame);
        return;
    }
    start++;
    for (int i = start; (frame[i] < '0' || frame[i] > '9')
    && frame[i] != '!'; i++) {
        if (frame[i] == '\n') {
            off.y += 1;
            off.x = 0;
            continue;
        }
        mvaddch(pos.y + off.y, pos.x + off.x, frame[i]);
        off.x++;
    }
    free(frame);
}

void draw_animation(game_t *g, vector2_t off)
{
    if (g->animation == 0)
        return;
    off.y += g->map_size.y + 2;
    off.x += g->map_size.x / 2;
    if (g->tetris->pos.y >= 4)
        return;
    mvprintw(off.y, off.x + 1, "BOOM");
    for (int i = 0; i < g->tetris->pos.y; i++)
        mvprintw(off.y, off.x + 6 + i, "!");
    mvprintw(off.y + 1, off.x - 4, "Tetris for %s", getlogin());
    off.y += 1;
    draw_frame("data/anim1.txt", g->tetris->pos.y, off);
}
