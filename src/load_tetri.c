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

int ends_with(char *str, char *ending)
{
    int i = 0;
    for ( ; *str != '\0'; str++)
        if (*str == ending[i])
            i++;
    if (i == my_strlen(ending))
        return TRUE;
    return FALSE;
}

int is_valid_tetrimino(char *filepath)
{
    int is_valid = TRUE;
    char *buffer = read_to_charstar(filepath);
    int line_count = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line_count++;
    if (line_count < 2)
        is_valid = FALSE;
    vector2_t size = {buffer[0] - '0', buffer[2] - '0'};
    if (line_count != size.y + 1)
        is_valid = FALSE;
    for ( ; *buffer != '\0' && *buffer != '\n'; buffer++);
    if (*buffer == '\0')
        is_valid = FALSE;
    buffer++;
    for ( ; *buffer != '\0'; buffer++)
        if (*buffer != '\n' && *buffer != '*' && *buffer != ' ')
            is_valid = FALSE;
    return is_valid;
}

int file_error_detection(char *path)
{
    if (ends_with(path, ".tetrimino") == FALSE)
        return FALSE;
    if (is_valid_tetrimino(path) == FALSE)
        return FALSE;
    return TRUE;
}

int get_file_count(char *path)
{
    DIR *folder;
    struct dirent *file;
    folder = opendir(path);
    int count = 0;
    while((file = readdir(folder))) {
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
