/*const byte NONE =-1, TABLE =0, FISH =1, LAPTOP =2, MINI =3, WORKSTATION =4, GAMER =5, DUAL =6, MAINFRAME = 7;

struct WorkstationSpecs
{
  byte id;
  // image goes here
};

struct WorkerSpecs
{
  byte id;
  // 
};
*/

struct Player
{
  int equipment;
};

using MenuAction = void (*)(Player &);

struct MenuOption
{
  const char * Text;
  MenuAction Action;
};

struct Menu
{
  const char * Title;
  const MenuOption * Options;
  uint8_t OptionsLength;
};

// This tricks the arduboy into thinking a progmem string has been created with the `F` macro
constexpr inline const __FlashStringHelper * AsFlashStringHelper(const char * flashString)
{
  return reinterpret_cast<const __FlashStringHelper*>(flashString);
}

// This gets the length of an array at compile time
template< typename T, size_t N > constexpr size_t ArrayLength(T (&)[N])
{
  return N;
}
