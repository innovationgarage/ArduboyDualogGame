double shipx = 0, shipy = 0;
double shipspeed = 0, shipangle = 0;
const int tilew = 8, tileh = 8;

// Tile for the background
void drawTile(int x, int y)
{
  //arduboy.drawRect(x * tilew, y * tileh, tilew, tileh);

  // Draw waves on the sea
  arduboy.drawPixel(tilew / 2 + x * tilew, tileh / 2 + y * tileh);
}

void drawSea()
{
  for (int i = 0; i < WIDTH / tilew; i++)
    for (int j = 0; j < HEIGHT / tileh; j++)
      if (j > 0 || i > 7)
        drawTile(i, j);
}

void doExploringGame()
{
  arduboy.clear();
  arduboy.pollButtons();

  // Control boat
  if (arduboy.pressed(UP_BUTTON))
  {
    // Speed up
    shipspeed += 0.1;
  }

  if (arduboy.pressed(DOWN_BUTTON))
  {
    // Speed down
    shipspeed -= 0.1;
  }

  if (arduboy.pressed(LEFT_BUTTON))
  {
    // Left
    shipangle -= 0.1;
  }

  if (arduboy.pressed(RIGHT_BUTTON))
  {
    // Right
    shipangle += 0.1;
  }


  tinyfont.setCursor(0, 0);
  tinyfont.print("Exploring");

  drawSea();

  // Draw boat
  arduboy.drawLine(WIDTH / 2, HEIGHT / 2, WIDTH / 2 + shipspeed * cos(shipangle), HEIGHT / 2 + shipspeed * sin(shipangle));
  arduboy.display();
}

