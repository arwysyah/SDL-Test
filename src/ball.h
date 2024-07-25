#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL_render.h>
struct Ball {
  float x, y;
  float xSpeed, ySpeed;
  int size;
};

Ball CreateBall(int size);
void UpdateBall(Ball *ball, float elapsed);
void RenderBall(Ball *ball, SDL_Renderer *renderer);

#endif // BALL_H
