#include "ball.h"
#include "defs.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <cmath>

Ball CreateBall(int size) {
  Ball fixedBall = {.x = (WINDOW_WIDTH / 2 - BALL_SIZE / 2),
                    .y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2,
                    .xSpeed = SPEED,
                    .ySpeed = SPEED,
                    .size = static_cast<int>(BALL_SIZE)};
  return fixedBall;
}

void UpdateBall(Ball *ball, float elapsedTime) {
  if (!isServed) {
    ball->x = static_cast<float>(WINDOW_WIDTH) / 2;
    ball->y = static_cast<float>(WINDOW_HEIGHT) / 2;
    return;
  }
  ball->x += ball->xSpeed * elapsedTime;
  ball->y += ball->ySpeed * elapsedTime;

  if (ball->x < 0 + (BALL_SIZE / 2)) {
    ball->xSpeed = fabs(ball->xSpeed);
  }
  if (ball->x > WINDOW_WIDTH - (BALL_SIZE / 2)) {
    ball->xSpeed = -fabs(ball->xSpeed);
  }
  if (ball->y < (0 + BALL_SIZE / 2)) {
    ball->ySpeed = fabs(ball->ySpeed);
  }
  if (ball->y > WINDOW_HEIGHT - (BALL_SIZE / 2)) {
    ball->ySpeed = -fabs(ball->ySpeed);
  }
}

void RenderBall(Ball *ball, SDL_Renderer *renderer) {
  int size = ball->size;
  SDL_Rect ballRect = {.x = static_cast<int>(ball->x) - size / 2,
                       .y = static_cast<int>(ball->y) - size / 2,
                       .w = size,
                       .h = size};
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &ballRect);
  SDL_RenderPresent(renderer);
}
