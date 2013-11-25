/* SparkFun WS2812 Breakout Board Example
  SparkFun Electronics
  date: July 25, 2013
  license: GNU GENERAL PUBLIC LICENSE
  
  Requires the Adafruit NeoPixel library. It's awesome, go get it.
  https://github.com/adafruit/Adafruit_NeoPixel
  
  This simple example code runs three sets of animations on a group of WS2812
  breakout boards. The more boards you link up, the better these animations
  will look. 
  
  For help linking WS2812 breakouts, checkout our hookup guide:
  https://learn.sparkfun.com/tutorials/ws2812-breakout-hookup-guide
  
  Before uploading the code, make sure you adjust the two defines at the
  top of this sketch: PIN and LED_COUNT. Pin should be the Arduino pin
  you've got connected to the first pixel's DIN pin. By default it's
  set to Arduino pin 4. LED_COUNT should be the number of breakout boards
  you have linked up.
*/
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 8
#define LED_COUNT 1

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin();  // Call this to start up the LED strip.
  leds.setPixelColor(0, 0);
  leds.show();
}

#define DELAY 60
#define MINCOLOR 0
#define MAXCOLOR 40

uint8_t r = MAXCOLOR; // start with red
uint8_t g = MINCOLOR;
uint8_t b = MINCOLOR;

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
