/*

Demonstrates the use of the Parallax WS2812B RGB Led Module (#28085)

This demo cycles the LED through the three primary colors, red, blue, and
green, slowly fading in for each color.

For a demonstration using two WS2812B RGB LED modules, and how the modules
may be daisychained from a single Arduino I/O pin, please see the 
'WS2812B_Dual' sketch.

------------

This sketch REQUIRES the use of a third-party library, Adafruit_NeoPixel. 
It is available for download from the following source.

https://github.com/adafruit/Adafruit_NeoPixel

On the GitHub site locate the 'Download Zip' button to download the full library. 
Once downloaded, unzip the files and place them into your Arduino 'libraries' folder. 
This folder is located within your Arduino sketch directory; on Windows this is usually 
My Documents\Arduino. If there is no 'libraries' folder within the sketch 
directory you must create one.

For your convenience, the Adafruit_NeoPixel library is also included in the
download with this demonstration sketch. Prior to use you MUST move the 
'Adafruit_NeoPixel' library folder into your Arduino sketch 'libraries' folder.

Important! After moving the Adafruit_NeoPixel library to the 'libraries' folder
you MUST restart the Arduino IDE.

This example code is for the Arduino Uno and direct compatible boards, using the
Arduino 1.0 or later IDE software. It has not been tested, nor designed for, other 
Arduino boards, including the Arduino Due.

------------

Connections:
LED      Arduino
GND      GND
5V       5V
SI       Digital Pin 6

*/

#include <Adafruit_NeoPixel.h>         // Include Adafruit NeoPixel library
#define PIN            A2               // LED on digital pin 6
#define NUMLEDS        1               // Use total of 1 LED

// Create 'leds' object to drive LEDs
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

int wait = 4;                         // Standard wait delay of 5 milliseconds 

void setup() {
  leds.begin();                       // Initialize 'leds' object

  //Make sure LED is off to demonstrate start of sketch
  leds.setPixelColor(0, leds.Color(0, 0, 0));  // Turn off LED
  leds.show();                        // Set new value
  delay(500);
  
}

// Loop through changing R, G, and B colors
// Each color fades in from off (i=0) to fully on (i=255)
void loop() {
  for(int i=0; i<255; i++) {            // Count up color units from 0 to 255
    leds.setPixelColor(0, leds.Color(i, 0, 0));  // Color mix for LED
    leds.show();                        // Set the LED
    delay(wait);                        // Delay for visual effect
  }
  for(int i=255; i>0; i--) {            // Count up color units from 0 to 255
    leds.setPixelColor(0, leds.Color(i, 0, 0));  // Color mix for LED
    leds.show();                        // Set the LED
    delay(wait);                        // Delay for visual effect
  }
  for(int i=0; i<255; i++) {            // Loop through next color change
    leds.setPixelColor(0, leds.Color(0, i, 0)); 
    leds.show(); 
    delay(wait); 
  }
  for(int i=255; i>0; i--) {            // Count up color units from 0 to 255
    leds.setPixelColor(0, leds.Color(0, i, 0));  // Color mix for LED
    leds.show();                        // Set the LED
    delay(wait);                        // Delay for visual effect
  }
  for(int i=0; i<255; i++) {            // Loop through next color change
    leds.setPixelColor(0, leds.Color(0, 0, i));
    leds.show(); 
    delay(wait);
  }
  for(int i=255; i>0; i--) {            // Count up color units from 0 to 255
    leds.setPixelColor(0, leds.Color(0, 0, i));  // Color mix for LED
    leds.show();                        // Set the LED
    delay(wait);                        // Delay for visual effect
  }
}
