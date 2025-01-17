// Development Plan:  Check off each step with an 'x' as you complete each one:
// [x] Showed up to the workshop.
// [ ] This file is open in VSCode.
// [ ] View the simulated Arduino by opening the diagram.json file (shows up when PlatformIO and WokWi Simulator extensions are installed).
// [ ] The Red LED is turned on.
// [ ] The Green LED is also turned on.
// [ ] The Blue LED is also turned on.
// [ ] 300 milliseconds after all the LEDs turn on, the Blue LED turns off.
// [ ] The Red LED then turns on and off every second, forever.
// [ ] The Green LED simultaneously turns on and off every half-second, forever.
// [ ] The Blue LED is on whenever the Green LED is off, and vice-versa.

/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/
#include <Arduino.h>
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
}

void loop() {

  // no need to repeat the melody.
}