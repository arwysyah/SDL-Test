#include "recta.h"
#include <SDL2/SDL.h>
Recta CreateRecta(Vecx post, int size) {
  Recta rect = {.postion = post, .size = size};
  return rect;
};

void RenderRecta(const Recta &rect, SDL_Renderer *renderer) {
  int size = rect.size;

  SDL_Rect object = {.x = static_cast<int>(rect.postion.x),
                     .y = static_cast<int>(rect.postion.y),
                     .w = size,
                     .h = size};

  SDL_SetRenderDrawColor(renderer, 122, 123, 123, 134);
  SDL_RenderFillRect(renderer, &object);

  SDL_RenderPresent(renderer);
};
