
#include "FastLED.h"
#define NUM_LEDS 50
#define DATA_PIN 5
#define BRIGHTNESS 255
#define NUM_COLORS 3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int j = 0;        // Starting color number
//CRGB myColors[] = {CRGB::Red, CRGB::White, CRGB::Green};
int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
int numColors = (sizeof(rainbow_palette) / sizeof(rainbow_palette[0]));

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  
  FastLED.setBrightness( BRIGHTNESS );
  FastLED.clear ();
}

//void loop() {
//  for (int i = 0; i <= NUM_LEDS; i++) {
//    leds[i] = myColors[(i + j) % NUM_COLORS];  // mod restricts the color number
//    FastLED.show();
//  }
//  
//
//  j = (j + 1) % NUM_COLORS;                // Cycle through the starting LED#
//  delay(500);
//}

//void setup() {
//  Serial.begin(115200);
//  Serial.println();
//
//  numColors = (sizeof(myColors) / sizeof(myColors[0]));
//  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
//  FastLED.setBrightness( BRIGHTNESS );
//  FastLED.clear ();
//}

void loop() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    int color = rainbow_palette[(i + j) % numColors];    // mod 3 means the color number will be 0-2.
    leds[i] = CHSV( color, 255, 255 );
  }
  FastLED.show();

  j = (j + 1) % numColors;        // Cycle through the starting LED#, 0 to numcolors-1
  delay(300);
}
