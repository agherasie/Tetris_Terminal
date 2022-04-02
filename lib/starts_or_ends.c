/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** starts_or_ends
*/

#include "my.h"
#define TRUE 1
#define FALSE 0

int starts_with(char *str1, char *str2, char end)
{
    for (; *str1 != end; str1++, str2++)
        if (*str1 != *str2) {
            return FALSE;
        }
    return TRUE;
}

int ends_with(char *str, char *ending)
{
    int i = 0;
    for (; *str != '\0'; str++)
        if (*str == ending[i])
            i++;
    if (i == my_strlen(ending))
        return TRUE;
    return FALSE;
}
