/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** my_to_word_array
*/

#include "../include/tetris.h"

int nb_words(char const *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (i != 0 && str[i] == '\n' && str[i - 1] != '\n') {
            j++;
        }
        i++;
    }
    if (str[i - 1] != '\n')
        j++;
    return j;
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int y = 0;
    char **array = malloc(sizeof(char *) * (nb_words(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == '\n')
            i++;
        else {
            array[y] = cpy_word(str, i);
            i += word_len(str, i);
            y += 1;
        }
    }
    array[y] = NULL;
    return array;
}

char *cpy_word(char *str, int i)
{
    int x = 0;
    int nb_lettres = 0;
    nb_lettres = word_len(str, i);
    char *cpy = malloc(sizeof(char) * nb_lettres + 1);
    while (x < nb_lettres) {
        cpy[x] = str[i + x];
        x++;
    }
    cpy[x] = '\0';
    return cpy;
}

int word_len(char const *str, int i)
{
    int len = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        len++;
        i++;
    }
    return len;
}
