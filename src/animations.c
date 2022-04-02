/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** animations
*/

#include "../include/tetris.h"

int is_sep(char c, char *sep)
{
    for (; *sep != '\0'; sep++)
        if (c == *sep)
            return TRUE;
    return FALSE;
}

void draw_buffer(char *buffer, vector2_t pos, char *sep)
{
    vector2_t off = {0, 0};
    for (int i = 0; is_sep(buffer[i], sep) == FALSE; i++) {
        if (buffer[i] == '\n') {
            off.y += 1;
            off.x = 0;
            continue;
        }
        mvaddch(pos.y + off.y, pos.x + off.x, buffer[i]);
        off.x++;
    }
}

void draw_frame(char *filepath, int number, vector2_t pos)
{
    char *frame = read_to_charstar(filepath);
    int start = 0;
    for (; frame[start] != number + '0' && frame[start] != '\0'; start++);
    if (frame[start] == '\0') {
        free(frame);
        return;
    }
    start++;
    draw_buffer(frame + start, pos, "0123456789!");
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
