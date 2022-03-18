/*
** EPITECH PROJECT, 2021
** MyDefender
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *gogeta = malloc(sizeof(char) * (len + 1));
    my_strcpy(gogeta, str1);
    my_strcpy(gogeta + my_strlen(str1), str2);
    gogeta[my_strlen(gogeta)] = '\0';
    return gogeta;
}
