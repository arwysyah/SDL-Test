#include "game.h"
#include "ball.h"
#include "defs.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <iostream>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern Ball ball;
extern Player player1;
extern bool isServed;

bool Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL INIT ERROR: " << SDL_GetError() << std::endl;
    return false;
  }

  window =
      SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!window) {
    return false;
  }

  ball = CreateBall(BALL_SIZE);
  player1 = MakePlayer();
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
}

void Update(float elapsed) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  UpdateBall(&ball, elapsed);
  RenderBall(&ball, renderer);
  UpdatePlayer(elapsed);
  RenderPlayer();
  SDL_RenderPresent(renderer);
}
