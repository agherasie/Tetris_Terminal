/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** score
*/

#include "../include/tetris.h"

int get_hiscore(void)
{
    char *buff = read_to_charstar("data/score.txt");
    if (buff[0] == '\0') {
        free(buff);
        return 0;
    }
    int i = 0;
    for (; buff[i] != ' ' && buff[i] != '!'; i++);
    if (buff[i] == '!') {
        free(buff);
        return 0;
    }
    char *in_letters = before_c(buff + i + 1, '\n');
    int hiscore = my_getnbr(in_letters);
    free(in_letters);
    free(buff);
    return hiscore;
}

char **get_player_names(char *buff, int count)
{
    char **players = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        players[i] = before_c(buff, ' ');
        for (; *buff != '\n'; buff++);
        buff++;
    }
    players[count] = NULL;
    return players;
}

int *get_scores(char *buff, int count)
{
    int *scores = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        for (; *buff != ' '; buff++);
        buff++;
        scores[i] = my_getnbr(before_c(buff, '\n'));
    }
    return scores;
}

int read_scoreboard(game_t *g, char ***players_ptr, int **scores_ptr)
{
    char *buff = read_to_charstar("data/score.txt");
    if (buff[0] == '\0')
        return -1;
    int count = 0;
    for (int i = 0; buff[i] != '!'; i++)
        if (buff[i] == '\n')
            count++;
    if (count == 0)
        return -1;
    char **players = get_player_names(buff, count);
    int *scores = get_scores(buff, count);
    free(buff);
    int rank = 0;
    for (; rank < count; rank++) {
        if (g->score > scores[rank])
            break;
    }
    *players_ptr = players;
    *scores_ptr = scores;
    return rank;
}
