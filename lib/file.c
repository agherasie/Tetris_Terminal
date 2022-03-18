/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** file
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *read_to_charstar(char *path)
{
    int f = open(path, O_RDONLY);
    int size = 0;
    int len = 0;
    char *buffer = malloc(sizeof(char) * 1000);
    while ((size = read(f, buffer + len, 1000 - len)) > 0)
        len += size;
    len -= size;
    char *charstar = malloc(sizeof(char) * (len + 1));
    close(f);
    f = open(path, O_RDONLY);
    read(f, charstar, len);
    charstar[len] = '\0';
    close(f);
    free(buffer);
    return charstar;
}
