unsigned int selected = 0;
long current = 0;

unsigned char* const chins[] = { l8_01, l8_02, l8_03, l8_04, l8_05, l8_06, l8_07, l8_08, l8_09, l8_10, l8_11, l8_12, l8_13, l8_14 };
unsigned char* const noses[] = { l7_01, l7_02, l7_03, l7_04, l7_05, l7_06, l7_07, l7_08, l7_09, l7_10, l7_11, l7_12, l7_13, l7_14 };
unsigned char* const hairlows[] = { l6_01, l6_02, l6_03, l6_04, l6_05, l6_06, l6_07, l6_08, l6_09, l6_10, l6_11, l6_12, l6_13, l6_14 };
unsigned char* const earss[] = { l5_01, l5_02, l5_03, l5_04, l5_05, l5_06, l5_07, l5_08, l5_09, l5_10, l5_11, l5_12, l5_13, l5_14 };
unsigned char* const mouths[] = { l4_01, l4_02, l4_03, l4_04, l4_05, l4_06, l4_07, l4_08, l4_09, l4_10, l4_11, l4_12, l4_13, l4_14 };
unsigned char* const eyess[] = { l3_01, l3_02, l3_03, l3_04, l3_05, l3_06, l3_07, l3_08, l3_09, l3_10, l3_11, l3_12, l3_13, l3_14 };
unsigned char* const hairs[] = { l2_01, l2_02, l2_03, l2_04, l2_05, l2_06, l2_07, l2_08, l2_09, l2_10, l2_11, l2_12, l2_13, l2_14 };


byte invert = false;
byte chin = 0, nose = 0, hairlow = 0, ears = 0, mouth = 0, eyes = 0, hair = 0, x = 0, y = 0, selection = 0;

void drawFace(byte x, byte y, byte chin, byte nose, byte hairlow, byte ears, byte mouth, byte eyes, byte hair)
{
  arduboy.drawRect(x, y, 50, 50);
  x++; y++;
  arduboy.drawCompressed(x, y, chins[chin]);
  arduboy.drawCompressed(x, y, noses[nose]);
  arduboy.drawCompressed(x, y, hairlows[hairlow]);
  arduboy.drawCompressed(x, y, earss[ears]);
  arduboy.drawCompressed(x, y, mouths[mouth]);
  arduboy.drawCompressed(x, y, eyess[eyes]);
  arduboy.drawCompressed(x, y, hairs[hair]);
  arduboy.invert(invert);
}

void doFace()
{
  arduboy.pollButtons();
  arduboy.clear();
  drawFace(x, y, chin, nose, hairlow, ears, mouth, eyes, hair);
  //  drawFace(x, y, 2,4,5,6,7,8,selection);

  byte *s;
  byte limit = 13, selectorx;
  const byte optionlimit = 9, selectory = 64 - 10;
  arduboy.setCursor(128 - 44, 64 - 8);
  switch (selection)
  {
    case 7: selectorx = 86; arduboy.print(x); s = &x; limit = 128 - 50; break;
    case 8: selectorx = 92; arduboy.print(y); s = &y; limit = 64 - 50; break;
    case 9: selectorx = 98; arduboy.print("invert"); s = &invert; limit = 1; break;
    case 0: selectorx = 42; arduboy.print("chin"); s = &chin; break;
    case 1: selectorx = 48; arduboy.print("nose"); s = &nose; break;
    case 2: selectorx = 54; arduboy.print("lowhair"); s = &hairlow; break;
    case 3: selectorx = 60; arduboy.print("ears"); s = &ears; break;
    case 4: selectorx = 66; arduboy.print("mouth"); s = &mouth; break;
    case 5: selectorx = 72; arduboy.print("eyes"); s = &eyes; break;
    case 6: selectorx = 78; arduboy.print("hair"); s = &hair; break;
  }
  selectorx -= 6 * 4;
  arduboy.drawLine(selectorx, selectory, selectorx + 4, selectory);

  if (arduboy.justPressed(RIGHT_BUTTON))
    selection = selection < optionlimit ? selection + 1 : 0;

  if (arduboy.justPressed(LEFT_BUTTON))
    selection = selection > 0 ? selection - 1 : optionlimit;


  if (arduboy.justPressed(UP_BUTTON))
    (*s) = (*s) < limit ? (*s) + 1 : 0;

  if (arduboy.justPressed(DOWN_BUTTON))
    (*s) = (*s) > 0 ? (*s) - 1 : limit;

  if (arduboy.justPressed(B_BUTTON))
    gameState = MENU;

  if (arduboy.justPressed(A_BUTTON))
  {
    chin = random(0, 14);
    nose = random(0, 14);
    hairlow = random(0, 14);
    ears = random(0, 14);
    mouth = random(0, 14);
    eyes = random(0, 14);
    hair = random(0, 14);
  }

  /*arduboy.print(":");
    arduboy.println(*s);*/

  arduboy.setCursor(0, 64 - 8);
  arduboy.print("0x0");
  arduboy.print(chin, HEX);
  arduboy.print(nose, HEX);
  arduboy.print(hairlow, HEX);
  arduboy.print(ears, HEX);
  arduboy.print(mouth, HEX);
  arduboy.print(eyes, HEX);
  arduboy.print(hair, HEX);

  arduboy.setCursor(62, 64 - 8);
  arduboy.print("XY#");

  arduboy.display();
}
