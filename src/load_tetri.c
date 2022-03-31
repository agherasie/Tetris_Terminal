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
            tetris->shape[y][x] = data[x] == '*' ? FULL : EMPTY;
        for (; x < tetris->size.x; x++)
            tetris->shape[y][x] = EMPTY;
        tetris->shape[y][tetris->size.x] = '\0';
    }
    tetris->shape[tetris->size.y] = NULL;
    free(data_address);
    return tetris;
}

int get_file_count(char *path)
{
    DIR *folder;
    struct dirent *file;
    folder = opendir(path);
    int count = 0;
    while ((file = readdir(folder))) {
        char *filepath = my_strcat(path, file->d_name);
        if (file_error_detection(filepath) == TRUE)
            count++;
        free(filepath);
    }
    closedir(folder);
    return count;
}

tetriminos_t **init_tetri(void)
{
    char *src_folder = "tetriminos/";
    int count = get_file_count(src_folder);
    tetriminos_t **tetri = malloc(sizeof(tetriminos_t *) * count);
    DIR *folder;
    struct dirent *file;
    folder = opendir(src_folder);
    int i = 0;
    while (i < count) {
        file = readdir(folder);
        char *path = my_strcat(src_folder, file->d_name);
        if (file_error_detection(path) == FALSE) {
            free(path);
            continue;
        }
        tetri[i] = init_tetriminos(path);
        free(path);
        i++;
    }
    closedir(folder);
    return tetri;
}
