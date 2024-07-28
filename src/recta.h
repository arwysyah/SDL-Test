#ifndef RECTA_H
#define RECTA_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
struct Vecx {
  float x;
  float y;
  Vecx() : x(0), y(0){};
  Vecx(float xCoord, float yCoord) : x(xCoord), y(yCoord){};
};
struct Recta {
  Vecx postion;
  int size;
};

Recta CreateRecta(Vecx post, int size);
void RenderRecta(const Recta &rect, SDL_Renderer *renderer);
#endif // DEBUG
