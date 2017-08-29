// Options
const char DemoMenuOptionTable[] PROGMEM = "Demo 1";
//void GivePlayerTable(Player & player) { /*give the player a table*/ }

const char DemoMenuOptionOrnament[] PROGMEM = "Demo 2";
//void GivePlayerOrnament(Player & player) { /*give the player an ornament*/ }

const char DemoMenuOptionLaptop[] PROGMEM = "Demo 3";
//void GivePlayerLaptop(Player & player) { /*give the player a laptop?*/ }

// Menu
const char DemoMenuTitle[] PROGMEM = "Title";

const MenuOption DemoMenuOptions[] PROGMEM =
{
  { DemoMenuOptionTable, GivePlayerTable },
  { DemoMenuOptionOrnament, GivePlayerOrnament },
  { DemoMenuOptionLaptop, GivePlayerLaptop },
};

const Menu DemoMenu PROGMEM =
{
  DemoMenuTitle,
  DemoMenuOptions,
  ArrayLength(DemoMenuOptions)
};

constexpr const static uint8_t DemoMenuLength =  ArrayLength(DemoMenuOptions);
constexpr const static uint8_t DemoMenuMinIndex =  0;
constexpr const static uint8_t DemoMenuMaxIndex =  DemoMenuLength - 1;
