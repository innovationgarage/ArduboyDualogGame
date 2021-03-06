void switchState(byte newState)
{
  oldState = gameState;
  gameState = newState;
}

void loop() {
  //Prevent the Arduboy from running too fast
  if (!arduboy.nextFrameDEV())
    return;

  switch (gameState)
  {
    case SPLASH:
      if (!tunes.playing())
        tunes.playScore(intro);
      doSplash();
      break;

    case EXPLORING:
      if (!tunes.playing())
        tunes.playScore(exploring);
      doExploringGame();
      break;

    case DEVELOPMENT:
      if (!tunes.playing())
        tunes.playScore(development);
      doDevelopmentGame();
      break;

    case SUPPORT:
      if (!tunes.playing())
        tunes.playScore(support);
      doSupportGame();
      break;

    case MAINMENU:
      if (tunes.playing())
        tunes.stopScore();
      doMenu();
      
      break;

    case FACE:
      doFace();
      break;
  }
}

void doMenu()
{
  arduboy.clear();
  arduboy.pollButtons();
  arduboy.drawCompressed(0, 0, dashboard);

  // Values
  arduboy.setTextSize(2);
  arduboy.setCursor(8, 13);
  arduboy.print("0");
  arduboy.setTextSize(1);
  arduboy.print("Ships");

  arduboy.setTextSize(2);
  arduboy.setCursor(8, 45);
  arduboy.print("0");
  arduboy.setTextSize(1);
  arduboy.print("Cases");

  arduboy.setTextSize(2);
  arduboy.setCursor(72, 13);
  arduboy.print("0");
  arduboy.setTextSize(1);
  arduboy.print("$NOK");

  arduboy.setTextSize(2);
  arduboy.setCursor(72, 45);
  arduboy.print("?");

  arduboy.setTextSize(2);
  arduboy.setCursor(105, 45);
  arduboy.print("?");

  arduboy.setTextSize(1);

  byte up = 0, left = 0, right = 1, down = 2;
  byte color = ((millis() - current) % 1000 > 400);

  switch (selected)
  {
    case 0:
      if (color)
      {
        arduboy.drawRect(0, 0, 63, 33);
        arduboy.drawRect(0, 0, 62, 32);
      }
      break;

    case 1:
      if (color)
      {
        arduboy.drawRect(64, 0, 63, 33);
        arduboy.drawRect(64, 0, 62, 32);
      }
      up = 1; left = 0; down = 3;
      break;

    case 2:
      if (color)
      {
        arduboy.drawRect(0, 34, 63, 30);
        arduboy.drawRect(0, 34, 62, 29);
      }
      left = 2; right = 3; down = 2;
      break;

    case 3:
      if (color)
      {
        arduboy.drawRect(64, 34, 31, 30);
        arduboy.drawRect(64, 34, 30, 29);
      }
      left = 2; up = 1; right = 4; down = 3;
      break;

    case 4:
      if (color)
      {
        arduboy.drawRect(96, 34, 31, 30);
        arduboy.drawRect(96, 34, 30, 29);
      }
      left = 3; up = 1; right = 4; down = 4;
      break;
  }


  if (arduboy.justPressed(A_BUTTON))
  {
    tunes.tone(1000, 100);
    delay(50);
    tunes.tone(900, 50);

    arduboy.clear();
    arduboy.display();
    delay(100);

    // Execute command
    switch (selected)
    {
      case 0:
        switchState(EXPLORING);
        break;

      case 1:
        switchState(DEVELOPMENT);
        break;

      case 2:
        switchState(SUPPORT);
        break;

      case 3:
        switchState(FACE);
        break;

      case 4:
        switchState(SPLASH);
        break;
    }
  }
  else
  {
    int previous = selected;

    if (arduboy.justPressed(UP_BUTTON))
      selected = up;

    if (arduboy.justPressed(DOWN_BUTTON))
      selected = down;

    if (arduboy.justPressed(LEFT_BUTTON))
      selected = left;

    if (arduboy.justPressed(RIGHT_BUTTON))
      selected = right;

    if (previous != selected)
      tunes.tone(900, 100);
  }

  arduboy.display();
}

void doSplash()
{
  arduboy.clear();
  arduboy.display();
  delay(500);

  for (int i = -8; i < 26; i = i + 1)
  {
    arduboy.clear();
    arduboy.setCursor(13, i);
    arduboy.print("Innovation Garage");
    arduboy.display();
    delay(20);
  }

  delay(600);
  arduboy.setCursor(41, 35);
  arduboy.print("presents");
  arduboy.display();
  delay(2000);

  arduboy.setTextColor(BLACK);
  arduboy.setTextBackground(WHITE);

  while (arduboy.buttonsState() == 0) {
    arduboy.clear();
    arduboy.drawCompressed(0, 0, splash);

    if (millis() % 400 > 200)
    {
      arduboy.setCursor(90, 2);
      arduboy.print("Press");
      arduboy.setCursor(83, 10);
      arduboy.print("any key");
    }
    arduboy.display();
  }
  tunes.stopScore();
  tunes.tone(987, 120);
  delay(60);
  tunes.tone(1318, 400);
  gameState = MAINMENU;
}
