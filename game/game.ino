#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
//#include <ArduboyTones.h>
#include <Tinyfont.h>
#include "vector2d.h"
#include "structs.h"
#include "waves.h"
#include "music.h"
#include "images.h"
#include "menus.h"
#include "faces.h"
#include "workstations.h"
//#include "menusdefinition.h"

//Initialize the arduboy object
Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
//ArduboyTones sound(arduboy.audio.enabled);
Sprites sprites;

const byte SPLASH = 1, MAINMENU = 2,EXPLORING = 20, DEVELOPMENT = 40,SUPPORT = 60, FACE = 99, INVALID = 0;

byte gameState = MAINMENU, oldState = INVALID;
//int gameState = EXPLORING;

const int framerate = 60;

// For timekeeping
// TODO: clean this!
unsigned long current = 0;
unsigned int selected = 0;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(framerate);
  arduboy.clear();

  initializeAudio();
}

void initializeAudio()
{
  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMutesScore(true);       // mute the score when a tone is sounding
#endif
}

