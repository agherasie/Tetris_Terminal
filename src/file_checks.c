/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** file_checks
*/

#include "../include/tetris.h"

int valid_checks(int line_count, char *buffer)
{
    int is_valid = TRUE;
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
        if (*buffer != '\n' && *buffer != '*' && *buffer != EMPTY)
            is_valid = FALSE;
    return is_valid;
}

int is_valid_tetrimino(char *filepath)
{
    int is_valid = TRUE;
    char *buffer = read_to_charstar(filepath);
    int line_count = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line_count++;
    is_valid = valid_checks(line_count, buffer);
    free(buffer);
    return is_valid;
}

int file_error_detection(char *path)
{
    if (ends_with(path, ".tetrimino") == FALSE)
        return FALSE;
    if (good_file(read_to_charstar(path)) == 1)
        return FALSE;
    return TRUE;
}
