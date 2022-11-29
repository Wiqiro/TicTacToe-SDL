#include "game.h"

bool player_play(Board board, short n) {
   if (board[n] == EMPTY) {
      board[n] = X;
      return true;
   } else {
      return false;
   }
}

bool is_winning(Board board, enum Square turn) {
   if (board[0] == turn) {
      if ((board[1] == turn && board[2] == turn) || (board[3] == turn && board[6] == turn) || (board[4] == turn && board[8] == turn)) {
         return true;
      }
   }
   if (board[4] == turn) {
      if ((board[3] == turn && board[5] == turn) || (board[1] == turn && board[7] == turn) || (board[2] == turn && board[6] == turn)) {
         return true;
      }
   }
   if (board[8] == turn) {
      if ((board[6] == turn && board[7] == turn) || (board[2] == turn && board[5] == turn)) {
         return true;
      }
   }
   return false;
}

bool is_full(Board board) {
   int i = 0;
   while (i < 9 && board[i] != EMPTY) {
      i++;
   }
   return (i == 9);
}


static short _minimax(Board board, enum Square turn, short depth) {
   if (is_winning(board, O)) {
      return (10 - depth);
   } else if (is_winning(board, X)) {
      return (depth - 10);
   } else if (is_full(board) || turn == EMPTY) {
      return 0;
   } else {
      if (turn == O) {
         short score = 10;
         for (short i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
               board[i] = O;
               score = fmax(score, _minimax(board, X, depth + 1));
               board[i] = EMPTY;
            }
         }
         return score;
      } else {
         short score = 10;
         for (short i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
               board[i] = X;
               score = fmin(score, _minimax(board, O, depth + 1));
               board[i] = EMPTY;
            }
         }
         return score;
      }
   }
}

void computer_play(Board board) {
   short move = 0, best = -11;

   for (short i = 0; i < 9; i++) {
      if (board[i] == EMPTY) {
         board[i] = O;
         short score = _minimax(board, X, 0);
         if (score > best) {
            best = score;
            move = i;
         }
         board[i] = EMPTY;
      }
   }
   board[move] = O;
}