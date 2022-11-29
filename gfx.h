#ifndef GFX_H
#define GFX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"

#define BOARD_SIZE 600

enum Textures {
   TEXTURE_BOARD,
   TEXTURE_GAME_OVER,
   TEXTURE_O,
   TEXTURE_X,

   TEXTURE_COUNT
};

SDL_Window* window_create();
SDL_Renderer* renderer_create(SDL_Window* window);
SDL_Texture** textures_load(SDL_Renderer* renderer);
void textures_destroy(SDL_Texture** textures);
void render(SDL_Renderer* renderer, SDL_Texture* textures[], Board board);

#endif