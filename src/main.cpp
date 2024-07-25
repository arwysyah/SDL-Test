#include "ball.h"
#include "defs.h"
#include "game.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
Ball ball;
Player player1;
bool isServed = false;

int main(int argc, const char *argv[]) {
  if (!Initialize()) {
    cerr << "There is something wrong when initializing the project" << endl;
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
  return 0;
}
