/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <time.h>
    #include <stdio.h>
    #include <unistd.h>

// STRING
void my_putchar(char c);
int my_putstr(char const *str);
int my_revstr(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

// FILE
char *read_to_charstar(char *path);
void get_score(int *hiscore);
void set_score(int *hiscore);

// RANDOM
int either_or(int either, int orthis);
int range(int min, int max);

// NUMBER
int is_num(char c);
int my_getnbr(char const *str);
int power_of_nbr(long number);
int number_of_digits(long number);
int power_of_ten(int count);
char *my_itoa(long nb);

#endif /* MY_H_ */
