/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** get_file_names
*/

#include "../include/tetris.h"

int fc_in_folder(char *path)
{
    DIR *folder = opendir(path);
    struct dirent *file;
    int count = 0;
    while ((file = readdir(folder))) {
        if (ends_with(file->d_name, ".tetrimino") == TRUE)
            count++;
    }
    closedir(folder);
    return count;
}

char **valid_files(void)
{
    int file_count = fc_in_folder("tetriminos/");
    char **file_names = malloc(sizeof(char *) * (file_count + 1));
    DIR *dir = opendir("tetriminos/");
    struct dirent *file;
    int i = 0;
    while ((file = readdir(dir))) {
        if (ends_with(file->d_name, ".tetrimino") == FALSE)
            continue;
        int len = my_strlen(file->d_name);
        file_names[i] = malloc(sizeof(char) * (len + 1));
        my_strcpy(file_names[i], file->d_name);
        file_names[i][len] = '\0';
        i++;
    }
    closedir(dir);
    file_names[i] = NULL;
    return file_names;
}
