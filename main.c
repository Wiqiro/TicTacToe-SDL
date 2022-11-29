#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "gfx.h"

int main(int argc, char* argv[]) {
   
   SDL_Window* window = window_create();
   SDL_Renderer* renderer = renderer_create(window);
   SDL_Texture** textures = textures_load(renderer);
   SDL_Event event;

   Board board = {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};
   bool turn = X;
   bool running = true;
   while (running) {

      SDL_PollEvent(&event);
      switch (event.type) {
      case SDL_QUIT:
         running = false;
         break;
      case SDL_MOUSEBUTTONDOWN:;
         int x, y;
         SDL_GetMouseState(&x, &y);

         int n = x / (BOARD_SIZE / 3) + (y * 3) / BOARD_SIZE * 3;
         if (n >= 0 && n < 9 && board[n] == EMPTY) {
            player_play(board, n);
            turn = O;
         }
      }
      if (is_winning(board, X) || is_winning(board, O) || is_full(board)) {
         running = false;
      } else if (turn == O) {
         computer_play(board);
         turn = X;
      }
      render(renderer, textures, board);
      SDL_RenderPresent(renderer);
   }
   while (event.type != SDL_QUIT) {
      SDL_PollEvent(&event);
      render(renderer, textures, board);
      SDL_RenderCopy(renderer, textures[TEXTURE_GAME_OVER], NULL, NULL);
      SDL_RenderPresent(renderer);
   }
   
   textures_destroy(textures);
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);

   return EXIT_SUCCESS;
}