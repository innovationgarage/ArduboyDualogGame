void doSupportGame()
{
  arduboy.clear();
  arduboy.pollButtons();

  // Back to menu
  if (arduboy.justPressed(B_BUTTON))
    switchState(MENU);

  tinyfont.setCursor(0, 0);
  tinyfont.print("Support");
  arduboy.display();
}

