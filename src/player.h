#ifndef PLAYER_H
#define PLAYER_H

struct Player {
  float yPosition;
};

Player MakePlayer();
void UpdatePlayer(float elapsed);
void RenderPlayer();
extern bool isServed;

#endif // PLAYER_H
