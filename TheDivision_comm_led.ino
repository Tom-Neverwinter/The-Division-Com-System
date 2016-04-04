#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
//ATTiny85 at 8mhz(minimum) or 16mhz (should work on other arduino boards/clones)

#define PIN_3 3
// Adafruit neopixel PINS (0 is for attiny85 and use a different pwm for any other arduino)
#define NUMPIXELS      16
// How many NeoPixels are attached to the Arduino

Adafruit_NeoPixel strip_a = Adafruit_NeoPixel (16, PIN_3, NEO_GRB + NEO_KHZ800);
//strip selection (number of leds, pin number, led info)

// put your setup code here, to run once:
void setup() {
  int delayval = 500; // delay for half a second
  strip_a.begin();
  strip_a.show(); // This initializes the NeoPixel library.
}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //strip_a.setPixelColor(i, strip_a.Color(255, 110, 14)); // The Division Orange from The Division Logo
    strip_a.setPixelColor(i, strip_a.Color(255, 50, 10)); // LED light (similar to logo and game)
    strip_a.show(); // This sends the updated pixel color to the hardware.

    delay(500); // delay for half a second

    /////////////Battery saving mode///////////////////////////////////////////
    //( strip_a.setBrightness(20)); // Brightness of the pixels, max is 255
    //strip_a.show(); // This sends the updated pixel color to the hardware.
    ///////////////////////////////////////////////////////////////////////////
  }
  delay(500); // Delay for a period of time (in milliseconds).
}
// Total max amperage = [16mA*16=480] + [microcontroller mA]
