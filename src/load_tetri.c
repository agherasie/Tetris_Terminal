/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** load_tetri
*/

#include "../include/tetris.h"

int get_file_count(char *path)
{
    DIR *folder;
    struct dirent *file;
    folder = opendir(path);
    int count = 0;
    while ((file = readdir(folder))) {
        char *filepath = my_strcat(path, file->d_name);
        char *buff = read_to_charstar(filepath);
        if (file_error_detection(filepath) == TRUE && good_file(buff) == TRUE)
            count++;
        free(buff);
        free(filepath);
    }
    closedir(folder);
    return count;
}

void folder_ld(tetriminos_t **tetri, int count, DIR *folder, char *src_folder)
{
    struct dirent *file;
    int i = 0;
    while (i < count) {
        file = readdir(folder);
        char *path = my_strcat(src_folder, file->d_name);
        char *buff = read_to_charstar(path);
        if (file_error_detection(path) == FALSE || good_file(buff) == FALSE) {
            free(path);
            continue;
        }
        tetri[i] = init_tetriminos(path);
        free(buff);
        free(path);
        i++;
    }
}

tetriminos_t **init_tetri(game_t *g)
{
    char *src_folder = "tetriminos/";
    int count = get_file_count(src_folder);
    if (count == 0)
        emergency_exit(g, 84);
    tetriminos_t **tetri = malloc(sizeof(tetriminos_t *) * (count + 1));
    DIR *folder;
    folder = opendir(src_folder);
    folder_ld(tetri, count, folder, src_folder);
    tetri[count] = NULL;
    closedir(folder);
    g->tetri_count = count;
    return tetri;
}
