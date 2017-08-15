#include "Waves.h"
#include "Arduino.h"

Waves::Waves()
{
  _Waves = new Wave[20];

  for( int i(0); i < 20; i++ )
  {
    Wave w;
    w.xPosition = random(0, 128);
    w.yPosition = random(0, 64);
    w.velocity = random(1, 25);
    _Waves[i] = w;
  }
}

void Waves::Draw()
{
  for( int i(0); i < 20; i++ )
  {
    Wave Wave = _Waves[i];
    arduboy.drawPixel( Wave.xPosition, Wave.yPosition, 1 );
  }
}


void Waves::Move( Vector2d v )
{
  for( int i(0); i < 20; i++ )
  {
    Wave* Wave = &_Waves[i];
    float velocityOverTime = Wave->velocity * DeltaTime;
    Wave->xPosition += v.x * velocityOverTime;
    Wave->yPosition += v.y * velocityOverTime;

    BoundsCheck(Wave);
  }
}

void Waves::BoundsCheck(Wave* Wave)
{
/*  bool setVelocity = false;
  int xPos = Wave->xPosition;
  int yPos = Wave->yPosition;
  if ( xPos > 128 )
  {
    Wave->xPosition = 0.0f;
    Wave->yPosition = random(0, 64);
    setVelocity = true;
  }
  else if ( xPos < 0 )
  {
    Wave->xPosition = 128.0f;
    Wave->yPosition = random(0, 64);
    setVelocity = true;
  }
  else if ( yPos > 63 )
  {
    Wave->xPosition = random(0, 128);
    Wave->yPosition = 0.0f;
    setVelocity = true;
  }
  else if ( yPos < 0 )
  {
    Wave->xPosition = random(0, 128);
    Wave->yPosition = 63;
    setVelocity = true;
  }
  if ( setVelocity )
    Wave->velocity = random(1, 25);*/
}

