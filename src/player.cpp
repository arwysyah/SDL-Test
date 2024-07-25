#include "player.h"
#include "ball.h"
#include "defs.h"
#include <SDL2/SDL.h>
#include <cmath>
extern SDL_Renderer *renderer;
extern Ball ball;
extern Player player1;

Player MakePlayer() {
  Player player = {.yPosition = static_cast<float>(WINDOW_HEIGHT) / 2};
  return player;
}

void UpdatePlayer(float elapsed) {
  const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
  if (keyboardState[SDL_SCANCODE_SPACE]) {
    isServed = true;
  }
  if (keyboardState[SDL_SCANCODE_S] &&
      player1.yPosition <
          WINDOW_HEIGHT - static_cast<float>(PLAYER_HEIGHT) / 2) {
    player1.yPosition += PLAYER_MOVEMENT_SPEED * elapsed;
  }
  if (keyboardState[SDL_SCANCODE_W] &&
      player1.yPosition > 0 + static_cast<float>(PLAYER_HEIGHT) / 2) {
    player1.yPosition -= PLAYER_MOVEMENT_SPEED * elapsed;
  }
  SDL_Rect firstPlayer = {.x = PLAYER_MARGIN,
                          .y = static_cast<int>(player1.yPosition) -
                               PLAYER_HEIGHT / 2,
                          .w = PLAYER_WIDTH,
                          .h = PLAYER_HEIGHT};
  int size = ball.size;
  SDL_Rect ballRect = {.x = static_cast<int>(ball.x) - size / 2,
                       .y = static_cast<int>(ball.y) - size / 2,
                       .w = size,
                       .h = size};

  if (SDL_HasIntersection(&ballRect, &firstPlayer)) {
    ball.xSpeed = fabs(ball.xSpeed);
  }
}

void RenderPlayer() {
  SDL_SetRenderDrawColor(renderer, 255, 222, 12, 255);
  SDL_Rect firstPlayer = {.x = PLAYER_MARGIN,
                          .y = static_cast<int>(player1.yPosition) -
                               PLAYER_HEIGHT / 2,
                          .w = PLAYER_WIDTH,
                          .h = PLAYER_HEIGHT};

  SDL_RenderFillRect(renderer, &firstPlayer);
}
