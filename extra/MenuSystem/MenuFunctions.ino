void DrawMenu(const Menu & menu, const uint8_t & selected)
{
	arduboy.println(AsFlashStringHelper(menu.Title));

	for (uint8_t i = 0; i < menu.OptionsLength; ++i)
	{
		arduboy.print((i == selected) ? F("> ") : F("  "));
		arduboy.println(AsFlashStringHelper(pgm_read_word(&menu.Options[i].Text)));
	}
}

inline void DrawProgmemMenu(const Menu & progmemMenu, const uint8_t & selected)
{
	Menu menu;
	memcpy_P(&menu, &progmemMenu, sizeof(Menu));
	DrawMenu(menu, selected);
}

bool ApplyMenuAction(Player & player, const Menu & menu, const uint8_t & selected)
{
	if(selected > menu.OptionsLength)
		return false;
	MenuAction action = reinterpret_cast<MenuAction>(pgm_read_word(&menu.Options[selected].Action));
	action(player);
	return true;
}

inline bool ApplyProgmemMenuAction(Player & player, const Menu & progmemMenu, const uint8_t & selected)
{
	Menu menu;
	memcpy_P(&menu, &progmemMenu, sizeof(Menu));
	return ApplyMenuAction(player, menu, selected);
}
