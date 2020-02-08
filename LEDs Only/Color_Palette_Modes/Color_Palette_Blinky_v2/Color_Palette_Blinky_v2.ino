
#include "FastLED.h"
#define NUM_LEDS 50
#define DATA_PIN 5
#define BRIGHTNESS 255
#define NUM_COLORS 3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int j;        // Starting color number
//CRGB myColors[] = {CRGB::Red, CRGB::White, CRGB::Green};
int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
int numColors = (sizeof(rainbow_palette) / sizeof(rainbow_palette[0]));

void setup() {
  delay(3000); // 3 second delay for recovery
  Serial.begin(9600);

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

int f;
void loop() {
  for (int h = 0; h < numColors; h++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV( rainbow_palette[h], 255, 255 );
    }

//    FastLED.show();
//    f++;
    
  }
  FastLED.show();
  delay(1000);
}

// for (int i = 0; i <= NUM_LEDS; i++) {
//    int color = rainbow_palette[(i + j) % numColors];    // mod 3 means the color number will be 0-2.
//    leds[i] = CHSV( color, 255, 255 );
//  }
//  FastLED.show();
//  j = (j + 1) % numColors;        // Cycle through the starting LED#, 0 to numcolors-1
//  delay(500);
