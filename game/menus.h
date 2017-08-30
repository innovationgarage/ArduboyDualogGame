
// Demo Menu
// Options
const char DemoMenuOption1[] PROGMEM = "Print player equipment";
const char DemoMenuOption2[] PROGMEM = "Demo 2";
const char DemoMenuOption3[] PROGMEM = "Demo 3";
const char DemoMenuOption4[] PROGMEM = "Demo 4";
const char DemoMenuOption5[] PROGMEM = "Demo 5";
const char DemoMenuOption6[] PROGMEM = "Demo 6";

void nullFunction() {
  Serial.println("Player equipment:");
}

// Menu
const char DemoMenuTitle[] PROGMEM = "Title";

const MenuOption DemoMenuOptions[] PROGMEM =
{
  { DemoMenuOption1, nullFunction },
  { DemoMenuOption2, nullFunction },
  { DemoMenuOption3, nullFunction },
  { DemoMenuOption4, nullFunction },
  { DemoMenuOption5, nullFunction },
  { DemoMenuOption6, nullFunction },
};

const Menu DemoMenu PROGMEM =
{
  DemoMenuTitle,
  DemoMenuOptions,
  ArrayLength(DemoMenuOptions)
};

// Equipment menu
/*#pragma once

  #include "Menu.h"
  #include "Player.h"
  #include "Utility.h"*/

// Options
const char EquipmentMenuOptionTable[] PROGMEM = "Table";
void GivePlayerTable(Player & player) {
  player.equipment++;
}

const char EquipmentMenuOptionOrnament[] PROGMEM = "Ornament";
void GivePlayerOrnament(Player & player) {
  player.equipment += 2;
}

const char EquipmentMenuOptionLaptop[] PROGMEM = "Laptop";
void GivePlayerLaptop(Player & player) {
  player.equipment += 3;
}

// Menu
const char EquipmentMenuTitle[] PROGMEM = "BUY EQUIPMENT";

const MenuOption EquipmentMenuOptions[] PROGMEM =
{
  { EquipmentMenuOptionTable, GivePlayerTable },
  { EquipmentMenuOptionOrnament, GivePlayerOrnament },
  { EquipmentMenuOptionLaptop, GivePlayerLaptop },
};

const Menu EquipmentMenu PROGMEM =
{
  EquipmentMenuTitle,
  EquipmentMenuOptions,
  ArrayLength(EquipmentMenuOptions)
};



// Menu system
constexpr const static uint8_t DemoMenuLength =  ArrayLength(DemoMenuOptions);
constexpr const static uint8_t DemoMenuMinIndex =  0;
constexpr const static uint8_t DemoMenuMaxIndex =  DemoMenuLength - 1;

constexpr const static uint8_t EquipmentMenuLength =  ArrayLength(EquipmentMenuOptions);
constexpr const static uint8_t EquipmentMenuMinIndex =  0;
constexpr const static uint8_t EquipmentMenuMaxIndex =  EquipmentMenuLength - 1;
