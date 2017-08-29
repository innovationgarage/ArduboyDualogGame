#include "Player.h"
#include "Utility.h"
#include "Menu.h"
#include "EquipmentMenu.h"
#include "DemoMenu.h"

Arduboy2 arduboy;
Player player;

void setup()
{
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
      {
        return;
      }


      arduboy.clear();
      DrawProgmemMenu(arduboy, DemoMenu, menuIndex);
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
  DrawProgmemMenu(arduboy, EquipmentMenu, menuIndex);
  arduboy.display();
}
