/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** sort
*/

#include "my.h"
#define TRUE 1
#define FALSE 0

void swap_pointer(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char **arr, char flag)
{
    for (int i = 0; arr[i + 1]; i++)
        if (my_strcmp(arr[i], arr[i + 1]) > 0)
            swap_pointer(&arr[i], &arr[i + 1]);
    int is_sorted = TRUE;
    for (int i = 0; arr[i + 1]; i++)
        if (my_strcmp(arr[i], arr[i + 1]) > 0)
            is_sorted = FALSE;
    if (is_sorted == FALSE)
        sort(arr, flag);
}
