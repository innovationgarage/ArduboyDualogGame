#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
//#include <ArduboyTones.h>
#include <Tinyfont.h>
#include "Vector2d.h"
#include "Waves.h"
#include "music.h"
#include "images.h"
#include "faces.h"
#include "workstations.h"

//Initialize the arduboy object
Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
//ArduboyTones sound(arduboy.audio.enabled);
Sprites sprites;

const byte SPLASH = 1, MENU = 2,EXPLORING = 20, DEVELOPMENT = 40,SUPPORT = 60, FACE = 99;

int gameState = MENU;
//int gameState = EXPLORING;

const int framerate = 60;

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

