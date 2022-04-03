/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** scoreboard
*/

#include "../include/tetris.h"

void print_score(int f, char *player, int score)
{
    write(f, player, my_strlen(player));
    write(f, " ", 1);
    char *in_letters = my_itoa(score);
    write(f, in_letters, my_strlen(in_letters));
    write(f, "\n", 1);
    free(in_letters);
}

void fill_scoreboard(game_t *g)
{
    char **players = NULL;
    int *scores = NULL;
    int rank = read_scoreboard(g, &players, &scores);
    int f = open("data/score.txt", O_TRUNC | O_WRONLY);
    if (rank == -1)
        print_score(f, getlogin(), g->score);
    for (int i = 0; i < 10; i++) {
        if (i == rank)
            print_score(f, getlogin(), g->score);
        if (players == NULL)
            break;
        if (players[i] == NULL)
            break;
        print_score(f, players[i], scores[i]);
        free(players[i]);
    }
    free(players);
    free(scores);
    write(f, "!", 1);
    close(f);
}

int scoreboard_buttons(game_t *g, int input)
{
    if (input != g->keys->p)
        return 0;
    if (g->select == 0) {
        int f = open("data/score.txt", O_TRUNC | O_WRONLY);
        write(f, "!", 1);
        close(f);
    }
    if (g->select == 1) {
        g->screen = MAIN;
        g->select = 0;
    }
    return 0;
}

int scoreboard(game_t *g)
{
    draw_button(g, "RESET", 0);
    draw_button(g, "BACK", 1);
    char *scores = read_to_charstar("data/score.txt");
    draw_buffer(scores, (vector2_t){COLS / 2 - 6, LINES / 2 + 3}, "!");
}
