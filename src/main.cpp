#include "ball.h"
#include "defs.h"
#include "game.h"
#include "player.h"
#include "recta.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

using namespace std;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
Ball ball;
Player player1;
bool isServed = false;
vector<Recta> rects;

int main(int argc, const char *argv[]) {
  if (!Initialize()) {
    cerr << "There is something wrong when initializing the project" << endl;
    exit(1);
  }
  atexit(ShutDown);
  bool isQuit = false;
  for (int x = 0; x < WINDOW_WIDTH; x++) {

    rects.push_back(CreateRecta(Vecx(x, x), BALL_SIZE));
  }

  SDL_Event event;
  Uint32 lastTick = SDL_GetTicks();
  while (!isQuit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        isQuit = true;
      }
    }
    // for (Recta rect : rects) {
    //   RenderRecta(rect, renderer);
    // }

    Uint32 currentTick = SDL_GetTicks();
    Uint32 diffTick = currentTick - lastTick;
    float elapse = diffTick / 1000.0f;
    Update(elapse);
    lastTick = currentTick;
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
