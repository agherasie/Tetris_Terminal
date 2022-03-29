/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** load_tetri
*/

#include "../include/tetris.h"

void skip_to_line(char **data)
{
    for (; **data != '\n'; *data += 1)
        if (**data == '\0')
            return;
    *data += 1;
}

tetriminos_t *init_tetriminos(char *filepath)
{
    tetriminos_t *tetris = malloc(sizeof(tetriminos_t));
    char *data = read_to_charstar(filepath);
    char *data_address = data;
    tetris->size = (vector2_t){data[0] - '0', data[2] - '0'};
    tetris->color = data[4] - '0';
    tetris->landed = FALSE;
    tetris->shape = malloc(sizeof(char *) * (tetris->size.y + 1));
    for (int y = 0; y < tetris->size.y; y++) {
        skip_to_line(&data);
        tetris->shape[y] = malloc(sizeof(char) * (tetris->size.x + 1));
        int x = 0;
        for (; data[x] != '\n'; x++)
            tetris->shape[y][x] = data[x];
        for (; x < tetris->size.x; x++)
            tetris->shape[y][x] = ' ';
        tetris->shape[y][tetris->size.x] = '\0';
    }
    tetris->shape[tetris->size.y] = NULL;
    free(data_address);
    return tetris;
}

tetriminos_t **init_tetri(void)
{
    tetriminos_t **tetri = malloc(sizeof(tetriminos_t *) * 7);
    for (int i = 0; i < 7; i++) {
        char *to_number = my_itoa(i);
        char *path = my_strcat("tetriminos/", to_number);
        char *fullpath = my_strcat(path, ".tetrimino");
        tetri[i] = init_tetriminos(fullpath);

        free(path);
        free(fullpath);
        free(to_number);
    }
    return tetri;
}
