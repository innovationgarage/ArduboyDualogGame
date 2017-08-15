#ifndef SEA_H
#define SEA_H

#include "Vector2d.h"

struct Wave
{
  float xPosition;
  float yPosition;
  int velocity;
};

class Waves
{
  public:
  Waves();
  void Draw();
  void Move( Vector2d v );
  void BoundsCheck(Wave* wave);

//  float MinSpeed = 1.0f;
//  float MaxSpeed = 25.0f;

  private:
  Wave* _Waves;
};

#endif
