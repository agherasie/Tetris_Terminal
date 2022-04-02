/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** init_tetris
*/

#include "../include/tetris.h"

void skip_to_line(char **data)
{
    for (; **data != '\n'; *data += 1)
        if (**data == '\0')
            return;
    *data += 1;
}

char **shape_form(tetriminos_t *t, char *data)
{
    char **shape = malloc(sizeof(char *) * (t->size.y + 1));
    for (int y = 0; y < t->size.y; y++) {
        skip_to_line(&data);
        shape[y] = malloc(sizeof(char) * (t->size.x + 1));
        int x = 0;
        for (; data[x] != '\n'; x++)
            shape[y][x] = data[x] == '*' ? FULL : EMPTY;
        for (; x < t->size.x; x++)
            shape[y][x] = EMPTY;
        shape[y][t->size.x] = '\0';
    }
    shape[t->size.y] = NULL;
    return shape;
}

tetriminos_t *init_tetriminos(char *filepath)
{
    tetriminos_t *tetris = malloc(sizeof(tetriminos_t));
    char *data = read_to_charstar(filepath);
    char *data_address = data;
    tetris->size = (vector2_t){data[0] - '0', data[2] - '0'};
    tetris->pos = (vector2_t){0, 0};
    tetris->color = data[4] - '0';
    tetris->color %= 7;
    if (tetris->color == 0)
        tetris->color++;
    tetris->landed = FALSE;
    tetris->amount = 0;
    tetris->shape = shape_form(tetris, data);
    free(data_address);
    return tetris;
}
