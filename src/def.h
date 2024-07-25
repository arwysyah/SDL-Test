#ifndef DEF_H
#define DEF_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BALL_SIZE 10.0f
#define SPEED 120
// STRUCT
typedef struct Ball {
  float x;
  float y;
  float xSpeed;
  float ySpeed;
  int size;
} Ball;

// FUNCTION
bool Initialize(void);
void Update(float);
void ShutDown();
Ball CreateBall(int);
void RenderBall(Ball *);
void UpdateBall(Ball *, float);
#endif // DEBUG
