/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** lines
*/

#include "../include/tetris.h"

int line_full(char *line)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == EMPTY)
            count++;
    if (count == 0)
        return TRUE;
    return FALSE;
}

int line_empty(char *line)
{
    int count = 0;
    int i = 0;
    for (i; line[i] != '\0'; i++)
        if (line[i] == EMPTY)
            count++;
    if (count == i)
        return TRUE;
    return FALSE;
}

int line_active(char *line)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] != EMPTY)
            count++;
    if (count > 0)
        return TRUE;
    return FALSE;
}

void empty_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        line[i] = EMPTY;
}

int full_lines(game_t *g)
{
    int lines = 0;
    for (int y = 0; g->map[y]; y++) {
        if (line_full(g->map[y]) == TRUE) {
            lines++;
            empty_line(g->map[y]);
        }
    }
    return lines;
}
