#include "def.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sys/types.h>

using namespace std;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
Ball ball;

int main(int argc, const char *argv[0]) {
  if (!Initialize()) {
    cerr << "There is something error when Initialize project" << endl;
    exit(1);
  }
  atexit(ShutDown);
  bool isQuit = false;

  SDL_Event event;
  Uint32 lastTick = SDL_GetTicks();

  while (!isQuit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isQuit = true;
      }
    }
    Uint32 currentTick = SDL_GetTicks();
    Uint32 diffTick = currentTick - lastTick;
    float elapse = diffTick / 1000.0f;
    Update(elapse);
    lastTick = currentTick;
  }
  SDL_Quit();
}
bool Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr << "SDL INIT ERROR" << SDL_GetError() << endl;
    return false;
  }

  window =
      SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(
      window, -1,
      SDL_RENDERER_ACCELERATED |
          SDL_RENDERER_PRESENTVSYNC); // SDL_RENDERER_ACCELERATED == GPU
  if (!window) {
    return false;
  }

  ball = CreateBall(BALL_SIZE);

  return true;
}

void ShutDown(void) {
  if (renderer) {
    SDL_DestroyRenderer(renderer);
  }
  if (window) {
    SDL_DestroyWindow(window);
  }

  SDL_Quit();
};

Ball CreateBall(int size) {
  Ball fixedBall = {.x = (WINDOW_WIDTH / 2 - BALL_SIZE / 2),
                    .y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2,
                    .xSpeed = SPEED,
                    .ySpeed = SPEED,
                    .size = static_cast<int>(BALL_SIZE)};
  return fixedBall;
};
void Update(float elapsed) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  UpdateBall(&ball, elapsed);
  RenderBall(&ball);

  SDL_RenderPresent(renderer);
}

void RenderBall(Ball *ball) {

  int size = ball->size;
  SDL_Rect ballRect = {.x = static_cast<int>(ball->x) - size / 2,
                       .y = static_cast<int>(ball->y) - size / 2,
                       .w = size,
                       .h = size

  };
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderFillRect(renderer, &ballRect);

  SDL_RenderPresent(renderer);
};

void UpdateBall(Ball *ball, float elaspeTime) {
  ball->x += ball->xSpeed * elaspeTime;
  ball->y += ball->ySpeed * elaspeTime;

  if (ball->x < 0 + (BALL_SIZE / 2)) {
    ball->xSpeed = fabs(ball->xSpeed);
  };
  if (ball->x > WINDOW_WIDTH - (BALL_SIZE / 2)) {
    ball->xSpeed = -fabs(ball->xSpeed);
  };
  if (ball->y < (0 + BALL_SIZE / 2)) {
    ball->ySpeed = fabs(ball->ySpeed);
  };
  if (ball->y > WINDOW_HEIGHT - (BALL_SIZE / 2)) {
    ball->ySpeed = -fabs(ball->ySpeed);
  };
}
