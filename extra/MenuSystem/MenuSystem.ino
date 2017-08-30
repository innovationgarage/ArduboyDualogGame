#include <Arduboy2.h>
#include <Tinyfont.h>
#include "Structs.h"
#include "Menus.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
Player player;


void setup()
{
  player.equipment = 0;
  arduboy.begin();
}

uint8_t menuIndex;


void loop2()
{
  while (true)
  {
    if (arduboy.nextFrame())
    {
      arduboy.pollButtons();

      if (arduboy.justPressed(B_BUTTON))
        return; // Return to first loop

      if (arduboy.justPressed(A_BUTTON))
      {
        ApplyProgmemMenuAction(player, DemoMenu, menuIndex);
      }

      arduboy.clear();
      DrawProgmemMenu(DemoMenu, menuIndex);
      arduboy.display();
    }
  }
}

void loop()
{
  if (!arduboy.nextFrame()) return;

  arduboy.pollButtons();

  if (arduboy.justPressed(DOWN_BUTTON))
  {
    if (menuIndex < EquipmentMenuMaxIndex)
      ++menuIndex;
  }

  if (arduboy.justPressed(UP_BUTTON))
  {
    if (menuIndex > EquipmentMenuMinIndex)
      --menuIndex;
  }

  if (arduboy.justPressed(A_BUTTON))
  {
    ApplyProgmemMenuAction(player, EquipmentMenu, menuIndex);
  }

  if (arduboy.justPressed(B_BUTTON))
  {
    loop2();
  }


  arduboy.clear();
  DrawProgmemMenu(EquipmentMenu, menuIndex);
  arduboy.display();
}
