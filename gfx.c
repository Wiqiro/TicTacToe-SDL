#include "gfx.h"

SDL_Window* window_create() {
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      fprintf(stderr, "Error: Failed to initialize SDL");
      return NULL;
   }

   SDL_Window* window = SDL_CreateWindow("Tic Tac Toe by Wiqiro", 50, 50, BOARD_SIZE, BOARD_SIZE, SDL_WINDOW_SHOWN);
   if (window == NULL) {
      fprintf(stderr, "Error: Failed to create SDL window\n");
   }
   return window;
}

SDL_Renderer* renderer_create(SDL_Window* window) {
   SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if (renderer == NULL) {
      fprintf(stderr, "Error: Failed to create SDL renderer\n");
   }
   return renderer;
}

SDL_Texture** textures_load(SDL_Renderer* renderer) {
   SDL_Texture** textures = (SDL_Texture**) malloc(sizeof(SDL_Texture*) * TEXTURE_COUNT);
   textures[TEXTURE_BOARD] = IMG_LoadTexture(renderer, "res/board.png");
   textures[TEXTURE_GAME_OVER] = IMG_LoadTexture(renderer, "res/game_over.png");
   textures[TEXTURE_O] = IMG_LoadTexture(renderer, "res/o.png");
   textures[TEXTURE_X] = IMG_LoadTexture(renderer, "res/x.png");

   return textures;
}

void textures_destroy(SDL_Texture** textures) {
   for (int i = 0; i < TEXTURE_COUNT; i++) {
      SDL_DestroyTexture(textures[i]);
   }
}

void render(SDL_Renderer* renderer, SDL_Texture* textures[], Board board) {
   SDL_RenderCopy(renderer, textures[TEXTURE_BOARD], NULL, NULL);
   for (int i = 0; i < 9; i++) {
      SDL_Rect rect = {(BOARD_SIZE / 3) * (i % 3), (BOARD_SIZE / 3) * (i / 3), BOARD_SIZE / 3, BOARD_SIZE / 3};
      if (board[i] == X) {
         SDL_RenderCopy(renderer, textures[TEXTURE_X], NULL, &rect);
      } else if (board[i] == O) {
         SDL_RenderCopy(renderer, textures[TEXTURE_O], NULL, &rect);
      }
   }
}