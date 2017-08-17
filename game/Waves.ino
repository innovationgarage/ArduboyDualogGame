// Based on https://github.com/wvillanueva/StarHonor/blob/master/
const int totalWaves = 20, minimumSpeed = 20, maximumSpeed = 25;
long lastUpdate = 0;

Waves::Waves()
{
  _Waves = new Wave[totalWaves];

  for ( int i(0); i < totalWaves; i++ )
  {
    Wave w;
    w.xPosition = random(0, WIDTH);
    w.yPosition = random(0, HEIGHT);
    w.velocity = random(minimumSpeed, maximumSpeed);
    _Waves[i] = w;
  }
}

void Waves::Draw()
{
  for ( int i(0); i < totalWaves; i++ )
  {
    Wave Wave = _Waves[i];

    /*for(int i=0;i<2;i++)
      {
      arduboy.drawPixel( Wave.xPosition+random(-i,i+1), Wave.yPosition );
      }*/

    x = Wave.xPosition;
    arduboy.drawPixel( x, Wave.yPosition );
    arduboy.drawPixel(++x, Wave.yPosition - 1 );
    //  arduboy.drawPixel(++x, Wave.yPosition - 1 );
    ++x;
    arduboy.drawPixel(++x, Wave.yPosition  );
    //  arduboy.drawPixel(++x, Wave.yPosition + 1 );
    //  arduboy.drawPixel(++x, Wave.yPosition + 1 );
    ++x;
    arduboy.drawPixel(++x, Wave.yPosition  );
    arduboy.drawPixel(++x, Wave.yPosition - 1 );
    //  arduboy.drawPixel(++x, Wave.yPosition - 1 );
    ++x;
    arduboy.drawPixel(++x, Wave.yPosition  );
    //  arduboy.drawPixel(++x, Wave.yPosition - 1 );
  }
}


void Waves::Move( Vector2d v )
{
  for ( int i(0); i < totalWaves; i++ )
  {
    Wave* Wave = &_Waves[i];
    float velocityOverTime = Wave->velocity * (1.0 / framerate);
    Wave->xPosition += v.x * velocityOverTime;
    Wave->yPosition += v.y * velocityOverTime;

    BoundsCheck(Wave);
  }
}

void Waves::BoundsCheck(Wave* Wave)
{
  bool setVelocity = false;
  int xPos = Wave->xPosition;
  int yPos = Wave->yPosition;
  if ( xPos > WIDTH )
  {
    Wave->xPosition = 0.0f;
    Wave->yPosition = random(0, HEIGHT);
    setVelocity = true;
  }
  else if ( xPos < 0 )
  {
    Wave->xPosition = WIDTH;
    Wave->yPosition = random(0, HEIGHT);
    setVelocity = true;
  }
  else if ( yPos > HEIGHT )
  {
    Wave->xPosition = random(0, WIDTH);
    Wave->yPosition = 0.0f;
    setVelocity = true;
  }
  else if ( yPos < 0 )
  {
    Wave->xPosition = random(0, WIDTH);
    Wave->yPosition = HEIGHT + 1;
    setVelocity = true;
  }
  if ( setVelocity )
    Wave->velocity = random(minimumSpeed, maximumSpeed);
}

