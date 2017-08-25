const byte totalSupportSlots = 6;
byte selectedSupportSlot = 0;
byte supportSlots[] = { 0, 0, 0, 0, 0, 0,};
const byte width = 38, height = 28;
const byte supportSlotsX[] = { 10, 10 + 38, 10 + 38 + 38, 10, 10 + 38, 10 + 38 + 38,};
const byte supportSlotsY[] = { 8, 8, 8, 8 + 28, 8 + 28, 8 + 28,};

byte chooseDialog(byte selected)
{
}

bool showMenu = false;
void doSupportGame()
{
  arduboy.clear();
  arduboy.pollButtons();

  tinyfont.setCursor(0, 0);
  tinyfont.print("Support");

  // Draw the slots
  for (byte i = 0; i < totalSupportSlots; i++)
  {
    byte s = supportSlots[i];

    if (s > 0)
      sprites.drawSelfMasked(supportSlotsX[i], supportSlotsY[i], workstations, s - 1);

    // Selection rectangle
    if (selectedSupportSlot == i)
      arduboy.drawRect(supportSlotsX[i], supportSlotsY[i], width, height);
  }

  // Keys
  if (!showMenu)
  {

    // Back to menu
    if (arduboy.justPressed(B_BUTTON))
      switchState(MENU);
    else
    {
      if (arduboy.justPressed(A_BUTTON))
        showMenu = true;
      else
      {
        if (arduboy.justPressed(RIGHT_BUTTON) && selectedSupportSlot < totalSupportSlots - 1)
          selectedSupportSlot++;

        if (arduboy.justPressed(LEFT_BUTTON) && selectedSupportSlot > 0)
          selectedSupportSlot--;

        if (arduboy.justPressed(UP_BUTTON) && selectedSupportSlot > 2)
          selectedSupportSlot -= 3;

        if (arduboy.justPressed(DOWN_BUTTON) && selectedSupportSlot < totalSupportSlots - 3)
          selectedSupportSlot += 3;
      }
    }
  }
  else
  {
    const byte x = 10, yy = 5, w = WIDTH - 20, h = HEIGHT - 10, s = 5;

    byte y = yy;
    arduboy.fillRect(x, y, w, h, BLACK);
    arduboy.drawRect(x - 1, y - 1, w + 1, h + 1);

    tinyfont.setCursor(x + 1, y + 1);
    tinyfont.print("BUY EQUIPMENT");

    y = yy + 2;
    tinyfont.setCursor(x + 1, y + s);
    tinyfont.print(">Table");
    tinyfont.setCursor(x + 1, y + s * 2);
    tinyfont.print(" Ornament");
    tinyfont.setCursor(x + 1, y + s * 3);
    tinyfont.print(" Laptop");
    tinyfont.setCursor(x + 1, y + s * 4);
    tinyfont.print(" Tiny workstation");
    tinyfont.setCursor(x + 1, y + s * 5);
    tinyfont.print(" Workstation");
    tinyfont.setCursor(x + 1, y + s * 6);
    tinyfont.print(" Gamer PC");
    tinyfont.setCursor(x + 1, y + s * 7);
    tinyfont.print(" Advanced workstation");
    tinyfont.setCursor(x + 1, y + s * 8);
    tinyfont.print(" Mainframe");

    if (arduboy.justPressed(B_BUTTON))
      showMenu = false;
  }

  arduboy.display();
}

