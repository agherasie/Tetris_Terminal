/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** file_checks
*/

#include "../include/tetris.h"

int ends_with(char *str, char *ending)
{
    int i = 0;
    for (str; *str != '\0'; str++)
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
    char *buffer_address = buffer;
    int line_count = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line_count++;
    if (line_count < 2)
        is_valid = FALSE;
    vector2_t size = {buffer[0] - '0', buffer[2] - '0'};
    if (line_count != size.y + 1)
        is_valid = FALSE;
    for (buffer; *buffer != '\0' && *buffer != '\n'; buffer++);
    if (*buffer == '\0')
        is_valid = FALSE;
    buffer++;
    for (buffer; *buffer != '\0'; buffer++)
        if (*buffer != '\n' && *buffer != '*' && *buffer != ' ')
            is_valid = FALSE;
    free(buffer_address);
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
