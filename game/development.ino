void doDevelopmentGame()
{
  arduboy.clear();
  arduboy.pollButtons();

  // Back to menu
  if (arduboy.justPressed(B_BUTTON))
    gameState = MENU;

  tinyfont.setCursor(0, 0);
  tinyfont.print("Development");
  arduboy.display();
}

