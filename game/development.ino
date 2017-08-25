int devx = 0, devy = 0, w;

void doDevelopmentGame()
{
  arduboy.clear();
  arduboy.pollButtons();

  // Back to menu
  if (arduboy.justPressed(B_BUTTON))
    switchState(MENU);

  tinyfont.setCursor(0, 0);
  tinyfont.print("Development");

  sprites.drawSelfMasked(devx, devy, workstations, w);

  if (arduboy.justPressed(LEFT_BUTTON))
    devx--;
  if (arduboy.justPressed(RIGHT_BUTTON))
    devx++;
  if (arduboy.justPressed(UP_BUTTON))
    devy--;
  if (arduboy.justPressed(DOWN_BUTTON))
    devy++;
  if (arduboy.justPressed(A_BUTTON))
  {
    w++;

    if (w == 8)
      w = 0;
  }

  arduboy.display();
}

