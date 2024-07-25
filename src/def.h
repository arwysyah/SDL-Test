#ifndef DEF_H
#define DEF_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BALL_SIZE 10.0f
#define SPEED 120
#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 75
#define PLAYER_MARGIN 10
#define PLAYER_MOVEMENT_SPEED 150.f

// STRUCT
typedef struct Ball {
  float x;
  float y;
  float xSpeed;
  float ySpeed;
  int size;
} Ball;

typedef struct Player {

  int score;
  float yPosition;
} Player;

// FUNCTION
bool Initialize(void);
void Update(float);
void ShutDown();
Ball CreateBall(int);
void RenderBall(Ball *);
void UpdateBall(Ball *, float);
Player MakePlayer(void);
void UpdatePlayer(float);
void RenderPlayer(void);

#endif // DEBUG
