/*
** EPITECH PROJECT, 2021
** scripts
** File description:
** score.c
*/

#include "my.h"
#include "fcntl.h"

void get_score(int *hiscore)
{
    char *score = read_to_charstar("data/score.txt");
    if (score != NULL)
        *hiscore = my_getnbr(score);
    else
        *hiscore = 0;
    free(score);
    return;
}

void set_score(int *hiscore)
{
    int fp = open("data/score.txt", O_WRONLY);
    char *in_letters = my_itoa(*hiscore);
    if (fp != -1)
        write(fp, in_letters, my_strlen(in_letters));
    close(fp);
    free(in_letters);
    return;
}
