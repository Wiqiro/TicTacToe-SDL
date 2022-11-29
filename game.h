#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum Square {
   X,
   O,
   EMPTY,
};

typedef enum Square Board[9];

bool player_play(Board board, short n);
bool is_winning(Board board, enum Square turn);
bool is_full(Board board);
void computer_play(Board board);

#endif