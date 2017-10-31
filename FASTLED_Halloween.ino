#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>

// Number of RGB LEDs in the strand
#define NUM_LEDS 115 

// Define the array of leds
CRGB leds[NUM_LEDS];

// Arduino pin used for Data
#define PIN 6

int current_color = 0;

// for some reason a few of thse colors are giving my strips trouble
//#define COLORSIZE 5
//CRGB colors_crgb[COLORSIZE] = { CRGB::Blue, CRGB::Gold, CRGB::GhostWhite, CRGB::Green, CRGB::Maroon};

#define COLORSIZE 3
CRGB colors_crgb[COLORSIZE] = { CRGB::Blue, CRGB::DarkRed, CRGB::Black};


//#define COLORSIZE 18
//CRGB colors_crgb[COLORSIZE] = { CRGB::FloralWhite, CRGB::Gainsboro, CRGB::GhostWhite, CRGB::Blue, CRGB::MediumBlue, CRGB::Navy, \
//CRGB::DarkBlue, CRGB::MidnightBlue, CRGB::FireBrick, CRGB::Maroon, CRGB::Crimson, CRGB::DarkRed, CRGB::DarkMagenta, CRGB::OrangeRed, \
//CRGB::DarkOrange, CRGB::BlueViolet, CRGB::DarkGreen, CRGB::Black};

// BUTTON
int buttonApin = 8;


void setup() {

  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);

  // BUTTON
  pinMode(buttonApin, INPUT_PULLUP);  

  // init strip
  printColorScreen();
}


void loop() {

  if (digitalRead(buttonApin) == LOW)
  {

        if (current_color >= (COLORSIZE - 1))
        {
          current_color = 0;
        }
        else
        {
          current_color = current_color + 1;
      
        }
        
    printColorScreen();
    delay(250);
  }



}



void printColorScreen() {
  fill_solid(leds, NUM_LEDS, colors_crgb[current_color]);
  FastLED.show();
}
