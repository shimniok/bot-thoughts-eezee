/* 
  eeZee RGB (WS2812B Breakout Board) Example
  Michael Shimniok (www.bot-thoughts.com)
  license: MIT License, see bottom of file
  http://opensource.org/licenses/mit-license.php

  Requires the Adafruit NeoPixel library.
  https://github.com/adafruit/Adafruit_NeoPixel
  
  This simple example code runs through a series of colors on a single WS2812B
  shifting between red, green, and blue LEDs.

  Hardware documentation:
  https://code.google.com/p/bot-thoughts-eezee/wiki/eeZeeRGB
*/
#include <Adafruit_NeoPixel.h>

#define PIN 8        // Arduino pin connected to WS2812B's DIN

#define DELAY 60     // ms between color changes
#define MINCOLOR 0   // lowest color setting (0-255)
#define MAXCOLOR 40  // highest color setting (0-255)

uint8_t r = MAXCOLOR; // start with red
uint8_t g = MINCOLOR;
uint8_t b = MINCOLOR;

// New instance of NeoPixel class
Adafruit_NeoPixel leds = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin();
  leds.setPixelColor(0, 0);
  leds.show();
}

void loop()
{
  // Red to Red+Blue to Blue
  for (r = MAXCOLOR, b = MINCOLOR; b < MAXCOLOR; r--, b++) {
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(DELAY);
  }
  // Blue to Blue+Green to Green
  for (b = MAXCOLOR, g = MINCOLOR; g < MAXCOLOR; b--, g++) {
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(DELAY);
  }
  // Green to Red+Green to Red
  for (g = MAXCOLOR, r = MINCOLOR; r < MAXCOLOR; g--, r++) {
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(DELAY);
  }
}


/*
The MIT License (MIT)

Copyright (c) 2013 by Michael Shimniok

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
